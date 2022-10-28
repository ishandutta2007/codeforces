#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int inp;
int cnt[N];
int pw2[N];
int dp[N];
int main(){
	scanf("%d" , &n);
	pw2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp);
		++cnt[inp];
		pw2[i] = (2LL * pw2[i - 1]) % mod;
	}
	for(int g = N - 1 ; g >= 1 ; --g){
		int tot = 0;
		for(int i = g ; i < N ; i += g){
			tot += cnt[i];
		}
		long long val = pw2[tot] - 1;
		for(int i = g + g ; i < N ; i += g){
			val -= dp[i];
		}
		dp[g] = ((val % mod) + mod) % mod;
	}
	printf("%d\n" , dp[1]);
}