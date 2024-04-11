/**
 *	author: nok0
 *	created: 2021.01.01 22:18:17
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

//ModInt
template <const int &mod>
struct ModInt {
private:
	int x;

public:
	ModInt() : x(0) {}

	ModInt(long long x_) {
		if((x = x_ % mod + mod) >= mod) x -= mod;
	}

	int val() const { return x; }

	static int get_mod() { return mod; }

	constexpr ModInt &operator+=(ModInt rhs) {
		if((x += rhs.x) >= mod) x -= mod;
		return *this;
	}

	constexpr ModInt &operator-=(ModInt rhs) {
		if((x -= rhs.x) < 0) x += mod;
		return *this;
	}

	constexpr ModInt &operator*=(ModInt rhs) {
		x = (unsigned long long)x * rhs.x % mod;
		return *this;
	}

	constexpr ModInt &operator/=(ModInt rhs) {
		x = (unsigned long long)x * rhs.inv().x % mod;
		return *this;
	}

	constexpr ModInt operator-() const noexcept { return -x < 0 ? mod - x : -x; }

	constexpr ModInt operator+(ModInt rhs) const noexcept { return ModInt(*this) += rhs; }

	constexpr ModInt operator-(ModInt rhs) const noexcept { return ModInt(*this) -= rhs; }

	constexpr ModInt operator*(ModInt rhs) const noexcept { return ModInt(*this) *= rhs; }

	constexpr ModInt operator/(ModInt rhs) const noexcept { return ModInt(*this) /= rhs; }

	constexpr ModInt &operator++() {
		*this += 1;
		return *this;
	}

	constexpr ModInt operator++(int) {
		*this += 1;
		return *this - 1;
	}

	constexpr ModInt &operator--() {
		*this -= 1;
		return *this;
	}

	constexpr ModInt operator--(int) {
		*this -= 1;
		return *this + 1;
	}

	bool operator==(ModInt rhs) const { return x == rhs.x; }

	bool operator!=(ModInt rhs) const { return x != rhs.x; }

	bool operator<=(ModInt rhs) const { return x <= rhs.x; }

	bool operator>=(ModInt rhs) const { return x >= rhs.x; }

	bool operator<(ModInt rhs) const { return x < rhs.x; }

	bool operator>(ModInt rhs) const { return x > rhs.x; }

	ModInt inv() {
		int a = x, b = mod, u = 1, v = 0, t;
		while(b > 0) {
			t = a / b;
			std::swap(a -= t * b, b);
			std::swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(long long n) const {
		ModInt ret(1), mul(x);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	ModInt sqrt() const {
		if(x <= 1) return x;
		int v = (mod - 1) / 2;
		if(pow(v) != 1) return -1;
		int q = mod - 1, m = 0;
		while(~q & 1) q >>= 1, m++;
		std::mt19937 mt;
		ModInt z = mt();
		while(z.pow(v) != mod - 1) z = mt();
		ModInt c = z.pow(q), t = pow(q), r = pow((q + 1) / 2);
		for(; m > 1; m--) {
			ModInt tmp = t.pow(1 << (m - 2));
			if(tmp != 1) r = r * c, t = t * c * c;
			c = c * c;
		}
		return std::min(r.x, mod - r.x);
	}

	friend std::ostream &operator<<(std::ostream &s, ModInt<mod> a) {
		s << a.x;
		return s;
	}

	friend std::istream &operator>>(std::istream &s, ModInt<mod> &a) {
		s >> a.x;
		return s;
	}
};
static int MOD = 998244353;
using mint = ModInt<MOD>;

const int CombMAX = 3000000;
mint fac[CombMAX + 1], finv[CombMAX + 1], inv[CombMAX + 1];

struct Combinationinit {
	Combinationinit() {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for(int i = 2; i <= CombMAX; i++) {
			fac[i] = fac[i - 1] * (mint)i;
			inv[i] = (mint)MOD - inv[MOD % i] * (MOD / i);
			finv[i] = finv[i - 1] * inv[i];
		}
	}
} Combinationinit_;

//nCk
mint COM(int n, int k) {
	if(n < k or n < 0 or k < 0) return 0;
	return fac[n] * finv[k] * finv[n - k];
}

mint bigCOM(int n, int k) {
	if(n < k or n < 0 or k < 0) return 0;
	mint res = 1;
	REPS(i, k) {
		res *= (n + 1 - i);
		res /= i;
	}
	return res;
}

int main() {
	INT(n);
	V<> l(n), r(n);
	mint res = 1, sum = 1;
	V<> pl;
	REP(i, n) {
		cin >> l[i] >> r[i];
		r[i]++;
		pl.pb(l[i]);
		pl.pb(r[i]);
		sum *= r[i] - l[i];
	}
	debug(sum);
	auto re = press(pl);
	int m = SZ(re);
	V<> interval(m - 1);
	REP(i, m - 1)
	interval[i] = re[i + 1] - re[i];
	res /= sum;

	VV<> can(n, V<>(m - 1));
	REP(i, n) {
		int ls = lower_bound(all(re), l[i]) - re.begin();
		int rs = lower_bound(all(re), r[i]) - re.begin();
		FOR(j, ls, rs)
		can[i][j] = 1;
	}

	vector dp(n + 1, vector(m, (mint)0));
	dp[0].back() = 1;
	REP(i, n) {
		REP(j, m - 1) {
			FOR(nx, i, n) {
				if(!can[nx][j]) break;
				mint sm = 0;
				FOR(k, j + 1, m) { sm += dp[i][k]; }
				dp[nx + 1][j] += sm * bigCOM(interval[j] + nx - i + 1 - 1, nx - i + 1);
			}
		}
	}
	mint SUM = accumulate(all(dp[n]), (mint)0);
	print(SUM * res);

	return 0;
}