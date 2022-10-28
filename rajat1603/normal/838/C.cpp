#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 18;
const int LN = 17;
int n , k , mod;
int factpow2[N];
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
int moba[1 << LN][LN];
int mobb[1 << LN][LN];
int popcnt[N];
int tmp[LN];
void mult(int moba[1 << LN][LN] , int mobb[1 << LN][LN]){
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; j < LN ; ++j){
			int res = 0;
			for(int k = 0 ; k <= j ; ++k){
				res = (res + 1LL * moba[i][k] * mobb[i][j - k]) % mod;
			}
			tmp[j] = res;
		}
		for(int j = 0 ; j < LN ; ++j){
			moba[i][j] = tmp[j];
		}
	}
}
void solve(int k){
	memset(moba , 0 , sizeof(moba));
	memset(mobb , 0 , sizeof(mobb));
	for(int i = n ; i ; i = (i - 1) & n){
		moba[i][popcnt[i]] = ifact[i * 2];
	}
	moba[0][0] = 1;
	mobb[0][0] = 1;
	for(int i = 0 ; i < LN ; ++i){
		for(int j = 0 ; j < LN ; ++j){
			for(int k = 0 ; k <= n ; ++k){
				if((k >> j) & 1){
					moba[k][i] += moba[k ^ (1 << j)][i];
					moba[k][i] -= (moba[k][i] >= mod) * mod;
				}
			}
		}
	}
	for(int i = 0 ; i <= n ; ++i){
		mobb[i][0] = 1;
	}
	while(k){
		if(k & 1){
			mult(mobb , moba);
		}
		mult(moba , moba);
		k >>= 1;
	}
	int i = popcnt[n];
	for(int j = 0 ; j < LN ; ++j){
		for(int k = 0 ; k <= n ; ++k){
			if((k >> j) & 1){
				mobb[k][i] -= mobb[k ^ (1 << j)][i];
				mobb[k][i] += (mobb[k][i] < 0) * mod;
			}
		}
	}
}
int solve(){
	solve(k);
	return (1LL * mobb[n][popcnt[n]] * fact[n * 2]) % mod;
}
int main(){
	cin >> n >> k >> mod;
	int ans;
	if(n & 1){
		ans = power(k , n);
	}
	else{
		fact[0] = 1;
		for(int i = 1 ; i <= n ; ++i){
			fact[i] = (1LL * fact[i - 1] * i) % mod;
		}
		ifact[n] = power(fact[n] , mod - 2);
		for(int i = n - 1 ; i >= 0 ; --i){
			ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
		}
		popcnt[0] = 0;
		for(int i = 1 ; i <= n ; ++i){
			popcnt[i] = popcnt[i >> 1] + (i & 1);
		}
		n >>= 1;
		ans = power(k , 2 * n) - solve();
		ans %= mod;
		ans += mod;
		ans %= mod;
	}
	printf("%d\n" , ans);
}