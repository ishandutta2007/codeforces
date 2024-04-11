#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
int n, m, d[mxN], dp[mxN];
bool vis[mxN];
vector<int> adj[mxN];

void dfs(int u) {
	vis[u] = 1;
	dp[u] = d[u];
	for (int v : adj[u]) if (d[u] < d[v]) {
		if (!vis[v]) dfs(v);
		dp[u] = min(dp[u], dp[v]);
	}
	for (int v : adj[u]) dp[u] = min(dp[u], d[v]);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
		d[i] = -1;
		vis[i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
	}
	d[0] = 0;
	queue<int> q; q.push(0);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) if (d[v] == -1) {
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i);
		cout << dp[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}