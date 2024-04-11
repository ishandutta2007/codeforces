#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

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

	constexpr long long inf = (long long)3e14;

	vector<array<array<long long, 2>, 2>> dist(n);
	vector<array<array<bool, 2>, 2>> visited(n);
	for (int i = 0; i < n; i++) {
		dist[i][0].fill(inf), dist[i][1].fill(inf);
		visited[i][0].fill(false), visited[i][1].fill(false);
	}

	using node = pair<long long, tuple<int, bool, bool>>;
	priority_queue<node, vector<node>, greater<>> pq;
	pq.emplace(0, make_tuple(0, 0, 0));
	dist[0][0][0] = 0;

	while (!pq.empty()) {
		auto [u, f1, f2] = pq.top().second;
		pq.pop();

		if (visited[u][f1][f2])
			continue;
		visited[u][f1][f2] = true;

		for (int i : g[u]) {
			int v = e[i].u ^ e[i].v ^ u;
			if (dist[u][f1][f2] + e[i].w < dist[v][f1][f2]) {
				dist[v][f1][f2] = dist[u][f1][f2] + e[i].w;
				pq.emplace(dist[v][f1][f2], make_tuple(v, f1, f2));
			}
			if (!f1 && dist[u][f1][f2] < dist[v][1][f2]) {
				dist[v][1][f2] = dist[u][f1][f2];
				pq.emplace(dist[v][1][f2], make_tuple(v, 1, f2));
			}
			if (!f2 && dist[u][f1][f2] + 2 * e[i].w < dist[v][f1][1]) {
				dist[v][f1][1] = dist[u][f1][f2] + 2 * e[i].w;
				pq.emplace(dist[v][f1][1], make_tuple(v, f1, 1));
			}
			if (!f1 && !f2 && dist[u][f1][f2] + e[i].w < dist[v][1][1]) {
				dist[v][1][1] = dist[u][f1][f2] + e[i].w;
				pq.emplace(dist[v][1][1], make_tuple(v, 1, 1));
			}
		}
	}

	for (int i = 1; i < n; i++) cout << dist[i][1][1] << ' ';
	cout << '\n';
	return 0;
}