#include <bits/stdc++.h>
using namespace std;

int N, M, T, mem[5005][5005], nxt[5005][5005];
vector<pair<int, int> > adj[5005];

int dp(int n, int k) {
	if (n == 1) return (k == 1 ? 0 : 1e9);
	if (mem[n][k] != -1) return mem[n][k];
	mem[n][k] = T + 5;
	for (auto u : adj[n]) {
		int x = min(T + 1, dp(u.first, k - 1) + u.second);
		if (x < mem[n][k]) {
			nxt[n][k] = u.first;
			mem[n][k] = x;
		}
	}
	return mem[n][k];
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		adj[v].emplace_back(u, w);
	}
	for (int i = N; i >= 1; i--) {
		if (dp(N, i) <= T) {
			cout << i << '\n';
			vector<int> v;
			for (int p = N, ci = i; p; p = nxt[p][ci--]) v.push_back(p);
			for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
			cout << '\n';
			return 0;
		}
	}
}