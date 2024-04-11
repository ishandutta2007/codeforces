#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, mxM=2e5;
int n, m, p[mxN], dp[mxN], d[mxN], anc[mxN][17];
vector<int> adj[mxN];
vector<ar<int, 2>> bad;
string ans;

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

void dfs1(int u=0) {
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u])
		if (v!=anc[u][0]) {
			d[v]=d[u]+1, anc[v][0]=u;
			dfs1(v);
		}
}

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=16; ~i; --i)
		if (d[v]-(1<<i)>=d[u])
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=16; ~i; --i)
		if (anc[u][i]!=anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

void dfs2(int u=0) {
	if (dp[u]==bad.size())
		ans[u]='1';
	for (int v : adj[u])
		if (v!=anc[u][0])
			dp[v]+=dp[u], dfs2(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	iota(p, p+n, 0);
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		if (find(u)!=find(v)) {
			p[find(v)]=find(u);
			adj[u].push_back(v);
			adj[v].push_back(u);
		} else
			bad.push_back({u, v});
	}
	dfs1();
	for (auto [u, v] : bad) {
		if (d[u]>d[v])
			swap(u, v);
		if (lca(u, v)==u) {
			++dp[0], ++dp[v];
			for (int i=16; ~i; --i)
				if (d[v]-(1<<i)>d[u])
					v=anc[v][i];
			--dp[v];
		} else
			++dp[u], ++dp[v];
	}
	ans=string(n, '0');
	dfs2();
	cout << ans;
	return 0;
}