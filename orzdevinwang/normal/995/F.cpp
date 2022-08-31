#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
using namespace std;
const int N = 3007, mod = 1e9 + 7;
int n, d, dp[N][N], sz[N], fa[N], f[N], g[N], inv[N], now, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> d, inv[1] = 1;
	L(i, 2, n) cin >> fa[i], inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, n) L(j, 1, n) dp[i][j] = 1;
	R(i, n, 2) L(j, 1, n) (dp[i][j] += dp[i][j - 1]) %= mod, dp[fa[i]][j] = (ll) dp[fa[i]][j] * dp[i][j] % mod; 
	L(i, 1, n) f[i] = (f[i - 1] + dp[1][i]) % mod;
	L(i, 1, n) {
		now = 1;
		R(j, i, 1) (g[i] += (ll) now * f[j] % mod) %= mod,now = (ll) now * j % mod * inv[i - j + 1] % mod * (mod - 1) % mod;
	}
	now = 1;
	L(i, 1, n) now = (ll) now * (d - i + 1) % mod * inv[i] % mod, (ans += (ll) now * g[i] % mod) %= mod;
	cout << ans << "\n";
	return 0;
}