#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
bool vis[200000]={};
vector<int> adj[200000];
vector<ar<int, 3>> comp;

ar<int, 3> dfs(int u) {
	vis[u]=1;
	int mn=u, mx=u, sze=1;
	for (int v:adj[u])
		if (!vis[v]) {
			ar<int, 3> x=dfs(v);
			mn=min(mn, x[0]);
			mx=max(mx, x[1]);
			sze+=x[2];
		}
	return {mn, mx, sze};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		if (!vis[i])
			comp.push_back(dfs(i));
	reverse(comp.begin(), comp.end());

	int ans=0;
	while (!comp.empty()) {
		ar<int, 3> x=comp.back(); comp.pop_back();
		if (x[1]-x[0]+1==x[2])
			continue;
		ans++;
		ar<int, 3> y=comp.back(); comp.pop_back();
		comp.push_back({x[0], max(x[1], y[1]), x[2]+y[2]});
	}
	cout << ans;
	return 0;
}