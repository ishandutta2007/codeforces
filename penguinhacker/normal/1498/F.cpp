#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[100000], dp[100000][40], ans[100000];
vector<int> adj[100000];

void dfs(int u = 0) {
	dp[u][0] = a[u];
	for (int v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		dfs(v);
		for (int i = 0; i < 2 * k; ++i)
			dp[u][(i + 1) % (2 * k)] ^= dp[v][i];
	}
}

void dfs2(int u = 0) {
	vector<int> prv(2 * k);
	for (int i = 0; i < 2 * k; ++i)
		prv[i] = dp[u][i];
	for (int v : adj[u]) {
		for (int i = 0; i < 2 * k; ++i)
			dp[u][(i + 1) % (2 * k)] = prv[(i + 1) % (2 * k)] ^ dp[v][i];
		for (int i = 0; i < 2 * k; ++i)
			dp[v][(i + 1) % (2 * k)] ^= dp[u][i];
		dfs2(v);
	}
	for (int i = 0; i < 2 * k; ++i)
		dp[u][i] = prv[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dfs();
	dfs2();
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		//for (int j = 0; j < 2 * k; ++j)
		//	cout << dp[i][j] << " ";
		//cout << "\n";
		for (int j = k; j < 2 * k; ++j)
			sum ^= dp[i][j];
		cout << (sum > 0) << " ";
	}
	return 0;
}