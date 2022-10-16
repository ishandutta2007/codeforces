#line 2 "/home/nok0/documents/programming/library/template/header.hpp"
#include <bits/stdc++.h>
#line 3 "/home/nok0/documents/programming/library/graph/graph.hpp"
#pragma region graph

template <class cost_type = long long>
class graph {
   public:
	struct edge {
	   public:
		int from, to;
		cost_type cost;
		int id;
		edge() = default;
		edge(int from_, int to_, cost_type cost_ = 1, int id_ = -1) : from(from_), to(to_), cost(cost_), id(id_) {}
		bool operator<(const edge &a) const { return cost < a.cost; }
		bool operator>(const edge &a) const { return cost > a.cost; }
		friend std::ostream &operator<<(std::ostream &s, const edge &a) {
			s << '(' << a.from << " -> " << a.to << "), cost: " << a.cost << ", id: " << a.id;
			return s;
		}
	};

   private:
	std::vector<std::vector<edge>> edges;
	int next_edge_id = 0;

   public:
	inline const std::vector<edge> &operator[](int k) const { return edges[k]; }
	inline std::vector<edge> &operator[](int k) { return edges[k]; }

	int size() const { return int(edges.size()); }
	void resize(const int n) { edges.resize(n); }
	int edge_count() const { return next_edge_id; }

	friend std::ostream &operator<<(std::ostream &s, const graph<cost_type> &g) {
		for(const auto &adj : g.edges)
			for(const auto &ed : adj) s << ed << '\n';
		return s;
	}

