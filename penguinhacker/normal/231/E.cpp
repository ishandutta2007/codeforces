#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 1e9 + 7;
const int mxN = 100000;
int n, m, q, par[mxN], dep[mxN], cmp[mxN];
vector<int> adj[mxN];
vector<int> adj2[mxN];

int dep2[mxN], dp[mxN], anc[mxN][17];
int ans[mxN];

void dfs(int u = 0) {
	for (int v : adj[u]) {
		if (par[v] == -1) {
			dep[v] = dep[u] + 1;
			par[v] = u;
			dfs(v);
		}
		else if (dep[v] + 2 <= dep[u]) {
			dp[v] = 1;
			for (int i = u; i != v; i = par[i]) cmp[i] = v;
		}
	}
}

void dfs2(int u = 0) {
	// cout << u << " ";
	for (int i = 1; i < 17; ++i) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for (int v : adj2[u]) if (v != anc[u][0]) {
		anc[v][0] = u;
		dep2[v] = dep2[u] + 1;
		dp[v] += dp[u];
		dfs2(v);
	}
}

int lca(int u, int v) {
	if (dep2[u] > dep2[v]) swap(u, v);
	for (int i = 16; ~i; --i) if (dep2[u] <= dep2[v] - (1 << i)) v = anc[v][i];
	assert(dep2[u] == dep2[v]);
	if (u == v) return u;
	for (int i = 16; ~i; --i) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(par + 1, par + n, -1);
	iota(cmp, cmp + n, 0);
	dfs();
	for (int i = 0; i < n; ++i) for (int j : adj[i]) if (cmp[i] != cmp[j]) adj2[cmp[i]].push_back(cmp[j]);
	dfs2();
	ans[0] = 1;
	for (int i = 1; i < n; ++i) ans[i] = 2 * ans[i - 1] % MOD;
	cin >> q;
	while(q--) {
		int a, b; cin >> a >> b;
		a = cmp[a - 1], b = cmp[b - 1];
		int l = lca(a, b);
		int c = dp[a] + dp[b] - dp[l];
		if (l > 0) c -= dp[anc[l][0]];
		assert(c < n);
		cout << ans[c] << "\n";
	}
	return 0;
}