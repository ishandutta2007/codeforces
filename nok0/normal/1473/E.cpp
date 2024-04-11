/**
 *	author: nok0
 *	created: 2021.01.13 23:26:59
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#pragma region Macros
// rep macro
#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, l, r) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, l, r, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)

// name macro
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

// input macro
template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
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
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
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

// output-macro
template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
template <class T>
void print(const T &a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T &a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "No\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}

//debug macro
namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  // namespace debugger
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif

// vector macro
template <class T>
int lb(const std::vector<T> &a, const T &x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T &x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
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
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}

// math macro
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
// modpow
long long POW(long long a, long long n, int mod) {
	long long ret = 1;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}

// others
struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;
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

	//
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

void main_() {
	INT(n, m);
	Graph G(n * 3), H(n * 4);
	REP(i, m) {
		LL(u, v, c);
		--u, --v;
		G.add(u, v, c);
		G.add(u + n, v + n, c);
		G.add(u + n * 2, v + n * 2, c);
		G.add(u, v + n, c * 2, 1);
		G.add(u + n, v + n * 2, 0, 1);
		G.add(v, u + n, c * 2, 1);
		G.add(v + n, u + n * 2, 0, 1);
		G.add(u, v + 2 * n, c, 1);
		G.add(v, u + 2 * n, c, 1);

		H.add(u, v, c);
		H.add(u + n, v + n, c);
		H.add(u + n * 2, v + n * 2, c);
		H.add(u, v + n, 0, 1);
		H.add(u + n, v + n * 2, c * 2, 1);
		H.add(v, u + n, 0, 1);
		H.add(v + n, u + n * 2, c * 2, 1);
		H.add(u, v + n * 2, c, 1);
		H.add(v, u + n * 2, c, 1);
	}

	auto dist = G.Dijkstra(0);
	auto dist2 = H.Dijkstra(0);

	V<ll> res;
	REPS(n - 1) { res.pb(min(dist[i + 2 * n], dist2[i + 2 * n])); }

	print(res);
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) main_();
	return 0;
}