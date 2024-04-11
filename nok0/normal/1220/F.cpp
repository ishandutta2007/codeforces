/**
 *	author: nok0
 *	created: 2021.08.02 22:35:14
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
#if __has_include(<atcoder/all>)
std::istream &operator>>(std::istream &is, atcoder::modint998244353 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
std::istream &operator>>(std::istream &is, atcoder::modint1000000007 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::static_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
#endif
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
#if __has_include(<atcoder/all>)
std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &a) { return os << a.val(); }
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<m> &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::dynamic_modint<m> &a) { return os << a.val(); }
#endif
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

template <class Compare>
class rmq {
	using value_compare = Compare;
	static constexpr ::std::size_t BLOCKSIZE = 16;
	using block_type = ::std::uint_least16_t;
	static_assert(BLOCKSIZE <= ::std::numeric_limits<block_type>::digits, "");
	using size_type = ::std::size_t;

private:
	static size_type msb(size_type c) {
#ifdef __has_builtin
		return 31 - __builtin_clz(c);
#else
		::std::size_t ret = 0;
		if(c >> 8)
			c >>= 8, ret += 8;
		if(c >> 4)
			c >>= 4, ret += 4;
		if(c >> 2)
			c >>= 2, ret += 2;
		return ret + (c >> 1);
#endif
	}
	static size_type ctz(const block_type c) {
#ifdef __has_builtin
		return __builtin_ctz(c);
#else
		static const ::std::array<size_type, 16> table = {
		    0, 1, 2, 5, 3, 9, 6, 11, 15, 4, 8, 10, 14, 7, 13, 12};
		return table[(c & ~c + 1) * 0x9AFU >> 12 & 0xF];
#endif
	}

	value_compare comp;
	::std::vector<block_type> small;
	::std::vector<::std::vector<size_type>> large;

	size_type get_min(const size_type left, const size_type right) const {
		return comp(left, right) ? left : right;
	}

public:
	rmq() : comp(), small(), large() {}
	explicit rmq(const size_type size, const value_compare &x)
	  : comp(x), small(), large() {
		::std::vector<size_type> st;
		st.reserve(BLOCKSIZE);
		large.emplace_back();
		large.front().reserve(size / BLOCKSIZE);
		small.reserve(size);
		for(size_type i = 0; i < size; ++i) {
			while(!st.empty() && !comp(st.back(), i))
				st.pop_back();
			small.emplace_back(st.empty() ? 0 : small[st.back()]);
			small.back() |= static_cast<block_type>(1) << (i % BLOCKSIZE);
			st.emplace_back(i);
			if(!((i + 1) % BLOCKSIZE)) {
				large.front().emplace_back(st.front());
				st.clear();
			}
		}
		for(size_type i = 1; i << 1 <= size / BLOCKSIZE; i <<= 1) {
			::std::vector<size_type> v;
			const size_type csz = size / BLOCKSIZE + 1 - (i << 1);
			v.reserve(csz);
			for(size_type k = 0; k < csz; ++k)
				v.emplace_back(get_min(large.back()[k], large.back()[k + i]));
			large.emplace_back(::std::move(v));
		}
	}

	size_type size() const { return small.size(); }

	size_type fold_closed(const size_type first, const size_type last) const {
		assert(first <= last);
		assert(last < size());

		const size_type left = first / BLOCKSIZE + 1;
		const size_type right = last / BLOCKSIZE;
		if(left < right) {
			const size_type p = msb(right - left);
			return get_min(
			    get_min((left - 1) * BLOCKSIZE +
			                ctz(small[left * BLOCKSIZE - 1] &
			                    ~static_cast<block_type>(0) << first % BLOCKSIZE),
			            large[p][left]),
			    get_min(large[p][right - (static_cast<size_type>(1) << p)],
			            right * BLOCKSIZE + ctz(small[last])));
		} else if(left == right) {
			return get_min((left - 1) * BLOCKSIZE +
			                   ctz(small[left * BLOCKSIZE - 1] &
			                       ~static_cast<block_type>(0) << first % BLOCKSIZE),
			               left * BLOCKSIZE + ctz(small[last]));
		} else {
			return right * BLOCKSIZE + ctz(small[last] & ~static_cast<block_type>(0)
			                                                 << first % BLOCKSIZE);
		}
	}
};

template <class Compare>
rmq<Compare> make_rmq(const ::std::size_t size, const Compare &x) {
	return rmq<Compare>(size, x);
}

using uint = unsigned int;

struct xorshift {
	using u32 = uint32_t;
	u32 x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	xorshift(u32 seed = 0) { z ^= seed; }
	u32 operator()() {
		u32 t = x ^ (x << 11);
		x = y;
		y = z;
		z = w;
		return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	}
};
xorshift rnd;

void main_() {
	INT(n);
	VEC(int, a, n);
	SUB(a);
	int zp = find(all(a), 0) - a.begin();
	int res = inf, ans = -1;
	unordered_set<int> st;
	clock_t start = clock();
	REP(_, 100) {
		int k = n / 2 - 50 + _;
		if(k < 0 or k >= n) continue;
		st.insert(k);
		auto c = a;
		rotate(c.begin(), c.begin() + (zp - k + n) % n, c.end());
		auto seq = make_rmq(n, [&c](const uint l, const uint r) { return c[l] <= c[r]; });
		auto depth = [&](auto depth, int l, int r) {
			if(r - l == 1) return 1;
			if(l >= r) return 0;
			auto p = seq.fold_closed(l, r - 1);
			return 1 + max(depth(depth, l, p), depth(depth, p + 1, r));
		};
		if(chmin(res, depth(depth, 0, n))) {
			ans = (zp - k + n) % n;
		}
	}
	while(clock() - start < 1950 and SZ(st) < n) {
		int k = 0;
		while(st.count(k)) k = rnd() % n;
		st.insert(k);
		auto c = a;
		rotate(c.begin(), c.begin() + (zp - k + n) % n, c.end());
		assert(c[k] == 0);
		auto seq = make_rmq(n, [&c](const uint l, const uint r) { return c[l] <= c[r]; });
		auto depth = [&](auto depth, int l, int r) {
			if(l >= r) return 0;
			auto p = seq.fold_closed(l, r - 1);
			return 1 + max(depth(depth, l, p), depth(depth, p + 1, r));
		};
		if(chmin(res, depth(depth, 0, n))) {
			ans = (zp - k + n) % n;
		}
	}
	assert(ans != -1);
	print(res, ans);
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) main_();
	return 0;
}