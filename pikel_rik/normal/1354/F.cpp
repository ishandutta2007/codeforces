#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <typename T, typename W>
struct flow_graph {
	struct edge {
		int u, v;
		T c, f; W w;
		edge(int u, int v, T c, W w, T f) : u(u), v(v), c(c), w(w), f(f) {}
	};

	int n, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	flow_graph(): n(), m() {}
	flow_graph(int n, int m = 0): n(n), m(), adj(n) {
		edges.reserve(2 * m);
	}

	void add_edge(int u, int v, T c, W w) {
		edges.emplace_back(u, v, c, w, 0);
		adj[u].push_back(m++);
		edges.emplace_back(v, u, 0, -w, 0);
		adj[v].push_back(m++);
	}
};

template <typename T, typename W>
std::pair<T, W> min_cost_max_flow(flow_graph<T, W> &g, int s, int t) {
	static constexpr W inf_cost = std::numeric_limits<W>::max();

	std::vector<W> d(g.n);
	std::vector<int> p(g.n);
	std::vector<bool> in_queue(g.n);

	auto bellman_ford = [&](void) -> void {
		std::fill(d.begin(), d.end(), inf_cost);
		std::fill(in_queue.begin(), in_queue.end(), false);

		queue<int> q;
		q.push(s);
		d[s] = 0, in_queue[s] = true;

		while (!q.empty()) {
			int x = q.front();
			q.pop(), in_queue[x] = false;

			for (int i : g.adj[x]) {
				const auto &e = g.edges[i];
				if (e.c - e.f > 0 && d[e.u] + e.w < d[e.v]) {
					d[e.v] = d[e.u] + e.w;
					p[e.v] = i;
					if (!in_queue[e.v]) {
						in_queue[e.v] = true;
						q.push(e.v);
					}
				}
			}
		}

//		for (int i = 1; i < g.n; i++) {
//			for (int j = 0; j < g.m; j++) {
//				const auto &e = g.edges[j];
//				if (e.c - e.f > 0 && d[e.u] != inf_cost && d[e.u] + e.w < d[e.v]) {
//					d[e.v] = d[e.u] + e.w;
//					p[e.v] = j;
//				}
//			}
//		}
	};

	W min_cost = 0;
	T max_flow = 0;

	while (bellman_ford(), d[t] != inf_cost) {
		T path_flow = std::numeric_limits<T>::max();
		for (int x = t; x != s; x = g.edges[p[x]].u) {
			path_flow = std::min(path_flow, g.edges[p[x]].c - g.edges[p[x]].f);
		}

		min_cost += path_flow * d[t];
		for (int x = t; x != s; x = g.edges[p[x]].u) {
			int i = p[x];
			g.edges[i].f += path_flow;
			g.edges[i ^ 1].f -= path_flow;
		}
		max_flow += path_flow;
	}

	return std::make_pair(min_cost, max_flow);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

		int s = k + n + 1, t = s + 1;
		flow_graph<int, int> g(t + 1);

		for (int i = 0; i < n; i++) {
			g.add_edge(s, i, 1, 0);
			for (int j = 0; j < k; j++) {
				g.add_edge(i, j + n, 1, -(a[i] + j * b[i]));
			}
			g.add_edge(i, k + n, 1, -((k - 1) * b[i]));
		}

		for (int j = 0; j < k; j++) {
			g.add_edge(j + n, t, 1, 0);
		}
		g.add_edge(k + n, t, n - k, 0);

		min_cost_max_flow(g, s, t);

		vector<int> final(k);
		for (const auto &e : g.edges) {
			if (e.f == 1 && 0 <= e.u && e.u < n && n <= e.v && e.v < k + n) {
				final[e.v - n] = e.u;
			}
		}

		cout << k + 2 * (n - k) << '\n';
		for (int i = 0; i < k - 1; i++) {
			cout << final[i] + 1 << ' ';
		}

		for (int i = 0; i < n; i++) {
			if (count(final.begin(), final.end(), i) == 0) {
				cout << i + 1 << ' ' << -i - 1 << ' ';
			}
		}

		cout << final[k - 1] + 1 << '\n';
	}
	return 0;
}