#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

using v_t = int32_t;
using vv_t = int64_t;
template<v_t MOD> struct modnum {
    static_assert(std::numeric_limits<v_t>::max() / 2 >= MOD, "Addition overflows v_t");
    static_assert(std::numeric_limits<vv_t>::max() / MOD >= MOD, "Multiplication overflows vv_t");
 
    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(v_t(_v % MOD)) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend std::istream& operator >> (std::istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend std::ostream& operator << (std::ostream& o, const modnum& n) { return o << n.v; }
 
    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
    friend bool operator <  (const modnum& a, const modnum& b) { return a.v <  b.v; }
 
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
            g %= r; std::swap(g, r);
            x -= q * y; std::swap(x, y);
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
        std::vector<int> tot_pr;
        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);
 
        for (v_t r = 2; r < MOD; r++) if (std::gcd(r, MOD) == 1) {
            bool root = true;
            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }
 
    static modnum generator() { static modnum g = primitive_root(); return g; }
    static v_t discrete_log(modnum v) {
        static const v_t M = ceil(std::sqrt(MOD));
        static std::unordered_map<v_t, v_t> table;
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
        static std::vector<modnum> table{ 0, 1 };
        while (int(table.size()) <= deg) {
            modnum w = unity_root(int(table.size()));
            for (int s = int(table.size()), i = s / 2; i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }
 
    static modnum factorial(int n) {
        static std::vector<modnum> fact = {1};
        assert(n >= 0);
        if (int(fact.size()) <= n) {
            int had = fact.size();
            fact.resize(n + 1);
            for (int i = had; i <= n; i++) fact[i] = fact[i-1] * i;
        }
        return fact[n];
    }
    static modnum inverse_factorial(int n) {
        static std::vector<modnum> finv = {1};
        assert(n >= 0);
        if (int(finv.size()) <= n) {
            int had = finv.size();
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
using num = modnum<MOD>;

const int FFT_CUTOFF = 150;
template<typename RandomAccessIterator>
void fft(RandomAccessIterator first, RandomAccessIterator last, bool invert) {
    int N = int(last - first);
    assert(__builtin_popcount(N) == 1);
 
    for (int i = 1, j = 0, k; i < N; i++) {
        for (k = N >> 1; (j ^= k) < k; k >>= 1);
        if (i < j) std::swap(first[i], first[j]);
    }
 
    using T = typename std::remove_reference<decltype(*first)>::type;
 
    for (int l = 1; l < N; l <<= 1) {
        for (int i = 0; i < N; i += 2 * l) {
            for (int j = 0; j < l; j++) {
                T w = T::unity_root(2 * l, invert ? -j : j);
                T u = first[i + j];
                T v = first[i + j + l] * w;
                first[i + j] = u + v;
                first[i + j + l] = u - v;
            }
        }
    }
 
    if (invert) {
        T N_inverse = T{N}.inv();
 
        for (int i = 0; i < N; i++)
            first[i] = first[i] * N_inverse;
    }
};
namespace ntt {
    template<int MOD>
    std::vector<modnum<MOD>> multiply(std::vector<modnum<MOD>> a, std::vector<modnum<MOD>> b) {
        if (a.empty() || b.empty()) return {};
        int s = int(a.size()) + int(b.size()) - 1;
        if (std::min(a.size(), b.size()) < FFT_CUTOFF) {
            const vv_t VV_BOUND = std::numeric_limits<vv_t>::max() - vv_t(MOD) * MOD;
            std::vector<vv_t> res(s);
            for (int i = 0; i < int(a.size()); i++) {
                for (int j = 0; j < int(b.size()); j++) {
                    res[i + j] += vv_t(a[i].v) * b[j].v;
                    if (res[i + j] > VV_BOUND)
                        res[i + j] %= MOD;
                }
            }
            return {res.begin(), res.end()};
        }
 
        int N = 1 << (s > 1 ? 32 - __builtin_clz(s - 1) : 0);
 
        bool eq = a == b;
        a.resize(N);
        fft(a.begin(), a.end(), false);
 
        if (!eq) {
            b.resize(N);
            fft(b.begin(), b.end(), false);
            for (int i = 0; i < N; i++) a[i] *= b[i];
        } else {
            for (int i = 0; i < N; i++) a[i] *= a[i];
        }
 
        fft(a.begin(), a.end(), true);
        a.resize(s);
        return a;
    }
};


// a tree is possible iff every node (other than 0) connects to at least one node less than it
// let's say you're attaching a subtree with A greater than root and B smaller than root
// something smaller than root must be in component with 1

// component with 1 and all the small things, components with the rest
// how many ways to arrange small component
// arrange big component: parent must always be less so: (A - 1)!
// arrange small component: B! (you can also choose what the root of the component is)

int n;
num dp[N], fact[N];

num nck(int n, int k) {
    return fact[n] / fact[k] / fact[n - k];
}
void solve() {
    cin >> n;

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++) fact[i] = fact[i-1] * i;

    /*
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min((n - 1) / 2, i); j++) {
            dp[i] += fact[j - 1] * dp[i - j] * nck(i - 1, j - 1);
        }
    }
    */

    vector<num> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = num(1) / i;
        sum[i] += sum[i-1];
    }

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = fact[i];
        dp[i] -= fact[i] * (sum[i] - sum[(n - 1) / 2]);
        /*
        for (int j = (n - 1) / 2 + 1; j <= i; j++) {
            // fact[i] / fact[j] / fact[i - j]
            // dp[i] -= nck(i, j) * fact[j - 1] * fact[i - j];
            dp[i] -= fact[i] / j;
        }
        */
    }


    cout << dp[n-1] << ' ';
    vector<num> one(n), two(n);
    for (int k = 0; k <= (n - 1) / 2; k++) {
        one[n - 1 - k] = 1 / fact[k];
    }
    for (int j = 1; j <= (n - 1) / 2; j++) {
        two[j] = fact[j - 1] * dp[n - 1 - j] / fact[n - 1 - j];
    }
    // j - k = i
    // j + (n - 1 - k) = i + n - 1
    /*
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++)
            ans[j + k] += one[k] * two[j];
    }
    */
    auto ans = ntt::multiply(one, two);

    /*
    for (int i = 1; i < n; i++) {
        num ans = 0;
        for (int j = i; j <= (n - 1) / 2; j++) {
            // fact[j - 1] * dp[n - 1 - j] / fact[n - 1 - j]
            // 1 / fact[j - i]
            // ans += fact[j - 1] * dp[n - 1 - j] * nck(n - i - 1, j - i);
            

            // ans += f(j - i) * f(j)
            // k = (j - i)
            // ans += f(k) * f(i + k)
            // things with common difference i

            ans += fact[j - 1] * dp[n - 1 - j] / fact[j - i] / fact[n - 1 - j]; // nck(n - i - 1, j - i);
        }
        ans *= i * fact[n - i - 1];
        cout << ans << ' ';
    }
    */
    for (int i = 1; i < n; i++) {
        cout << ans[i + n - 1] * i * fact[n - i - 1] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}