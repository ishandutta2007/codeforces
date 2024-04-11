#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int n, m;
int dep[mxN], anc[mxN][17];
int ind[mxN], cnt[mxN], ans[mxN];
vector<ar<int, 2>> adj[mxN];

void dfs1(int u=0, int p=-1) {
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (auto& v: adj[u]) if (v[0]!=p) {
		dep[v[0]]=dep[u]+1;
		anc[v[0]][0]=u;
		dfs1(v[0], u);
	}
}

int lca(int a, int b) {
	if (dep[a]>dep[b]) swap(a, b);
	for (int i=16; ~i; --i)
		if (dep[b]-(1<<i)>=dep[a])
			b=anc[b][i];
	if (a==b) return a;
	for (int i=16; ~i; --i)
		if (anc[a][i]!=anc[b][i])
			a=anc[a][i], b=anc[b][i];
	return anc[a][0];
}

void dfs2(int u=0, int p=-1) {
	for (auto &v: adj[u]) if (v[0]!=p) {
		ind[v[0]]=v[1];
		dfs2(v[0], u);
		cnt[u]+=cnt[v[0]];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}
	dfs1();
	cin >> m;
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		++cnt[a], ++cnt[b];
		cnt[lca(a, b)]-=2;
	}
	dfs2();
	for (int i=1; i<n; ++i)
		ans[ind[i]]=cnt[i];
	for (int i=1; i<n; ++i)
		cout << ans[i] << " ";
	return 0;
}