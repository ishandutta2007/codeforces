#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 1e5 + 5, P = 1e9 + 7;
typedef long long ll;
int n, q; vector <pair <int, ll> > G[N];
int idx, d[N], sz[N], dfn[N], suf[N], fa[17][N];
ll f[N], g[N], D[N], dis[N], Dis[N];
void dfs(int u) {
	dfn[u] = ++idx, sz[u] = 1;
	rep(i, 1, 16) fa[i][u] = fa[i-1][fa[i-1][u]];
	for(auto [v, w] : G[u]) if(v ^ fa[0][u]) {
		d[v] = d[u] + 1, fa[0][v] = u, dfs(v), sz[u] += sz[v];
		g[u] = (g[u] + g[v] + w * sz[v]) % P;
		f[u] = (f[u] + f[v] + 2 * w * g[v] + w * w % P * sz[v]) % P;
	} suf[u] = idx;
}
void Dfs(int u) {
	for(auto [v, w] : G[u]) if(v ^ fa[0][u]) {
		D[v] = (D[u] + w) % P, dis[v] = (dis[u] + sz[v] * w) % P;
		Dis[v] = (Dis[u] + w * g[v] + (w * w - w * D[v]) % P * sz[v]) % P;
		Dfs(v);
	}
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	per(i, 16, 0) if(d[u] - (1 << i) >= d[v]) u = fa[i][u];
	if(u == v) return u;
	per(i, 16, 0) if(fa[i][u] ^ fa[i][v]) u = fa[i][u], v = fa[i][v];
	return fa[0][u];
}
ll calc(int u, int v) {
	if(dfn[v] <= dfn[u] && dfn[u] <= suf[v]) {
		ll len = D[u] - D[v];
		ll res = (f[v] + 2 * len * g[v] + len * len % P * sz[v]) % P;
		return (res - (Dis[u] - Dis[v] + D[u] * (dis[u] - dis[v])) % P * 4) % P;
	}
	else {
		ll len = (D[u] + D[v] - 2 * D[lca(u, v)]) % P;
		return (f[v] + 2 * len * g[v] + len * len % P * sz[v]) % P;
	}
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	int u, v, w;
	rep(i, 2, n) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(make_pair(v, w)), G[v].push_back(make_pair(u, w));
	}
	dfs(1), Dfs(1); 
	cin >> q;
	rep(i, 1, q) {
		scanf("%d%d", &u, &v);
		printf("%lld\n", ((2 * calc(u, v) - calc(u, 1)) % P + P) % P);
	}
	return 0;
}