/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> deg(n);
	vector<vector<int>> edges(n);
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		--v;
		--u;
		if (v > u) swap(v, u);
		edges[v].push_back(u);
		deg[v]++;
		deg[u]++;
	}
	long long all = 0;
	long long have = 0;
	auto get = [&](int v) {
		int x = (int) edges[v].size();
		int y = deg[v] - x;
		return ((long long) x * (x - 1) + (long long) y * (y - 1)) >> 1;
	};
	for (int i = 0; i < n; i++) {
		all += (long long) deg[i] * (deg[i] - 1) / 2;
		have += get(i);
	}
	int q;
	cin >> q;
	cout << all - have << '\n';
	for (int i = 0; i < q; i++) {
		int v;
		cin >> v;
		--v;
		have -= get(v);
		for (int u : edges[v]) {
			have -= get(u);
			edges[u].push_back(v);
			have += get(u);
		}
		edges[v].clear();
		have += get(v);
		cout << all - have << '\n';
	}
}