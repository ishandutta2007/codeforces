// Olaf Surgut 17.09.2022 10:18:49
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	
	#define int int64_t

	int n, m; cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	vector<vector<pair<int, int>>> adjr(n);

	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w; u--, v--;

		adj[u].emplace_back(v, w);
		adjr[v].emplace_back(u, w);
	}

	const int inf = 1e18 + 7;

	vector<int> dist(n, inf);

	auto dijkstra = [&](vector<vector<pair<int, int>>> &graph) {
		typedef pair<int, int> State;

		priority_queue<State, vector<State>, greater<State>> pq;

		for (int i = 0; i < n; i++) {
			pq.emplace(dist[i], i);
		}

		while (pq.size()) {
			auto [d, u] = pq.top(); pq.pop();

			if (d != dist[u]) {
				continue;
			}

			for (auto [v, w] : graph[u]) {
				int new_d = d + w;

				if (dist[v] > new_d) {
					dist[v] = new_d;
					pq.emplace(new_d, v);
				}
			}
		}
	};

	dist[0] = 0;

	dijkstra(adj);
	dijkstra(adjr);

	for (int i = 1; i < n; i++) {
		cout << (dist[i] == inf ? (int) -1 : dist[i]) << ' ';
	}
	cout << '\n';

}