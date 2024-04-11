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
std::vector<int> iota(int n) {
	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	return p;
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
		T mid = (ok + ng) >> 1;
		(f(mid) ? ok : ng) = mid;
	}
	return ok;
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
#line 7 "/Users/nok0/Documents/Programming/nok0/graph/mincost_b_flow.hpp"

enum Objective {
	MINIMIZE = 1,
	MAXIMIZE = -1,
};
enum class Status {
	OPTIMAL,
	INFEASIBLE,
};

template <class Flow, class Cost, Objective objective = Objective::MINIMIZE, Flow SCALING_FACTOR = 2>
struct MinCostFlow {
private:
	using V_id = uint32_t;
	using E_id = uint32_t;

	struct Edge {
		friend struct MinCostFlow;

	private:
		V_id src, dst;
		Flow flow, cap;
		Cost cost;
		E_id rev;

	public:
		Edge() = default;

		Edge(const V_id src, const V_id dst, const Flow cap, const Cost cost,
		     const E_id rev)
		  : src(src), dst(dst), flow(0), cap(cap), cost(cost), rev(rev) {}

		[[nodiscard]] Flow residual_cap() const { return cap - flow; }
	};

public:
	struct EdgePtr {
		friend struct MinCostFlow;

	private:
		const MinCostFlow *instance;
		const V_id v;
		const E_id e;

		EdgePtr(const MinCostFlow *instance, const V_id v, const E_id e)
		  : instance(instance), v(v), e(e) {}

		[[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }

		[[nodiscard]] const Edge &rev() const {
			const Edge &e = edge();
			return instance->g[e.dst][e.rev];
		}

	public:
		[[nodiscard]] V_id src() const { return rev().dst; }

		[[nodiscard]] V_id dst() const { return edge().dst; }

		[[nodiscard]] Flow flow() const { return edge().flow; }

		[[nodiscard]] Flow lower() const { return -rev().cap; }

		[[nodiscard]] Flow upper() const { return edge().cap; }

		[[nodiscard]] Cost cost() const { return edge().cost; }

		[[nodiscard]] Cost gain() const { return -edge().cost; }
	};

private:
	V_id n;
	std::vector<std::vector<Edge>> g;
	std::vector<Flow> b;

public:
	MinCostFlow() : n(0) {}

	V_id add_vertex() {
		++n;
		g.resize(n);
		b.resize(n);
		return n - 1;
	}

	std::vector<V_id> add_vertices(const size_t size) {
		std::vector<V_id> ret;
		for(V_id i = 0; i < size; ++i) ret.emplace_back(n + i);
		n += size;
		g.resize(n);
		b.resize(n);
		return ret;
	}

	EdgePtr add_edge(const V_id src, const V_id dst, const Flow lower, const Flow upper, const Cost cost) {
		const E_id e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();
		assert(lower <= upper);
		g[src].emplace_back(Edge{src, dst, upper, cost * objective, re});
		g[dst].emplace_back(Edge{dst, src, -lower, -cost * objective, e});
		return EdgePtr{this, src, e};
	}

	void add_supply(const V_id v, const Flow amount) { b[v] += amount; }

	void add_demand(const V_id v, const Flow amount) { b[v] -= amount; }

private:
	static Cost constexpr unreachable = std::numeric_limits<Cost>::max();
	Cost farthest;
	std::vector<Cost> potential;
	std::vector<Cost> dist;
	std::vector<Edge *> parent;
	std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int>>, std::greater<>> pq;
	std::vector<V_id> excess_vs, deficit_vs;

	Edge &rev(const Edge &e) { return g[e.dst][e.rev]; }

	void push(Edge &e, const Flow amount) {
		e.flow += amount;
		g[e.dst][e.rev].flow -= amount;
	}

	Cost residual_cost(const V_id src, const V_id dst, const Edge &e) {
		return e.cost + potential[src] - potential[dst];
	}

