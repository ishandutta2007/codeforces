#include <bits/stdc++.h>
using namespace std;

int n, o[2];
vector<int> adj[200001];

void dfs(int now, int prev, int c) {
	o[c]++;
	for (int u: adj[now]) {
		if (u != prev) dfs(u, now, 1-c);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0);
	cout << min(o[0], o[1]) - 1 << '\n';

	return 0;
}