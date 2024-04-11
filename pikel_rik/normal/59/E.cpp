#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

struct Graph {
	struct edge {
		int u, v;
		edge(int u, int v): u(u), v(v) {}
	};

	int n, m;
	vector<edge> edges;
	vector<vector<int>> adj;

	Graph(): n(), m() {}
	Graph(int n): n(n), m(), adj(n) {}

	const vector<int>& operator[](int x) const { return adj[x]; }
	vector<int>& operator[](int x) { return adj[x]; }

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.emplace_back(u, v);
		m++;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	Graph g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g.addEdge(--u, --v);
	}

	vector<vector<pair<int, int>>> en(n);
	for (int i = 0, a, b, c; i < k; i++) {
		cin >> a >> b >> c;
		--a; --b; --c;
		en[c].emplace_back(a, b);
	}

	for (int i = 0; i < n; i++) {
		sort(en[i].begin(), en[i].end());
	}

	vector<vector<int>> lvl(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n));
	vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(n));

	queue<pair<int, int>> q;
	q.emplace(0, 0);
	visited[0][0] = true;

	while (!q.empty()) {
		auto pp = q.front();
		q.pop();

		for (int i : g[pp.second]) {
			if (!visited[pp.second][i] && !binary_search(en[i].begin(), en[i].end(), pp)) {
				lvl[pp.second][i] = 1 + lvl[pp.first][pp.second];
				visited[pp.second][i] = true;
				p[pp.second][i] = pp;
				q.emplace(pp.second, i);
			}
		}
	}

	pair<int, int> x = {-1, -1};
	for (int i = 0; i < n - 1; i++) {
		if (x.first == -1 && visited[i][n - 1]) {
			x = make_pair(i, n - 1);
		} else if (x.first != -1 && visited[i][n - 1]) {
			if (lvl[i][n - 1] < lvl[x.first][x.second]) {
				x = make_pair(i, n - 1);
			}
		}
	}

	if (x.first == -1) {
		cout << "-1\n";
		return 0;
	}

	vector<int> path = {n - 1};
	while (true) {
		path.push_back(x.first);
		if (path.back() == 0) {
			break;
		}
		x = p[x.first][x.second];
	}

	reverse(path.begin(), path.end());
	cout << (int)path.size() - 1 << '\n';
	for (int i : path) cout << i + 1 << ' '; cout << '\n';
	return 0;
}