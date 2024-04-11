#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int mod = 1e9 + 7;
int n;
int d[N];
inline int c2(int x){
	return ((x * (x - 1)) >> 1);
}
inline int c3(int x){
	return (x * (x - 1) * (x - 2)) / 6;
}
inline int ncr(int n , int r){
	if(r == 0){
		return 1;
	}
	if(r == 1){
		return n;
	}
	if(r == 2){
		return c2(n);
	}
	if(r == 3){
		return c3(n);
	}
}
map < int , int > dp[N][N][N][N];
int solve(int x21 , int x22 , int x11 , int x12 , int pos){
	if(pos > n){
		return (x21 + x22 + x11 + x12) == 0;
	}
	if(dp[pos][x21][x22][x11].find(x12) != dp[pos][x21][x22][x11].end()){
		return dp[pos][x21][x22][x11][x12];
	}
	int res = 0;
	if(d[pos] == 2){
		/*if(x11 >= 2 && (x21 + x22 == 0)){
			res = (res + 1LL * c2(x11) * solve(x11 - 2 , x12 , 0 , 0 , pos + 1)) % mod;
		}
		if(x12 >= 2 && (x21 + x22 == 0)){
			res = (res + 1LL * c2(x12) * solve(x11 + 2 , x12 - 2 , 0 , 0 , pos + 1)) % mod;
		}*/
		if(x11 >= 1 && (x21 + x22 == 0)){
			res = (res + 1LL * x11 * solve(x11 - 1 , x12 , 1 , 0 , pos + 1)) % mod;
		}
		if(x12 >= 1 && (x21 + x22 == 0)){
			res = (res + 1LL * x12 * solve(x11 + 1 , x12 - 1 , 1 , 0 , pos + 1)) % mod;
		}
		/*if(x11 >= 1 && x12 >= 1 && (x21 + x22 == 0)){
			res = (res + 1LL * x11 * x12 * solve(x11 , x12 - 1 , 0 , 0 , pos + 1)) % mod;
		}*/
		/*
		if(x21 >= 2){
			res = (res + 1LL * c2(x21) * solve(x21 - 2 , x22 , x11 , x12 , pos + 1)) % mod;
		}
		if(x22 >= 2){
			res = (res + 1LL * c2(x22) * solve(x21 + 2 , x22 - 2 , x11 , x12 , pos + 1)) % mod;
		}
		if(x21 >= 1 && x22 >= 1){
			res = (res + 1LL * x21 * x22 * solve(x21 , x22 - 1 , x11 , x12 , pos + 1)) % mod;
		}*/
		if(x21 >= 1){
			res = (res + 1LL * x21 * solve(x21 - 1 , x22 , x11 + 1 , x12 , pos + 1)) % mod;
		}
		if(x22 >= 1){
			res = (res + 1LL * x22 * solve(x21 + 1 , x22 - 1 , x11 + 1 , x12 , pos + 1)) % mod;
		}
		if(x21 >= 1 && x11 >= 1){
			res = (res + 1LL * x21 * x11 * solve(x21 - 1 , x22 , x11 - 1 , x12 , pos + 1)) % mod;
		}
		if(x21 >= 1 && x12 >= 1){
			res = (res + 1LL * x21 * x12 * solve(x21 - 1 , x22 , x11 + 1 , x12 - 1 , pos + 1)) % mod;
		}
		if(x22 >= 1 && x11 >= 1){
			res = (res + 1LL * x22 * x11 * solve(x21 + 1 , x22 - 1 , x11 - 1 , x12 , pos + 1)) % mod;
		}
		if(x22 >= 1 && x12 >= 1){
			res = (res + 1LL * x22 * x12 * solve(x21 + 1 , x22 - 1 , x11 + 1 , x12 - 1 , pos + 1)) % mod;
		}
	}
	else{
		/*if(x11 >= 2 && (x21 + x22 == 0)){
			res = (res + 1LL * c2(x11) * solve(x11 - 2 , x12 , 1 , 0 , pos + 1)) % mod;
		}
		if(x12 >= 2 && (x21 + x22 == 0)){
			res = (res + 1LL * c2(x12) * solve(x11 + 2 , x12 - 2 , 1 , 0 , pos + 1)) % mod;
		}*/
		if(x11 >= 1 && (x21 + x22 == 0)){
			res = (res + 1LL * x11 * solve(x11 - 1 , x12 , 0 , 1 , pos + 1)) % mod;
		}
		if(x12 >= 1 && (x21 + x22 == 0)){
			res = (res + 1LL * x12 * solve(x11 + 1 , x12 - 1 , 0 , 1 , pos + 1)) % mod;
		}
		/*if(x11 >= 1 && x12 >= 1 && (x21 + x22 == 0)){
			res = (res + 1LL * x11 * x12 * solve(x11 , x12 - 1 , 1 , 0 , pos + 1)) % mod;
		}*/
		/*if(x21 >= 2){
			res = (res + 1LL * c2(x21) * solve(x21 - 2 , x22 , x11 + 1 , x12 , pos + 1)) % mod;
		}
		if(x22 >= 2){
			res = (res + 1LL * c2(x22) * solve(x21 + 2 , x22 - 2 , x11 + 1 , x12 , pos + 1)) % mod;
		}
		if(x21 >= 1 && x22 >= 1){
			res = (res + 1LL * x21 * x22 * solve(x21 , x22 - 1 , x11 + 1 , x12 , pos + 1)) % mod;
		}*/
		if(x21 >= 1){
			res = (res + 1LL * x21 * solve(x21 - 1 , x22 , x11 , x12 + 1 , pos + 1)) % mod;
		}
		if(x22 >= 1){
			res = (res + 1LL * x22 * solve(x21 + 1 , x22 - 1 , x11 , x12 + 1 , pos + 1)) % mod;
		}
		if(x21 >= 1 && x11 >= 1){
			res = (res + 1LL * x21 * x11 * solve(x21 - 1 , x22 , x11 - 1 + 1 , x12 , pos + 1)) % mod;
		}
		if(x21 >= 1 && x12 >= 1){
			res = (res + 1LL * x21 * x12 * solve(x21 - 1 , x22 , x11 + 1 + 1 , x12 - 1 , pos + 1)) % mod;
		}
		if(x22 >= 1 && x11 >= 1){
			res = (res + 1LL * x22 * x11 * solve(x21 + 1 , x22 - 1 , x11 - 1 + 1 , x12 , pos + 1)) % mod;
		}
		if(x22 >= 1 && x12 >= 1){
			res = (res + 1LL * x22 * x12 * solve(x21 + 1 , x22 - 1 , x11 + 1 + 1 , x12 - 1 , pos + 1)) % mod;
		}

		/*if(x11 >= 3 && (x21 + x22 == 0)){
			res = (res + 1LL * c3(x11) * solve(x11 - 3 , x12 , 0 , 0 , pos + 1)) % mod;
		}
		if(x12 >= 3 && (x21 + x22 == 0)){
			res = (res + 1LL * c3(x12) * solve(x11 + 3 , x12 - 3 , 0 , 0 , pos + 1)) % mod;
		}
		if(x11 >= 2 && x12 >= 1 && (x21 + x22 == 0)){
			res = (res + 1LL * c2(x11) * x12 * solve(x11 - 2 + 1 , x12 - 1 , 0 , 0 , pos + 1)) % mod;
		}
		if(x11 >= 1 && x12 >= 2 && (x21 + x22 == 0)){
			res = (res + 1LL * x11 * c2(x12) * solve(x11 - 1 + 2 , x12 - 2 , 0 , 0 , pos + 1)) % mod;
		}*/
		for(int i = 0 ; i <= 1 && i <= x21 ; ++i){
			for(int j = 0 ; j <= 1 - i && j <= x22 ; ++j){
				if(i + j == 0){
					continue;
				}
				int k = 3 - (i + j);
				for(int x = 0 ; x <= k && x <= x11 ; ++x){
					int y = k - x;
					if(y > x12){
						continue;
					}
					res = (res + 1LL * ncr(x21 , i) * ncr(x22 , j) * ncr(x11 , x) * ncr(x12 , y) * solve(x21 - i + j , x22 - j , x11 - x + y , x12 - y , pos + 1)) % mod;
				}
			}
		}
	}
	//cout << x21 << " " << x22 << " " << x11 << " " << x12 << " " << pos << " " << res << endl;
	return dp[pos][x21][x22][x11][x12] = res;
	//return res;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , d + i);
	}
	printf("%d\n" , solve(d[1] == 2 , d[1] == 3 , d[2] == 2 , d[2] == 3 , 3));
}