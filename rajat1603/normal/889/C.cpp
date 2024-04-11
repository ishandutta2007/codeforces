#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int n , k;
int fact[N];
int ifact[N];
int fastvalid[N];
int sum[N];
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
inline int ncr(int n , int r){
	int res = fact[n];
	res = (1LL * res * ifact[r]) % mod;
	res = (1LL * res * ifact[n - r]) % mod;
	return res;
}
inline int get(int n , int k){
	return ncr(n + 1 , k + 1);
}
int main(){
	scanf("%d %d" , &n , &k);
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = (1LL * fact[i - 1] * i) % mod;
	}
	ifact[N - 1] = power(fact[N - 1] , mod - 2);
	for(int i = N - 2 ; i >= 0 ; --i){
		ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
	}
	fastvalid[0] = 1;
	sum[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		if(i <= k){
			fastvalid[i] = fact[i];
			sum[i] = (sum[i - 1] + 1LL * fastvalid[i] * ifact[i]) % mod;
			continue;
		}
		fastvalid[i] = (1LL * (sum[i - 1] - sum[i - k - 1] + mod) * fact[i - 1]) % mod;
		sum[i] = (sum[i - 1] + 1LL * fastvalid[i] * ifact[i]) % mod;
	}
	int ans = 0;
	for(int i = k + 1 ; i <= n - 1 ; ++i){
		int sum = 0;
		sum = get(n - 2 , i - 1);
		sum = (1LL * sum * fastvalid[i - k - 1]) % mod;
		sum = (1LL * sum * fact[k]) % mod;
		sum = (1LL * sum * fact[n - i]) % mod;
		sum = (1LL * sum * ifact[k]) % mod;
		sum = (1LL * sum * ifact[i - k - 1]) % mod;
		sum = (1LL * sum * fact[i - 1]) % mod;
		ans = (ans + sum) % mod;
	}
	printf("%d\n" , ans);
}