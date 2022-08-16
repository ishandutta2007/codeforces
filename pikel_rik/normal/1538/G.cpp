#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct flow_graph {
	struct edge {
		int u, v;
		T c, f;
		edge(int u, int v, T c, T f) : u(u), v(v), c(c), f(f) {}
	};

	int n, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	flow_graph(): n(), m() {}
	flow_graph(int n, int m = 0): n(n), m(), adj(n) {
		edges.reserve(2 * m);
	}

	void add_edge(int u, int v, T c) {
		edges.emplace_back(u, v, c, 0);
		adj[u].push_back(m++);
		edges.emplace_back(v, u, 0, 0);
		adj[v].push_back(m++);
	}
};

template <typename T>
T max_flow(flow_graph<T> &g, int s, int t) {
	std::vector<int> lvl(g.n);

	auto bfs = [&](void) -> void {
		std::fill(lvl.begin(), lvl.end(), -1);
		std::queue<int> q;
		q.push(s);
		lvl[s] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i : g.adj[x]) {
				const auto &e = g.edges[i];
				if (lvl[e.v] == -1 && e.c - e.f > 0) {
					lvl[e.v] = 1 + lvl[x];
					q.push(e.v);
				}
			}
		}
	};

	std::vector<int> p(g.n), ptr(g.n);

	auto dfs = [&](int x, const auto &dfs) -> bool {
		if (x == t) return true;
		for (; ptr[x] < g.adj[x].size(); ptr[x]++) {
			const auto &e = g.edges[g.adj[x][ptr[x]]];
			if (lvl[x] + 1 == lvl[e.v] && e.c - e.f > 0) {
				p[e.v] = g.adj[x][ptr[x]];
				if (dfs(e.v, dfs)) {
					return true;
				}
			}
		}
		return false;
	};

	T max_flow = 0;
	while (bfs(), lvl[t] != -1) {
		while (dfs(s, dfs)) {
			T path_flow = std::numeric_limits<T>::max();
			for (int x = t; x != s; x = g.edges[p[x]].u) {
				path_flow = std::min(path_flow, g.edges[p[x]].c - g.edges[p[x]].f);
			}
			max_flow += path_flow;
			for (int x = t; x != s; x = g.edges[p[x]].u) {
				int i = p[x];
				g.edges[i].f += path_flow;
				g.edges[i ^ 1].f -= path_flow;
			}
		}
		std::fill(ptr.begin(), ptr.end(), 0);
	}
	return max_flow;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;

		if (a == b) {
			cout << min(x, y) / a << '\n';
			continue;
		}

		//(s, T)
		// s * a + T * b <= x
		// s * b + T * a <= y
		// max(s + T)

		//s * (a^2 - b^2) = ax - yb
		//s = (ax - yb) / (a^2 - b^2)

		double s = (a * x - y * b) / double(a * a - b * b);
		double t = (x - s * a) / b;

		int ans = max(min(x / a, y / b), min(x / b, y / a));

		for (int del_s = -10; del_s <= 10; del_s++) {
			for (int del_t = -10; del_t <= 10; del_t++) {
				long long ss = s + del_s, tt = t + del_t;
				if (0 <= ss && 0 <= tt && ss * a + tt * b <= x && ss * b + tt * a <= y) {
					ans = max((long long)ans, ss + tt);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}