	graph() = default;
	graph(int n) : edges(n) {}
	graph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) : edges(n) { input(e, weight, directed, idx); }
	const cost_type INF = std::numeric_limits<cost_type>::max() / 3;

	void input(int e = -1, bool weight = false, bool directed = false, int idx = 1) {
		if(e == -1) e = size() - 1;
		while(e--) {
			int u, v;
			std::cin >> u >> v;
			cost_type cost = 1;
			if(weight) std::cin >> cost;
			add_edge(u, v, cost, directed, idx);
		}
	}

	inline int add_edge(int u, int v, cost_type cost = 1, bool directed = false, int idx = 0) {
		u -= idx, v -= idx;
		edges[u].emplace_back(u, v, cost, next_edge_id);
		if(!directed && u != v) edges[v].emplace_back(v, u, cost, next_edge_id);
		return next_edge_id++;
	}

	// (V+E)
	std::vector<cost_type> bfs(int s) const {
		std::vector<cost_type> dist(size(), INF);
		std::queue<int> que;
		dist[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int v = que.front();
			que.pop();
			for(auto &e : edges[v]) {
				if(dist[e.to] != INF) continue;
				dist[e.to] = dist[v] + e.cost;
				que.push(e.to);
			}
		}
		return dist;
	}

	// (V+E)
	// constraint: cost of each edge is zero or x (>= 0)
	std::vector<cost_type> zero_one_bfs(int s) const {
		std::vector<cost_type> dist(size(), INF);
		std::deque<int> deq;
		dist[s] = 0;
		deq.push_back(s);
		while(!deq.empty()) {
			int v = deq.front();
			deq.pop_front();
			for(auto &e : edges[v]) {
				if(dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					e.cost ? deq.push_back(e.to) : deq.push_front(e.to);
				}
			}
		}
		return dist;
	}

	// ((E+V) lg E)
	// unreachable: INF
	std::vector<cost_type> dijkstra(int s) const {
		std::vector<cost_type> dist(size(), INF);
		const auto compare = [](const std::pair<cost_type, int> &a, const std::pair<cost_type, int> &b) {
			return a.first > b.first;
		};
		std::priority_queue<std::pair<cost_type, int>, std::vector<std::pair<cost_type, int>>, decltype(compare)> que{compare};
		dist[s] = 0;
		que.emplace(0, s);
		while(!que.empty()) {
			std::pair<cost_type, int> p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(auto &e : edges[v]) {
				if(dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					que.emplace(dist[e.to], e.to);
				}
			}
		}
		return dist;
	}

	// (VE)
	// unreachable: INF
	// reachable via negative cycle: -INF
	std::vector<cost_type> bellman_ford(int s) const {
		int n = size();
		std::vector<cost_type> res(n, INF);
		res[s] = 0;
		for(int loop = 0; loop < n - 1; loop++) {
			for(int v = 0; v < n; v++) {
				if(res[v] == INF) continue;
				for(auto &e : edges[v]) {
					res[e.to] = std::min(res[e.to], res[v] + e.cost);
				}
			}
		}
		std::queue<int> que;
		std::vector<int> chk(n);
		for(int v = 0; v < n; v++) {
			if(res[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(res[e.to] > res[v] + e.cost and !chk[e.to]) {
					que.push(e.to);
					chk[e.to] = 1;
				}
			}
		}
		while(!que.empty()) {
			int now = que.front();
			que.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					que.push(e.to);
				}
			}
		}
		for(int i = 0; i < n; i++)
			if(chk[i]) res[i] = -INF;
		return res;
	}

	// (V^3)
	std::vector<std::vector<cost_type>> warshall_floyd() const {
		const int n = size();
		std::vector<std::vector<cost_type>> dist(n, std::vector<cost_type>(n, INF));
		for(int i = 0; i < n; i++) dist[i][i] = 0;
		for(int i = 0; i < n; i++)
			for(auto &e : edges[i]) dist[i][e.to] = std::min(dist[i][e.to], e.cost);
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++) {
				if(dist[i][k] == INF) continue;
				for(int j = 0; j < n; j++) {
					if(dist[k][j] == INF) continue;
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		return dist;
	}

	// (V) (using DFS)
	// if a cycle exists, return {}
	std::vector<int> topological_sort() const {
		std::vector<int> res;
		std::vector<int> used(size(), 0);
		bool not_DAG = false;
		auto dfs = [&](auto self, int k) -> void {
			if(not_DAG) return;
			if(used[k]) {
				if(used[k] == 1) not_DAG = true;
				return;
			}
			used[k] = 1;
			for(auto &e : edges[k]) self(self, e.to);
			used[k] = 2;
			res.push_back(k);
		};
		for(int i = 0; i < size(); i++) dfs(dfs, i);
		if(not_DAG) return std::vector<int>{};
		std::reverse(res.begin(), res.end());
		return res;
	}

	bool is_dag() const { return !topological_sort().empty(); }

	// (V)
	// array of the distance to the most distant vertex
	// constraint: the graph is a tree
	std::vector<cost_type> height() const {
		auto vec1 = bfs(0);
		int v1 = -1, v2 = -1;
		cost_type dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v1 = i;
		vec1 = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v2 = i;
		auto vec2 = bfs(v2);
		for(int i = 0; i < int(size()); i++) {
			if(vec1[i] < vec2[i]) vec1[i] = vec2[i];
		}
		return vec1;
	}

	// O(V+E)
	// vector<(int)(0 or 1)>
	// if it is not bipartite, return {}
	std::vector<int> bipartite_grouping() const {
		std::vector<int> colors(size(), -1);
		auto dfs = [&](auto self, int now, int col) -> bool {
			colors[now] = col;
			for(auto &e : edges[now]) {
				if(col == colors[e.to]) return false;
				if(colors[e.to] == -1 and !self(self, e.to, !col)) return false;
			}
			return true;
		};
		for(int i = 0; i < int(size()); i++)
			if(colors[i] == -1 and !dfs(dfs, i, 0)) return std::vector<int>{};
		return colors;
	}

	bool is_bipartite() const { return !bipartite_grouping().empty(); }

	// (V+E)
	// (v1, v2, diameter)
	std::tuple<int, int, cost_type> diameter() {
		std::vector<cost_type> dist = bfs(0);
		auto it = std::max_element(dist.begin(), dist.end());
		const int v = it - dist.begin();
		dist = bfs(v);
		it = std::max_element(dist.begin(), dist.end());
		return std::make_tuple(v, int(it - dist.begin()), *it);
	}

	// (V+E)
	std::vector<int> subtree_size(const int root) {
		const int n = size();
		std::vector<int> ret(n, 1);
		auto dfs = [&](auto self, int now, int p = -1) -> void {
			for(const auto &e : (*this)[now]) {
				if(e.to == p) continue;
				self(self, e.to, now);
				ret[now] += ret[e.to];
			}
		};
		dfs(dfs, root);
		return ret;
	}

	// (ElgE)
	cost_type prim() const {
		cost_type res = 0;
		std::priority_queue<edge, std::vector<edge>, std::greater<edge>> que;
		for(auto &e : edges[0]) que.push(e);
		std::vector<int> chk(size());
		chk[0] = 1;
		int cnt = 1;
		while(cnt < size()) {
			auto e = que.top();
			que.pop();
			if(chk[e.to]) continue;
			cnt++;
			res += e.cost;
			chk[e.to] = 1;
			for(auto &e2 : edges[e.to]) que.push(e2);
		}
		return res;
	}

	// (ElgE)
	cost_type kruskal() const {
		std::vector<std::tuple<int, int, cost_type>> eds;
		for(const auto &adj : edges)
			for(const auto &ed : adj) eds.emplace_back(ed.from, ed.to, ed.cost);
		std::sort(eds.begin(), eds.end(), [](const std::tuple<int, int, cost_type> &a, const std::tuple<int, int, cost_type> &b) {
			return std::get<2>(a) < std::get<2>(b);
		});
		std::vector<int> uf_data(size(), -1);
		auto root = [&uf_data](auto self, int x) -> int {
			if(uf_data[x] < 0) return x;
			return uf_data[x] = self(self, uf_data[x]);
		};
		auto unite = [&uf_data, &root](int u, int v) -> bool {
			u = root(root, u), v = root(root, v);
			if(u == v) return false;
			if(uf_data[u] > uf_data[v]) std::swap(u, v);
			uf_data[u] += uf_data[v];
			uf_data[v] = u;
			return true;
		};
		cost_type ret = 0;
		for(auto &e : eds)
			if(unite(std::get<0>(e), std::get<1>(e))) ret += std::get<2>(e);
		return ret;
	}

	// O(V)
	std::vector<int> centroid() const {
		std::vector<int> centroid, sz(size());
		auto dfs = [&](auto self, int now, int per) -> void {
			sz[now] = 1;
			bool is_centroid = true;
			for(auto &e : edges[now]) {
				if(e.to != per) {
					self(self, e.to, now);
					sz[now] += sz[e.to];
					if(sz[e.to] > size() / 2) is_centroid = false;
				}
			}
			if(size() - sz[now] > size() / 2) is_centroid = false;
			if(is_centroid) centroid.push_back(now);
		};
		dfs(dfs, 0, -1);
		return centroid;
	}

	// O(V+E)
	// bridge: (s, t)  (s < t);
	std::pair<std::vector<std::pair<int, int>>, std::vector<int>> bridges_and_articulations() const {
		std::vector<int> order(size(), -1), low(size()), articulation;
		int order_next = 0;
		std::vector<std::pair<int, int>> bridge;
		auto dfs = [&](auto self, int now, int par = -1) -> void {
			low[now] = order[now] = order_next++;
			bool is_articulation = false;
			int cnt = 0;
			for(auto &ed : edges[now]) {
				int &nxt = ed.to;
				if(nxt == par) continue;
				if(order[nxt] == -1) {
					cnt++;
					self(self, nxt, now);
					if(order[now] < low[nxt]) bridge.push_back(std::minmax(now, nxt));
					if(order[now] <= low[nxt]) is_articulation = true;
					low[now] = std::min(low[now], low[nxt]);
				} else if(order[now] > order[nxt]) {
					low[now] = std::min(low[now], order[nxt]);
				}
			}
			if(par == -1 and cnt < 2) is_articulation = false;
			if(is_articulation) articulation.push_back(now);
			return;
		};
		for(int i = 0; i < (int)size(); i++)
			if(order[i] == -1) dfs(dfs, i);
		return std::make_pair(bridge, articulation);
	}

	// (V+E)
	// directed graph from root to leaf
	graph root_to_leaf(int root = 0) const {
		graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(now, e.to, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	// (V+E)
	// directed graph from leaf to root
	graph leaf_to_root(int root = 0) const {
		graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(e.to, now, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	// cost_type Chu_Liu_Edmonds(int root = 0) {}
};
#pragma endregion
#line 3 "/home/nok0/documents/programming/library/graph/hld.hpp"

template <class cost_type>
struct heavy_light_decomposition {
   public:
	std::vector<int> sz, in, out, head, rev, par;

   private:
	graph<cost_type> &g;

	void dfs_sz(int v, int p = -1) {
		par[v] = p;
		if(!g[v].empty() and g[v].front().to == p) std::swap(g[v].front(), g[v].back());
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			dfs_sz(e.to, v);
			sz[v] += sz[e.to];
			if(sz[g[v].front().to] < sz[e.to]) std::swap(g[v].front(), e);
		}
	}

	void dfs_hld(int v, int &t, int p = -1) {
		in[v] = t++;
		rev[in[v]] = v;
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			head[e.to] = (g[v].front().to == e.to ? head[v] : e.to);
			dfs_hld(e.to, t, v);
		}
		out[v] = t;
	}

	void build(int root = 0) {
		dfs_sz(root);
		int t = 0;
		head[root] = root;
		dfs_hld(root, t);
	}

   public:
	heavy_light_decomposition(graph<cost_type> &g_, int root = 0) : g(g_) {
		int n = g.size();
		sz.resize(n, 1);
		in.resize(n);
		out.resize(n);
		head.resize(n);
		rev.resize(n);
		par.resize(n);
		build(root);
	}

	int level_ancestor(int v, int level) {
		while(true) {
			int u = head[v];
			if(in[v] - level >= in[u]) return rev[in[v] - level];
			level -= in[v] - in[u] + 1;
			v = par[u];
		}
	}

	int lowest_common_ancestor(int u, int v) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) return u;
		}
	}

	// u, v: vertex, unit: unit, q: query on a path, f: binary operation ((T, T) -> T)
	template <typename T, typename Q, typename F>
	T query(int u, int v, const T &unit, const Q &q, const F &f, bool edge = false) {
		T l = unit, r = unit;
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v), std::swap(l, r);
			if(head[u] == head[v]) break;
			l = f(q(in[head[v]], in[v] + 1), l);
		}
		return f(f(q(in[u] + edge, in[v] + 1), l), r);
	}

	// u, v: vertex, q: update query
	template <typename Q>
	void add(int u, int v, const Q &q, bool edge = false) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) break;
			q(in[head[v]], in[v] + 1);
		}
		q(in[u] + edge, in[v] + 1);
	}

	std::pair<int, int> subtree(int v, bool edge = false) { return std::pair<int, int>(in[v] + edge, out[v]); }
};
#line 3 "/home/nok0/documents/programming/library/template/def_const.hpp"

