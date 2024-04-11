#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define endl "\n"
typedef pair<int,int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define PB push_back
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(s) (s).begin(),(s).end()
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define PQminll priority_queue<ll, vector<ll>, greater<ll>>
#define PQmaxll priority_queue<ll,vector<ll>,less<ll>>
#define PQminP priority_queue<P, vector<P>, greater<P>>
#define PQmaxP priority_queue<P,vector<P>,less<P>>
#define NP next_permutation
typedef string::const_iterator State;
class ParseError {};
//const ll mod = 1000000009;
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.00000000000001);
//static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T,class K>void vcin(vector<T> &n,vector<K> &m){for(int i=0;i<int(n.size());i++) cin>>n[i]>>m[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
template<class T>void vcin(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cin>>n[i][j];}}}
template<class T>void vcout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<endl;}cout<<endl;}
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void POSSIBLE(bool a){ cout<<(a?"POSSIBLE":"IMPOSSIBLE")<<endl; }
template<class T>void print(T a){cout<<a<<endl;}
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}
P hyou(P a){ll x=fastgcd(abs(a.fi),abs(a.se));a.fi/=x;a.se/=x;if(a.se<0){a.fi*=-1;a.se*=-1;}return a;}
P Pplus(P a,P b){ return hyou({a.fi*b.se+b.fi*a.se,a.se*b.se});}
P Ptimes(P a,ll b){ return hyou({a.fi*b,a.se});}
P Ptimes(P a,P b){ return hyou({a.fi*b.fi,a.se*b.se});}
P Pminus(P a,P b){ return hyou({a.fi*b.se-b.fi*a.se,a.se*b.se});}
P Pgyaku(P a){ return hyou({a.se,a.fi});}
namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder
namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m < 2^31`
    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

}  // namespace internal

}  // namespace atcoder
namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder
namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }
    static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }
    dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder
namespace atcoder {

namespace internal {

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
    if (first) {
        first = false;
        mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[bsf(~(unsigned int)(s))];
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly_inv(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    if (first) {
        first = false;
        mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] =
                    (unsigned long long)(mint::mod() + l.val() - r.val()) *
                    inow.val();
            }
            inow *= sum_ie[bsf(~(unsigned int)(s))];
        }
    }
}

}  // namespace internal

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        if (n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mint> ans(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
        return ans;
    }
    int z = 1 << internal::ceil_pow2(n + m - 1);
    a.resize(z);
    internal::butterfly(a);
    b.resize(z);
    internal::butterfly(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::butterfly_inv(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = static_modint<mod>;
    std::vector<mint> a2(n), b2(m);
    for (int i = 0; i < n; i++) {
        a2[i] = mint(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b2[i] = mint(b[i]);
    }
    auto c2 = convolution(move(a2), move(b2));
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        c[i] = c2[i].val();
    }
    return c;
}

std::vector<long long> convolution_ll(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  // 2^24
    static constexpr unsigned long long MOD2 = 167772161;  // 2^25
    static constexpr unsigned long long MOD3 = 469762049;  // 2^26
    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::inv_gcd(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::inv_gcd(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::inv_gcd(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * M2M3;
        x += (c2[i] * i2) % MOD2 * M1M3;
        x += (c3[i] * i3) % MOD3 * M1M2;
        // B = 2^63, -B <= x, r(real value) < B
        // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)
        // r = c1[i] (mod MOD1)
        // focus on MOD1
        // r = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)
        // r = x,
        //     x - M' + (0 or 2B),
        //     x - 2M' + (0, 2B or 4B),
        //     x - 3M' + (0, 2B, 4B or 6B) (without mod!)
        // (r - x) = 0, (0)
        //           - M' + (0 or 2B), (1)
        //           -2M' + (0 or 2B or 4B), (2)
        //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)
        // we checked that
        //   ((1) mod MOD1) mod 5 = 2
        //   ((2) mod MOD1) mod 5 = 3
        //   ((3) mod MOD1) mod 5 = 4
        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  // namespace atcoder
using namespace atcoder;
void cincout() {
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
}
template<class T>
vector<T> NTT(vector<T> a,vector<T> b){
  ll nmod=T::mod();
  int n=a.size();
  int m=b.size();
  vector<int> x1(n);
  vector<int> y1(m);
  for(int i=0;i<n;i++){
    ll tmp1,tmp2,tmp3;
    tmp1=a[i].val();
    x1[i]=tmp1;
  }
  for(int i=0;i<m;i++){
    ll tmp1,tmp2,tmp3;
    tmp1=b[i].val();
    y1[i]=tmp1;
  }
  auto z1=convolution<167772161>(x1,y1);
  auto z2=convolution<469762049>(x1,y1);
  auto z3=convolution<1224736769>(x1,y1);
  vector<T> res(n+m-1);
  ll m1=167772161;
  ll m2=469762049;
  ll m3=1224736769;
  ll m1m2=104391568;
  ll m1m2m3=721017874;
  ll mm12=m1*m2%nmod;
  for(int i=0;i<n+m-1;i++){
    int v1=(z2[i]-z1[i])*m1m2%m2;
    if(v1<0) v1+=m2;
    int v2=(z3[i]-(z1[i]+v1*m1)%m3)*m1m2m3%m3;
    if(v2<0) v2+=m3;
    res[i]=(z1[i]+v1*m1+v2*mm12);
  }
  return res;
}
template<class T>
struct FormalPowerSeries:vector<T>{
  using vector<T>::vector;
  using F=FormalPowerSeries;
  F &operator=(const vector<T> &g){
    int n=g.size();
    int m=(*this).size();
    (*this).resize(n);
    for(int i=0;i<n;i++) (*this)[i]=g[i];
    return (*this);
  }
  F &operator=(const F &g){
    int n=g.size();
    int m=(*this).size();
    (*this).resize(n);
    for(int i=0;i<n;i++) (*this)[i]=g[i];
    return (*this);
  }
  F &operator-(){
    for(int i=0;i<(*this).size();i++) (*this)[i]*=-1;
    return (*this);
  }
  F &operator+=(const F &g){
    int n=(*this).size();
    int m=g.size();
    if(n<m) (*this).resize(m);
    for(int i=0;i<m;i++) (*this)[i]+=g[i];
    return (*this);
  }
  F &operator+=(const T &r){
    if((*this).size()==0) (*this).resize(1);
    (*this)[0]+=r;
    return (*this);
  }
  F &operator-=(const F &g){
    int n=(*this).size();
    int m=g.size();
    if(n<m) (*this).resize(m);
    for(int i=0;i<m;i++) (*this)[i]-=g[i];
    return (*this);
  }
  F &operator-=(const T &r){
    if((*this).size()==0) (*this).resize(1);
    (*this)[0]-=r;
    return (*this);
  }
  F &operator*=(const F &g){
    (*this)=convolution((*this),g);
    return (*this);
  }
  F &operator*=(const T &r){
    for(int i=0;i<(*this).size();i++) (*this)[i]*=r;
    return (*this);
  }
  F &operator/=(const F &g){
    int n=(*this).size();
    (*this)=convolution((*this),g.inv());
    (*this).resize(n);
    return (*this);
  }
  F &operator/=(const T &r){
    r=r.inv();
    for(int i=0;i<(*this).size();i++) (*this)[i]*=r;
    return (*this);
  }
  F &operator<<=(const int d) {
    int n=(*this).size();
    (*this).insert((*this).begin(),d,0);
    return *this;
  }
  F &operator>>=(const int d) {
    int n=(*this).size();
    (*this).erase((*this).begin(),(*this).begin()+min(n, d));
    return *this;
  }
  F operator*(const T &g) const { return F(*this)*=g;}
  F operator-(const T &g) const { return F(*this)-=g;}
  F operator+(const T &g) const { return F(*this)+=g;}
  F operator/(const T &g) const { return F(*this)/=g;}
  F operator*(const F &g) const { return F(*this)*=g;}
  F operator-(const F &g) const { return F(*this)-=g;}
  F operator+(const F &g) const { return F(*this)+=g;}
  F operator/(const F &g) const { return F(*this)/=g;}
  F operator%(const F &g) const { return F(*this)%=g;}
  F operator<<(const int d) const { return F(*this)<<=d;}
  F operator>>(const int d) const { return F(*this)>>=d;}  
  F pre(int sz) const {
    return F(begin(*this), begin(*this) + min((int)this->size(), sz));
  }
  F inv(int deg=-1) const {
    int n=(*this).size();
    if(deg==-1) deg=n;
    assert(n>0&&(*this)[0]!=T(0));
    F g(1);
    g[0]=(*this)[0].inv();
    while(g.size()<deg){
      int m=g.size();
      F f(begin(*this),begin(*this)+min(n,2*m));
      F r(g);
      f.resize(2*m);
      r.resize(2*m);
      internal::butterfly(f);
      internal::butterfly(r);
      for(int i=0;i<2*m;i++) f[i]*=r[i];
      internal::butterfly_inv(f);
      f.erase(f.begin(),f.begin()+m);
      f.resize(2*m);
      internal::butterfly(f);
      for(int i=0;i<2*m;i++) f[i]*=r[i];
      internal::butterfly_inv(f);
      T in=T(2*m).inv();
      in*=-in;
      for(int i=0;i<m;i++) f[i]*=in;
      g.insert(g.end(),f.begin(),f.begin()+m);
    }
    return g.pre(deg);
  }
  T eval(const T &a){
    T x=1;
    T ret=0;
    for(int i=0;i<(*this).size();i++){
      ret+=(*this)[i]*x;
      x*=a;
    }
    return ret;
  }
  void onemul(const int d,const T c){
    int n=(*this).size();
    for(int i=n-d-1;i>=0;i--){
      (*this)[i+d]+=(*this)[i]*c;
    }
  }
  void onediv(const int d,const T c){
    int n=(*this).size();
    for(int i=0;i<n-d;i++){
      (*this)[i+d]-=(*this)[i]*c;
    }
  }
  F diff() const {
    int n=(*this).size();
    F ret(n);
    for(int i=1;i<n;i++) ret[i-1]=(*this)[i]*i;
    ret[n-1]=0;
    return ret;
  }
  F integral() const {
    int n=(*this).size(),mod =T::mod();
    vector<T> inv(n);
    inv[1]=1;
    for(int i=2;i<n;i++) inv[i]=T(mod)-inv[mod%i]*(mod/i);
    F ret(n);
    for(int i=n-2;i>=0;i--) ret[i+1]=(*this)[i]*inv[i+1];
    ret[0]=0;
    return ret;
  }
  F log(int deg=-1) const {
    int n=(*this).size();
    if(deg==-1) deg=n;
    assert((*this)[0]==T(1));
    return ((*this).diff()*(*this).inv(deg)).pre(deg).integral();
  }
  F exp(int deg=-1) const {
    int n=(*this).size();
    if(deg==-1) deg=n;
    assert(n==0||(*this)[0]==0);
    F Inv;
    Inv.reserve(deg);
    Inv.push_back(T(0));
    Inv.push_back(T(1));
    auto inplace_integral = [&](F& f) -> void {
    const int n = (int)f.size();
      int mod=T::mod();
      while(Inv.size()<=n){
        int i = Inv.size();
        Inv.push_back((-Inv[mod%i])*(mod/i));
      }
      f.insert(begin(f),T(0));
      for(int i=1;i<=n;i++) f[i]*=Inv[i];
    };
    auto inplace_diff = [](F &f) -> void {
      if(f.empty()) return;
      f.erase(begin(f));
      T coeff=1,one=1;
      for(int i=0;i<f.size();i++){
        f[i]*=coeff;
        coeff++;
      }
    };
    F b{1,1<(int)(*this).size()?(*this)[1]:0},c{1},z1,z2{1,1};
    for(int m=2;m<=deg;m<<=1){
      auto y=b;
      y.resize(2*m);
      internal::butterfly(y);
      z1=z2;
      F z(m);
      for(int i=0;i<m;i++) z[i]=y[i]*z1[i];
      internal::butterfly_inv(z);
      T si=T(m).inv();
      for(int i=0;i<m;i++) z[i]*=si;
      fill(begin(z),begin(z)+m/2,T(0));
      internal::butterfly(z);
      for(int i=0;i<m;i++) z[i]*=-z1[i];
      internal::butterfly_inv(z);
      for(int i=0;i<m;i++) z[i]*=si;
      c.insert(end(c),begin(z)+m/2,end(z));
      z2=c;
      z2.resize(2*m);
      internal::butterfly(z2);
      F x(begin((*this)),begin((*this))+min<int>((*this).size(),m));
      x.resize(m);
      inplace_diff(x);
      x.push_back(T(0));
      internal::butterfly(x);
      for(int i=0;i<m;i++) x[i]*=y[i];
      internal::butterfly_inv(x);
      for(int i=0;i<m;i++) x[i]*=si;
      x-=b.diff();
      x.resize(2*m);
      for(int i=0;i<m-1;i++) x[m+i]=x[i],x[i]=T(0);
      internal::butterfly(x);
      for(int i=0;i<2*m;i++) x[i]*=z2[i];
      internal::butterfly_inv(x);
      T si2=T(m<<1).inv();
      for(int i=0;i<2*m;i++) x[i]*=si2;
      x.pop_back();
      inplace_integral(x);
      for(int i=m;i<min<int>((*this).size(),2*m);i++) x[i]+=(*this)[i];
      fill(begin(x),begin(x)+m,T(0));
      internal::butterfly(x);
      for(int i=0;i<2*m;i++) x[i]*=y[i];
      internal::butterfly_inv(x);
      for(int i=0;i<2*m;i++) x[i]*=si2;
      b.insert(end(b),begin(x)+m,end(x));
    }
    return b.pre(deg);
  }
  F pow(ll m){
    int n=(*this).size();
    int x=0;
    if(m==0){
      F d(n);
      d[0]=1;
      return d;
    }
    while(x<(*this).size()&&(*this)[x]==T(0)){
      x++;
    }
    if(x*m>=n){
      F ret(n);
      return ret;
    }
    F f(n-x);
    T y=(*this)[x];
    for(int i=x;i<n;i++) f[i-x]=(*this)[i]/y;
    f=f.log();
    for(int i=0;i<f.size();i++) f[i]*=m;
    f=f.exp();
    y=y.pow(m);
    for(int i=0;i<f.size();i++) f[i]*=y;
    F ret(n);
    for(int i=x*m;i<n;i++) ret[i]=f[i-x*m];
    return ret;
  }
  F shift(T c){
    int n=(*this).size();
    int mod=T::mod();
    vector<T> inv(n+1);
    inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=mod-inv[mod%i]*(mod/i);
    T x=1;
    for(int i=0;i<n;i++){
      (*this)[i]*=x;
      x*=(i+1);
    }
    F g(n);
    T y=1;
    T now=1;
    for(int i=0;i<n;i++){
      g[n-i-1]=now*y;
      now*=c;
      y*=inv[i+1];
    }
    auto tmp=convolution(g,(*this));
    T z=1;
    for(int i=0;i<n;i++){
      (*this)[i]=tmp[n+i-1]*z;
      z*=inv[i+1];
    }
    return (*this);
  }
  pair<F,F> division(F g){
    F f=(*this);
    int n=f.size();
    int m=g.size();
    if(n<m){
      F p(0);
      return {p,f};
    }
    F p(n-m+1),q(n-m+1);
    for(int i=0;i<n-m+1;i++) p[i]=f[n-i-1];
    for(int i=0;i<n-m+1&&i<m;i++) q[i]=g[m-i-1];
    p/=q;
    for(int i=0;i<(n-m+1)/2;i++) swap(p[i],p[(n-m+1)-i-1]);
    g.resize(n);
    g*=p;
    for(int i=0;i<n;i++) f[i]-=g[i];
    int v=n-m+1,u=0;
    for(int i=0;i<n;i++) if(f[i].val()) chmax(u,i+1);
    p.resize(v);
    f.resize(u);
    return {p,f};
  }
  vector<T> multieva(vector<T> p){
    int m=p.size();
    int n=(*this).size();
    int M=1;
    int l=0;
    while(M<m){
      M*=2;
      l++;
    }
    p.resize(M);
    swap(m,M);
    vector<vector<F>> g(l+1);
    g[0].resize(m);
    for(int i=0;i<m;i++){
      g[0][i].resize(2);
      g[0][i][0]=-p[i];
      g[0][i][1]=1;
    }
    for(int i=0;i<l;i++){
      g[i+1].resize(m>>(i+1));
      for(int j=0;j<(m>>(i+1));j++) g[i+1][j]=g[i][2*j]*g[i][2*j+1];
    }
    g[l][0]=(*this).division(g[l][0]).se;
    for(int i=l;i>=1;i--){
      for(int j=0;j<(m>>(i-1));j++){
        g[i-1][j]=g[i][j/2].division(g[i-1][j]).se;
      }
    }
    for(int i=0;i<M;i++) if(g[0][i].size()==0) g[0][i].resize(1);
    vector<T> ret(M);
    for(int i=0;i<M;i++) ret[i]=g[0][i][0];
    return ret;
  }
};
template<class T>
void GaussJordan(vector<vector<T>> &A,bool is_extended = false){
  ll m=A.size(),n=A[0].size();
  ll rank=0;
  for(int i=0;i<n;i++){
    if(is_extended&&i==n-1) break;
    ll p=-1;
    for(int j=rank;j<m;j++){
      if(A[j][i]!=T(0)){
        p=j;
        break;
      }
    }
    if(p==-1) continue;
    swap(A[p],A[rank]);
    auto k=A[rank][i];
    for(int i2=0;i2<n;i2++){
      A[rank][i2]/=k;
    }
    for(int j=0;j<m;j++){
      if(j!=rank&&A[j][i]!=T(0)){
        auto fac=A[j][i];
        for(int i2=0;i2<n;i2++){
          A[j][i2]-=A[rank][i2]*fac;
        }
      }
    }
    rank++;
  }
}
 
template<class T>
void linear_equation(vector<vector<T>> a, vector<T> b, vector<T> &res) {
  ll m=a.size(),n=a[0].size();
  vector<vector<T>> M(m,vector<T>(n+1));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      M[i][j]=a[i][j];
    }
    M[i][n]=b[i];
  }
  GaussJordan(M,true);
  res.assign(n,0);
  for(int i=0;i<n;i++) res[i]=M[i][n];
}
template<class F>
pair<F,F> Characteristic_equation(const F &a) {
  using T=typename F::value_type;
  ll n=a.size();
  ll p=n/2;
  ll u=p+(p+1);
  vector<vector<T>> f(u,vector<T>(u));
  f[0][0]=1;
  for(int i=1;i<=p;i++){
    f[i][i-1]=-1;
  }
  for(int i=p;i<u;i++){
    ll t=0;
    for(int j=1+i-p;j<u;j++){
      f[j][i]=a[t];
      t++;
    }
  }
  vector<T> b(u);
  b[0]=1;
  vector<T> res(u);
  linear_equation(f,b,res);
  F X(p),Y(p+1);
  for(int i=0;i<p;i++) X[i]=res[i];
  for(int j=p;j<res.size();j++) Y[j-p]=res[j];
  return {X,Y};
}
template <class T>
T getK(FormalPowerSeries<T> p, FormalPowerSeries<T> q,ll k){
  if(p.size()==0) return 0;
  if(k==0) return p[0]/q[0];
  if(p.size()>=q.size()){
    p=p.division(q).se;
  }
  if(k<0) return T(0);
  ll d=q.size();
  while(k){
    auto qn=q;
    for(int i=1;i<d;i+=2) qn[i]*=-1;
    p*=qn;
    q*=qn;
    for(int i=0;i<d-1;i++){
      p[i]=p[(i<<1)|(k&1)];
    }
    for(int i=0;i<d;i++){
      q[i]=q[(i<<1)];
    }
    p.resize(d-1);
    q.resize(d);
    k/=2;
  }
  return p[0];
}
using fps=FormalPowerSeries<modint998244353>;
using mint = modint998244353;
constexpr ll MAX = 300010;
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
ll binom(ll n,ll k){
  if(n<k) return 0;
  if(n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
ll HOM(ll n,ll k){
  if(n==0&&k==0) return 1;
  return binom(n+k-1,k);
}
ll POM(ll n,ll k){
  if(n<k) return 0;
  return fac[n]*finv[n-k]%mod;
}
//
template<class T>
vector<vector<T>> multi(vector<vector<T>> &a,vector<vector<T>> &b){
  vector<vector<T>> c(a.size(),vector<T>(b[0].size()));
  for(int i=0;i<int(a.size());i++){
    for(int j=0;j<=i;j++){
      for(int k=0;k<=j;k++){
        c[i][k]+=a[i][j]*b[j][k];
      }
    }
  }
  return c;
}
template<class T>
vector<vector<T>> mul_exp(vector<vector<T>> adj, ll k){
  if (k == 1) return adj;
  vector<vector<T>> res(int(adj.size()),vector<T>(int(adj[0].size())));
  for(int i=0;i<int(adj.size());i++){
    res[i][i]=1;
  }
  while(k>0){
    if(k&1) res=multi(adj,res);
    adj=multi(adj,adj);
    k/=2;
  }
  return res;
}
vector<mint> solve(ll n){
  vector<mint> a(n+1);
  for(int i=0;i<=n;i++) a[i]=mint(i).pow(n)*finv[n];
  for(int i=0;i<=n;i++) a[i]*=finv[i];
  vector<mint> b(n+1);
  for(int i=0;i<=n;i++) b[i]=finv[i]*mint(-1).pow(i);
  a=convolution(a,b);
  for(int i=0;i<=n;i++) a[i]*=fac[i];
  a.resize(n+1);
  vector<vector<vector<fps>>> d(n);
  for(int i=1;i<=n;i++){
    d[i-1]={{fps({1}),fps({0,a[i]}),fps({-a[i]*(i-1)*inv[i],-a[i]*inv[i]})},{fps({0}),fps({0,1}),fps({-(i-1)*inv[i],-inv[i]})},{fps({0}),fps({0}),fps({-(i-1)*inv[i],-inv[i]})}};
    swap(d[i-1][0][1],d[i-1][1][0]);
    swap(d[i-1][1][2],d[i-1][2][1]);
    swap(d[i-1][2][0],d[i-1][0][2]);
  }
  while(d.size()>1){
    ll m=d.size();
    vector<vector<vector<fps>>> e((m+1)/2);
    for(int i=0;i<m;i+=2){
      if(i+1<m) e[i/2]=multi(d[i],d[i+1]);
      else e[i/2]=d[i];
    }
    d=e;
  }
  fps q=d[0][0][0]*a[0]+d[0][1][0]+d[0][2][0];
  fps p(n+1);
  for(int i=0;i<=n;i++) p[i]=q[n-i];
  p=p.shift(-1);
  p*=fps({-1,1});
  fps r(n+1);
  r[0]=-1;
  r[1]=1;
  p/=r;
  p*=fac[n];
  vector<mint> ret(n);
  for(int i=0;i<n;i++) ret[i]=p[i+1];
  return ret;
}
int main() {
  cincout();
  COMinit();
  ll n,s;
  cin>>n>>s;
  if(n==s+1){
    for(int i=0;i<n;i++){
      if(i==n-1) cout<<1<<" ";
      else cout<<0<<" ";
    }
    cout<<endl;
    return 0;
  }
  vector<mint> a=solve(n-s),b=solve(n-s-1);
  for(int i=0;i<b.size();i++) a[i+1]+=b[i];
  vector<mint> ans;
  for(int i=0;i<s;i++) ans.pb(0);
  for(int i=0;i<a.size();i++) ans.pb(a[i]);
  while(ans.size()<n) ans.pb(0);
  for(auto e:ans) cout<<(e*binom(n-1,s)).val()<<" ";
}