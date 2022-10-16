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
#line 3 "b.cpp"

void main_();
int main() {
	int t = 1;
	while(t--) main_();
}

void main_() {
	INT(n, k);
	V<> in(n);
	rep(i, 2 * k) {
		INT(x);
		in[--x] = 1;
	}
	graph g(n, -1);
	auto h = g.root_to_leaf(0);
	V<> wei(n);
	auto dfs = [&](auto dfs, int now) -> void {
		for(auto e : h[now]) {
			dfs(dfs, e.to);
			wei[now] += wei[e.to];
		}
		wei[now] += in[now];
	};
	dfs(dfs, 0);
	debug(wei);
	ll res = 0;
	rep(i, n) {
		for(auto e : h[i]) {
			debug(i, e.to, res);
			res += min(k * 2 - wei[e.to], wei[e.to]);
		}
	}
	print(res);
}