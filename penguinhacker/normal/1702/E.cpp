#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, col[mxN];
vector<int> adj[mxN];

bool dfs(int u, int p=0) {
	col[u]=p;
	for (int v : adj[u]) {
		if (col[v]==-1&&!dfs(v, p^1))
			return 0;
		if (col[u]==col[v])
			return 0;
	}
	return 1;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		col[i]=-1;
	}
	bool ok=1;
	for (int i=0; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		ok&=u!=v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		ok&=adj[i].size()<=2;
	if (!ok) {
		cout << "NO\n";
		return;
	}
	for (int i=0; i<n; ++i)
		if (col[i]==-1&&!dfs(i)) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
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