const int inf = 1000000000;
const long long INF = 1000000000000000000ll;
#line 4 "/home/nok0/documents/programming/library/template/debug.hpp"

namespace viewer {
void view(const long long &e) {
	if(e == INF)
		std::cerr << "INF";
	else if(e == -INF)
		std::cerr << "-INF";
	else
		std::cerr << e;
}

void view(const int &e) {
	if(e == inf)
		std::cerr << "inf";
	else if(e == -inf)
		std::cerr << "-inf";
	else
		std::cerr << e;
}

template <typename T>
void view(const T &e) {
	std::cerr << e;
}

template <typename T, typename U>
void view(const std::pair<T, U> &p) {
	std::cerr << "(";
	view(p.first);
	std::cerr << ", ";
	view(p.second);
	std::cerr << ")";
}

template <class T0, class T1, class T2>
void view(const std::tuple<T0, T1, T2> &p) {
	std::cerr << "(";
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ")";
}

template <class T0, class T1, class T2, class T3>
void view(const std::tuple<T0, T1, T2, T3> &p) {
	std::cerr << "(";
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ", ";
	view(std::get<3>(p));
	std::cerr << ")";
}

template <typename T>
void view(const std::set<T> &s) {
	if(s.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::unordered_set<T> &s) {
	if(s.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::multiset<T> &s) {
	if(s.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::unordered_multiset<T> &s) {
	if(s.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::vector<T> &v) {
	if(v.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(const auto &e : v) {
		view(e);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T, std::size_t ary_size>
void view(const std::array<T, ary_size> &v) {
	if(v.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << "{ ";
	for(const auto &e : v) {
		view(e);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	std::cerr << "{\n";
	for(const auto &v : vv) {
		std::cerr << "\t";
		view(v);
		std::cerr << '\n';
	}
	std::cerr << "}";
}

template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	std::cerr << "{\n";
	for(const auto &c : v) {
		std::cerr << "\t(";
		view(c.first);
		std::cerr << ", ";
		view(c.second);
		std::cerr << ")\n";
	}
	std::cerr << "}";
}

template <class T0, class T1, class T2>
void view(const std::vector<std::tuple<T0, T1, T2>> &v) {
	if(v.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << '{';
	for(const auto &t : v) {
		std::cerr << "\n\t";
		view(t);
		std::cerr << ",";
	}
	std::cerr << "\n}";
}

template <class T0, class T1, class T2, class T3>
void view(const std::vector<std::tuple<T0, T1, T2, T3>> &v) {
	if(v.empty()) {
		std::cerr << "{ }";
		return;
	}
	std::cerr << '{';
	for(const auto &t : v) {
		std::cerr << "\n\t";
		view(t);
		std::cerr << ",";
	}
	std::cerr << "\n}";
}

template <typename T, typename U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &t : m) {
		std::cerr << "\t[";
		view(t.first);
		std::cerr << "] : ";
		view(t.second);
		std::cerr << '\n';
	}
	std::cerr << "}";
}

template <typename T, typename U>
void view(const std::unordered_map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &t : m) {
		std::cerr << "\t[";
		view(t.first);
		std::cerr << "] : ";
		view(t.second);
		std::cerr << '\n';
	}
	std::cerr << "}";
}
}  // namespace viewer

// when compiling : g++ foo.cpp -DLOCAL
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	viewer::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(0)
#define dump(x)                                      \
	do {                                             \
		std::cerr << __LINE__ << " " << #x << " : "; \
		viewer::view(x);                             \
		std::cerr << '\n';                           \
	} while(0)

#else
#define debug(...) (void(0))
#define dump(x)    (void(0))
#endif
#line 3 "/home/nok0/documents/programming/library/template/def_name.hpp"

#define pb        push_back
#define eb        emplace_back
#define SZ(x)     ((int)(x).size())
#define all(x)    (x).begin(), (x).end()
#define rall(x)   (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template<class T = int>
using V = std::vector<T>;
template<class T = int>
using VV = std::vector<std::vector<T>>;
template<class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
#line 3 "/home/nok0/documents/programming/library/template/fast_io.hpp"

struct fast_io {
	fast_io() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout << std::fixed << std::setprecision(15);
	}
} fast_io_;
#line 3 "/home/nok0/documents/programming/library/template/input.hpp"

template<class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template<class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &i : v) is >> i;
    return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
    std::string s;
    is >> s;
    __int128_t ret = 0;
    for (int i = 0; i < (int)s.length(); i++)
        if ('0' <= s[i] and s[i] <= '9')
            ret = 10 * ret + s[i] - '0';
    a = ret * (s[0] == '-' ? -1 : 1);
    return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template<class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template<class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template<class Head, class... Tail>
void INPUT(Head &head, Tail &...tail) {
    scan(head);
    INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
    std::vector<type> name(size); \
    scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
    std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
    scanner::INPUT(name)
#define INT(...)     \
    int __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
    long long __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
    std::string __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
    char __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
    double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
    long double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#line 3 "/home/nok0/documents/programming/library/template/math.hpp"

template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	a = (a % mod + mod) % mod;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}
template <class T, class F>
T bin_search(T ok, T ng, const F &f) {
	while(abs(ok - ng) > 1) {
		T mid = (ok + ng) >> 1;
		(f(mid) ? ok : ng) = mid;
	}
	return ok;
}
template <class T, class F>
T bin_search(T ok, T ng, const F &f, int loop) {
	for(int i = 0; i < loop; i++) {
		T mid = (ok + ng) / 2;
		(f(mid) ? ok : ng) = mid;
	}
	return ok;
}
#line 3 "/home/nok0/documents/programming/library/template/output.hpp"


template<class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
    for (int i = 0; i < int(a.size()); ++i) {
        if (i) os << " ";
        os << a[i];
    }
    return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
template<class T>
void print(const T a) { std::cout << a << '\n'; }
template<class Head, class... Tail>
void print(Head H, Tail... T) {
    std::cout << H << ' ';
    print(T...);
}
template<class T>
void printel(const T a) { std::cout << a << '\n'; }
template<class T>
void printel(const std::vector<T> &a) {
    for (const auto &v : a)
        std::cout << v << '\n';
}
template<class Head, class... Tail>
void printel(Head H, Tail... T) {
    std::cout << H << '\n';
    printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
#line 2 "/home/nok0/documents/programming/library/template/rep.hpp"

#define foa(v, a)                   for (auto &v : a)
#define repname(a, b, c, d, e, ...) e
#define rep(...)                    repname(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rep0(x)                     for (int rep_counter = 0; rep_counter < (x); ++rep_counter)
#define rep1(i, x)                  for (int i = 0; i < (x); ++i)
#define rep2(i, l, r)               for (int i = (l); i < (r); ++i)
#define rep3(i, l, r, c)            for (int i = (l); i < (r); i += (c))

#define repsname(a, b, c, ...) c
#define reps(...)              repsname(__VA_ARGS__, reps1, reps0)(__VA_ARGS__)
#define reps0(x)               for (int reps_counter = 1; reps_counter <= (x); ++reps_counter)
#define reps1(i, x)            for (int i = 1; i <= (x); ++i)

#define rrepname(a, b, c, ...) c
#define rrep(...)              rrepname(__VA_ARGS__, rrep1, rrep0)(__VA_ARGS__)
#define rrep0(x)               for (int rrep_counter = (x)-1; rrep_counter >= 0; --rrep_counter)
#define rrep1(i, x)            for (int i = (x)-1; i >= 0; --i)
#line 3 "/home/nok0/documents/programming/library/template/vector.hpp"

template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...)              SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a)               std::sort((a).begin(), (a).end())
#define SORT1(a, c)            std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
struct cum_vector {
   public:
	cum_vector() = default;
	template <class U>
	cum_vector(const std::vector<U> &vec) : cum((int)vec.size() + 1) {
		for(int i = 0; i < (int)vec.size(); i++)
			cum[i + 1] = cum[i] + vec[i];
	}
	T prod(int l, int r) {
		return cum[r] - cum[l];
	}

   private:
	std::vector<T> cum;
};
std::vector<std::pair<char, int>> rle(const std::string &s) {
	const int n = s.size();
	std::vector<std::pair<char, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and s[l] == s[r]; r++) {}
		ret.emplace_back(s[l], r - l);
		l = r;
	}
	return ret;
}
template <class T>
std::vector<std::pair<T, int>> rle(const std::vector<T> &v) {
	int n = v.size();
	std::vector<std::pair<T, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and v[l] == v[r]; r++) {}
		ret.emplace_back(v[l], r - l);
		l = r;
	}
	return ret;
}
std::vector<int> iota(int n) {
	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	return p;
}
#line 11 "/home/nok0/documents/programming/library/template/all"
using namespace std;
#line 4 "b.cpp"

