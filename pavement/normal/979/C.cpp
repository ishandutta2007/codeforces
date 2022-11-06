#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, X, Y, S = 1, R = 1;
vector<int> adj[300005];

bool loc(int n, int e, int c) {
	if (n == c) return 1;
	for (auto u : adj[n])
		if (u ^ e && loc(u, n, c)) return 1;
	return 0;
}

int sz(int n, int e) {
	int s = 1;
	for (auto u : adj[n])
		if (u ^ e) s += sz(u, n);
	return s;
}

main() {
	cin >> N >> X >> Y;
	for (int i = 0, u, v; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (auto u : adj[X])
		R += !loc(u, X, Y) * sz(u, X);
	for (auto u : adj[Y])
		S += !loc(u, Y, X) * sz(u, Y);
	cout << N * (N - 1) - R * S << '\n';
}