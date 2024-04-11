#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 15, mod = 1e9 + 7;
int n, q, a[N], e[N][N]; // i win j
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int dp[1 << N], ns;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) L(j, 1, n) e[i][j] = (ll) a[i] * qpow (a[i] + a[j]) % mod;
	L(i, 1, (1 << n) - 1) {
		dp[i] = 1;
		L(a, 1, n) 
			if(i >> (a - 1) & 1) 
				L(b, 1, n) if(!(i >> (b - 1) & 1)) 
					dp[i] = (ll) dp[i] * e[a][b] % mod;
		for(int j = i & (i - 1); j; j = i & (j - 1)) {
			int k = i ^ ((1 << n) - 1), now = dp[j];
			L(x, 1, n) if((i ^ j) >> (x - 1) & 1) L(y, 1, n) if(k >> (y - 1) & 1) now = (ll) now * e[x][y] % mod;
			(dp[i] += mod - now) %= mod;
		}
		(ns += (ll) dp[i] * __builtin_popcount(i) % mod) %= mod;
	}
	cout << ns << "\n";
	return 0;
}