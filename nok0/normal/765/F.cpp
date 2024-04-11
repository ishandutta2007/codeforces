#line 1 "f.cpp"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <array>
#include <cstdint>
#include <vector>

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
#line 9 "f.cpp"

namespace w_ary_tree_impl {
using u32 = uint32_t;
using u64 = uint64_t;
constexpr u32 ws = 64;
constexpr u32 calc_c(u32 n) {
	u32 ret = 1;
	while(n > 64) ret *= ws, n /= ws;
	return ret;
}
constexpr u32 ceil_div(u32 n, u32 k) {
	return (n + k - 1) / k;
}
u32 bsf(const u64 x) { return __builtin_ctzll(x); }
u32 bsr(const u64 x) { return 63 - __builtin_clzll(x); }
u64 to_bit(const u32 x) { return static_cast<u64>(1) << x; }

template <u32 N, class D = void>
struct w_ary_tree {
	static constexpr u32 C = calc_c(N);
	u64 map;
	std::array<w_ary_tree<C>, ceil_div(N, C)> child;

public:
	w_ary_tree() : map(0), child() {}

	bool insert(const u32 key) {
		const u32 pos = key / C;
		map |= to_bit(pos);
		return child[pos].insert(key % C);
	}

	bool erase(const u32 key) {
		const u32 pos = key / C;
		const bool ret = child[pos].erase(key % C);
		if(child[pos]._get_map() == 0) map ^= to_bit(pos);
		return ret;
	}

	bool contains(const u32 key) const {
		return child[key / C].contains(key % C);
	}

	u32 min() const {
		const u32 pos = bsf(map);
		return pos * C + child[pos].min();
	}

	u32 max() const {
		const u32 pos = bsr(map);
		return pos * C + child[pos].max();
	}

	u32 prev(const u32 key) const {
		const u32 pos = key / C;
		const u32 t = child[pos].prev(key % C);
		if(t != -1) return pos * C + t;
		const u64 masked = map & ~(~static_cast<u64>(0) << pos);
		if(masked) {
			const u32 pos2 = bsr(masked);
			return pos2 * C + child[pos2].max();
		} else
			return -1;
	}

	u32 next(const u32 key) const {
		const u32 pos = key / C;
		const u32 t = child[pos].next(key % C);
		if(t != -1) return pos * C + t;
		const u64 masked = map & ~(~static_cast<u64>(0) >> (63 - pos));
		if(masked) {
			const u32 pos2 = bsf(masked);
			return pos2 * C + child[pos2].min();
		} else
			return -1;
	}

	u64 _get_map() const { return map; }
};

template <u32 N>
struct w_ary_tree<N, typename std::enable_if<(N <= ws)>::type> {
	u64 map;

public:
	w_ary_tree() : map(0) {}

	bool insert(const u32 key) {
		const u64 bit = to_bit(key);
		if(map & bit)
			return false;
		else
			map |= bit;
		return true;
	}

	bool erase(const u32 key) {
		const u64 bit = to_bit(key);
		if(map & bit) {
			map ^= bit;
			return true;
		}
		return false;
	}

	bool contains(const u32 key) const {
		return map & to_bit(key);
	}

	u32 min() const { return bsf(map); }
	u32 max() const { return bsr(map); }

	u32 prev(const u32 key) const {
		const u64 masked = map & ~(~static_cast<u64>(0) << key);
		if(masked)
			return bsr(masked);
		else
			return -1;
	}

	u32 next(const u32 key) const {
		const u64 masked = map & (~static_cast<u64>(0) << key);
		if(masked)
			return bsf(masked);
		else
			return -1;
	}

	u64 _get_map() const { return map; }
};
}  // namespace w_ary_tree_impl

template <int N>
using w_ary_tree = w_ary_tree_impl::w_ary_tree<static_cast<uint32_t>(N)>;

void main_() {
	INT(N);
	const int n = N;
	VEC(int, a, n);
	V<> b(n), rec(n + 1);

	//press part
	{
		V<pii> ai(n);
		REP(i, n) { ai[i] = {a[i], i}; }
		SORT(ai);
		REP(i, n) {
			b[ai[i].second] = i + 1;
		}
		REP(i, n) {
			rec[b[i]] = a[i];
		}
	}

	w_ary_tree<100002> st;

	INT(q);
	VEC(pii, querys, q);
	for(auto &p : querys) p.first--;
	st.insert(0);
	st.insert(n + 1);
	V<> ans(q);
	int mn = inf, snap_min = inf;
	stack<int> history;
	auto add = [&](int i) {
		auto aft = st.next(b[i]);
		auto bef = st.prev(b[i]);
		if(aft <= n) chmin(mn, rec[aft] - a[i]);
		if(bef > 0) chmin(mn, a[i] - rec[bef]);
		st.insert(b[i]);
		history.push(b[i]);
	};
	auto exe = [&](int i) {
		ans[i] = mn;
	};
	auto snapshot = [&]() {
		snap_min = mn;
		history = {};
	};
	auto rollback = [&]() {
		mn = snap_min;
		while(!history.empty()) {
			st.erase(history.top());
			history.pop();
		}
	};
	auto reset = [&]() {
		mn = inf;
		history = {};
		st = w_ary_tree<100002>();
		st.insert(0);
		st.insert(n + 1);
	};
	const int width = sqrt(q);
	std::vector<int> lef, rig, order(q), chk(n);
	for(const auto &p : querys) {
		lef.emplace_back(p.first);
		rig.emplace_back(p.second);
	}

	auto compare = [&](const int a, const int b) {
		const int a_block = lef[a] / width, b_block = lef[b] / width;
		if(a_block != b_block) return a_block < b_block;
		return rig[a] < rig[b];
	};

	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), compare);

	for(auto idx : order) {
		if(rig[idx] - lef[idx] < width) {
			REP(i, lef[idx], rig[idx]) { add(i); }
			exe(idx);
			rollback();
		}
	}

	int nr = 0;
	int last_block = -1;

	for(auto idx : order) {
		if(rig[idx] - lef[idx] < width) continue;
		int block = lef[idx] / width;
		if(last_block != block) {
			reset();
			last_block = block;
			nr = (block + 1) * width;
		}
		while(nr < rig[idx]) add(nr++);
		snapshot();
		for(int j = (block + 1) * width - 1; j >= lef[idx]; j--) add(j);
		exe(idx);
		rollback();
	}

	printel(ans);
}