	bool dual(const Flow delta) {
		dist.assign(n, unreachable);
		parent.assign(n, nullptr);
		excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs), [&](const V_id v) { return b[v] < delta; }), std::end(excess_vs));
		deficit_vs.erase(std::remove_if(std::begin(deficit_vs), std::end(deficit_vs), [&](const V_id v) { return b[v] > -delta; }), std::end(deficit_vs));
		for(const auto v : excess_vs) pq.emplace(dist[v] = 0, v);
		farthest = 0;
		std::size_t deficit_count = 0;
		while(!pq.empty()) {
			const auto [d, u] = pq.top();
			pq.pop();
			if(dist[u] < d) continue;
			farthest = d;
			if(b[u] <= -delta) ++deficit_count;
			if(deficit_count >= deficit_vs.size()) break;
			for(auto &e : g[u]) {
				if(e.residual_cap() < delta) continue;
				const auto v = e.dst;
				const auto new_dist = d + residual_cost(u, v, e);
				if(new_dist >= dist[v]) continue;
				pq.emplace(dist[v] = new_dist, v);
				parent[v] = &e;
			}
		}
		pq = decltype(pq)();
		for(V_id v = 0; v < n; ++v) {
			potential[v] += std::min(dist[v], farthest);
		}
		return deficit_count > 0;
	}

	void primal(const Flow delta) {
		for(const auto t : deficit_vs) {
			if(dist[t] > farthest) continue;
			Flow f = -b[t];
			V_id v;
			for(v = t; parent[v] != nullptr && f >= delta; v = parent[v]->src) {
				f = std::min(f, parent[v]->residual_cap());
			}
			f = std::min(f, b[v]);
			if(f < delta) continue;
			for(v = t; parent[v] != nullptr;) {
				auto &e = *parent[v];
				push(e, f);
				const size_t u = parent[v]->src;
				parent[v] = nullptr;
				v = u;
			}
			b[t] += f;
			b[v] -= f;
		}
	}

	void saturate_negative(const Flow delta) {
		excess_vs.clear();
		deficit_vs.clear();
		for(auto &es : g)
			for(auto &e : es) {
				const Flow rcap = e.residual_cap();
				const Cost rcost = residual_cost(e.src, e.dst, e);
				if(rcost < 0 && rcap >= delta) {
					push(e, rcap);
					b[e.src] -= rcap;
					b[e.dst] += rcap;
				}
			}
		for(V_id v = 0; v < n; ++v)
			if(b[v] != 0) {
				(b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);
			}
	}

public:
	std::pair<Status, Cost> solve() {
		potential.resize(n);
		for(auto &es : g)
			for(auto &e : es) {
				const Flow rcap = e.residual_cap();
				if(rcap < 0) {
					push(e, rcap);
					b[e.src] -= rcap;
					b[e.dst] += rcap;
				}
			}

		Flow inf_flow = 1;
		for(const auto &es : g)
			for(const auto &e : es) inf_flow = std::max(inf_flow, e.residual_cap());
		Flow delta = 1;
		while(delta <= inf_flow) delta *= SCALING_FACTOR;

		for(delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {
			saturate_negative(delta);
			while(dual(delta)) primal(delta);
		}

		Cost value = 0;
		for(const auto &es : g)
			for(const auto &e : es) {
				value += e.flow * e.cost;
			}
		value /= 2;

		if(excess_vs.empty() && deficit_vs.empty()) {
			return {Status::OPTIMAL, value / objective};
		} else {
			return {Status::INFEASIBLE, value / objective};
		}
	}
};

template <class Flow, class Cost>
using MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;
#line 3 "e.cpp"

void main_() {
	INT(n, a, b);
	MaxGainFlow<int16_t, ll> mgf;
	auto sa = mgf.add_vertex();
	mgf.add_supply(sa, a);
	auto sb = mgf.add_vertex();
	mgf.add_supply(sb, b);
	auto t = mgf.add_vertex();
	mgf.add_demand(t, a + b);
	VEC(float, tp, n);
	VEC(float, tu, n);
	V<> p(n),u(n);
	REP(i,n) p[i] = tp[i] * 1000, u[i] = tu[i] * 1000;
	auto ver = mgf.add_vertices(n);
	REP(i, n) {
		mgf.add_edge(sa, ver[i], 0, 1, p[i] * 1000);
		mgf.add_edge(sb, ver[i], 0, 1, u[i] * 1000);
		mgf.add_edge(ver[i], t, 0, 1, 0);
		mgf.add_edge(ver[i], t, 0, 1, -p[i] * u[i]);
	}
	print((double)mgf.solve().second / 1000000);
}