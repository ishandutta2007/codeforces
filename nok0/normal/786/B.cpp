#include <bits/stdc++.h>

template <class W>
struct range_edge_graph {
private:
	size_t n;
	struct edge {
		int to;
		W weight;
		edge() = default;
		edge(int to_, W weight_)
		  : to(to_), weight(weight_) {}
	};
	std::vector<std::vector<edge>> g;

	void add_edge(int u, int v, W w) {
		if(3 * n <= u) u -= 2 * n;
		g[u].emplace_back(v, w);
	}

public:
	range_edge_graph() = default;

	range_edge_graph(size_t n_)
	  : n(n_), g(3 * n_) {
		for(int i = 1; i < n; i++) {
			int cl = i << 1 | 0, cr = i << 1 | 1;
			add_edge(i, cl, 0);
			add_edge(i, cr, 0);
			add_edge(cl + 2 * n, i + 2 * n, 0);
			add_edge(cr + 2 * n, i + 2 * n, 0);
		}
	}

	void add_edge(int l1, int r1, int l2, int r2, W w) {
		int idx = g.size();
		for(l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {
			if(l1 & 1) add_edge(l1 + 2 * n, idx, 0), l1++;
			if(r1 & 1) --r1, add_edge(r1 + 2 * n, idx, 0);
		}
		std::vector<edge> node;
		for(l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {
			if(l2 & 1) node.emplace_back(l2++, w);
			if(r2 & 1) node.emplace_back(--r2, w);
		}
		g.push_back(node);
	}

	std::vector<W> dijkstra(int s) {
		s += n;
		std::vector<W> dist(g.size(), std::numeric_limits<W>::max());
		dist[s] = 0;
		using P = std::pair<W, int>;
		std::priority_queue<P, std::vector<P>, std::greater<P>> que;
		que.emplace(0, s);
		while(!que.empty()) {
			P p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(edge &e : g[v]) {
				if(dist[e.to] > dist[v] + e.weight) {
					dist[e.to] = dist[v] + e.weight;
					que.emplace(dist[e.to], e.to);
				}
			}
		}
		std::vector<W> res(dist.begin() + n, dist.begin() + 2 * n);
		return res;
	}
};

int main() {
	int n, q, s, t, l, r, v, u, w;
	std::cin >> n >> q >> s;
	range_edge_graph<long long> G(n);
	const long long INF = std::numeric_limits<long long>::max();
	while(q--) {
		std::cin >> t;
		if(t == 1) {
			std::cin >> v >> u >> w;
			G.add_edge(v - 1, v, u - 1, u, w);
		}
		if(t == 2) {
			std::cin >> v >> l >> r >> w;
			G.add_edge(v - 1, v, l - 1, r, w);
		}
		if(t == 3) {
			std::cin >> v >> l >> r >> w;
			G.add_edge(l - 1, r, v - 1, v, w);
		}
	}
	auto res = G.dijkstra(--s);
	for(auto v : res) std::cout << (v != INF ? v : -1) << " ";
	std::cout << std::endl;
}