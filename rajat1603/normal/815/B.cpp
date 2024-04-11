#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n;
int arr[N];
int fact[N];
int ifact[N];
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
void pre(){
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = (1LL * fact[i - 1] * i) % mod;
	}
	ifact[N - 1] = power(fact[N - 1] , mod - 2);
	for(int i = N - 2 ; i >= 0 ; --i){
		ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
	}
}
int ncr(int n , int r){
	return (1LL * ((1LL * fact[n] * ifact[r]) % mod) * ifact[n - r]) % mod;
}
int val[N];
int tmp[N];
int ans;
int main(){
	pre();
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	memset(val , 0 , sizeof(val));
	if(n % 4 == 1){
		int row = (n - 1) / 2;
		int cur = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(i & 1){
				val[i] = ncr(row , cur);
				++cur;
			}
			else{
				val[i] = 0;
			}
		}
	}
	else if(n % 4 == 2){
		int row = (n - 2) / 2;
		int cur = 0;
		for(int i = 1 ; i <= n ; i += 2){
			val[i] = ncr(row , cur);
			val[i + 1] = ncr(row , cur);
			++cur;
		}
	}
	else if(n % 4 == 0){
		int row = (n - 2) / 2;
		int cur = 0;
		for(int i = 1 ; i <= n ; i += 2){
			val[i] = ncr(row , cur);
			val[i + 1] = (mod - ncr(row , cur)) % mod;
			++cur;
		}
	}
	else{
		--n;
		int row = (n - 2) / 2;
		int cur = 0;
		for(int i = 1 ; i <= n ; i += 2){
			tmp[i] = ncr(row , cur);
			tmp[i + 1] = ncr(row , cur);
			++cur;
		}
		++n;
		val[1] = tmp[1];
		for(int i = 2 ; i < n ; ++i){
			if(i & 1){
				val[i] = (tmp[i] - tmp[i - 1] + mod) % mod;
			}
			else{
				val[i] = (tmp[i - 1] + tmp[i]) % mod;
			}
		}
		val[n] = (mod - tmp[n - 1]) % mod;
	}
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		ans = (ans + 1LL * val[i] * arr[i]) % mod;
	}
	printf("%d\n" , ans);
}