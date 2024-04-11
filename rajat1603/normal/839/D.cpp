#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int n;
int cnt[N];
int pw2[N];
int dp[N];
int inv[N];
int ans;
int main(){
	pw2[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		pw2[i] = (2LL * pw2[i - 1]) % mod;
	}
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		int tmp;
		scanf("%d" , &tmp);
		++cnt[tmp];
	}
	inv[0] = 0;
	inv[1] = 1;
	for(int i = 2 ; i < N ; ++i){
		inv[i] = (((1LL * (-(mod / i)) * inv[mod % i]) % mod) + mod) % mod;
	}
	ans = 0;
	for(int i = N - 1 ; i >= 2 ; --i){
		int tot = 0;
		for(int j = i ; j < N ; j += i){
			tot += cnt[j];
		}
		int res = 0;
		if(tot){
			res = (1LL * tot * pw2[tot - 1]) % mod;
			res = (1LL * res * i) % mod;
		}
		for(int j = i + i ; j < N ; j += i){
			res = (res - 1LL * ((1LL * dp[j] * inv[j]) % mod) * i) % mod;
			res += (res < 0) * mod;
		}
		dp[i] = res;
		ans = (ans + res) % mod;
	}
	printf("%d\n" , ans);
}