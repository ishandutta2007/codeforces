#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	struct edge {
		int u, v, w;
	};

	int n, m;
	cin >> n >> m;

	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[--e[i].u].push_back(i);
		g[--e[i].v].push_back(i);
	}

	constexpr long long inf = (long long)1e15;
	vector<vector<long long>> dist(n, vector<long long>(n, inf));

	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		dist[e[i].u][e[i].v] = e[i].w;
		dist[e[i].v][e[i].u] = e[i].w;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] != inf && dist[k][j] != inf) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int q;
	cin >> q;

	vector<vector<int>> queries(n, vector<int>(n));

	while (q--) {
		int u, v, l;
		cin >> u >> v >> l;
		--u, --v;

		for (int i = 0; i < n; i++) {
			if (dist[u][i] < l) {
				queries[i][v] = max(queries[i][v], l - (int)dist[u][i]);
			}
			if (dist[v][i] < l) {
				queries[i][u] = max(queries[i][u], l - (int)dist[v][i]);
			}
		}
	}

	vector<bool> ok(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int id : g[i]) {
				int k = e[id].u ^ e[id].v ^ i;
				if (e[id].w + dist[k][j] <= queries[i][j]) {
					ok[id] = true;
				}
			}
		}
	}

	cout << count(ok.begin(), ok.end(), true) << '\n';
	return 0;
}