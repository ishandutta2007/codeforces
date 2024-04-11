#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=2e5;
int n, a[mxN], ans, offset[mxN];
vector<int> adj[mxN];
set<int> vals[mxN];
 
void dfs(int u=0, int p=-1) {
	vals[u].insert(a[u]);
	bool bad=0;
	for (int v : adj[u])
		if (v!=p) {
			dfs(v, u);
			if (bad)
				continue;
			offset[v]^=a[u];
			if (vals[v].size()>vals[u].size()) {
				swap(vals[u], vals[v]);
				swap(offset[u], offset[v]);
			}
			for (int i : vals[v]) {
				i^=offset[u]^offset[v];
				if (vals[u].find(i^a[u])!=vals[u].end()) {
					vals[u].clear();
					bad=1;
					break;
				}
			}
			if (bad)
				continue;
			for (int i : vals[v])
				vals[u].insert(i^offset[u]^offset[v]);
		}
	ans+=bad;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << ans;
	return 0;
}