void main_();
int main() {
	int t = 1;
	while(t--) main_();
}

#line 12 "b.cpp"


enum {
	NOTFOUND = 0xFFFFFFFFFFFFFFFFLLU
};

class SuccinctBitVector {
   private:
	const uint64_t size;  // 
	static const uint64_t blockBitNum = 16;
	static const uint64_t LEVEL_L = 512;
	static const uint64_t LEVEL_S = 16;

	std::vector<uint64_t> L;  // 
	std::vector<uint16_t> S;  // 
	std::vector<uint16_t> B;  // 

	uint64_t numOne = 0;  // 1bit

   public:
	explicit SuccinctBitVector(const uint64_t n) : size(n) {
		const uint64_t s = (n + blockBitNum - 1) / blockBitNum + 1;  // ceil(n, blockSize)
		this->B.assign(s, 0);
		this->L.assign(n / LEVEL_L + 1, 0);
		this->S.assign(n / LEVEL_S + 1, 0);
	}

	// B[pos] = bit
	void setBit(const uint64_t bit, const uint64_t pos) {
		assert(bit == 0 or bit == 1);
		assert(pos < this->size);

		const uint64_t blockPos = pos / blockBitNum;
		const uint64_t offset = pos % blockBitNum;
		if(bit == 1) {
			B.at(blockPos) |= (1LLU << offset);
		} else {
			B.at(blockPos) &= (~(1LLU << offset));
		}
	}

