#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

template<unsigned MOD_> struct ModInt {
    static constexpr unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const { return pow(MOD-2); }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;

template<unsigned MOD, unsigned ROOT> struct NTT {
    typedef ModInt<MOD> Mint;

    static void ntt(vector<Mint> &x, const int inverse=false) {
	int n = x.size(); // n == 1<<k;
	static vector<Mint> y, e, er;
	if (n != (int)e.size()) {
	    y.resize(n); e.resize(n); er.resize(n);
	    e[0] = 1; e[1] = Mint(ROOT).pow((MOD-1)/n);
	    er[0] = 1; er[1] = e[1].inv();
	    for (int i=2; i<n; i++) e[i] = e[i-1] * e[1];
	    for (int i=2; i<n; i++) er[i] = er[i-1] * er[1];
	}
	if (inverse) swap(e, er);
	int nn = n, s = 1, eo = 0;
	for (; nn>1;) {
	    const int m = nn / 2;
	    for (int p=0; p<m; p++) {
		Mint wp = e[p*(n/nn)];
		for (int q=0; q<s; q++) {
		    Mint a = x[q+s*p];
		    Mint b = x[q+s*(p+m)];
		    y[q+s*(p+p)] = a + b;
		    y[q+s*(p+p+1)] = (a - b) * wp;
		}
	    }
	    nn = m; s += s; eo ^= 1;
	    swap(x, y);
	}
	if (eo) {
	    for (int q=0; q<s; q++) y[q] = x[q];
	    swap(x, y);
	}
	if (inverse) {
	    swap(e, er);
	    Mint d = Mint(n).inv();
	    for (int i=0; i<n; i++) x[i] = x[i] * d;
	}
    }

    static vector<Mint> convolution(const vector<Mint> &f, const vector<Mint> &g) {
	int sz = 1;
	while (sz < (int)(f.size() + g.size())) sz *= 2;
	static vector<Mint> f1, g1;
	f1.resize(sz); fill(f1.begin(), f1.end(), 0);
	g1.resize(sz); fill(g1.begin(), g1.end(), 0);
	REP (i, f.size()) f1[i] = f[i];
	REP (i, g.size()) g1[i] = g[i];
	ntt(f1);
	ntt(g1);
	REP (i, sz) f1[i] *= g1[i];
	ntt(f1, true);
	vector<Mint> ret(f.size() + g.size());
	REP (i, ret.size()) ret[i] = f1[i].x;
	return ret;
    }
};

namespace POLYNOMIAL {
const size_t MAGIC = 500;

template<class T> vector<T> convolution(const vector<T> &x, const vector<T> &y) {
    assert(false && "ERROR: convolution not defined");
    if (0) return x;
    return y;
}

template<> vector<ModInt<998244353> > convolution(const vector<ModInt<998244353> > &x, const vector<ModInt<998244353> > &y) {
    return NTT<998244353, 3>::convolution(x, y);
}

// P + Q: O(n);
// P - Q: O(n);
// P * Q: O(n^2) or O(n log n);
// P / Q, polynomial div: O(n log n);
// P % Q, polynomial mod: O(n log n);
// P.divmod(), polynomial divmod: O(n log n);
// P.inv(k) == 1 / P mod x^k: O(n log n);
// P.deriv(): O(n);
// P.integr(): O(n);
// P.exp(k) == exp(P) mod x^k: O(n log n);
// P.log(k) == log(P) mod x^k: O(n log n);
// P.pow(y, k) == P^y mod x^k: O(n log n);
template<class T> struct Polynomial {
    vector<T> a;

    Polynomial() {}
    explicit Polynomial(const vector<T> &a_) : a(a_) { normalize(); }
    explicit Polynomial(vector<T> &&a_) : a(move(a_)) { normalize(); }

    size_t size() const { return a.size(); }

    bool empty() const { return a.empty(); }

    void push_back(const T &k) { a.push_back(k); }
    T& back() { return a.back(); }
    void pop_back() { a.pop_back(); }

    T& operator[](size_t i) { return a[i]; }
    const T& operator[](size_t i) const { return a[i]; }

    // safe access;
    T at(size_t i) const {
	return i < size()? a[i]: T(0);
    }

    void set(size_t i, T v) {
	while (a.size() <= i) a.push_back(0);
	a[i] = v;
	normalize();
    }

    void add(size_t i, T v) {
	while (a.size() <= i) a.push_back(0);
	a[i] += v;
	normalize();
    }

    void normalize() {
	while (!empty() && a.back() == T(0)) a.pop_back();
    }

    Polynomial& operator+=(const Polynomial &y) {
	if (size() < y.size()) a.resize(y.size(), 0);
	REP (i, y.size()) a[i] += y[i];
	normalize();
	return *this;
    }

    Polynomial& operator-=(const Polynomial &y) {
	if (size() < y.size()) a.resize(y.size(), 0);
	REP (i, y.size()) a[i] -= y[i];
	normalize();
	return *this;
    }

    friend Polynomial operator+(Polynomial x, const Polynomial &y) { return x += y; }
    friend Polynomial operator-(Polynomial x, const Polynomial &y) { return x -= y; }
    friend Polynomial operator-(Polynomial x) { REP (i, x.size()) x[i] = -x[i]; return x; }

    Polynomial& operator*=(const Polynomial &y) { return *this = *this * y; }

    Polynomial& operator*=(const T &y) {
	REP (i, size()) a[i] *= y;
	normalize();
	return *this;
    }

    // O(n^2), O(n log n);
    friend Polynomial operator*(const Polynomial &x, const Polynomial &y) {
	if (x.empty() || y.empty()) return Polynomial();
	if (x.size() < MAGIC || y.size() < MAGIC) return mul_slow(x, y);
	return mul_fft(x, y);
    }

    // O(n^2);
    static Polynomial mul_slow(const Polynomial &x, const Polynomial &y) {
	Polynomial z; z.a.resize(x.size() + y.size() - 1u);
	REP (i, x.size()) REP (j, y.size()) z[i+j] += x[i] * y[j];
	z.normalize();
	return z;
    }

    // O(n log n);
    static Polynomial mul_fft(const Polynomial &x, const Polynomial &y) {
	return Polynomial(convolution(x.a, y.a));
    }

    friend Polynomial operator*(Polynomial x, const T &y) { return x *= y; }
    friend Polynomial operator*(const T &x, Polynomial y) { return y *= x; }

    Polynomial& operator/=(const T &y) { return *this *= T(1) / y; }

    Polynomial& operator/=(const Polynomial &y) { return *this = *this / y; }
    Polynomial& operator%=(const Polynomial &y) { return *this = *this % y; }

    friend Polynomial operator/(const Polynomial &x, const Polynomial &y) { return x.divmod(y).first; }
    friend Polynomial operator%(const Polynomial &x, const Polynomial &y) { return x.divmod(y).second; }
    friend Polynomial operator/(Polynomial x, const T &y) { return x /= y; }

    // O(n);
    Polynomial deriv() const {
	if (size() <= 1u) return Polynomial();
	Polynomial z; z.a.resize(size()-1u);
	for (int i=1; i<(int)size(); i++) z[i-1] = a[i] * i;
	z.normalize();
	return z;
    }

    // O(n);
    Polynomial integr() const {
	if (empty()) return Polynomial();
	Polynomial z; z.a.resize(size()+1u);
	// precalc inv table;
	REP (i, size()) z[i+1] = a[i] * inv[i+1];
	z.normalize();
	return z;
    }

    // O(n+k); mul (x^k);
    Polynomial mul_xk(size_t k) const {
	if (empty()) return Polynomial();
	Polynomial z;
	z.a.resize(a.size() + k);
	REP (i, a.size()) z.a[k+i] = a[i];
	z.normalize();
	return z;
    }

    // O(k); mod (x^k);
    Polynomial mod_xk(size_t k) const {
	amin(k, a.size());
	return Polynomial(vector<T>(a.begin(), a.begin()+k));
    }

    // O(n+k); div (x^k);
    Polynomial div_xk(size_t k) const {
	if (a.size() <= k) return Polynomial();
	return Polynomial(vector<T>(a.begin()+k, a.end()));
    }

    Polynomial substr(size_t l, size_t r) const {
	amin(l, a.size());
	amin(r, a.size());
	return Polynomial(vector<T>(a.begin()+l, a.begin()+r));
    }

    // Input: P(x), k;
    // Output: Q(x);
    // Q(x) := 1 / P(x) (mod x^k);
    // P(x) Q(x) == 1 (mod x^k);
    // Condition: P(x)[0] != 0;
    // O(n log n);
    // e.g. (1-x)^{-1} == 1 + x + x^2 + x^3 + ... + x^{k-1}
    Polynomial inv(size_t k) const {
	assert(!empty());
	assert(a[0] != T());
	Polynomial ret;
	ret.push_back(1/a[0]);
	size_t w = 1;
	while (w < k) {
	    Polynomial tmp = (ret * mod_xk(w*2)).substr(w, w*2);
	    ret -= (ret * tmp).mod_xk(w*2).mul_xk(w);
	    w *= 2;
	}
	return ret.mod_xk(k);
    }

    Polynomial reverse() const {
	vector<T> b = a;
	std::reverse(b.begin(), b.end());
	return Polynomial(b);
    }

    // Input: A(x), B(x);
    // Output: Q(x), R(x);
    // A(x) == Q(x) * B(x) + R(x);
    // deg(R) < deg(B)
    // O(n log n);
    pair<Polynomial, Polynomial> divmod(const Polynomial &y) const {
	if (size() < y.size()) return make_pair(Polynomial(), *this);
	size_t diff = size() - y.size();
	if (min(diff, y.size()) < MAGIC) return divmod_slow(y);
	else return divmod_fast(y);
    }

    // O(n MAGIC);
    pair<Polynomial, Polynomial> divmod_slow(const Polynomial &y) const {
	int n = size();
	int yn = y.size();
	vector<T> q, r(a);
	q.reserve(n - yn +1);
	while (r.size() >= y.size()) {
	    q.push_back(r.back() / y.a.back());
	    REP (i, y.size()) r[(int)r.size()-1-i] -= q.back() * y[yn-1-i];
	    r.pop_back();
	}
	std::reverse(q.begin(), q.end());
	return make_pair(Polynomial(q), Polynomial(r));
    }

    // O(n log n);
    pair<Polynomial, Polynomial> divmod_fast(const Polynomial &y) const {
	int m = size() - y.size();
	Polynomial q = (reverse().mod_xk(m+1) * y.reverse().mod_xk(m+1).inv(m+1)).mod_xk(m+1);
	int t = q.size();
	q = q.reverse().mul_xk(m+1-t);
	return make_pair(q, *this - q * y);
    }

    T eval(T x) {
	T ret(0);
	for (int i=size(); i--;) {
	    ret *= x;
	    ret += a[i];
	}
	return ret;
    }

    // Input: P(x), k;
    // Output: ln P(x) (mod x^k);
    // (ln P(x))' == P'(x) / P(x)
    // Condition: P(x)[0] == 1;
    // O(n log n);
    Polynomial log(size_t k) const {
	assert(!empty());
	assert(a[0] == T(1));
	if (k <= 1) return Polynomial();
	return (deriv() * inv(k)).mod_xk(k-1).integr();
    }

    // Input: P(x), k;
    // Output: Q(x) = exp(P(x)) (mod x^k);
    // ln Q(x) == P(x);
    // Condition: P(x)[0] == 0;
    Polynomial exp(size_t k) const {
	assert(empty() || a[0] == T(0));
	if (k == 0) return Polynomial();
	Polynomial one = Polynomial({1});
	if (empty()) return one;
	Polynomial ret;
	ret.push_back(T(1));
	size_t w = 1;
	while (w < k) {
	    ret = (ret * (mod_xk(w*2) - ret.log(w*2) + one)).mod_xk(w*2);
	    w *= 2;
	}
	return ret.mod_xk(k);
    }

    // Input: P(x), y, k;
    // Output: Q == (P(x))^y (mod x^k);
    // Q == exp(y ln P(x)) if P(x)[0] == 1
    // Q == a^y x^{yt} exp(y ln R(x)) if P(x) == a x^t R(x) and R(x)[0] == 1;
    // O(n log n);
    // y non-negative;
    Polynomial pow(unsigned long long y, size_t k) const {
	if (k == 0 || empty()) return Polynomial();
	size_t t = 0;
	while (a[t] == T(0)) t++;
	Mint alpha = a[t], alpha_inv = T(1)/alpha;
	if (t != 0 && y >= k / t) return Polynomial();
	size_t w = k - y*t;
	return (((substr(t, size()).mod_xk(w) * alpha_inv).log(w) * y).exp(w) * alpha.pow(t)).mul_xk(y * t);
    }

    int deg() const { return (int)size() - 1; }

    T lead() const { return empty()? 0: a.back(); }

//    static Polynomial resultant(Polynomial x, Polynomial y);
//
//    vector<T> eval_all(vector<T> xs) {
//    }
//    
//    static Polynomial inter(const vector<T> &xs, const vector<T> &ys) {
//	assert(xs.size() == ys.size());
//    }
};
}; // namespace POLYNOMIAL;

using Polynomial = POLYNOMIAL::Polynomial<Mint>;

int N, M;
char S[200011];

Polynomial P[200011];

const Mint inv2 = Mint(1) / 2;

void MAIN() {
    scanf("%d%d", &N, &M);
    scanf("%s", S);

    REP (i, N) {
	int w, b;
	if (i % 2 == 0) {
	    b = 0;
	    w = 1;
	} else {
	    b = 1;
	    w = 0;
	}

	if (S[i] == 'b') {
	    P[i].set(b, 1);
	} else if (S[i] == 'w') {
	    P[i].set(w, 1);
	} else if (S[i] == '?') {
	    P[i].set(b, 1);
	    P[i].set(w, 1);
	}
    }

    int shift = 1;
    while (shift < N) {
	for (int i=0; i+shift<N; i+=shift*2) {
	    P[i] = P[i] * P[i+shift];
	    P[i+shift] = Polynomial();
	}
	shift += shift;
    }

    Mint way = 0;
    Mint crs = 0;
    REP (i, N+1) {
	int j = i - N/2;
	if (j % 2 == 0) {
	    Mint v = P[0].at(i);
	    way += v;
	    crs += abs(j) / 2 * v;
	}
    }

    Mint ans = crs / way;
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}