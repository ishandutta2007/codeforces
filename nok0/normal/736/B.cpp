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
#line 2 "/Users/nok0/Documents/Programming/nok0/math/factorize.hpp"

namespace inner {
using u32 = uint32_t;
using u64 = uint64_t;
using i64 = int64_t;
using u128 = __uint128_t;

u64 gcd_impl(u64 n, u64 m) {
	constexpr u64 K = 5;
	for(u32 i = 0; i < 80; ++i) {
		u64 t = n - m;
		u64 s = n - m * K;
		bool q = t < m;
		bool p = t < m * K;
		n = q ? m : t;
		m = q ? t : m;
		if(m == 0) return n;
		n = p ? n : s;
	}
	return gcd_impl(m, n % m);
}

u64 gcd_pre(u64 n, u64 m) {
	for(u32 i = 0; i < 4; ++i) {
		u64 t = n - m;
		bool q = t < m;
		n = q ? m : t;
		m = q ? t : m;
		if(m == 0) return n;
	}
	return gcd_impl(n, m);
}

u64 gcd_fast(u64 n, u64 m) { return n > m ? gcd_pre(n, m) : gcd_pre(m, n); }

struct modint64 {
	using u64 = uint64_t;

public:
	static u64 mod;
	static u64 r, n2;
	static void set_mod(u64 m) {
		mod = m;
		n2 = -u128(m) % m;
		r = get_r();
		assert(r * mod == 1);
	}
	modint64() : a(0) {}
	modint64(const i64 &b) : a(reduce((u128(b) + mod) * n2)) {}

	modint64 &operator+=(const modint64 &b) {
		if(i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
		return *this;
	}

	modint64 &operator-=(const modint64 &b) {
		if(i64(a -= b.a) < 0) a += 2 * mod;
		return *this;
	}

	modint64 &operator*=(const modint64 &b) {
		a = reduce(u128(a) * b.a);
		return *this;
	}

	modint64 operator+(const modint64 &b) const { return modint64(*this) += b; }
	modint64 operator-(const modint64 &b) const { return modint64(*this) -= b; }
	modint64 operator*(const modint64 &b) const { return modint64(*this) *= b; }

	modint64 pow(u128 n) const {
		modint64 ret(1), mul(*this);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	u64 val() const {
		u64 ret = reduce(a);
		return ret >= mod ? ret - mod : ret;
	}

	static u64 get_mod() { return mod; }

private:
	u64 a;

	static u64 get_r() {
		u64 ret = mod;
		for(u32 i = 0; i < 5; i++) ret *= 2 - mod * ret;
		return ret;
	}

	static u64 reduce(const u128 &b) {
		return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
	}
};
typename modint64::u64 modint64::mod, modint64::r, modint64::n2;

u64 rnd() {
	static u64 x = 10150724397891781847ull;
	x ^= x << 7;
	return x ^= x >> 9;
}

constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) x += m;
	return x;
}

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while(n) {
		if(n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

bool is_prime(const u64 n) {
	if(~n & 1) return n == 2;
	if(n < (1ll << 30)) {
		if(n <= 1) return false;
		if(n == 2 || n == 7 || n == 61) return true;
		if(n % 2 == 0) return false;
		long long d = n - 1;
		while(d % 2 == 0) d /= 2;
		constexpr long long bases[3] = {2, 7, 61};
		for(long long a : bases) {
			long long t = d;
			long long y = pow_mod_constexpr(a, t, n);
			while(t != n - 1 && y != 1 && y != n - 1) {
				y = y * y % n;
				t <<= 1;
			}
			if(y != n - 1 && t % 2 == 0) {
				return false;
			}
		}
		return true;
	}
	u64 d = n - 1;
	while(~d & 1) d >>= 1;
	if(modint64::get_mod() != n) modint64::set_mod(n);
	for(const u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if(n <= a) break;
		modint64 t = d, y = modint64(a).pow(d);
		while(t.val() != n - 1 and y.val() != 1 and y.val() != n - 1) {
			y *= y;
			t *= 2;
		}
		if(y.val() != n - 1 and ~t.val() & 1) return false;
	}
	return true;
}

u64 pollard_rho(const u64 n) {
	if(~n & 1) return 2;
	if(is_prime(n)) return n;
	if(modint64::get_mod() != n) modint64::set_mod(n);
	modint64 R, one = 1;
	auto f = [&](modint64 x) { return x * x + R; };
	auto rng = [&]() { return rnd() % (n - 2) + 2; };
	for(;;) {
		modint64 x, y(rng()), ys, q = one;
		R = rng();
		u64 g = 1;
		constexpr u32 m = 128;
		for(u32 r = 1; g == 1; r <<= 1) {
			x = y;
			for(u32 i = 0; i < r; i++) y = f(y);
			for(u32 k = 0; g == 1 and k < r; k += m) {
				ys = y;
				for(u32 i = 0; i < m and i < r - k; i++) q *= x - (y = f(y));
				g = gcd_fast(q.val(), n);
			}
		}
		if(g == n) do
				g = gcd_fast((x - (ys = f(ys))).val(), n);
			while(g == 1);
		if(g != n) return g;
	}
	exit(1);
}

std::vector<u64> factorize(const u64 n) {
	if(n == 1) return {};
	if(is_prime(n)) return {n};
	auto d = pollard_rho(n);
	auto res = factorize(d);
	auto sub = factorize(n / d);
	std::copy(sub.begin(), sub.end(), std::back_inserter(res));
	return res;
}

};  // namespace inner
using inner::is_prime;

template <typename T>
std::vector<T> factorize(const T n) {
	auto tmp = inner::factorize(n);
	std::vector<T> res{tmp.begin(), tmp.end()};
	std::sort(res.begin(), res.end());
	return res;
}

template <typename T>
std::vector<std::pair<T, int>> pair_factorize(const T n) {
	std::vector<std::pair<T, int>> res;
	auto tmp = factorize(n);
	if(tmp.empty()) return {};
	T now = tmp.front();
	int cnt = 0;
	for(auto &v : tmp) {
		if(now == v)
			cnt++;
		else {
			res.emplace_back(now, cnt);
			now = v;
			cnt = 1;
		}
	}
	res.emplace_back(now, cnt);
	return res;
}
#line 3 "b.cpp"

void main_() {
	INT(n);
	if(is_prime(n)) {
		print(1);
		return;
	}
	if(n % 2 == 0 or is_prime(n - 2)) {
		print(2);
	} else
		print(3);
}