	// B[pos]
	uint64_t access(const uint64_t pos) {
		assert(pos < this->size);
		const uint64_t blockPos = pos / blockBitNum;
		const uint64_t offset = pos % blockBitNum;
		return ((B.at(blockPos) >> offset) & 1);
	}

	void build() {
		uint64_t num = 0;
		for(uint64_t i = 0; i <= size; i++) {
			if(i % LEVEL_L == 0) {
				L.at(i / LEVEL_L) = num;
			}
			if(i % LEVEL_S == 0) {
				S.at(i / LEVEL_S) = num - L.at(i / LEVEL_L);
			}
			if(i != size and i % blockBitNum == 0) {
				num += this->popCount(this->B.at(i / blockBitNum));
			}
		}
		this->numOne = num;
	}

	// B[0, pos)bit
	uint64_t rank(const uint64_t bit, const uint64_t pos) {
		assert(bit == 0 or bit == 1);
		assert(pos <= this->size);

		if(bit) {
			return L[pos / LEVEL_L] + S[pos / LEVEL_S] + popCount(B[pos / blockBitNum] & ((1 << (pos % blockBitNum)) - 1));
		} else {
			return pos - rank(1, pos);
		}
	}

	// rankbit + 1(rank1-origin)
	uint64_t select(const uint64_t bit, const uint64_t rank) {
		assert(bit == 0 or bit == 1);
		assert(rank > 0);
		if(bit == 0 and rank > this->size - this->numOne) { return NOTFOUND; }
		if(bit == 1 and rank > this->numOne) { return NOTFOUND; }

		// L
		uint64_t large_idx = 0;
		{
			uint64_t left = 0;
			uint64_t right = L.size();
			while(right - left > 1) {
				uint64_t mid = (left + right) / 2;
				uint64_t r = L.at(mid);
				r = (bit) ? r : mid * LEVEL_L - L.at(mid);

				if(r < rank) {
					left = mid;
					large_idx = mid;
				} else {
					right = mid;
				}
			}
		}

		// S
		uint64_t small_idx = (large_idx * LEVEL_L) / LEVEL_S;
		{
			uint64_t left = (large_idx * LEVEL_L) / LEVEL_S;
			uint64_t right = std::min(((large_idx + 1) * LEVEL_L) / LEVEL_S, (uint64_t)S.size());
			while(right - left > 1) {
				uint64_t mid = (left + right) / 2;
				uint64_t r = L.at(large_idx) + S.at(mid);
				r = (bit) ? r : mid * LEVEL_S - r;

				if(r < rank) {
					left = mid;
					small_idx = mid;
				} else {
					right = mid;
				}
			}
		}

		// B
		uint64_t rank_pos = 0;
		{
			const uint64_t begin_block_idx = (small_idx * LEVEL_S) / blockBitNum;
			uint64_t total_bit = L.at(large_idx) + S.at(small_idx);
			if(bit == 0) {
				total_bit = small_idx * LEVEL_S - total_bit;
			}
			for(uint64_t i = 0;; ++i) {
				uint64_t b = popCount(B.at(begin_block_idx + i));
				if(bit == 0) {
					b = blockBitNum - b;
				}
				if(total_bit + b >= rank) {
					uint64_t block = (bit) ? B.at(begin_block_idx + i) : ~B.at(begin_block_idx + i);
					rank_pos = (begin_block_idx + i) * blockBitNum + selectInBlock(block, rank - total_bit);
					break;
				}
				total_bit += b;
			}
		}

		return rank_pos + 1;
	}

	uint64_t getNumOne() const {
		return numOne;
	}

   private:
	uint64_t popCount(uint64_t x) {
		x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);
		x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
		x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
		x = x + (x >> 8);
		x = x + (x >> 16);
		x = x + (x >> 32);
		return x & 0x7FLLU;
	}

	uint64_t selectInBlock(uint64_t x, uint64_t rank) {
		uint64_t x1 = x - ((x & 0xAAAAAAAAAAAAAAAALLU) >> 1);
		uint64_t x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> 2) & 0x3333333333333333LLU);
		uint64_t x3 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FLLU;

		uint64_t pos = 0;
		for(;; pos += 8) {
			uint64_t rank_next = (x3 >> pos) & 0xFFLLU;
			if(rank <= rank_next) break;
			rank -= rank_next;
		}

		uint64_t v2 = (x2 >> pos) & 0xFLLU;
		if(rank > v2) {
			rank -= v2;
			pos += 4;
		}

		uint64_t v1 = (x1 >> pos) & 0x3LLU;
		if(rank > v1) {
			rank -= v1;
			pos += 2;
		}

		uint64_t v0 = (x >> pos) & 0x1LLU;
		if(v0 < rank) {
			rank -= v0;
			pos += 1;
		}

		return pos;
	}
};

class WaveletMatrix {
   private:
	std::vector<SuccinctBitVector> bit_arrays;
	std::vector<uint64_t> begin_one;                    // bit1
	std::map<uint64_t, uint64_t> begin_alphabet;        // 
	std::vector<std::vector<uint64_t>> cumulative_sum;  // bit

	uint64_t size;             // 
	uint64_t maximum_element;  // 
	uint64_t bit_size;         // bit

