#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int n, m;
bool vis[300000], take[300000];
vector<int> adj[300000];
vector<int> ans;
 
void dfs(int u = 0) {
	vis[u] = 1;
	take[u] = 1;
	for (int v : adj[u]) take[u] &= !take[v];
	if (take[u]) ans.push_back(u);
	for (int v : adj[u]) if (!vis[v]) dfs(v);
}
 
void solve() {
	cin >> n >> m;
	ans.clear();
	for (int i = 0; i < n; ++i) {
		vis[i] = 0;
		take[i] = 0;
		adj[i].clear();
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	if (count(vis, vis + n, 0) > 0) {cout << "NO\n"; return;}
	cout << "YES\n" << ans.size() << "\n";
	for (int i : ans) cout << i + 1 << " ";
	cout << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}