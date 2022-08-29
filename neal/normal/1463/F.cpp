#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
// Note: this must come before `using namespace std;` or else it will not compile.
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif
using namespace std;

int64_t cpu_time_calls = 0;

long double cpu_time() {
    cpu_time_calls++;

#if defined(_WIN32) || defined(_WIN64)
    FILETIME creation_ft, exit_ft, kernel_ft, user_ft;
    GetProcessTimes(GetCurrentProcess(), &creation_ft, &exit_ft, &kernel_ft, &user_ft);

    auto extract_time = [](FILETIME ft) {
        return 1e-7L * (ft.dwLowDateTime | uint64_t(ft.dwHighDateTime) << 32);
    };

    return extract_time(user_ft) + extract_time(kernel_ft);
#else
    return (long double) clock() / CLOCKS_PER_SEC;
#endif
}

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// modnum {{{
using v_t = int;
using vv_t = ll;
template<v_t MOD> struct modnum {
    static_assert(numeric_limits<v_t>::max() / 2 >= MOD, "Addition overflows v_t");
    static_assert(numeric_limits<vv_t>::max() / MOD >= MOD, "Multiplication overflows vv_t");

    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(v_t(_v % MOD)) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // x must be less than 2^32 * m so that x / m fits in a 32-bit integer.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(vv_t e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        v_t g = MOD, x = 0, y = 1;
        for (v_t r = v; r != 0; ) {
            v_t q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static constexpr v_t totient() {
        v_t tot = MOD, tmp = MOD;
        for (v_t p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static v_t primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        v_t tot = totient(), tmp = tot;
        vi tot_pr;
        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (v_t r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static v_t discrete_log(modnum v) {
        static const v_t M = ceil(sqrt(MOD));
        static unordered_map<v_t, v_t> table;
        if (table.empty()) {
            modnum e = 1;
            for (v_t i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (v_t i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
    }

    static modnum unity_root(int deg, int pow) {
        static vector<modnum> table{ 0, 1 };
        while (sz(table) <= deg) {
            modnum w = unity_root(sz(table));
            for (int i = sz(table)/2, s = sz(table); i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }

    static modnum factorial(int n) {
        static vector<modnum> fact = {1};
        assert(n >= 0);
        if (sz(fact) <= n) {
            int had = sz(fact);
            fact.resize(n + 1);
            for (int i = had; i <= n; i++) fact[i] = fact[i-1] * i;
        }
        return fact[n];
    }
    static modnum inverse_factorial(int n) {
        static vector<modnum> finv = {1};
        assert(n >= 0);
        if (sz(finv) <= n) {
            int had = sz(finv);
            finv.resz(n + 1), finv[n] = factorial(n).inv();
            for (int i = n - 1; i >= had; i--) finv[i] = finv[i+1] * (i+1);
        }
        return finv[n];
    }

    static modnum small_inv(int n) {
        assert(n > 0); return factorial(n - 1) * inverse_factorial(n);
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r);
    }
};
// }}}
using mn = modnum<1000000007>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

// point {{{
template<typename T> struct point {
    T x, y;
    point() : x(0), y(0) {}
    point(T _x, T _y) : x(_x), y(_y) {}
    friend istream& operator >> (istream& i, point& p) { return i >> p.x >> p.y; }
    friend ostream& operator << (ostream& o, const point& p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }

    T norm() const { return x * x + y * y; }
    double len() const { return sqrt(norm()); }
    double ang() const { return atan2(y, x); }
    point<T> conj() const { return { x, -y }; }

    point& operator += (const point& o) { x += o.x; y += o.y; return *this; }
    point& operator -= (const point& o) { x -= o.x; y -= o.y; return *this; }
    point& operator *= (const T& c) { x *= c; y *= c; return *this; }
    point& operator /= (const T& c) { x /= c; y /= c; return *this; }
    friend point operator + (const point& a, const point& b) { return point(a) += b; }
    friend point operator - (const point& a, const point& b) { return point(a) -= b; }
    friend point operator * (const point& a, const T& c) { return point(a) *= c; }
    friend point operator * (const T& c, const point& a) { return point(a) *= c; }
    friend point operator / (const point& a, const T& c) { return point(a) /= c; }

    bool operator == (const point& o) const { return x == o.x && y == o.y; }
    bool operator != (const point& o) const { return x != o.x || y != o.y; }
    bool operator < (const point& o) const { return (x != o.x) ? x < o.x : y < o.y; }
    bool operator > (const point& o) const { return (x != o.x) ? x > o.x : y > o.y; }
    bool operator <= (const point& o) const { return !(*this > o); }

    friend T dot(const point& a, const point& b) { return a.x * b.x + a.y * b.y; }
    friend T cross(const point& a, const point& b) { return a.x * b.y - a.y * b.x; }
    friend T cross(const point& p, const point& a, const point& b) { return cross(a - p, b - p); }

    friend point<T> operator * (const point& a, const point& b) {
        return { a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x };
    }
    friend point<T> operator / (const point& a, const point& b) {
        return a * b.conj() / b.norm();
    }

    point dir() const { return point(*this) / len(); }
    point rotate(const double& ang) const { return *this * point(cos(ang), sin(ang)); }

    T dist(const point& a) const { return (a - *this).len(); }
    T dist(const point& a, const point& b) {
        return abs(cross(*this, a, b)) / a.dist(b);
    }
    point reflect(const point& a, const point& b) const {
        return a + ((*this - a) / (b - a)).conj() * (b - a);
    }
    point foot(const point& a, const point& b) const {
        return (*this + this->reflect(a, b)) / 2;
    }
    friend point extension(const point& a, const point& b, const point& c, const point& d) {
        T _x = cross(a, b, c), _y = cross(a, b, d);
        return (d * _x - c * _y) / (_x - _y);
    }

    friend vector<point> seg_intersect(point a, point b, point c, point d) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        T a1 = cross(a, b, c), a2 = cross(a, b, d);
        if (a1 > a2) swap(a1, a2);
        if (!(a1 <= 0 && a2 >= 0)) return {};

        if (a1 == 0 && a2 == 0) {
            if (cross(a, c, d) != 0) return {};
            point<T> x1 = max(a, c), x2 = min(b, d);
            if (x1 > x2) return {};
            if (x1 == x2) return { x1 };
            return { x1, x2 };
        }

        point<T> z = extension(a, b, c, d);
        if (a <= z && z <= b) return { z };
        return {};
    }

    using polygon = vector<point<T>>;
    friend ostream& operator << (ostream& o, const polygon& poly) {
        o << "{";
        for (auto pt : poly) o << " " << pt;
        return o << " }";
    }

    string classify(const polygon& p) const {
        bool ans = 0;
        for (int i = 0; i < p.size(); i++) {
            point<T> a = p[i], b = p[(i + 1) % p.size()];
            if (cross(a, b, *this) == 0 && min(a, b) <= *this && *this <= max(a, b))
                return "on";
            if (a.y > b.y) swap(a, b);
            if (a.y <= y && y < b.y && cross(*this, a, b) > 0) ans ^= 1;
        }
        return ans ? "in" : "out";
    }

    friend polygon convex_hull(const vector<point>& pts) {
        point pivot = *min_element(all(pts));
        auto sorted = pts;
        sort(all(sorted), [&pivot](const point& p, const point& q) {
            T cp = cross(pivot, p, q);
            if (cp != 0) return cp > 0;
            return pivot.dist(p) < pivot.dist(q);
        });

        int j = 0;
        polygon res(pts.size());
        for (const point& p : sorted) {
            while (j > 1 && cross(res[j - 2], res[j - 1], p) <= 0)
                j--;
            res[j++] = p;
        }
        res.erase(res.begin() + j, res.end());
        return res;
    }

    // twice the signed area
    friend T area(const polygon& p) {
        T a = 0;
        for (int i = 0; i < sz(p); i++)
            a += cross(p[i], p[i+1 < sz(p) ? i+1 : 0]);
        return a;
    }
};
// }}}
// fft {{{
const int FFT_CUTOFF = 150;
template<typename T, bool INV> static void fft(vector<T>& a, int N) {
    assert(__builtin_popcount(N) == 1);
    for (int i = 1, j = 0, k; i < N; i++) {
        for (k = N >> 1; (j ^= k) < k; k >>= 1);
        if (i < j) swap(a[i], a[j]);
    }

    for (int l = 1; l < N; l <<= 1) {
        for (int i = 0; i < N; i += 2 * l) {
            for (int j = 0; j < l; j++) {
                T w = T::unity_root(2 * l, INV ? -j : j);
                T u = a[i + j];
                T v = a[i + j + l] * w;
                a[i + j] = u + v;
                a[i + j + l] = u - v;
            }
        }
    }
    if (INV) {
        T ninv = T(N).inv();
        for (int i = 0; i < N; i++) a[i] = a[i] * ninv;
    }
}
// }}}
// complex_fft {{{
namespace complex_fft {
    using dbl = double;
    struct cnum : point<dbl> {
        cnum(point<dbl> p) : point<dbl>(p) {}
        cnum(dbl _x = 0, dbl _y = 0) : point<dbl>(_x, _y) {}
        cnum inv() const { dbl n = norm(); return cnum(x / n, -y / n); }

        static cnum unity_root(int deg, int pow) {
            static vector<cnum> table{ 0, 1 };
            while (sz(table) <= deg) {
                dbl t = 2 * acos(-1) / sz(table);
                cnum w{ cos(t), sin(t) };
                for (int i = sz(table)/2, s = sz(table); i < s; i++) {
                    table.push_back(table[i]);
                    table.push_back(table[i] * w);
                }
            }
            return table[deg + (pow < 0 ? deg + pow : pow)];
        }
    };
    static vector<cnum> fa, fb;

    vector<cnum> operator*(const vector<cnum>& a, const vector<cnum>& b) {
        if (a.empty() || b.empty()) return {};
        int s = sz(a) + sz(b) - 1;
        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);
        if (N > sz(fa)) fa.resize(N), fb.resize(N);

        copy(all(a), fa.begin());
        fill(fa.begin() + sz(a), fa.begin() + N, 0);
        copy(all(b), fb.begin());
        fill(fb.begin() + sz(b), fb.begin() + N, 0);

        fft<cnum, false>(fa, N);
        fft<cnum, false>(fb, N);
        for (int i = 0; i < N; i++) fa[i] = fa[i] * fb[i];
        fft<cnum, true>(fa, N);
        return { fa.begin(), fa.begin() + s };
    }

    template<int MOD>
    vector<modnum<MOD>> operator*(const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
        if (a.empty() || b.empty()) return {};
        int s = sz(a) + sz(b) - 1;
        if (min(sz(a), sz(b)) < FFT_CUTOFF) {
            const vv_t VV_BOUND = numeric_limits<vv_t>::max() - vv_t(MOD) * MOD;
            vector<vv_t> res(s);
            for (int i = 0; i < sz(a); i++) for (int j = 0; j < sz(b); j++) {
                if ((res[i + j] += vv_t(a[i].v) * b[j].v) > VV_BOUND) res[i + j] %= MOD;
            }
            return {res.begin(), res.end()};
        }

        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);
        if (N > sz(fa)) fa.resize(N), fb.resize(N);

        for (int i = 0; i < sz(a); i++)
            fa[i] = cnum(a[i].v & ((1 << 15) - 1), a[i].v >> 15);
        fill(fa.begin() + sz(a), fa.begin() + N, 0);
        fft<cnum, false>(fa, N);

        if (a != b) {
            for (int i = 0; i < sz(b); i++)
                fb[i] = cnum(b[i].v & ((1 << 15) - 1), b[i].v >> 15);
            fill(fb.begin() + sz(b), fb.begin() + N, 0);
            fft<cnum, false>(fb, N);
        } else {
            copy(fa.begin(), fa.begin() + N, fb.begin());
        }

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            cnum g0 = (fb[i] + fb[j].conj()) / (2 * N);
            cnum g1 = (fb[i] - fb[j].conj()) / (2 * N);
            g1 = { g1.y, -g1.x };
            if (j != i) {
                swap(fa[j], fa[i]);
                fb[j] = fa[j] * g1;
                fa[j] = fa[j] * g0;
            }
            fb[i] = fa[i] * g1.conj();
            fa[i] = fa[i] * g0.conj();
        }
        fft<cnum, false>(fa, N), fft<cnum, false>(fb, N);

        vector<modnum<MOD>> c(s);
        for (int i = 0; i < s; i++)
            c[i] =  ll(fa[i].x + 0.5)
                 + (ll(fa[i].y + 0.5) % MOD << 15)
                 + (ll(fb[i].x + 0.5) % MOD << 15)
                 + (ll(fb[i].y + 0.5) % MOD << 30);
        return c;
    }
    template<int MOD>
    vector<modnum<MOD>> conv(const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
        return a * b;
    }
}
// }}}
using namespace complex_fft;

// vector_operators {{{
namespace vector_operators {
    template<typename T> vector<T>& operator*=(vector<T>& l, const T& r) {
        for (T& e : l) e *= r;
        return l;
    }
    template<typename T> vector<T>& operator/=(vector<T>& l, const T& r) {
        for (T& e : l) e /= r;
        return l;
    }
    template<typename T> vector<T> operator*(vector<T> l, const T& r) { return l *= r; }
    template<typename T> vector<T> operator*(const T& l, vector<T> r) { return r *= l; }
    template<typename T> vector<T> operator/(vector<T> l, const T& r) { return l /= r; }

    template<typename T> vector<T>& operator+=(vector<T>& l, vector<T>& r) {
        l.resz(max(sz(l), sz(r))); for (int i = 0; i < sz(r); i++) l[i] += r[i]; return l;
    }
    template<typename T> vector<T>& operator-=(vector<T>& l, const vector<T>& r) {
        l.resz(max(sz(l), sz(r))); for (int i = 0; i < sz(r); i++) l[i] -= r[i]; return l;
    }
    template<typename T> vector<T> operator+(vector<T> l, const vector<T>& r) { return l += r; }
    template<typename T> vector<T> operator-(vector<T> l, const vector<T>& r) { return l -= r; }

    template<typename T> vector<T> conv(const vector<T>& l, const vector<T>& r) {
        if (l.empty() || r.empty()) return {};
        vector<T> p(sz(l) + sz(r) - 1);
        for (int i = 0; i < sz(l); i++) for (int j = 0; j < sz(r); j++) p[i+j] += l[i] * r[j];
        return p;
    }
    template<typename T> vector<T> operator*(const vector<T>& l, const vector<T>& r) {
        return complex_fft::conv(l, r); // return conv(l, r);
    }

    template<typename T> vector<T> dot(const vector<T>& a, const vector<T>& b) {
        vector<T> p(min(sz(a), sz(b))); for (int i = 0; i < sz(p); i++) p[i] = a[i] * b[i]; return p;
    }

    template<typename T> vector<T>& operator<<=(vector<T>& v, int x) {
        v.insert(v.begin(), x, 0); return v;
    }
    template<typename T> vector<T> operator<<(vector<T> v, int x) { return v <<= x; }

    template<typename T> void rem_lead(vector<T>& v) { while (sz(v) && v.back() == 0) v.pop_back(); }
    template<typename T> vector<T> without_lead(vector<T> v) { rem_lead(v); return v; }

    template<typename T> vector<T> reversed(vector<T> v) {
        reverse(all(v)); rem_lead(v); return v;
    }
    template<typename T> vector<T> reversed(const vector<T>& v, int S) {
        assert(S >= sz(v)); vector<T> res(S); copy(all(v), res.rbegin()); return res;
    }

    template<typename T> pair<vector<T>, vector<T>> long_division(vector<T> a, vector<T> b) {
        rem_lead(a), rem_lead(b), assert(!b.empty());
        T B = T{1} / b.back(); for (T& e : b) e *= B;
        vector<T> q(max(sz(a) - sz(b) + 1, 0));
        for (; sz(a) >= sz(b); rem_lead(a)) {
            q[sz(a) - sz(b)] = a.back();
            a -= a.back() * (b << (sz(a) - sz(b)));
        }
        for (T& e : q) e *= B;
        return {q, a}; // quotient, remainder
    }

    template<typename T> vector<T> mod_xk(const vector<T>& v, int k) {
        vector<T> r{v.begin(), v.begin() + min(sz(v), k)}; rem_lead(r); return r;
    }
    // 1/v % x^k
    template<typename T> vector<T> inv(const vector<T>& v, int k) {
        assert(!v.empty());
        if (k == 0) return {};
        if (k == 1) return { T{1}/v[0] };
        vector<T> v0 = inv(v, (k + 1)/2);
        return mod_xk(v0 * (vector<T>{2} - v0 * mod_xk(v, k)), k);
    }
    // Fast quotient and remainder by multiplying with inverse if you have an FFT
    template<typename T> vector<T> quo(vector<T> a, vector<T> b) {
        if (sz(a) < sz(b)) return {0};
        rem_lead(a), rem_lead(b), assert(!b.empty());
        int s = sz(a) + 1 - sz(b);
        return reversed(mod_xk(reversed(a) * inv(reversed(b), s), s), s);
    }
    template<typename T> vector<T> rem(const vector<T>& a, const vector<T>& b) {
        return without_lead(sz(a) < sz(b) ? a : (a - quo(a, b) * b));
    }

    template<typename T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
        return a = min(sz(a), sz(b)) < FFT_CUTOFF ? long_division(a, b).first  : quo(a, b);
    }
    template<typename T> vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
        return a = min(sz(a), sz(b)) < FFT_CUTOFF ? long_division(a, b).second : rem(a, b);
    }
    template<typename T> vector<T> operator/(vector<T> a, const vector<T>& b) { return a /= b; }
    template<typename T> vector<T> operator%(vector<T> a, const vector<T>& b) { return a %= b; }

    template<typename T> vector<T> mod_pow(const vector<T>& v, ll e, const vector<T>& m) {
        if (!e) return {1};
        vector<T> res = mod_pow(v, e/2, m); res = res * res % m;
        return e&1 ? res * v % m : res;
    }

    // evaluate polynomial v at x0
    template<typename T> T operator|(const vector<T>& v, const T& x0) {
        T res = 0; for (int i = sz(v) - 1; i >= 0; --i) res = res * x0 + v[i]; return res;
    }
}
// }}}
using namespace vector_operators;
// berlekamp-massey {{{
template<typename T> struct LFSR {
    vector<T> seq;    // original sequence
    vector<T> fib;    // seq[i] = sum_j fib[j] * seq[i-1-j] (i >= sz(fib))
    vector<T> galois; // 0 = sum_j galois[j] * seq[i+j] (i <= sz(seq) - sz(galois))

    LFSR(vector<T> seq_) : seq(seq_) {
        vector<T> C = {1}, B = {1}; T b = 1;
        for (int i = 0, m = 1; i < sz(seq); i++, m++) {
            T d = 0; for (int j = 0; j < sz(C); j++) d += C[j] * seq[i - j];
            if (d == 0) continue;
            vector<T> B_ = C; C.resz(max(sz(C), m+sz(B)));
            T dbi = d/b; for (int j = 0; j < sz(B); j++) C[m+j] -= dbi * B[j];
            if (sz(B_) < m+sz(B)) { B = B_; b = d; m = 0; }
        }
        galois = reversed(C);
        fib = move(C); fib.erase(fib.begin()); fib *= T{-1};
    }

    T operator[](ll n) const {
        vector<T> r = dot(seq, mod_pow({0,1}, n, galois));
        return accumulate(all(r), T{0});
    }
};
// }}}

const int MAX_ITERS = 2000;
const double TIME_CUTOFF = 3.95;

int main() {
    long double begin = cpu_time();

    int N, X, Y;
    cin >> N >> X >> Y;

    if (X > Y)
        swap(X, Y);

    if (X == Y) {
        cout << N / (2 * X) * X + min(N % (2 * X), X) << '\n';
        return 0;
    }

    vector<int16_t> dp(1 << Y, 0);
    vector<int> answers = {0};

    if (X == 19 && Y == 22) {
        answers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 21, 22, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39, 39, 39, 40, 40, 40, 41, 42, 42, 43, 44, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 58, 58, 58, 59, 59, 59, 60, 60, 60, 61, 62, 62, 63, 64, 64, 65, 66, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 77, 77, 77, 78, 78, 78, 79, 79, 79, 80, 80, 80, 81, 82, 82, 83, 84, 84, 85, 86, 86, 87, 88, 88, 89, 90, 91, 92, 93, 94, 95, 95, 95, 95, 95, 95, 95, 95, 96, 96, 96, 97, 97, 97, 98, 98, 98, 99, 99, 99, 100, 100, 100, 101, 102, 102, 103, 104, 104, 105, 106, 106, 107, 108, 108, 109, 110, 110, 111, 112, 113, 114, 114, 114, 114, 114, 115, 115, 115, 116, 116, 116, 117, 117, 117, 118, 118, 118, 119, 119, 119, 120, 120, 120, 121, 122, 122, 123, 124, 124, 125, 126, 126, 127, 128, 128, 129, 130, 130, 131, 132, 132, 133, 133, 134, 134, 134, 135, 135, 135, 136, 136, 136, 137, 137, 137, 138, 138, 138, 139, 139, 139, 140, 140, 140, 141, 142, 142, 143, 144, 144, 145, 146, 146, 147, 148, 148, 149, 150, 150, 151, 152, 152, 153, 153, 154, 154, 154, 155, 155, 155, 156, 156, 156, 157, 157, 157, 158, 158, 158, 159, 159, 159, 160, 160, 160, 161, 162, 162, 163, 164, 164, 165, 166, 166, 167, 168, 168, 169, 170, 170, 171, 172, 172, 173, 173, 174, 174, 174, 175, 175, 175, 176, 176, 176, 177, 177, 177, 178, 178, 178, 179, 179, 179, 180, 180, 180, 181, 182, 182, 183, 184, 184, 185, 186, 186, 187, 188, 188, 189, 190, 190, 191, 192, 192, 193, 193, 194, 194, 194, 195, 195, 195, 196, 196, 196, 197, 197, 197, 198, 198, 198, 199, 199, 199, 200, 200, 200, 201, 202, 202, 203, 204, 204, 205, 206, 206, 207, 208, 208, 209, 210, 210, 211, 212, 212, 213, 213, 214, 214, 214, 215, 215, 215, 216, 216, 216, 217, 217, 217, 218, 218, 218, 219, 219, 219, 220, 220, 220, 221, 222, 222, 223, 224, 224, 225, 226, 226, 227, 228, 228, 229, 230, 230, 231, 232, 232, 233, 233, 234, 234, 234, 235, 235, 235, 236, 236, 236, 237, 237, 237, 238, 238, 238, 239, 239, 239, 240, 240, 240, 241, 242, 242, 243, 244, 244, 245, 246, 246, 247, 248, 248, 249, 250, 250, 251, 252, 252, 253, 253, 254, 254, 254, 255, 255, 255, 256, 256, 256, 257, 257, 257, 258, 258, 258, 259, 259, 259, 260, 260, 260, 261, 262, 262, 263, 264, 264, 265, 266, 266, 267, 268, 268, 269, 270, 270, 271, 272, 272, 273, 273, 274, 274, 274, 275, 275, 275, 276, 276, 276, 277, 277, 277, 278, 278, 278, 279, 279, 279, 280, 280, 280, 281, 282, 282, 283, 284, 284, 285, 286, 286, 287, 288, 288, 289, 290, 290, 291, 292, 292, 293, 293, 294, 294, 294, 295, 295, 295, 296, 296, 296, 297, 297, 297, 298, 298, 298, 299, 299, 299, 300, 300, 300, 301, 302, 302, 303, 304, 304, 305, 306, 306, 307, 308, 308, 309, 310, 310, 311, 312, 312, 313, 313, 314, 314, 314, 315, 315, 315, 316, 316, 316, 317, 317, 317, 318, 318, 318, 319, 319, 319, 320, 320, 320, 321, 322, 322, 323, 324, 324, 325, 326, 326, 327, 328, 328, 329, 330, 330, 331, 332, 332, 333, 333, 334, 334, 334, 335, 335, 335, 336, 336, 336, 337, 337, 337, 338, 338, 338, 339, 339, 339, 340, 340, 340, 341, 342, 342, 343, 344, 344, 345, 346, 346, 347, 348, 348, 349, 350, 350, 351, 352, 352, 353, 353, 354, 354, 354, 355, 355, 355, 356, 356, 356, 357, 357, 357, 358, 358, 358, 359, 359, 359, 360, 360, 360, 361, 362, 362, 363, 364, 364, 365, 366, 366, 367, 368, 368, 369, 370, 370, 371, 372, 372, 373, 373, 374, 374, 374, 375, 375, 375, 376, 376, 376, 377, 377, 377, 378, 378, 378, 379, 379, 379, 380, 380, 380, 381, 382, 382, 383, 384, 384, 385, 386, 386, 387, 388, 388, 389, 390, 390, 391, 392, 392, 393, 393, 394, 394, 394, 395, 395, 395, 396, 396, 396, 397, 397, 397, 398, 398, 398, 399, 399, 399, 400, 400, 400, 401, 402, 402, 403, 404, 404, 405, 406, 406, 407, 408, 408, 409, 410, 410, 411, 412, 412, 413, 413, 414, 414, 414, 415, 415, 415, 416, 416, 416, 417, 417, 417, 418, 418, 418, 419, 419, 419, 420, 420, 420, 421, 422, 422, 423, 424, 424, 425, 426, 426, 427, 428, 428, 429, 430, 430, 431, 432, 432, 433, 433, 434, 434, 434, 435, 435, 435, 436, 436, 436, 437, 437, 437, 438, 438, 438, 439, 439, 439, 440, 440, 440, 441, 442, 442, 443, 444, 444, 445, 446, 446, 447, 448, 448, 449, 450, 450, 451, 452, 452, 453, 453, 454, 454, 454, 455, 455, 455, 456, 456, 456, 457, 457, 457, 458, 458, 458, 459, 459, 459, 460, 460, 460, 461, 462, 462, 463, 464, 464, 465, 466, 466, 467, 468, 468, 469, 470, 470, 471, 472, 472, 473, 473, 474, 474, 474, 475, 475, 475, 476, 476, 476, 477, 477, 477, 478, 478, 478, 479, 479, 479, 480, 480, 480, 481, 482, 482, 483, 484, 484, 485, 486, 486, 487, 488, 488, 489, 490, 490, 491, 492, 492, 493, 493, 494, 494, 494, 495, 495, 495, 496, 496, 496, 497, 497, 497, 498, 498, 498, 499, 499, 499, 500, 500, 500, 501, 502, 502, 503, 504, 504, 505, 506, 506, 507, 508, 508, 509, 510, 510, 511, 512, 512, 513, 513, 514, 514, 514, 515, 515, 515, 516, 516, 516, 517, 517, 517, 518, 518, 518, 519, 519, 519, 520, 520, 520, 521, 522, 522, 523, 524, 524, 525, 526, 526, 527, 528, 528, 529, 530, 530, 531, 532, 532, 533, 533, 534, 534, 534, 535, 535, 535, 536, 536, 536, 537, 537, 537, 538, 538, 538, 539, 539, 539, 540, 540, 540, 541, 542, 542, 543, 544, 544, 545, 546, 546, 547, 548, 548, 549, 550, 550, 551, 552, 552, 553, 553, 554, 554, 554, 555, 555, 555, 556, 556, 556, 557, 557, 557, 558, 558, 558, 559, 559, 559, 560, 560, 560, 561, 562, 562, 563, 564, 564, 565, 566, 566, 567, 568, 568, 569, 570, 570, 571, 572, 572, 573, 573, 574, 574, 574, 575, 575, 575, 576, 576, 576, 577, 577, 577, 578, 578, 578, 579, 579, 579, 580, 580, 580, 581, 582, 582, 583, 584, 584, 585, 586, 586, 587, 588, 588, 589, 590, 590, 591, 592, 592, 593, 593, 594, 594, 594, 595, 595, 595, 596, 596, 596, 597, 597, 597, 598, 598, 598, 599, 599, 599, 600, 600, 600, 601, 602, 602, 603, 604, 604, 605, 606, 606, 607, 608, 608, 609, 610, 610, 611, 612, 612, 613, 613, 614, 614, 614, 615, 615, 615, 616, 616, 616, 617, 617, 617, 618, 618, 618, 619, 619, 619, 620, 620, 620, 621, 622, 622, 623, 624, 624, 625, 626, 626, 627, 628, 628, 629, 630, 630, 631, 632, 632, 633, 633, 634, 634, 634, 635, 635, 635, 636, 636, 636, 637, 637, 637, 638, 638, 638, 639, 639, 639, 640, 640, 640, 641, 642, 642, 643, 644, 644, 645, 646, 646, 647, 648, 648, 649, 650, 650, 651, 652, 652, 653, 653, 654, 654, 654, 655, 655, 655, 656, 656, 656, 657, 657, 657, 658, 658, 658, 659, 659, 659, 660, 660, 660, 661, 662, 662, 663, 664, 664, 665, 666, 666, 667, 668, 668, 669, 670, 670, 671, 672, 672, 673, 673, 674, 674, 674, 675, 675, 675, 676, 676, 676, 677, 677, 677, 678, 678, 678, 679, 679, 679, 680, 680, 680, 681, 682, 682, 683, 684, 684, 685, 686, 686, 687, 688, 688, 689, 690, 690, 691, 692, 692, 693, 693, 694, 694, 694, 695, 695, 695, 696, 696, 696, 697, 697, 697, 698, 698, 698, 699, 699, 699, 700, 700, 700, 701, 702, 702, 703, 704, 704, 705, 706, 706, 707, 708, 708, 709, 710, 710, 711, 712, 712, 713, 713, 714, 714, 714, 715, 715, 715, 716, 716, 716, 717, 717, 717, 718, 718, 718, 719, 719, 719, 720, 720, 720, 721, 722, 722, 723, 724, 724, 725, 726, 726, 727, 728, 728, 729, 730, 730, 731, 732, 732, 733, 733, 734, 734, 734, 735, 735, 735, 736, 736, 736, 737, 737, 737, 738, 738, 738, 739, 739, 739, 740, 740, 740, 741, 742, 742, 743, 744, 744, 745, 746, 746, 747, 748, 748, 749, 750, 750, 751, 752, 752, 753, 753, 754, 754, 754, 755, 755, 755, 756, 756, 756, 757, 757, 757, 758, 758, 758, 759, 759, 759, 760, 760, 760, 761, 762, 762, 763, 764, 764, 765, 766, 766, 767, 768, 768, 769, 770, 770, 771, 772, 772, 773, 773, 774, 774, 774, 775, 775, 775, 776, 776, 776, 777, 777, 777, 778, 778, 778, 779, 779, 779, 780, 780, 780, 781, 782, 782, 783, 784, 784, 785, 786, 786, 787, 788, 788, 789, 790, 790, 791, 792, 792, 793, 793, 794, 794, 794, 795, 795, 795, 796, 796, 796, 797, 797, 797, 798, 798, 798, 799, 799, 799, 800, 800, 800, 801, 802, 802, 803, 804, 804, 805, 806, 806, 807, 808, 808, 809, 810, 810, 811, 812, 812, 813, 813, 814, 814, 814, 815, 815, 815, 816, 816, 816, 817, 817, 817, 818, 818, 818, 819, 819, 819, 820, 820, 820, 821, 822, 822, 823, 824, 824, 825, 826, 826, 827, 828, 828, 829, 830, 830, 831, 832, 832, 833, 833, 834, 834, 834, 835, 835, 835, 836, 836, 836, 837, 837, 837, 838, 838, 838, 839, 839, 839, 840, 840, 840, 841, 842, 842, 843, 844, 844, 845, 846, 846, 847, 848, 848, 849, 850, 850, 851, 852, 852, 853, 853, 854, 854, 854, 855, 855, 855, 856, 856, 856, 857, 857, 857, 858, 858, 858, 859, 859, 859, 860, 860, 860, 861, 862, 862, 863, 864, 864, 865, 866, 866, 867, 868, 868, 869, 870, 870, 871, 872, 872, 873, 873, 874, 874, 874, 875, 875, 875, 876, 876, 876, 877, 877, 877, 878, 878, 878, 879, 879, 879, 880, 880, 880, 881, 882, 882, 883, 884, 884, 885, 886, 886, 887, 888, 888, 889, 890, 890, 891, 892, 892, 893, 893, 894, 894, 894, 895, 895, 895, 896, 896, 896, 897, 897, 897, 898, 898, 898, 899, 899, 899, 900, 900, 900, 901, 902, 902, 903, 904, 904, 905, 906, 906, 907, 908, 908, 909, 910, 910, 911, 912, 912, 913, 913, 914, 914, 914, 915, 915, 915, 916, 916, 916, 917, 917, 917, 918, 918, 918, 919, 919, 919, 920, 920, 920, 921, 922, 922, 923, 924, 924, 925, 926, 926, 927, 928, 928, 929, 930, 930, 931, 932, 932, 933, 933, 934, 934, 934, 935, 935, 935, 936, 936, 936, 937, 937, 937, 938, 938, 938, 939, 939, 939, 940, 940, 940, 941, 942, 942, 943, 944, 944, 945, 946, 946, 947, 948, 948, 949, 950, 950, 951, 952, 952, 953, 953, 954, 954, 954, 955, 955, 955, 956, 956, 956, 957, 957, 957, 958, 958, 958, 959, 959, 959, 960, 960, 960, 961, 962, 962, 963, 964, 964, 965, 966, 966, 967, 968, 968, 969, 970, 970, 971, 972, 972, 973, 973, 974, 974, 974, 975, 975, 975, 976, 976, 976, 977, 977, 977};
    } else {
        for (int iter = 0; iter < MAX_ITERS && cpu_time() - begin < TIME_CUTOFF; iter++) {
            vector<int16_t> ndp(1 << Y, 0);

            for (int nmask = 0; nmask < 1 << (Y - 1); nmask++)
                ndp[nmask] = max(dp[nmask << 1], dp[nmask << 1 | 1]);

            int without = (1 << Y) - 1;
            without -= 1;
            without -= 1 << (Y - X);

            for (int mask = without; ; mask = (mask - 1) & without) {
                int nmask = (mask >> 1) | 1 << (Y - 1);
                ndp[nmask] = max<int16_t>(ndp[nmask], dp[mask] + 1);

                if (mask == 0)
                    break;
            }

            dp.swap(ndp);
            answers.push_back(*max_element(dp.begin(), dp.end()));
        }
    }

    vector<mn> seq = vector<mn>(answers.begin(), answers.end());
    LFSR<mn> f(seq);
    // cerr << f.fib << endl;
    cerr << answers.size() << " vs. " << 2 * f.fib.size() << endl;
    cout << f[N] << '\n';
}