   public:
	WaveletMatrix(const std::vector<uint64_t> &array) {
		assert(array.size() > 0);
		size = array.size();
		maximum_element = *max_element(array.begin(), array.end()) + 1;
		bit_size = get_num_of_bit(maximum_element);
		if(bit_size == 0) {
			bit_size = 1;
		}

		for(uint64_t i = 0; i < bit_size; ++i) {
			SuccinctBitVector sv(size);
			bit_arrays.push_back(sv);
		}
		this->begin_one.resize(bit_size);
		this->cumulative_sum.resize(bit_size + 1, std::vector<uint64_t>(size + 1, 0));

		for(uint64_t j = 0; j < array.size(); ++j) {
			this->cumulative_sum.at(0).at(j + 1) = this->cumulative_sum.at(0).at(j) + array[j];
		}

		std::vector<uint64_t> v(array);
		for(uint64_t i = 0; i < bit_size; ++i) {
			std::vector<uint64_t> temp;
			// 0temp
			for(uint64_t j = 0; j < v.size(); ++j) {
				uint64_t c = v.at(j);
				uint64_t bit = (c >> (bit_size - i - 1)) & 1;  //ibit
				if(bit == 0) {
					temp.push_back(c);
					bit_arrays.at(i).setBit(0, j);
				}
			}

			this->begin_one.at(i) = temp.size();

			// 1temp
			for(uint64_t j = 0; j < v.size(); ++j) {
				uint64_t c = v.at(j);
				uint64_t bit = (c >> (bit_size - i - 1)) & 1;  //ibit
				if(bit == 1) {
					temp.push_back(c);
					bit_arrays.at(i).setBit(1, j);
				}
			}

			for(uint64_t j = 0; j < temp.size(); ++j) {
				this->cumulative_sum.at(i + 1).at(j + 1) = this->cumulative_sum.at(i + 1).at(j) + temp.at(j);
			}

			bit_arrays.at(i).build();
			v = temp;
		}

		// 
		for(int i = v.size() - 1; i >= 0; --i) {
			this->begin_alphabet[v.at(i)] = i;
		}
	}

	// v[pos]
	uint64_t access(uint64_t pos) {
		if(pos >= this->size) { return NOTFOUND; }

		uint64_t c = 0;
		for(uint64_t i = 0; i < bit_arrays.size(); ++i) {
			uint64_t bit = bit_arrays.at(i).access(pos);  // ibit
			c = (c <<= 1) | bit;
			pos = bit_arrays.at(i).rank(bit, pos);
			if(bit) {
				pos += this->begin_one.at(i);
			}
		}
		return c;
	}

	// ic + 1rank1-origin
	uint64_t select(uint64_t c, uint64_t rank) {
		assert(rank > 0);
		if(c >= maximum_element) {
			return NOTFOUND;
		}
		if(this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
			return NOTFOUND;
		}

		uint64_t index = this->begin_alphabet.at(c) + rank;
		for(uint64_t i = 0; i < bit_arrays.size(); ++i) {
			uint64_t bit = ((c >> i) & 1);  // ibit
			if(bit == 1) {
				index -= this->begin_one.at(bit_size - i - 1);
			}
			index = this->bit_arrays.at(bit_size - i - 1).select(bit, index);
		}
		return index;
	}

	// v[begin_pos, end_pos)index
	uint64_t maxRange(uint64_t begin_pos, uint64_t end_pos) {
		return quantileRange(begin_pos, end_pos, end_pos - begin_pos - 1);
	}

	// v[begin_pos, end_pos)index
	uint64_t minRange(uint64_t begin_pos, uint64_t end_pos) {
		return quantileRange(begin_pos, end_pos, 0);
	}

	// v[begin_pos, end_pos)kindex(k0-origin)
	// k
	uint64_t quantileRange(uint64_t begin_pos, uint64_t end_pos, uint64_t k) {
		if((end_pos > size || begin_pos >= end_pos) || (k >= end_pos - begin_pos)) {
			return NOTFOUND;
		}

		uint64_t val = 0;
		for(uint64_t i = 0; i < bit_size; ++i) {
			const uint64_t num_of_zero_begin = bit_arrays.at(i).rank(0, begin_pos);
			const uint64_t num_of_zero_end = bit_arrays.at(i).rank(0, end_pos);
			const uint64_t num_of_zero = num_of_zero_end - num_of_zero_begin;  // beginend0
			const uint64_t bit = (k < num_of_zero) ? 0 : 1;                    // kibit01

			if(bit) {
				k -= num_of_zero;
				begin_pos = this->begin_one.at(i) + begin_pos - num_of_zero_begin;
				end_pos = this->begin_one.at(i) + end_pos - num_of_zero_end;
			} else {
				begin_pos = num_of_zero_begin;
				end_pos = num_of_zero_begin + num_of_zero;
			}

			val = ((val << 1) | bit);
		}

		uint64_t left = 0;
		for(uint64_t i = 0; i < bit_size; ++i) {
			const uint64_t bit = (val >> (bit_size - i - 1)) & 1;  // ibit
			left = bit_arrays.at(i).rank(bit, left);               // cibit
			if(bit) {
				left += this->begin_one.at(i);
			}
		}

		const uint64_t rank = begin_pos + k - left + 1;
		return select(val, rank) - 1;
	}

	// v[0, pos)c
	uint64_t rank(uint64_t c, uint64_t pos) {
		assert(pos < size);
		if(c >= maximum_element) {
			return 0;
		}
		if(this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
			return 0;
		}

		for(uint64_t i = 0; i < bit_size; ++i) {
			uint64_t bit = (c >> (bit_size - i - 1)) & 1;  // ibit
			pos = bit_arrays.at(i).rank(bit, pos);         // cibit
			if(bit) {
				pos += this->begin_one.at(i);
			}
		}

		uint64_t begin_pos = this->begin_alphabet.at(c);
		return pos - begin_pos;
	}

	// v[begin_pos, end_pos)[min, max)
	uint64_t rangeFreq(uint64_t begin_pos, uint64_t end_pos, uint64_t min_c, uint64_t max_c) {
		if((end_pos > size || begin_pos >= end_pos) || (min_c >= max_c) || min_c >= maximum_element) {
			return 0;
		}

		const auto maxi_t = rankAll(max_c, begin_pos, end_pos);
		const auto mini_t = rankAll(min_c, begin_pos, end_pos);
		return std::get<1>(maxi_t) - std::get<1>(mini_t);
	}

