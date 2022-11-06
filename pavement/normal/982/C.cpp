#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, t, sz[100005];
vector<int> adj[100005];

int dfs(int n, int e) {
	sz[n] = 1;
	for (auto u : adj[n])
		if (u ^ e) sz[n] += dfs(u, n);
	return sz[n];
}

void cnt(int n, int e) {
	for (auto u : adj[n])
		if (u ^ e) {
			t += !((sz[u] | (sz[1] - sz[u])) & 1);
			cnt(u, n);
		}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	if (N & 1) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0, u, v; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cnt(1, -1);
	cout << t << '\n';
}