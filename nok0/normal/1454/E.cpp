/**
 *	author: nok0
 *	created: 2020.11.24 23:54:00
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
#define FOR(i, l, r) for(int i = (l); i < (r); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FOR(i, 1, n + 1)
#define RFOR(i, l, r) for(int i = (l); i >= (r); --i)
#define RREP(i, n) RFOR(i, n - 1, 0)
#define RREPS(i, n) RFOR(i, n, 1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <class T = int>
using V = vector<T>;
template <class T = int>
using VV = V<V<T>>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define VEC(type, name, size) \
	V<type> name(size);       \
	INPUT(name)
#define VVEC(type, name, h, w)    \
	VV<type> name(h, V<type>(w)); \
	INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LL(...)     \
	ll __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	DOUBLE __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LD(...)     \
	LD __VA_ARGS__; \
	INPUT(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T>
void scan(V<T> &);
template <class T, class L>
void scan(pair<T, L> &);
template <class T>
void scan(V<T> &a) {
	for(auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}
template <class T>
void scan(T &a) { cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
template <class T>
inline void print(T x) { cout << x << '\n'; }
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for(T &in : v) is >> in;
	return is;
}
template <class T>
ostream &operator<<(ostream &os, const V<T> &v) {
	REP(i, SZ(v)) {
		if(i) os << " ";
		os << v[i];
	}
	return os;
}
//debug
template <typename T>
void view(const V<T> &v) {
	cerr << "{ ";
	for(const auto &e : v) {
		cerr << e << ", ";
	}
	cerr << "\b\b }";
}
template <typename T>
void view(const VV<T> &vv) {
	cerr << "{\n";
	for(const auto &v : vv) {
		cerr << "\t";
		view(v);
		cerr << "\n";
	}
	cerr << "}";
}
template <typename T, typename U>
void view(const V<pair<T, U>> &v) {
	cerr << "{\n";
	for(const auto &c : v) cerr << "\t(" << c.first << ", " << c.second << ")\n";
	cerr << "}";
}
template <typename T, typename U>
void view(const map<T, U> &m) {
	cerr << "{\n";
	for(auto &t : m) cerr << "\t[" << t.first << "] : " << t.second << "\n";
	cerr << "}";
}
template <typename T, typename U>
void view(const pair<T, U> &p) { cerr << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
void view(const set<T> &s) {
	cerr << "{ ";
	for(auto &t : s) {
		view(t);
		cerr << ", ";
	}
	cerr << "\b\b }";
}
template <typename T>
void view(T e) { cerr << e; }
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	view(H);
	cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                           \
	do {                                                     \
		cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                              \
		cerr << "\b\b]\n";                                   \
	} while(0)
#else
#define debug(...) (void(0))
#endif
template <class T>
V<T> press(V<T> &x) {
	V<T> res = x;
	sort(all(res));
	res.erase(unique(all(res)), res.end());
	REP(i, SZ(x)) {
		x[i] = lower_bound(all(res), x[i]) - res.begin();
	}
	return res;
}
template <class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}
inline void Yes(bool b = true) { cout << (b ? "Yes" : "No") << '\n'; }
inline void YES(bool b = true) { cout << (b ? "YES" : "NO") << '\n'; }
inline void err(bool b = true) {
	if(b) {
		cout << -1 << '\n';
		exit(0);
	}
}
template <class T>
inline void fin(bool b = true, T e = 0) {
	if(b) {
		cout << e << '\n';
		exit(0);
	}
}
template <class T>
T divup(T x, T y) { return (x + (y - 1)) / y; }
template <typename T>
T pow(T a, long long n, T e = 1) {
	T ret = e;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
struct iofast {
	iofast() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} iofast_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

#pragma region graph
struct Edge {
	int to;
	long long cost;
	Edge() = default;
	Edge(int to_, long long cost_)
	  : to(to_), cost(cost_) {}
	bool operator<(const Edge &a) const {
		return cost < a.cost;
	}
	bool operator>(const Edge &a) const {
		return cost > a.cost;
	}
	friend std::ostream &operator<<(std::ostream &s, Edge &a) {
		s << "to:" << a.to << " cost:" << a.cost;
		return s;
	}
};

struct Graph : private std::vector<std::vector<Edge>> {
	using std::vector<std::vector<Edge>>::vector;
	using std::vector<std::vector<Edge>>::operator[];
	using std::vector<std::vector<Edge>>::operator=;
	using std::vector<std::vector<Edge>>::size;
	using std::vector<std::vector<Edge>>::resize;
	using std::vector<std::vector<Edge>>::clear;
	using std::vector<std::vector<Edge>>::push_back;
	using std::vector<std::vector<Edge>>::emplace_back;
	using std::vector<std::vector<Edge>>::begin;
	using std::vector<std::vector<Edge>>::end;

private:
	const long long INF = 1e18;

	bool lcainit_done = false;
	std::vector<std::vector<int>> parent;
	std::vector<int> lcadist;

	template <class T>
	inline bool chmax(T &a, T b) {
		if(a < b) {
			a = b;
			return true;
		}
		return false;
	}

	template <class T>
	inline bool chmin(T &a, T b) {
		if(a > b) {
			a = b;
			return true;
		}
		return false;
	}

public:
	void read(int e = -1, bool weight = 0, bool directed = false, int idx = 1) {
		if(e == -1) e = size() - 1;
		while(e--) {
			int u, v;
			long long cost = 1;
			std::cin >> u >> v;
			if(weight) std::cin >> cost;
			u -= idx, v -= idx;
			(*this)[u].emplace_back(v, cost);
			if(!directed) (*this)[v].emplace_back(u, cost);
		}
	}

	void add(int u, int v, int cost = -1, bool directed = false, int idx = 0) {
		if(cost == -1)
			cost = 1;
		u -= idx, v -= idx;
		(*this)[u].emplace_back(v, cost);
		if(!directed) (*this)[v].emplace_back(u, cost);
	}

	std::vector<long long> bfs(int s) {
		std::vector dist(size(), INF);
		std::queue<int> que;
		dist[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int v = que.front();
			que.pop();
			for(auto &e : (*this)[v]) {
				if(dist[e.to] != INF) continue;
				dist[e.to] = dist[v] + e.cost;
				que.push(e.to);
			}
		}
		return dist;
	}

	std::vector<long long> Dijkstra(int s) {
		std::vector dist(size(), INF);
		using pll = std::pair<long long, long long>;
		std::priority_queue<pll, std::vector<pll>, std::greater<pll>> que;
		dist[s] = 0;
		que.push(pll(0, s));
		while(!que.empty()) {
			pll p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(int i = 0; i < int((*this)[v].size()); i++) {
				Edge e = (*this)[v][i];
				if(dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					que.push(pll(dist[e.to], e.to));
				}
			}
		}
		return dist;
	}

	std::vector<long long> BellmanFord(int s) {
		int n = size();
		std::vector res(n, INF);
		res[s] = 0;
		for(int loop = 0; loop < n - 1; loop++) {
			for(int v = 0; v < n; v++) {
				if(res[v] == INF) continue;
				for(auto &e : (*this)[v]) {
					res[e.to] = std::min(res[e.to], res[v] + e.cost);
				}
			}
		}

		std::queue<int> que;
		std::vector chk(n, 0);
		for(int v = 0; v < n; v++) {
			if(res[v] == INF) continue;
			for(auto &e : (*this)[v]) {
				if(res[e.to] > res[v] + e.cost) {
					res[e.to] = res[v] + e.cost;
					if(!chk[e.to]) {
						que.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!que.empty()) {
			int now = que.front();
			que.pop();
			for(auto &e : (*this)[now]) {
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

	std::vector<std::vector<long long>> WarshallFloyd() {
		int n = size();
		std::vector dist(n, std::vector(n, INF));
		for(int i = 0; i < n; i++) {
			dist[i][i] = 0;
		}
		for(int i = 0; i < n; i++) {
			for(auto e : (*this)[i]) {
				chmin(dist[i][e.to], e.cost);
			}
		}
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					chmin(dist[i][j], dist[i][k] + dist[k][j]);
		return dist;
	}

	int lca(int u, int v) {
		if(!lcainit_done) {
			auto dfs = [&](auto self, int now, int per, int d) -> void {
				parent[0][now] = per;
				lcadist[now] = d;
				for(auto &e : (*this)[now])
					if(e.to != per) self(self, e.to, now, d + 1);
			};

			lcainit_done = true;
			int n = size();
			int k = 1;
			while((1 << k) < n) k++;
			parent.assign(k, std::vector(n, -1));
			lcadist.assign(n, -1);

			dfs(dfs, 0, -1, 0);
			for(int i = 0; i < k - 1; i++)
				for(int v = 0; v < n; v++) {
					if(parent[i][v] < 0)
						parent[i + 1][v] = -1;
					else
						parent[i + 1][v] = parent[i][parent[i][v]];
				}
		}
		if(lcadist[u] < lcadist[v]) std::swap(u, v);
		int k = parent.size();
		for(int i = 0; i < k; i++)
			if((lcadist[u] - lcadist[v]) >> i & 1) u = parent[i][u];
		if(u == v) return u;
		for(int i = k - 1; i >= 0; i--)
			if(parent[i][u] != parent[i][v])
				u = parent[i][u], v = parent[i][v];
		return parent[0][u];
	}

	int dist(int u, int v) {
		if(!lcainit_done) {
			std::function<void(int, int, int)> dfs = [&](int now, int per, int d) {
				parent[0][now] = per;
				lcadist[now] = d;
				for(auto &e : (*this)[now])
					if(e.to != per) dfs(e.to, now, d + 1);
			};

			lcainit_done = true;
			int n = size();
			int k = 1;
			while((1 << k) < n) k++;
			parent.assign(k, std::vector(n, -1));
			lcadist.assign(n, -1);

			dfs(0, -1, 0);
			for(int i = 0; i < k - 1; i++)
				for(int v = 0; v < n; v++) {
					if(parent[i][v] < 0)
						parent[i + 1][v] = -1;
					else
						parent[i + 1][v] = parent[i][parent[i][v]];
				}
		}
		return lcadist[u] + lcadist[v] - 2 * lcadist[lca(u, v)];
	}

	std::vector<int> tsort() {
		std::vector<int> res;
		int n = size();
		std::vector<int> used(n, 0);
		bool notDAG = false;

		auto dfs = [&](auto self, int k) -> void {
			if(notDAG) return;
			if(used[k]) {
				if(used[k] == 1)
					notDAG = true;
				return;
			}
			used[k] = 1;
			for(auto &e : (*this)[k]) self(self, e.to);
			used[k] = 2;
			res.push_back(k);
		};

		for(int i = 0; i < n; i++) dfs(dfs, i);
		if(notDAG) return std::vector<int>{};
		std::reverse(res.begin(), res.end());
		return res;
	}

	bool isDAG() { return tsort().size(); }

	std::vector<long long> height() {
		std::vector<long long> fir(size(), -1), sec(size(), -1);

		auto dfs = [&](auto self, int now, int par) -> long long {
			long long f = 0, s = 0;
			for(auto &e : (*this)[now]) {
				if(e.to == par) continue;
				s = std::max(s, self(self, e.to, now) + e.cost);
				if(f < s) std::swap(f, s);
			}
			sec[now] = s;
			return fir[now] = f;
		};

		auto solve = [&](auto self, int now, int par, long long parf, long long pars, long long parcost) -> void {
			if(fir[now] + parcost == parf) parf = pars;
			sec[now] = std::max(sec[now], parf + parcost);
			if(fir[now] < sec[now]) std::swap(fir[now], sec[now]);
			for(auto &e : (*this)[now]) {
				if(e.to == par) continue;
				self(self, e.to, now, fir[now], sec[now], e.cost);
			}
			return;
		};

		dfs(dfs, 0, -1);
		solve(solve, 0, -1, -1, -1, -1);
		return fir;
	}

	//{01}
	std::pair<bool, std::vector<int>> isBiparate() {
		std::vector<int> colors(size()), ret(size());

		auto dfs = [&](auto self, int now, int col) -> bool {
			colors[now] = col;
			if(col == 1) ret[now] = 1;
			for(auto &e : (*this)[now]) {
				if(col == colors[e.to]) return false;
				if(colors[e.to] == 0 and !self(self, e.to, -col)) return false;
			}
			return true;
		};

		return std::pair(dfs(dfs, 0, 1), ret);
	}

	//{{},}
	std::pair<std::pair<int, int>, long long> Diameter() {
		auto vec = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(chmax(dia, vec[i]))
				v1 = i;
		vec = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(chmax(dia, vec[i]))
				v2 = i;

		std::pair<std::pair<int, int>, long long> res = {{v1, v2}, dia};
		return res;
	}

	//
	long long Prim() {
		long long res = 0;
		std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> que;
		for(auto &e : (*this)[0])
			que.push(e);
		std::vector chk(size(), 0);
		chk[0] = 1;
		while(!que.empty()) {
			auto e = que.top();
			que.pop();
			if(chk[e.to]) continue;
			res += e.cost;
			chk[e.to] = 1;
			for(auto &e : (*this)[e.to]) {
				que.push(e);
			}
		}
		return res;
	}

	//
	std::vector<int> Centroid() {
		int n = size();
		std::vector<int> centroid, sz(n);

		auto dfs = [&](auto self, int now, int per) -> void {
			sz[now] = 1;
			bool is_centroid = true;
			for(auto &e : (*this)[now])
				if(e.to != per) {
					self(self, e.to, now);
					sz[now] += sz[e.to];
					if(sz[e.to] > n / 2) is_centroid = false;
				}
			if(n - sz[now] > n / 2) is_centroid = false;
			if(is_centroid) centroid.push_back(now);
		};

		dfs(dfs, 0, -1);

		return centroid;
	}

	//pair{(pair),(int)}
	std::pair<std::vector<std::pair<int, int>>, std::vector<int>> lowlink() {
		int n = size(), k = 0;
		std::vector<int> used(n, 0), order(n, 0), low(n, 0), articulation;
		std::vector<std::pair<int, int>> bridge;

		auto dfs = [&](auto self, int idx, int k, int par) -> int {
			used[idx] = 1;
			order[idx] = k++;
			low[idx] = order[idx];
			bool is_articulation = false, neko = false;
			int cnt = 0;
			for(auto &e : (*this)[idx]) {
				if(e.to == par and !std::exchange(neko, true)) {
					continue;
				}
				if(!used[e.to]) {
					++cnt;
					k = self(self, e.to, k, idx);
					low[idx] = std::min(low[idx], low[e.to]);
					is_articulation |= par >= 0 and low[e.to] >= order[idx];
					if(order[idx] < low[e.to]) {
						auto p = std::minmax(idx, e.to);
						bridge.emplace_back(p.first, p.second);
					}
				} else {
					low[idx] = std::min(low[idx], order[e.to]);
				}
			}
			is_articulation |= par == -1 and cnt > 1;
			if(is_articulation) articulation.push_back(idx);
			return k;
		};

		for(int i = 0; i < n; i++)
			if(!used[i]) k = dfs(dfs, i, k, -1);
		return std::pair(bridge, articulation);
	}

	//
	Graph RootToLeaf(int root = 0) {
		Graph res(size());
		std::vector chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : (*this)[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add(now, e.to, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	//
	Graph LeafToRoot(int root = 0) {
		Graph res(size());
		std::vector chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : (*this)[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add(e.to, now, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}
};

struct SCC {
private:
	const Graph &g;
	Graph ng, rg;
	std::vector<int> compo, order, used;

	void dfs(int now) {
		if(used[now]) return;
		used[now] = true;
		for(auto &e : ng[now]) dfs(e.to);
		order.emplace_back(now);
	}

	void rdfs(int now, int count) {
		if(compo[now] != -1) return;
		compo[now] = count;
		for(auto &e : rg[now]) rdfs(e.to, count);
	}

public:
	SCC(Graph &g_) : g(g_) {
		int n = g.size();
		ng.resize(n);
		rg.resize(n);
		compo.assign(n, -1);
		used.resize(n);
		for(int i = 0; i < n; i++) {
			for(auto &e : g[i]) {
				ng[i].emplace_back(e.to, 1);
				rg[e.to].emplace_back(i, 1);
			}
		}
	}

	int operator[](int k) { return compo[k]; }

	Graph build() {
		Graph ret;
		for(int i = 0; i < (int)ng.size(); i++)
			dfs(i);
		reverse(order.begin(), order.end());
		int group = 0;
		for(auto i : order)
			if(compo[i] == -1) rdfs(i, group), group++;

		ret.resize(group);
		for(int i = 0; i < (int)g.size(); i++) {
			for(auto &e : g[i]) {
				int s = compo[i], t = compo[e.to];
				if(s != t) ret[s].emplace_back(t, 1);
			}
		}

		return ret;
	}
};

struct HeavyLightDecomposition {
public:
	std::vector<int> sz, in, out, head, rev, par;

private:
	Graph &g;

	void dfs_sz(int v, int p = -1) {
		par[v] = p;
		if(!g[v].empty() and g[v].front().to == p)
			std::swap(g[v].front(), g[v].back());
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			dfs_sz(e.to, v);
			sz[v] += sz[e.to];
			if(sz[g[v].front().to] < sz[e.to])
				std::swap(g[v].front(), e);
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
	HeavyLightDecomposition(Graph &g_, int root = 0) : g(g_) {
		int n = g.size();
		sz.assign(n, 1);
		in.resize(n);
		out.resize(n);
		head.resize(n);
		rev.resize(n);
		par.resize(n);
		build(root);
	}

	//v0k
	int la(int v, int k) {
		while(true) {
			int u = head[v];
			if(in[v] - k >= in[u]) return rev[in[v] - k];
			k -= in[v] - in[u] + 1;
			v = par[u];
		}
	}

	int lca(int u, int v) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) return u;
		}
	}

	//u,v: ti: q: f:merge
	template <typename T, typename Q, typename F>
	T query(int u, int v, const T &ti, const Q &q, const F &f, bool edge = false) {
		T l = ti, r = ti;
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v), std::swap(l, r);
			if(head[u] == head[v]) break;
			l = f(q(in[head[v]], in[v] + 1), l);
		}
		return f(f(q(in[u] + edge, in[v] + 1), l), r);
	}

	//u,v: q:
	template <typename Q>
	void add(int u, int v, const Q &q, bool edge = false) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) break;
			q(in[head[v]], in[v] + 1);
		}
		q(in[u] + edge, in[v] + 1);
	}

	std::pair<int, int> subtree(int v, bool edge = false) {
		return std::pair<int, int>(in[v] + edge, out[v]);
	}
};
#pragma endregion

void solve() {
	INT(n);
	Graph G(n);
	V<pii> e(n);
	REP(i, n) {
		INT(u, v);
		--u, --v;
		if(u > v) swap(u, v);
		e[i] = {u, v};
		G.add(u, v);
	}
	auto vec = G.lowlink().first;
	map<pii, int> mp;
	for(auto &v : vec) {
		mp[v] = true;
	}
	V<> roop(n);
	for(auto &v : e) {
		if(mp[v]) continue;
		roop[v.first] = roop[v.second] = 1;
	}
	V<> seen(n);
	auto dfs = [&](auto self, int now) -> int {
		int res = 1;
		for(auto &e : G[now]) {
			if(roop[e.to] or seen[e.to]) continue;
			seen[e.to] = 1;
			res += self(self, e.to);
		}
		return res;
	};
	ll rc = accumulate(all(roop), 0ll);
	ll res = rc * (rc - 1);
	REP(i, n) {
		if(!roop[i]) continue;
		seen[i] = 1;
		ll bu = dfs(dfs, i) - 1;
		res += bu * (bu - 1) / 2 + (rc - 1) * bu * 2 + bu + bu * (n - bu - rc);
	}
	print(res);
	return;
}

int main() {
	INT(t);
	while(t--) solve();
}