#line 1 "/Users/nok0/Documents/Programming/nok0/cftemp.hpp"
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
void ADD(std::vector<T> &a, const T x = 1) {
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
std::vector<std::pair<char, int>> rle(const string &s) {
	int n = s.size();
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

void main_();

int main() {
	main_();
	return 0;
}
#line 2 "e.cpp"

#pragma region Flow Project Selection Problem
template <typename flow_t>
struct Dinic {
private:
	const flow_t INF;
	struct edge {
		int to;
		flow_t cap;
		int rev;
		bool isrev;
		int idx;
	};
	std::vector<std::vector<edge>> graph;
	std::vector<int> min_cost, iter;

	bool bfs(int s, int t) {
		min_cost.assign(graph.size(), -1);
		std::queue<int> que;
		min_cost[s] = 0;
		que.push(s);
		while(!que.empty() and min_cost[t] == -1) {
			int p = que.front();
			que.pop();
			for(auto &e : graph[p]) {
				if(e.cap > 0 and min_cost[e.to] == -1) {
					min_cost[e.to] = min_cost[p] + 1;
					que.push(e.to);
				}
			}
		}
		return min_cost[t] != -1;
	}

	flow_t dfs(int idx, const int t, flow_t flow) {
		if(idx == t) return flow;
		for(int &i = iter[idx]; i < SZ(graph[idx]); i++) {
			edge &e = graph[idx][i];
			if(e.cap > 0 and min_cost[idx] < min_cost[e.to]) {
				flow_t d = dfs(e.to, t, min(flow, e.cap));
				if(d > 0) {
					e.cap -= d;
					graph[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	Dinic(int v = 0) : INF(std::numeric_limits<flow_t>::max()), graph(v) {}

	void add_edge(int from, int to, flow_t cap, int idx = -1) {
		graph[from].emplace_back(edge{to, cap, int(graph[to].size()), false, idx});
		graph[to].emplace_back(edge{from, 0, int(graph[from].size()) - 1, true, idx});
	}

	flow_t max_flow(int s, int t) {
		flow_t flow = 0;
		while(bfs(s, t)) {
			iter.assign(graph.size(), 0);
			flow_t f = 0;
			while((f = dfs(s, t, INF)) > 0) flow += f;
		}
		return flow;
	}

	void output() {
		for(int i = 0; i < (int)graph.size(); i++) {
			for(auto &e : graph[i]) {
				if(e.isrev) continue;
				auto &rev_e = graph[e.to][e.rev];
				std::cout << i << "->" << e.to << " (flow:" << rev_e.cap << "/" << e.cap + rev_e.cap << ")\n";
			}
		}
	}

	void resize(int x) { graph.resize(x); }

	int size() { return graph.size(); }
};

template <typename T>
struct ProjectSelectionProblem {
private:
	int n;
	const T INF;
	T res = 0;
	Dinic<T> dinic;

public:
	ProjectSelectionProblem(int n_) : n(n_), INF(std::numeric_limits<T>::max()), dinic(n + 2) {}

	void x_and_noty_loss(int x, int y, T loss) {
		assert(loss >= 0);
		dinic.add_edge(x, y, loss);
	}

	void x_xor_y_loss(int x, int y, T loss) {
		x_and_noty_loss(x, y, loss);
		x_and_noty_loss(y, x, loss);
	}

	void x_get(int x, T get) {
		if(get < 0) {
			dinic.add_edge(x, n + 1, -get);
			return;
		}
		res += get;
		notx_loss(x, get);
	}

	void x_loss(int x, T loss) {
		if(loss < 0) {
			x_get(x, -loss);
			return;
		}
		dinic.add_edge(x, n + 1, loss);
	}

	void notx_get(int x, T get) {
		if(get < 0) {
			dinic.add_edge(n, x, -get);
			return;
		}
		res += get;
		x_loss(x, get);
	}

	void notx_loss(int x, T loss) {
		if(loss < 0) {
			notx_get(x, -loss);
			return;
		}
		dinic.add_edge(n, x, loss);
	}

	void x_and_y_get(int x, int y, T get) {
		assert(get >= 0);
		res += get;
		dinic.resize(dinic.size() + 1);
		int w = dinic.size() - 1;
		dinic.add_edge(n, w, get);
		dinic.add_edge(w, x, INF);
		dinic.add_edge(w, y, INF);
	}

	void x_nor_y_get(int x, int y, T get) {
		assert(get >= 0);
		res += get;
		dinic.resize(dinic.size() + 1);
		int w = dinic.size() - 1;
		dinic.add_edge(w, n + 1, get);
		dinic.add_edge(x, w, INF);
		dinic.add_edge(y, w, INF);
	}

	void x_equal_y_get(int x, int y, T get) {
		x_and_y_get(x, y, get);
		x_nor_y_get(x, y, get);
	}

	T min_lost() {
		return dinic.max_flow(n, n + 1) - res;
	}

	T max_profit() {
		return -min_lost();
	}
};
#pragma endregion

struct S {
	int u, d, l, r;
	S(int u, int d, int l, int r) : u(u), d(d), l(l), r(r) {}
};

void main_() {
	INT(n, m);
	if(!m) {
		print(0);
		return;
	}
	V<S> recs;
	V<> xp, yp;
	REP(i, m) {
		INT(u, l, d, r);
		++d, ++r;
		xp.pb(u);
		xp.pb(d);
		yp.pb(l);
		yp.pb(r);
		recs.eb(u, d, l, r);
	}
	auto rex = press(xp);
	auto rey = press(yp);
	int H = SZ(rex) - 1, W = SZ(rey) - 1;
	V<> len_h(H), len_w(W);
	REP(i, H) { len_h[i] = rex[i + 1] - rex[i]; }
	REP(i, W) { len_w[i] = rey[i + 1] - rey[i]; }
	VV<> board(H, V<>(W));
	foa(rec, recs) {
		REP(i, lb(rex, rec.u), lb(rex, rec.d)) {
			REP(j, lb(rey, rec.l), lb(rey, rec.r)) {
				board[i][j] = 1;
			}
		}
	}
	//true true
	ProjectSelectionProblem<int> psp(H + W);
	REP(i, H) {
		psp.x_loss(i, len_h[i]);
	}
	REP(j, W) {
		psp.notx_loss(H + j, len_w[j]);
	}
	REP(i, H) {
		REP(j, W) {
			if(board[i][j]) {
				psp.x_and_noty_loss(H + j, i, inf);
			}
		}
	}
	print(psp.min_lost());
}