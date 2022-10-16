#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int n, m, k;
vector<pair<int, int>> adj[1000];

vector<int> dijkstra(int s) {
	vector<int> dist(n, INF);

	priority_queue<pair<int, int>> pq;
	pq.push({0, s}); dist[s] = 0;

	while (pq.size()) {
		auto [ds, now] = pq.top(); pq.pop();

		for (auto [u, w]: adj[now]) {
			if (dist[now] + w < dist[u]) {
				dist[u] = dist[now] + w;
				pq.push({-dist[u], u});
			}
		}
	}

	return dist;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		x--, y--;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);

		edges.emplace_back(x, y, w);
	}

	vector<vector<int>> dist;
	for (int i = 0; i < n; i++) {
		dist.push_back(dijkstra(i));
	}

	vector<pair<int, int>> r;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y; x--; y--;
		r.emplace_back(x, y);
	}
	int ans = INF;

	for (auto [u, v, w]: edges) {
		int tmp = 0;
		for (auto [x, y]: r) {
			int ss = dist[x][u] + dist[y][v];
			ss = min(ss, dist[x][v] + dist[y][u]);
			ss = min(ss, dist[x][y]);

			tmp += ss;
		}
		ans = min(ans, tmp);
	}
	cout << ans << '\n';

	return 0;
}