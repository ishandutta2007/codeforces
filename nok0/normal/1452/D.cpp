/**
 *	author: nok0
 *	created: 2020.11.19 23:44:02
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

//Modulo Calculation
static int MOD = 998244353;
using mint = ModInt<MOD>;

struct NumberTheoreticTransformFriendlyModInt {
	std::vector<mint> dw, idw;
	int max_base;
	mint root;

	NumberTheoreticTransformFriendlyModInt() {
		const unsigned mod = mint::get_mod();
		assert(mod >= 3 && mod % 2 == 1);
		auto tmp = mod - 1;
		max_base = 0;
		while(tmp % 2 == 0) tmp >>= 1, max_base++;
		root = 2;
		while(root.pow((mod - 1) >> 1) == 1) root += 1;
		assert(root.pow(mod - 1) == 1);
		dw.resize(max_base);
		idw.resize(max_base);
		for(int i = 0; i < max_base; i++) {
			dw[i] = -root.pow((mod - 1) >> (i + 2));
			idw[i] = mint(1) / dw[i];
		}
	}

	void ntt(std::vector<mint> &a) {
		const int n = (int)a.size();
		assert((n & (n - 1)) == 0);
		assert(__builtin_ctz(n) <= max_base);
		for(int m = n; m >>= 1;) {
			mint w = 1;
			for(int s = 0, k = 0; s < n; s += 2 * m) {
				for(int i = s, j = s + m; i < s + m; ++i, ++j) {
					mint x = a[i], y = a[j] * w;
					a[i] = x + y, a[j] = x - y;
				}
				w *= dw[__builtin_ctz(++k)];
			}
		}
	}

	void intt(std::vector<mint> &a, bool f = true) {
		const int n = (int)a.size();
		assert((n & (n - 1)) == 0);
		assert(__builtin_ctz(n) <= max_base);
		for(int m = 1; m < n; m *= 2) {
			mint w = 1;
			for(int s = 0, k = 0; s < n; s += 2 * m) {
				for(int i = s, j = s + m; i < s + m; ++i, ++j) {
					mint x = a[i], y = a[j];
					a[i] = x + y, a[j] = (x - y) * w;
				}
				w *= idw[__builtin_ctz(++k)];
			}
		}
		if(f) {
			mint inv_sz = mint(1) / n;
			for(int i = 0; i < n; i++) a[i] *= inv_sz;
		}
	}

	std::vector<mint> multiply(std::vector<mint> a, std::vector<mint> b) {
		int need = a.size() + b.size() - 1;
		int nbase = 1;
		while((1 << nbase) < need) nbase++;
		int sz = 1 << nbase;
		a.resize(sz, 0);
		b.resize(sz, 0);
		ntt(a);
		ntt(b);
		mint inv_sz = mint(1) / sz;
		for(int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;
		intt(a, false);
		a.resize(need);
		return a;
	}
};

struct FormalPowerSeries : std::vector<mint> {
	using std::vector<mint>::vector;
	using P = FormalPowerSeries;

	using MULT = std::function<P(P, P)>;
	using FFT = std::function<void(P &)>;
	using SQRT = std::function<mint(mint)>;

	static MULT &get_mult() {
		static MULT mult = nullptr;
		return mult;
	}

	static void set_mult(MULT f) {
		get_mult() = f;
	}

	static FFT &get_fft() {
		static FFT fft = nullptr;
		return fft;
	}

	static FFT &get_ifft() {
		static FFT ifft = nullptr;
		return ifft;
	}

	static void set_fft(FFT f, FFT g) {
		get_fft() = f;
		get_ifft() = g;
	}

	static SQRT &get_sqrt() {
		static SQRT sqr = nullptr;
		return sqr;
	}

	static void set_sqrt(SQRT sqr) {
		get_sqrt() = sqr;
	}

	void shrink() {
		while(this->size() && this->back() == mint(0)) this->pop_back();
	}

	P operator+(const P &r) const { return P(*this) += r; }

	P operator+(const mint &v) const { return P(*this) += v; }

	P operator-(const P &r) const { return P(*this) -= r; }

	P operator-(const mint &v) const { return P(*this) -= v; }

	P operator*(const P &r) const { return P(*this) *= r; }

	P operator*(const mint &v) const { return P(*this) *= v; }

	P operator/(const P &r) const { return P(*this) /= r; }

	P operator%(const P &r) const { return P(*this) %= r; }

	P &operator+=(const P &r) {
		if(r.size() > this->size()) this->resize(r.size());
		for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
		return *this;
	}

	P &operator+=(const mint &r) {
		if(this->empty()) this->resize(1);
		(*this)[0] += r;
		return *this;
	}

	P &operator-=(const P &r) {
		if(r.size() > this->size()) this->resize(r.size());
		for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
		shrink();
		return *this;
	}

	P &operator-=(const mint &r) {
		if(this->empty()) this->resize(1);
		(*this)[0] -= r;
		shrink();
		return *this;
	}

	P &operator*=(const mint &v) {
		const int n = (int)this->size();
		for(int k = 0; k < n; k++) (*this)[k] *= v;
		return *this;
	}

	P &operator*=(const P &r) {
		if(this->empty() || r.empty()) {
			this->clear();
			return *this;
		}
		assert(get_mult() != nullptr);

		return *this = get_mult()(*this, r);
	}

	P &operator%=(const P &r) { return *this -= *this / r * r; }

	P operator-() const {
		P ret(this->size());
		for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
		return ret;
	}

	P &operator/=(const P &r) {
		if(this->size() < r.size()) {
			this->clear();
			return *this;
		}
		int n = this->size() - r.size() + 1;
		return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
	}

	P dot(P r) const {
		P ret(std::min(this->size(), r.size()));
		for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];
		return ret;
	}

	P pre(int sz) const { return P(std::begin(*this), std::begin(*this) + std::min((int)this->size(), sz)); }

	P operator>>(int sz) const {
		if(this->size() <= sz) return {};
		P ret(*this);
		ret.erase(ret.begin(), ret.begin() + sz);
		return ret;
	}

	P operator<<(int sz) const {
		P ret(*this);
		ret.insert(ret.begin(), sz, mint(0));
		return ret;
	}

	P rev(int deg = -1) const {
		P ret(*this);
		if(deg != -1) ret.resize(deg, mint(0));
		std::reverse(std::begin(ret), std::end(ret));
		return ret;
	}

	P diff() const {
		const int n = (int)this->size();
		P ret(std::max(0, n - 1));
		for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * mint(i);
		return ret;
	}

	P integral() const {
		const int n = (int)this->size();
		P ret(n + 1);
		ret[0] = mint(0);
		for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / mint(i + 1);
		return ret;
	}

	// F(0) must not be 0
	P inv(int deg = -1) const {
		assert(((*this)[0]) != mint(0));
		const int n = (int)this->size();
		if(deg == -1) deg = n;
		if(get_fft() != nullptr) {
			P ret(*this);
			ret.resize(deg, mint(0));
			return ret.inv_fast();
		}
		P ret({mint(1) / (*this)[0]});
		for(int i = 1; i < deg; i <<= 1) {
			ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
		}
		return ret.pre(deg);
	}

	// F(0) must be 1
	P log(int deg = -1) const {
		assert((*this)[0] == 1);
		const int n = (int)this->size();
		if(deg == -1) deg = n;
		return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
	}

	P sqrt(int deg = -1) const {
		const int n = (int)this->size();
		if(deg == -1) deg = n;
		if((*this)[0] == mint(0)) {
			for(int i = 1; i < n; i++) {
				if((*this)[i] != mint(0)) {
					if(i & 1) return {};
					if(deg - i / 2 <= 0) break;
					auto ret = (*this >> i).sqrt(deg - i / 2);
					if(ret.empty()) return {};
					ret = ret << (i / 2);
					if(ret.size() < deg) ret.resize(deg, mint(0));
					return ret;
				}
			}
			return P(deg, 0);
		}

		P ret;
		if(get_sqrt() == nullptr) {
			assert((*this)[0] == mint(1));
			ret = {mint(1)};
		} else {
			auto sqr = get_sqrt()((*this)[0]);
			if(sqr * sqr != (*this)[0]) return {};
			ret = {mint(sqr)};
		}

		mint inv2 = mint(1) / mint(2);
		for(int i = 1; i < deg; i <<= 1) {
			ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
		}
		return ret.pre(deg);
	}

	// F(0) must be 0
	P exp(int deg = -1) const {
		assert((*this)[0] == mint(0));
		const int n = (int)this->size();
		if(deg == -1) deg = n;
		if(get_fft() != nullptr) {
			P ret(*this);
			ret.resize(deg, mint(0));
			return ret.exp_rec();
		}
		P ret({mint(1)});
		for(int i = 1; i < deg; i <<= 1) {
			ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
		}
		return ret.pre(deg);
	}

	P online_convolution_exp(const P &conv_coeff) const {
		const int n = (int)conv_coeff.size();
		assert((n & (n - 1)) == 0);
		vector<P> conv_ntt_coeff;
		auto &fft = get_fft();
		auto &ifft = get_ifft();
		for(int i = n; i >= 1; i >>= 1) {
			P g(conv_coeff.pre(i));
			fft(g);
			conv_ntt_coeff.emplace_back(g);
		}
		P conv_arg(n), conv_ret(n);
		auto rec = [&](auto rec, int l, int r, int d) -> void {
			if(r - l <= 16) {
				for(int i = l; i < r; i++) {
					mint sum = 0;
					for(int j = l; j < i; j++) sum += conv_arg[j] * conv_coeff[i - j];
					conv_ret[i] += sum;
					conv_arg[i] = i == 0 ? mint(1) : conv_ret[i] / i;
				}
			} else {
				int m = (l + r) / 2;
				rec(rec, l, m, d + 1);
				P pre(r - l);
				for(int i = 0; i < m - l; i++) pre[i] = conv_arg[l + i];
				fft(pre);
				for(int i = 0; i < r - l; i++) pre[i] *= conv_ntt_coeff[d][i];
				ifft(pre);
				for(int i = 0; i < r - m; i++) conv_ret[m + i] += pre[m + i - l];
				rec(rec, m, r, d + 1);
			}
		};
		rec(rec, 0, n, 0);
		return conv_arg;
	}

	P exp_rec() const {
		assert((*this)[0] == mint(0));
		const int n = (int)this->size();
		int m = 1;
		while(m < n) m *= 2;
		P conv_coeff(m);
		for(int i = 1; i < n; i++) conv_coeff[i] = (*this)[i] * i;
		return online_convolution_exp(conv_coeff).pre(n);
	}

	P inv_fast() const {
		assert(((*this)[0]) != mint(0));

		const int n = (int)this->size();
		P res{mint(1) / (*this)[0]};

		for(int d = 1; d < n; d <<= 1) {
			P f(2 * d), g(2 * d);
			for(int j = 0; j < std::min(n, 2 * d); j++) f[j] = (*this)[j];
			for(int j = 0; j < d; j++) g[j] = res[j];
			get_fft()(f);
			get_fft()(g);
			for(int j = 0; j < 2 * d; j++) f[j] *= g[j];
			get_ifft()(f);
			for(int j = 0; j < d; j++) {
				f[j] = 0;
				f[j + d] = -f[j + d];
			}
			get_fft()(f);
			for(int j = 0; j < 2 * d; j++) f[j] *= g[j];
			get_ifft()(f);
			for(int j = 0; j < d; j++) f[j] = res[j];
			res = f;
		}
		return res.pre(n);
	}

	P pow(int64_t k, int deg = -1) const {
		const int n = (int)this->size();
		if(deg == -1) deg = n;
		for(int i = 0; i < n; i++) {
			if((*this)[i] != mint(0)) {
				mint rev = mint(1) / (*this)[i];
				P ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));
				if(i * k > deg) return P(deg, mint(0));
				ret = (ret << (i * k)).pre(deg);
				if(ret.size() < deg) ret.resize(deg, mint(0));
				return ret;
			}
		}
		return *this;
	}

	mint eval(mint x) const {
		mint r = 0, w = 1;
		for(auto &v : *this) {
			r += w * v;
			w *= x;
		}
		return r;
	}

	P pow_mod(int64_t n, P mod) const {
		P modinv = mod.rev().inv();
		auto get_div = [&](P base) {
			if(base.size() < mod.size()) {
				base.clear();
				return base;
			}
			int n = base.size() - mod.size() + 1;
			return (base.rev().pre(n) * modinv.pre(n)).pre(n).rev(n);
		};
		P x(*this), ret{1};
		while(n > 0) {
			if(n & 1) {
				ret *= x;
				ret -= get_div(ret) * mod;
			}
			x *= x;
			x -= get_div(x) * mod;
			n >>= 1;
		}
		return ret;
	}
};

NumberTheoreticTransformFriendlyModInt ntt;
using FPS = FormalPowerSeries;
struct FPS_setup {
	FPS_setup() {
		auto mult = [&](const FPS::P &a, const FPS::P &b) {
			auto ret = ntt.multiply(a, b);
			return FPS::P(ret.begin(), ret.end());
		};
		FPS::set_mult(mult);
		FPS::set_fft([&](FPS::P &a) { ntt.ntt(a); }, [&](FPS::P &a) { ntt.intt(a); });
	}
} FPS_setup_;

mint res, half = (mint)1 / 2;
int main() {
	INT(n);
	FPS f(n + 1, 0);
	f[0] = 1;

	for(int i = 1; i <= n; i += 2)
		f[i] = -half.pow(i);

	f = f.inv();

	print(f[n]);
}