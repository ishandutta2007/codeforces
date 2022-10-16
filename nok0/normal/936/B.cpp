/**
 *	author: nok0
 *	created: 2021.08.11 20:59:08
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

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
#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
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
using int128 = __int128_t;
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
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
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
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
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
void NO() { std::cout << "NO\n"; }
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

namespace atcoder {
namespace internal {

template <class E>
struct csr {
	std::vector<int> start;
	std::vector<E> elist;
	explicit csr(int n, const std::vector<std::pair<int, E>> &edges)
	  : start(n + 1), elist(edges.size()) {
		for(auto e : edges) {
			start[e.first + 1]++;
		}
		for(int i = 1; i <= n; i++) {
			start[i] += start[i - 1];
		}
		auto counter = start;
		for(auto e : edges) {
			elist[counter[e.first]++] = e.second;
		}
	}
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {
namespace internal {

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
public:
	explicit scc_graph(int n) : _n(n) {}

	int num_vertices() { return _n; }

	void add_edge(int from, int to) { edges.push_back({from, {to}}); }

	// @return pair of (# of scc, scc id)
	std::pair<int, std::vector<int>> scc_ids() {
		auto g = csr<edge>(_n, edges);
		int now_ord = 0, group_num = 0;
		std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
		visited.reserve(_n);
		auto dfs = [&](auto self, int v) -> void {
			low[v] = ord[v] = now_ord++;
			visited.push_back(v);
			for(int i = g.start[v]; i < g.start[v + 1]; i++) {
				auto to = g.elist[i].to;
				if(ord[to] == -1) {
					self(self, to);
					low[v] = std::min(low[v], low[to]);
				} else {
					low[v] = std::min(low[v], ord[to]);
				}
			}
			if(low[v] == ord[v]) {
				while(true) {
					int u = visited.back();
					visited.pop_back();
					ord[u] = _n;
					ids[u] = group_num;
					if(u == v) break;
				}
				group_num++;
			}
		};
		for(int i = 0; i < _n; i++) {
			if(ord[i] == -1) dfs(dfs, i);
		}
		for(auto &x : ids) {
			x = group_num - 1 - x;
		}
		return {group_num, ids};
	}

	std::vector<std::vector<int>> scc() {
		auto ids = scc_ids();
		int group_num = ids.first;
		std::vector<int> counts(group_num);
		for(auto x : ids.second) counts[x]++;
		std::vector<std::vector<int>> groups(ids.first);
		for(int i = 0; i < group_num; i++) {
			groups[i].reserve(counts[i]);
		}
		for(int i = 0; i < _n; i++) {
			groups[ids.second[i]].push_back(i);
		}
		return groups;
	}

private:
	int _n;
	struct edge {
		int to;
	};
	std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

struct scc_graph {
public:
	scc_graph() : internal(0) {}
	explicit scc_graph(int n) : internal(n) {}

	void add_edge(int from, int to) {
		int n = internal.num_vertices();
		assert(0 <= from && from < n);
		assert(0 <= to && to < n);
		internal.add_edge(from, to);
	}

	std::vector<std::vector<int>> scc() { return internal.scc(); }

private:
	internal::scc_graph internal;
};

}  // namespace atcoder

using scc = atcoder::scc_graph;
using graph = vector<vector<int>>;

bool eop[100000][2], vis[100000], has_draw[100000];
bool vis2[100000][2];
void main_() {
	INT(n, m);
	graph G(n), rG(n), ex_graph(n * 2);
	scc sg(n);
	V<pii> es;
	REP(u, n) {
		INT(k);
		while(k--) {
			INT(v);
			--v;
			es.eb(u, v);
			sg.add_edge(u, v);
			G[u].pb(v);
			rG[v].pb(u);
		}
	}
	INT(s);
	--s;
	REP(i, n) {
		REP(j, 2) { eop[i][j] = vis[i] = has_draw[i] = 0; }
	}
	REP(i, n) {
		if(SZ(G[i]) == 0) {
			auto dfs = [&](auto dfs, int now, bool odd) -> void {
				if(eop[now][odd]) return;
				eop[now][odd] = 1;
				for(auto to : rG[now]) {
					ex_graph[to].pb(now + n);
					ex_graph[to + n].pb(now);
					dfs(dfs, to, !odd);
				}
			};
			dfs(dfs, i, 0);
		}
	}

	if(eop[s][1]) {
		print("Win");
		queue<int> que;
		que.push(s);
		V<> dist(2 * n, inf), bef(2 * n);
		bef[s] = -1;
		dist[s] = 0;
		while(que.size()) {
			int now = que.front();
			que.pop();
			for(auto to : ex_graph[now]) {
				if(dist[to] != inf) continue;
				dist[to] = dist[now] + 1;
				que.push(to);
				bef[to] = now;
			}
		}
		REP(i, n) {
			if(dist[i + n] != inf and SZ(G[i]) == 0) {
				V<> res{i};
				int now = i + n;
				while(bef[now] != -1) {
					now = bef[now];
					res.pb(now % n);
				}
				reverse(all(res));
				ADD(res, 1);
				print(res);
				return;
			}
		}
	}

	auto vec = sg.scc();
	int N = vec.size();
	V<> cnt(N);
	V<> id(n);
	REP(i, N) {
		cnt[i] = SZ(vec[i]);
		foa(v, vec[i]) id[v] = i;
	}

	graph sG(N);
	for(auto [u, v] : es) {
		if(id[u] != id[v]) {
			sG[id[u]].pb(id[v]);
		}
	}

	auto dfs = [&](auto dfs, int now) -> void {
		if(vis[now]) return;
		vis[now] = 1;
		if(cnt[now] > 1) has_draw[now] = 1;
		for(auto to : sG[now]) {
			dfs(dfs, to);
			has_draw[now] |= has_draw[to];
		}
	};

	int r = id[s];
	dfs(dfs, r);
	if(has_draw[r]) {
		print("Draw");
		return;
	}
	print("Lose");
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) main_();
	return 0;
}