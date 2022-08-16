#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

class Graph {
public:
    struct edge {
        int u, v, w;
        edge(int u, int v, int w): u(u), v(v), w(w) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<pair<int, int>>> adj;

    Graph(): n(), m() {}
    Graph(int n): n(n), m(), adj(n) {}

    const vector<pair<int, int>>& operator[](const int &x) const { return adj[x]; }
    vector<pair<int, int>>& operator[](const int &x) { return adj[x]; }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
        m++;
    }
};

vector<int> dijkstra(const Graph &g, int s) {
	vector<bool> visited(g.n);
	vector<int> dist(g.n, inf);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	q.emplace(0, s);

	dist[s] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();

		if (visited[u])
			continue;
		visited[u] = true;

		for (auto &[v, w] : g[u]) {
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.emplace(dist[v], v);
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	Graph g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g.addEdge(--u, --v, w);
	}

	vector<pair<int, int>> paths(k);
	for (int i = 0; i < k; i++) {
		cin >> paths[i].first >> paths[i].second;
		--paths[i].first; --paths[i].second;
	}

	vector<vector<int>> dist(n);
	for (int i = 0; i < n; i++) {
		dist[i] = dijkstra(g, i);
	}

	int ans = INT_MAX;
	for (const auto& [u, v, w] : g.edges) {
		int now = 0;
		for (auto& [a, b] : paths) {
			now += min({dist[a][b], dist[a][u] + dist[v][b], dist[a][v] + dist[u][b]});
		}
		ans = min(ans, now);
	}
	cout << ans << '\n';
	return 0;
}