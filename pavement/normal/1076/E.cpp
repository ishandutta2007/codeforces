#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, Q, u, v, d, x, ft[600005], o[300005];
vector<int> adj[300005];
vector<pair<int, int> > qu[300005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int l, int r, int v) {
	for (; l <= N; l += ls(l)) ft[l] += v;
	for (r++; r <= N; r += ls(r)) ft[r] -= v;
}

void dfs(int n, int d, int e) {
	for (auto u : qu[n])
		upd(d, d + u.first, u.second);
	for (auto u : adj[n])
		if (u != e) dfs(u, d + 1, n);
	o[n] = qry(d);
	for (auto u : qu[n])
		upd(d, d + u.first, -u.second);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> Q;
	while (Q--) {
		cin >> v >> d >> x;
		d = min(d, N);
		qu[v].emplace_back(d, x);
	}
	dfs(1, 1, -1);
	for (int i = 1; i <= N; i++) cout << o[i] << ' ';
	cout << '\n';
}