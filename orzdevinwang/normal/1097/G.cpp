#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7, M = 205, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N], S[M][M];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	S[0][0] = 1;
	L(i, 1, 200) L(j, 1, i) S[i][j] = (S[i - 1][j - 1] + (ll) S[i - 1][j] * j % mod) % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, k, fns[M];
int ehd[N], ev[N * 2], enx[N * 2], eid;
void eadd(int u, int v) { ++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid; }
int dp[N][M], s[M], siz[N];
void dfs(int x, int fa) {
	dp[x][0] = 1;
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) {
		dfs(ev[i], x), ++siz[ev[i]];
		R(j, min(k, siz[ev[i]]), 1) (dp[ev[i]][j] += dp[ev[i]][j - 1]) %= mod;
		L(a, 0, min(k, siz[x])) L(b, 0, min(k - a, siz[ev[i]])) 
			(s[a + b] += (ll) dp[x][a] * dp[ev[i]][b] % mod) %= mod;
		siz[x] += siz[ev[i]]; 
		L(a, 0, min(k, siz[x])) (dp[x][a] += s[a]) %= mod, s[a] = 0;
	} 
	L(i, 0, min(k, siz[x])) dp[x][i] = (ll) dp[x][i] * 2 % mod;
	(dp[x][0] += mod - 1) %= mod;
	L(i, 0, min(k, siz[x])) (fns[i] += dp[x][i]) %= mod;
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) { 
		R(j, min(k, siz[ev[i]]), 0) (fns[j] += mod - dp[ev[i]][j]) %= mod; 
	}
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k, init(n);
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		eadd(u, v), eadd(v, u);
	}
	dfs(1, 0);
	int ns = 0;
	L(i, 0, k) (ns += (ll) fac[i] * S[k][i] % mod * fns[i] % mod) %= mod;
	cout << ns << '\n';
	return 0;
}