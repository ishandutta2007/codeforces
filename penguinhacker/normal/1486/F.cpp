#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, d[mxN], anc[mxN][19], dp1[mxN], dp2[mxN];
vector<int> adj[mxN];
vector<ar<int, 2>> at[mxN];
ll ans;

void dfs1(int u=0) {
	for (int i=1; i<19; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u])
		if (v!=anc[u][0]) {
			d[v]=d[u]+1;
			anc[v][0]=u;
			dfs1(v);
		}
}

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=18; ~i; --i)
		if (d[v]-(1<<i)>=d[u])
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=18; ~i; --i)
		if (anc[u][i]!=anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

int lift(int u, int x) {
	for (int i=0; i<19; ++i)
		if (x&1<<i)
			u=anc[u][i];
	return u;
}

ll C2(int x) {
	return (ll)x*(x-1)/2;
}

void dfs2(int u=0) {
	for (int v : adj[u]) {
		if (v==anc[u][0])
			continue;
		dfs2(v);
		dp1[u]+=dp1[v];
		dp2[u]+=dp2[v];
	}
	//cout << u << " " << dp1[u] << " " << dp2[u] << "\n";
	map<int, int> mp1;
	map<ar<int, 2>, int> mp2;
	for (ar<int, 2> x : at[u]) {
		ans+=dp1[u];
		if (x[0]!=-1) {
			ans-=dp2[x[0]];
			++mp1[x[0]];
		}
		if (x[1]!=-1) {
			ans-=dp2[x[1]];
			++mp1[x[1]];
		}
		if (x[0]!=-1&&x[1]!=-1)
			++mp2[{min(x[0], x[1]), max(x[0], x[1])}];
	}
	ans+=C2(at[u].size());
	for (auto x : mp1)
		ans-=C2(x.second);
	for (auto x : mp2)
		ans+=C2(x.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	cin >> m;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		int uv=lca(u, v);
		++dp1[u], ++dp1[v], dp1[uv]-=2;
		int uc=u==uv?-1:lift(u, d[u]-d[uv]-1);
		int vc=v==uv?-1:lift(v, d[v]-d[uv]-1);
		if (uc!=-1)
			++dp2[u], --dp2[uc];
		if (vc!=-1)
			++dp2[v], --dp2[vc];
		at[uv].push_back({uc, vc});
	}
	dfs2();
	cout << ans;
	return 0;
}