	// v[0, pos)c
	uint64_t rankLessThan(uint64_t c, uint64_t begin, uint64_t end) {
		auto t = rankAll(c, begin, end);
		return std::get<1>(t);
	}

	// v[0, pos)c
	uint64_t rankMoreThan(uint64_t c, uint64_t begin, uint64_t end) {
		auto t = rankAll(c, begin, end);
		return std::get<2>(t);
	}

	// v[begin, end)(ccc)
	std::tuple<uint64_t, uint64_t, uint64_t> rankAll(const uint64_t c, uint64_t begin, uint64_t end) {
		assert(end <= size);
		const uint64_t num = end - begin;

		if(begin >= end) {
			return std::make_tuple(0, 0, 0);
		}
		if(c >= maximum_element || end == 0) {
			return std::make_tuple(0, num, 0);
		}

		uint64_t rank_less_than = 0, rank_more_than = 0;
		for(size_t i = 0; i < bit_size && begin < end; ++i) {
			const uint64_t bit = (c >> (bit_size - i - 1)) & 1;

			const uint64_t rank0_begin = this->bit_arrays.at(i).rank(0, begin);
			const uint64_t rank0_end = this->bit_arrays.at(i).rank(0, end);
			const uint64_t rank1_begin = begin - rank0_begin;
			const uint64_t rank1_end = end - rank0_end;

			if(bit) {
				rank_less_than += (rank0_end - rank0_begin);  // ibit0
				begin = this->begin_one.at(i) + rank1_begin;
				end = this->begin_one.at(i) + rank1_end;
			} else {
				rank_more_than += (rank1_end - rank1_begin);  // ibit1
				begin = rank0_begin;
				end = rank0_end;
			}
		}

		const uint64_t rank = num - rank_less_than - rank_more_than;
		return std::make_tuple(rank, rank_less_than, rank_more_than);
	}

