#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr long long inf = (long long)1e15;

	int n, m;
	cin >> n >> m;

	struct edge {
		int u, v, w;
	};

	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[--e[i].u].push_back(i);
		g[--e[i].v].push_back(i);
	}

	priority_queue<pair<long long, pair<int, int>>> pq;

	vector<array<long long, 51>> dist(n);
	for (int i = 0; i < n; i++) {
		dist[i].fill(inf);
	}

	vector<array<bool, 51>> visited(n, {0});

	pq.emplace(0, make_pair(0, 0));
	dist[0][0] = 0;

	while (!pq.empty()) {
		auto [u, w] = pq.top().second;
		pq.pop();

		if (visited[u][w])
			continue;
		visited[u][w] = true;

		if (w == 0) {
			for (int i : g[u]) {
				int v = e[i].u ^ e[i].v ^ u;
				if (dist[u][0] < dist[v][e[i].w]) {
					dist[v][e[i].w] = dist[u][0];
					pq.emplace(-dist[v][e[i].w], make_pair(v, e[i].w));
				}
			}
		} else {
			for (int i : g[u]) {
				int v = e[i].u ^ e[i].v ^ u;
				if (dist[u][w] + (w + e[i].w) * (w + e[i].w) < dist[v][0]) {
					dist[v][0] = dist[u][w] + (w + e[i].w) * (w + e[i].w);
					pq.emplace(-dist[v][0], make_pair(v, 0));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (visited[i][0]) {
			cout << dist[i][0] << ' ';
		} else {
			cout << -1 << ' ';
		}
	}
	cout << '\n';
	return 0;
}