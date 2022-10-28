#include "bits/stdc++.h"
using namespace std;
const int mod = 998244353;
const int N = 5e3 + 3;
int a , b , c;
int pascal[N][N];
int fact[N];
int main(){
	for(int i = 0 ; i < N ; ++i){
		pascal[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j){
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			pascal[i][j] -= (pascal[i][j] >= mod) * mod;
		}
	}
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = (1LL * fact[i - 1] * i) % mod;
	}
	int ans = 0;
	int ans2 = 0;
	scanf("%d %d %d" , &a , &b , &c);
	for(int i = 0 ; i <= min(b , c) ; ++i){
		ans2 = (ans2 + 1LL * pascal[b][i] * ((1LL * pascal[c][i] * fact[i]) % mod)) % mod;
	}
	for(int i = 0 ; i <= min(a , b) ; ++i){
		for(int j = 0 ; j <= min(a , c) ; ++j){
			long long tmp = 1;
			tmp = (1LL * tmp * pascal[a][i]) % mod;
			tmp = (1LL * tmp * pascal[b][i]) % mod;
			tmp = (1LL * tmp * fact[i]) % mod;
			tmp = (1LL * tmp * pascal[a][j]) % mod;
			tmp = (1LL * tmp * pascal[c][j]) % mod;
			tmp = (1LL * tmp * fact[j]) % mod;
			ans = (ans + tmp) % mod;
		}
	}
	ans = (1LL * ans * ans2) % mod;
	printf("%d\n" , ans);
}