	// T[s, e)k()
	// 
	std::vector<std::pair<uint64_t, uint64_t>> topk(uint64_t s, uint64_t e, uint64_t k) {
		assert(s < e);
		std::vector<std::pair<uint64_t, uint64_t>> result;

		// ()
		auto c = [](const std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t> &l, const std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t> &r) {
			// width
			if(std::get<0>(l) != std::get<0>(r)) {
				return std::get<0>(l) < std::get<0>(r);
			}
			// depth
			if(std::get<3>(l) != std::get<3>(r)) {
				return std::get<3>(l) > std::get<3>(r);
			}
			// value
			if(std::get<4>(l) != std::get<4>(r)) {
				return std::get<4>(l) > std::get<4>(r);
			}
			return true;
		};

		std::priority_queue<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>, std::vector<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>>, decltype(c)> que(c);  // width, left, right, depth, value
		que.push(std::make_tuple(e - s, s, e, 0, 0));

		while(not que.empty()) {
			auto element = que.top();
			que.pop();
			uint64_t width, left, right, depth, value;
			std::tie(width, left, right, depth, value) = element;

			if(depth >= this->bit_size) {
				result.emplace_back(std::make_pair(value, right - left));
				if(result.size() >= k) {
					break;
				}
				continue;
			}

			// 0
			const uint64_t left0 = this->bit_arrays.at(depth).rank(0, left);
			const uint64_t right0 = this->bit_arrays.at(depth).rank(0, right);
			if(left0 < right0) {
				que.push(std::make_tuple(right0 - left0, left0, right0, depth + 1, value));
			}

			// 1
			const uint64_t left1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, left);
			const uint64_t right1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, right);
			if(left1 < right1) {
				que.push(std::make_tuple(right1 - left1, left1, right1, depth + 1, value | (1 << (bit_size - depth - 1))));
			}
		}

		return result;
	};

	// T[begin_pos, end_pos)x <= c < yc
	uint64_t rangeSum(const uint64_t begin, const uint64_t end, const uint64_t x, const uint64_t y) {
		return rangeSum(begin, end, 0, 0, x, y);
	}

	// T[begin_pos, end_pos)x <= c < yc
	uint64_t prevValue(const uint64_t begin_pos, const uint64_t end_pos, const uint64_t x, uint64_t y) {
		assert(end_pos <= size);
		const uint64_t num = end_pos - begin_pos;

		if(x >= y or y == 0) {
			return NOTFOUND;
		}
		if(y > maximum_element) {
			y = maximum_element;
		}

		if(begin_pos >= end_pos) {
			return NOTFOUND;
		}
		if(x >= maximum_element || end_pos == 0) {
			return NOTFOUND;
		}

		y--;  // x <= c <= y

		std::stack<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, bool>> s;  // (begin, end, depth, c, tight)
		s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

		while(not s.empty()) {
			uint64_t b, e, depth, c;
			bool tight;
			std::tie(b, e, depth, c, tight) = s.top();
			s.pop();

			if(depth == bit_size) {
				if(c >= x) {
					return c;
				}
				continue;
			}

			const uint64_t bit = (y >> (bit_size - depth - 1)) & 1;

			const uint64_t rank0_begin = this->bit_arrays.at(depth).rank(0, b);
			const uint64_t rank0_end = this->bit_arrays.at(depth).rank(0, e);
			const uint64_t rank1_begin = b - rank0_begin;
			const uint64_t rank1_end = e - rank0_end;

			// dbit0
			const uint64_t b0 = rank0_begin;
			const uint64_t e0 = rank0_end;
			if(b0 != e0) {  // 
				const uint64_t c0 = ((c << 1) | 0);
				s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight and bit == 0));
			}

			// dbit1
			const uint64_t b1 = this->begin_one.at(depth) + rank1_begin;
			const uint64_t e1 = this->begin_one.at(depth) + rank1_end;
			if(b1 != e1) {
				if(not tight or bit == 1) {
					const auto c1 = ((c << 1) | 1);
					s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight));
				}
			}
		}

		return NOTFOUND;
	}

	// T[begin_pos, end_pos)x <= c < yc
	uint64_t nextValue(const uint64_t begin_pos, const uint64_t end_pos, const uint64_t x, const uint64_t y) {
		assert(end_pos <= size);
		const uint64_t num = end_pos - begin_pos;

		if(x >= y or y == 0) {
			return NOTFOUND;
		}

		if(begin_pos >= end_pos) {
			return NOTFOUND;
		}
		if(x >= maximum_element || end_pos == 0) {
			return NOTFOUND;
		}

		std::stack<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, bool>> s;  // (begin, end, depth, c, tight)
		s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

		while(not s.empty()) {
			uint64_t b, e, depth, c;
			bool tight;
			std::tie(b, e, depth, c, tight) = s.top();
			s.pop();

			if(depth == bit_size) {
				if(c < y) {
					return c;
				}
				continue;
			}

			const uint64_t bit = (x >> (bit_size - depth - 1)) & 1;

			const uint64_t rank0_begin = this->bit_arrays.at(depth).rank(0, b);
			const uint64_t rank0_end = this->bit_arrays.at(depth).rank(0, e);
			const uint64_t rank1_begin = b - rank0_begin;
			const uint64_t rank1_end = e - rank0_end;

			// dbit1
			const uint64_t b1 = this->begin_one.at(depth) + rank1_begin;
			const uint64_t e1 = this->begin_one.at(depth) + rank1_end;
			if(b1 != e1) {
				const auto c1 = ((c << 1) | 1);
				s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight and bit == 1));
			}

			// dbit0
			const uint64_t b0 = rank0_begin;
			const uint64_t e0 = rank0_end;
			if(b0 != e0) {
				if(not tight or bit == 0) {
					const uint64_t c0 = ((c << 1) | 0);
					s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight));
				}
			}
		}

		return NOTFOUND;
	}

	// T[s1, e1)T[s2, e2)
	std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> intersect(uint64_t _s1, uint64_t _e1, uint64_t _s2, uint64_t _e2) {
		assert(_s1 < _e1);
		assert(_s2 < _e2);

		std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> intersection;

		std::queue<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>> que;  // s1, e1, s2, e2, depth, value
		que.push(std::make_tuple(_s1, _e1, _s2, _e2, 0, 0));
		while(not que.empty()) {
			auto e = que.front();
			que.pop();
			uint64_t s1, e1, s2, e2, depth, value;
			std::tie(s1, e1, s2, e2, depth, value) = e;

			if(depth >= this->bit_size) {
				intersection.emplace_back(std::make_tuple(value, e1 - s1, e2 - s2));
				continue;
			}

			// 0
			uint64_t s1_0 = this->bit_arrays.at(depth).rank(0, s1);
			uint64_t e1_0 = this->bit_arrays.at(depth).rank(0, e1);
			uint64_t s2_0 = this->bit_arrays.at(depth).rank(0, s2);
			uint64_t e2_0 = this->bit_arrays.at(depth).rank(0, e2);

			if(s1_0 != e1_0 and s2_0 != e2_0) {
				que.push(std::make_tuple(s1_0, e1_0, s2_0, e2_0, depth + 1, value));
			}

			// 1
			uint64_t s1_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s1);
			uint64_t e1_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e1);
			uint64_t s2_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s2);
			uint64_t e2_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e2);

			if(s1_1 != e1_1 and s2_1 != e2_1) {
				que.push(std::make_tuple(s1_1, e1_1, s2_1, e2_1, depth + 1, value | (1 << bit_size - depth - 1)));
			}
		}

		return intersection;
	};

   private:
	uint64_t get_num_of_bit(uint64_t x) {
		if(x == 0) return 0;
		x--;
		uint64_t bit_num = 0;
		while(x >> bit_num) {
			++bit_num;
		}
		return bit_num;
	}

	uint64_t rangeSum(const uint64_t begin, const uint64_t end, const uint64_t depth, const uint64_t c, const uint64_t x, const uint64_t y) {
		if(begin == end) {
			return 0;
		}

		if(depth == bit_size) {
			if(x <= c and c < y) {
				return c * (end - begin);  //  * 
			}
			return 0;
		}

		const uint64_t next_c = ((uint64_t)1 << (bit_size - depth - 1)) | c;                // depthbit
		const uint64_t all_one_c = (((uint64_t)1 << (bit_size - depth - 1)) - 1) | next_c;  // depthbit(1)
		if(all_one_c < x or y <= c) {
			return 0;
		}

		// [begin, pos)[x, y)
		if(x <= c and all_one_c < y) {
			return this->cumulative_sum.at(depth).at(end) - this->cumulative_sum.at(depth).at(begin);
		}

		const uint64_t rank0_begin = this->bit_arrays.at(depth).rank(0, begin);
		const uint64_t rank0_end = this->bit_arrays.at(depth).rank(0, end);
		const uint64_t rank1_begin = begin - rank0_begin;
		const uint64_t rank1_end = end - rank0_end;

		return rangeSum(rank0_begin, rank0_end, depth + 1, c, x, y) + rangeSum(this->begin_one.at(depth) + rank1_begin, this->begin_one[depth] + rank1_end, depth + 1, next_c, x, y);
	}
};


void main_() {
	INT(n, q);
	graph g(n);
	rep(i, 1, n) {
		INT(p);
		g.add_edge(--p, i);
	}
	heavy_light_decomposition hld(g);
	V<> pl(n);
	rep(i, n) {
		pl[hld.in[i]] = i;
	}
	auto h = g.root_to_leaf(0);
	auto sz = h.subtree_size(0);
	V<uint64_t> wmsz(n);
	rep(i, n) {
		wmsz[hld.in[i]] = sz[i];
	}
	auto dep = h.bfs(0);

	WaveletMatrix wm(wmsz);
	rep(i, q) {
		INT(x);
		auto [l, r] = hld.subtree(--x);
		debug(divup(sz[x], 2));
		debug(wm.rankLessThan(divup(sz[x], 2), l, r));
		print(pl[wm.quantileRange(l, r, wm.rankLessThan(divup(sz[x], 2), l, r))] + 1);
	}
}