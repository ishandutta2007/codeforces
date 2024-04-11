#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
	}

	vector<bool> visited(n);
	vector<vector<int>> d(n, vector<int>(n, -5 * n));

	for (int s = 0; s < n; s++) {
		auto &lvl = d[s];

		queue<int> q;
		q.push(s), lvl[s] = 0;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i : g[x]) {
				if (lvl[i] == -5 * n) {
					lvl[i] = 1 + lvl[x];
					q.push(i);
				}
			}
		}
	}

	vector<vector<int>> outgoing(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		iota(outgoing[i].begin(), outgoing[i].end(), 0);
		sort(outgoing[i].begin(), outgoing[i].end(), [&](int u, int v) {
			return d[i][u] > d[i][v];
		});
	}

	int best_ans = 0;
	array<int, 4> ans;

	for (int u = 0; u < n; u++) {
		vector<int> incoming(n);
		iota(incoming.begin(), incoming.end(), 0);
		sort(incoming.begin(), incoming.end(), [&](int i, int j) {
			return d[i][u] > d[j][u];
		});

		for (int v = 0; v < n; v++) {
			if (u == v) {
				continue;
			}
			for (int i = 0; i < min(4, n - 1); i++) {
				if (incoming[i] == u || incoming[i] == v) {
					continue;
				}
				for (int j = 0; j < min(4, n - 1); j++) {
					if (outgoing[v][j] == u || outgoing[v][j] == v || outgoing[v][j] == incoming[i]) {
						continue;
					}
					if (d[incoming[i]][u] + d[u][v] + d[v][outgoing[v][j]] > best_ans) {
						best_ans = d[incoming[i]][u] + d[u][v] + d[v][outgoing[v][j]];
						ans = {incoming[i], u, v, outgoing[v][j]};
					}
				}
			}
		}
	}

	for (auto &x : ans) cout << x + 1 << ' ';
	cout << '\n';
	return 0;
}