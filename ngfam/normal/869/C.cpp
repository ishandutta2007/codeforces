#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long Qpow(long long x, long long y){
	if(y == 0) return 1;
	if(y == 1) return x;

	long long C = Qpow(x, y >> 1);
  C = (C * C) % mod;
  return (C * Qpow(x, y % 2)) % mod;
}

const int N = 5050;

long long fact[N];
long long dp[N][N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	long long a, b, c;
	cin >> a >> b >> c;

	dp[0][0] = 1;

	int t = max(max(a, b), c);

	fact[0] = 1;
	for(int i = 1; i <= t; ++i){
		fact[i] = fact[i - 1] * i % mod;
	}

	for(int i = 1; i <= t; ++i){
		dp[i][0] = 1;
		for(int j = 1; j <= t; ++j){
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			if(dp[i][j] >= mod) dp[i][j] -= mod;
		}
	}

	long long ans = 1, x = 0, y = 0, z = 0;

	for(int i = 0; i <= min(a, b); ++i){
		x += (dp[a][i] * dp[b][i] % mod) * fact[i];
		x %= mod;
	}

	for(int i = 0; i <= min(a, c); ++i){
		y += (dp[a][i] * dp[c][i] % mod) * fact[i];
		y %= mod;
	}

	for(int i = 0; i <= min(c, b); ++i){
		z += (dp[c][i] * dp[b][i] % mod) * fact[i];
		z %= mod;
	}

	cout << ((x * y) % mod) * z  % mod;

	return 0;
}