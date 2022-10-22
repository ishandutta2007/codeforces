#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
vector<pair<int, int>> edge;
vector<int> adj[200001];
vector<int> col, ord, pos;

void init() {
	cin >> n >> m;
	edge.clear();
	ord.clear();
	for (int i=1; i<=n; ++i) adj[i].clear();
	for (int i=0, t, u, v; i<m; ++i) {
		cin >> t >> u >> v;
		if (t) {
			adj[v].push_back(u);
		}
		edge.emplace_back(u, v);
	}
	col.assign(n+1, 0);
	pos.resize(n+1);
}

bool dfs(int u) {
	if (col[u]==1) return 0;
	if (col[u]==2) return 1;
	col[u]++;
	for (int v : adj[u])
		if (!dfs(v)) return 0;
	col[u]++;
	ord.push_back(u);
	return 1;
}

void solve() {
	init();
	for (int i=1; i<=n; ++i) {
		if (col[i]==0&&!dfs(i)) {
			cout << "NO\n";
			return;
		}
	}
	for (int i=0; i<n; ++i)
		pos[ord[i]]=i;
	cout << "YES\n";
	//for (int i=1; i<=n; ++i)
	//	cout << pos[i] << '\n';
	for (auto &x : edge) {
		if (pos[x.first]>pos[x.second]) swap(x.first, x.second);
		cout << x.first << ' ' << x.second << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/