#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 8;
int mod;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, dp[N][N], ns;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> mod; 
//	n = 200, mod = 998244353;
	init (n + 1);
	L(mn, max(n - 20, 0), n + 1) {
		memset(dp, 0, sizeof(dp));
		L(i, 1, min(mn, n)) dp[i][0] = ifac[i];
		L(i, mn + 1, n + 1) 
			R(a, i - 1, 1) 
				L(b, 0, mn) if(dp[a][b]) {
					int up = min(min(i - a, (mn * (i - a) - b) / i), (mn - b) / (i - mn));
					L(k, 1, up) 
						(dp[a + k][b + (i - mn) * k] += (ll) ifac[k] * dp[a][b] % mod) %= mod;
				}
		L(i, 0, mn) (ns += dp[n][i]) %= mod;
	}
	cout << (ll) ns * fac[n] % mod << '\n';
	return 0;
}