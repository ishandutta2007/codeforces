#include <bits/stdc++.h>
using namespace std;

int sz[100005], lvl[100005], par[100005], dist[100005], dep[100005], anc[100005][20], distl[100005][20], val[100005], clogn;
vector<int> adj[100005];

void init_lca(int n, int e, int d) {
	dist[n] = d;
	anc[n][0] = e;
	for (int i = 1; i <= clogn; i++)
		if (anc[n][i - 1] != -1)
			anc[n][i] = anc[anc[n][i - 1]][i - 1];
	for (auto u : adj[n])
		if (u != e) dep[u] = dep[n] + 1, init_lca(u, n, d + 1);
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = clogn; i >= 0; i--)
		if (dep[u] - (1<<i) >= dep[v])
			u = anc[u][i];
	if (u == v) return u;
	for (int i = clogn; i >= 0; i--)
		if (anc[u][i] != anc[v][i])
			u = anc[u][i],
			v = anc[v][i];
	return anc[u][0];
}

int dfs(int n, int e) {
	sz[n] = 1;
	for (auto u : adj[n])
		if (u != e && lvl[u] == -1)
			sz[n] += dfs(u, n);
	return sz[n];
}

int cent(int n, int e, int s) {
	for (auto u : adj[n])
		if (u != e && lvl[u] == -1 && sz[u] > s / 2)
			return cent(u, n, s);
	return n;
}

void build(int n, int e, int l) {
	int s = dfs(n, e), c = cent(n, e, s);
	if (e == -1) e = c;
	par[c] = e;
	lvl[c] = l++;
	for (auto u : adj[c])
		if (lvl[u] == -1) build(u, c, l);
}

int main() {
	memset(anc, -1, sizeof anc);
	memset(lvl, -1, sizeof lvl);
	memset(val, 127, sizeof val);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, u, v, q, ans;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	clogn = ceil(log2(n));
	init_lca(1, -1, 0);
	build(1, -1, 0);
	for (int i = 1; i <= n; i++) {
		u = par[i];
		for (int j = 1; j <= lvl[i]; j++, u = par[u])
			distl[i][j] = dist[i] + dist[u] - 2 * dist[lca(i, u)];
	}
	u = 1;
	for (int i = 0; i <= lvl[1]; i++, u = par[u])
		val[u] = distl[1][i];
	while (q--) {
		cin >> u >> v;
		if (u == 1) {
			u = v;
			for (int i = 0; i <= lvl[v]; i++, u = par[u])
				val[u] = min(val[u], distl[v][i]);
		} else {
			ans = 1e9;
			u = v;
			for (int i = 0; i <= lvl[v]; i++, u = par[u])
				ans = min(ans, val[u] + distl[v][i]);
			cout << ans << '\n';
		}
	}
}