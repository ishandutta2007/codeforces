#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v;	// directed
	int capacity;
	int flow;
};

struct Flow {
	int n;
	int source, sink;

	vector<vector<int>> a;
	vector<Edge> E;

	vector<int> cur;
	vector<int> dist;

	Flow();
	Flow(int n, int s, int t) {
		this->n = n;
		source = s; sink = t;
		a.resize(n+1);
		cur.resize(n+1);
		dist.resize(n+1);
	}

	void add_edge(int u, int v, int c) {
		a[u].push_back(E.size());	E.push_back({u, v, c, 0});
		a[v].push_back(E.size());	E.push_back({v, u, 0, 0});
	}

	int bfs() {
		fill(dist.begin(), dist.end(), -1);

		queue<int> Q;
		Q.push(source); dist[source] = 0;

		while (!Q.empty()) {
			int u = Q.front(); Q.pop();

			for (int i = 0; i < a[u].size(); i++) {
				int id = a[u][i];
				int v = E[id].v;

				if (dist[v] < 0 && E[id].flow < E[id].capacity) {
					dist[v] = dist[u] + 1;
					Q.push(v);
				}
			}
		}

		return dist[sink] >= 0;
	}

	int dfs(int now, int flow) {
		if (flow == 0) return 0;
		if (now == sink) return flow;

		for (; cur[now] < a[now].size(); cur[now]++) {
			int id = a[now][cur[now]];
			int v = E[id].v;

			if (dist[v] == dist[now] + 1) {
				int delta = dfs(v, min(flow, E[id].capacity - E[id].flow));
				if (delta) {
					E[id].flow += delta;
					E[id^1].flow -= delta;

					return delta;
				}
			}
		}

		return 0;
	}

	vector<pair<int, int>> maxflow(int m) {
		int ans = 0;
		while (bfs()) {
			fill(cur.begin(), cur.end(), 0);
			while (1) {
				int delta = dfs(source, 1e9);
				if (!delta) break;

				ans += delta;
			}
		}

		vector<pair<int, int>> res;
		for (Edge e: E) {
			if (e.flow > 0) {
				//cout << e.u << ' ' << e.v << '\n';
				if (e.u >= 2 && e.u <= m+1) {
					res.emplace_back(e.u - 2, e.v - (m+1));
				}
			}
		}

		return res;
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); 
	
	int n, m; cin >> n >> m;
	vector<int> s(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> deg(n+1);

	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		edges.emplace_back(x, y);
		deg[x]++; deg[y]++;
	}

	for (int i = 1; i <= n; i++) {
		if (s[i] == 0) a[i] = -1;
		else {
			if (abs(a[i] % 2) != (deg[i] % 2)) {
				cout << "NO\n";
				return 0;
			}
			a[i] = (a[i] + deg[i])/2;
		}
	}

	int reserve = m;
	for (int i = 1; i <= n; i++) {
		if (a[i] != -1) reserve -= a[i];
	}
	if (reserve < 0) {cout << "NO\n"; exit(0);}

	// source is 1
	// edges are 2 to m+1
	// nodes are m+2 to m+n+1
	// special node is m+n+2
	// source is m+n+3

	Flow f(m+n+3, 1, m+n+3);
	for (int i = 2; i <= m+1; i++) {
		f.add_edge(1, i, 1);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) f.add_edge(m+1+i, m+n+3, a[i]);
	}
	if (reserve) f.add_edge(m+n+2, m+n+3, reserve);

	for (int i = 0; i < m; i++) {
		auto [x, y] = edges[i];

		if (a[x] != -1) f.add_edge(i+2, m+1+x, 1);
		else f.add_edge(i+2, m+n+2, 1);

		if (a[y] != -1) f.add_edge(i+2, m+1+y, 1);
		else f.add_edge(i+2, m+n+2, 1);
	}

	vector<pair<int, int>> ans = f.maxflow(m);
	if (ans.size() != m) {cout << "NO\n"; exit(0);}
	
	cout << "YES\n";
	for (auto [u, v]: ans) {
		int x, y; tie(x, y) = edges[u];

		if (v == n+1) {
			if (a[y] != -1) swap(x, y);
		} else {
			if (y != v) swap(x, y);
		}
		cout << x << ' ' << y << '\n';
	}

	return 0;
}