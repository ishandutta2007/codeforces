#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int K = 55;
const int mult = 10;
int n , p , k;
int r , inp;
int a[N];
int b[N];
int c[N + K];
pair < int , int > dp[N + K][K][2];
inline void setmax(pair < int , int > &res , pair < int , int > other , int val , bool take){
	if(other.first + val > res.first){
		res.first = other.first + val;
		res.second = other.second + take;
	}
	else if(other.first + val == res.first){
		res.second = min(res.second , other.second + take);
	}
}
int check(int penalty){
	for(int pos = n ; pos >= 1 ; --pos){
		int a = ::a[pos] - ::a[pos - 1];
		int b = ::b[pos] - ::b[pos - 1];
		for(int abk = 0 ; abk < k ; ++abk){
			pair < int , int > resa = {0 , 0};
			pair < int , int > resb = {0 , 0};
			if(abk){
				setmax(resa , dp[pos + 1][abk - 1][0] , a * mult , 0);
				setmax(resb , dp[pos + 1][abk - 1][1] , b * mult , 0);
				setmax(resa , dp[pos + abk][k - abk][1] , c[pos + abk - 1] * mult - c[pos - 1] * mult - penalty , 1);
				setmax(resb , dp[pos + abk][k - abk][0] , c[pos + abk - 1] * mult - c[pos - 1] * mult - penalty , 1);
			}
			else{
				setmax(resa , dp[pos + 1][0][0] , 0 , 0);
				setmax(resb , dp[pos + 1][0][1] , 0 , 0);
				setmax(resa , dp[pos + 1][k - 1][0] , a * mult - penalty , 1);
				setmax(resb , dp[pos + 1][k - 1][1] , b * mult - penalty , 1);
				setmax(resa , resb , 0 , 0);
				setmax(resb , resa , 0 , 0);
			}
			dp[pos][abk][0] = resa;
			dp[pos][abk][1] = resb;
		}
	}
	return dp[1][0][0].second;
}
int main(){
	scanf("%d %d %d" , &n , &p , &k);
	scanf("%d" , &r);
	while(r--){
		scanf("%d" , &inp);
		a[inp] = 1;
	}
	scanf("%d" , &r);
	while(r--){
		scanf("%d" , &inp);
		b[inp] = 1;
	}
	if(p * k >= n * 2){
		inp = 0;
		for(int i = 1 ; i <= n ; ++i){
			inp += a[i] | b[i];
		}
		printf("%d\n" , inp);
		return 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		c[i] = a[i] | b[i];
		a[i] += a[i - 1];
		b[i] += b[i - 1];
		c[i] += c[i - 1];
	}
	for(int i = n + 1 ; i <= n + k ; ++i){
		c[i] = c[i - 1];
	}
	int l = 0;
	int r = k * mult;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid) > p){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	check(l);
	printf("%d\n" , (dp[1][0][0].first + l * p) / mult);
}