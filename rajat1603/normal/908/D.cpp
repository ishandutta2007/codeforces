#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int mod = 1e9 + 7;
int k , xa , xb;
int pa , pb;
int pinv;
int pabypb;
int pbbypa;
int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}
int dp[N][N];
int solve(int a , int ab){
	if(ab >= k){
		return ab;
	}
	if(a >= k){
		return (a + 0LL + ab + 0LL + pabypb) % mod;
	}
	if(dp[a][ab] != -1){
		return dp[a][ab];
	}
	int res = (1LL * solve(a + 1 , ab) * pa + 1LL * solve(a , ab + a) * pb) % mod;
	return dp[a][ab] = res;
}
int main(){
	cin >> k >> xa >> xb;
	pinv = power(xa + xb , mod - 2);
	pa = (1LL * xa * pinv) % mod;
	pb = (1LL * xb * pinv) % mod;
	pabypb = (1LL * pa * power(pb , mod - 2)) % mod;
	pbbypa = (1LL * pb * power(pa , mod - 2)) % mod;
	memset(dp , -1 , sizeof(dp));
	printf("%d\n" , solve(1 , 0));
}