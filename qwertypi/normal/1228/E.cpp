#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1000000007;
template <class T>
T powmod(T a, ll b, ll m){
	T res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

ll modinv(ll a, ll m){
	return powmod(a, m - 2, m);
}

ll fact[251];

ll C(int n, int r){
	return ((fact[n] * modinv(fact[r], mod)) % mod * modinv(fact[n-r], mod)) % mod;
}

ll prec[251][251]; // i -> j
ll dp[251][251]; // tries, left
int main(){
	fact[0] = 1;
	for(int i = 1; i <= 250; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	ll n, l;
	cin >> n >> l;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(j > i){
				prec[i][j] = 0;
				continue;
			}
			prec[i][j] = powmod<ll>(l, n - i, mod) * C(i, i - j) % mod * powmod<ll>(l - 1, j, mod) % mod;
			if(i == j){
				prec[i][j] = ((prec[i][j] - powmod<ll>(l - 1, n, mod)) % mod + mod) % mod;
			}
		}
	}
	dp[0][0] = 1;
	for(int i = 1; i < n; i++){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = 0;
			for(int k = 0; k <= n; k++){
				dp[i][j] = (dp[i][j] + (dp[i-1][k] * prec[j][k]) % mod) % mod;
			}
		}
	}
	cout << dp[n][n];
}