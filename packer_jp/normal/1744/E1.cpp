#include <bits/stdc++.h>
using namespace std;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define uniq(a) (a).erase(unique(all(a)), (a).end())
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
constexpr double PI = 3.14159265358979323846;
constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr ll sign(ll a) { return (a > 0) - (a < 0); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
constexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }
constexpr ull bit(int n) { return 1ull << n; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template <typename T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {
    os << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
#ifdef ONLINE_JUDGE
#define dump(...) (void(0))
#else
void debug() { cerr << endl; }
template <typename Head, typename... Tail> void debug(Head &&head, Tail &&... tail) {
    cerr << head;
    if (sizeof...(Tail)) cerr << ", ";
    debug(tail...);
}
#define dump(...) cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ", debug(__VA_ARGS__)
#endif
template <typename T> constexpr T mypow(T x, ll n) {
    T ret = 1;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}
constexpr ll modpow(ll x, ll n, ll mod) {
    x %= mod;
    ll ret = 1;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}
template <typename T> T xor64(T lb, T ub) {
    static ull x = 88172645463325252ull;
    x ^= x << 7;
    return lb + (x ^= x >> 9) % (ub - lb);
}
constexpr ll safemod(ll x, ll mod) { return (x % mod + mod) % mod; }
template <typename T> constexpr T sq(const T &a) { return a * a; }
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U> bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <typename T, typename U> bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <typename T> T make_vector(T &&a) { return a; }
template <typename... Ts> auto make_vector(int h, Ts &&... ts) { return vector(h, make_vector(ts...)); }
struct rep {
    struct itr {
        ll v;
        itr(ll v) : v(v) {}
        void operator++() { ++v; }
        ll operator*() const { return v; }
        bool operator!=(itr i) const { return v < *i; }
    };
    ll l, r;
    rep(ll l, ll r) : l(l), r(r) {}
    rep(ll r) : rep(0, r) {}
    itr begin() const { return l; };
    itr end() const { return r; };
};
struct per {
    struct itr {
        ll v;
        itr(ll v) : v(v) {}
        void operator++() { --v; }
        ll operator*() const { return v; }
        bool operator!=(itr i) const { return v > *i; }
    };
    ll l, r;
    per(ll l, ll r) : l(l), r(r) {}
    per(ll r) : per(0, r) {}
    itr begin() const { return r - 1; };
    itr end() const { return l - 1; };
};
struct io_setup {
    static constexpr int PREC = 20;
    io_setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} iOS;
template <ll MOD = 1000000007> struct modint {
    ll val;
    modint(ll val = 0) : val(val >= 0 ? val % MOD : (MOD - (-val) % MOD) % MOD) {}
    static ll mod() { return MOD; }
    modint inv() const {
        ll a = val, b = MOD, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    modint pow(ll k) const {
        modint ret = 1, mul = val;
        while (k) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    modint &operator+=(const modint &a) {
        if ((val += a.val) >= MOD) val -= MOD;
        return *this;
    }
    modint &operator-=(const modint &a) {
        if ((val += MOD - a.val) >= MOD) val -= MOD;
        return *this;
    }
    modint &operator*=(const modint &a) {
        (val *= a.val) %= MOD;
        return *this;
    }
    modint &operator/=(const modint &a) { return *this *= a.inv(); }
    modint operator+() const { return *this; }
    modint operator-() const { return modint(-val); }
    friend bool operator==(const modint &a, const modint &b) { return a.val == b.val; }
    friend bool operator!=(const modint &a, const modint &b) { return rel_ops::operator!=(a, b); }
    friend modint operator+(const modint &a, const modint &b) { return modint(a) += b; }
    friend modint operator-(const modint &a, const modint &b) { return modint(a) -= b; }
    friend modint operator*(const modint &a, const modint &b) { return modint(a) *= b; }
    friend modint operator/(const modint &a, const modint &b) { return modint(a) /= b; }
    friend istream &operator>>(istream &is, modint &a) {
        ll val;
        is >> val;
        a = modint(val);
        return is;
    }
    friend ostream &operator<<(ostream &os, const modint &a) { return os << a.val; }
};
template <typename F> ll bisect(ll ok, ll ng, F f) {
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <typename mint> struct combination {
    vector<mint> fact, finv, inv;
    combination(int n) : fact(n + 1), finv(n + 1), inv(n + 1) {
        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i : rep(2, n + 1)) {
            fact[i] = fact[i - 1] * i;
            inv[i] = -inv[mint::mod() % i] * (mint::mod() / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    mint P(int n, int r) { return r < 0 || n < r ? 0 : (fact[n] * finv[n - r]); }
    mint C(int n, int r) { return P(n, r) * finv[r]; }
    mint H(int n, int r) { return C(n + r - 1, r); }
    mint catalan(int n) { return C(2 * n, n) / (n + 1); }
};

struct uf {
    int n;
    vector<int> ps;
    uf(int n) : n(n), ps(n, -1) {}
    int find(int i) {
        if (ps[i] < 0) return i;
        return ps[i] = find(ps[i]);
    }
    int size(int i) { return -ps[find(i)]; }
    void unite(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (-ps[i] < -ps[j]) swap(i, j);
        ps[i] += ps[j];
        ps[j] = i;
    }
    bool same(int i, int j) { return find(i) == find(j); }
    vector<vector<int>> groups() {
        vector<vector<int>> ret(n);
        for (int i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<int> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};

template <typename S> struct lazy_segtree {
    using V = typename S::val_t;
    using F = typename S::fn_t;
    int n, size, log;
    vector<V> val;
    vector<F> lazy;
    lazy_segtree(int n) : lazy_segtree(vector(n, S::e())) {}
    lazy_segtree(const vector<V> &src) : n(src.size()) {
        for (size = 1, log = 0; size < n; size <<= 1, ++log) {}
        val.resize(size << 1);
        copy(all(src), val.begin() + size);
        lazy.resize(size << 1, S::id());
        for (int i : per(1, size)) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    V reflect(int i) { return S::mapping(lazy[i], val[i]); }
    void push(int i) {
        val[i] = S::mapping(lazy[i], val[i]);
        lazy[i << 1 | 0] = S::composition(lazy[i], lazy[i << 1 | 0]);
        lazy[i << 1 | 1] = S::composition(lazy[i], lazy[i << 1 | 1]);
        lazy[i] = S::id();
    }
    void thrust(int i) {
        for (int j = log; j; j--) push(i >> j);
    }
    void recalc(int i) {
        while (i >>= 1) val[i] = S::op(reflect(i << 1 | 0), reflect(i << 1 | 1));
    }
    void set(int i, const V &a) {
        thrust(i += size);
        val[i] = a;
        lazy[i] = S::id();
        recalc(i);
    }
    void apply(int l, int r, F f) {
        if (l >= r) return;
        thrust(l += size);
        thrust(r += size - 1);
        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) lazy[i] = S::composition(f, lazy[i]), ++i;
            if (j & 1) --j, lazy[j] = S::composition(f, lazy[j]);
        }
        recalc(l);
        recalc(r);
    }
    V get(int i) {
        thrust(i += size);
        return reflect(i);
    }
    V prod(int l, int r) {
        if (l >= r) return S::e();
        thrust(l += size);
        thrust(r += size - 1);
        V a = S::e(), b = S::e();
        for (++r; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = S::op(a, reflect(l++));
            if (r & 1) b = S::op(reflect(--r), b);
        }
        return S::op(a, b);
    }
    template <typename G> int max_right(int l, G g) {
        if (l == n) return n;
        thrust(l += size);
        V a = S::e();
        do {
            while (~l & 1) l >>= 1;
            if (!g(S::op(a, reflect(l)))) {
                while (l < size) {
                    push(l);
                    l = l << 1 | 0;
                    if (g(S::op(a, reflect(l)))) a = S::op(a, reflect(l++));
                }
                return l - size;
            }
            a = S::op(a, reflect(l++));
        } while ((l & -l) != l);
        return n;
    }
    template <typename G> int min_left(int r, G g) {
        if (r == 0) return 0;
        thrust((r += size) - 1);
        V a = S::e();
        do {
            --r;
            while (r > 1 && r & 1) r >>= 1;
            if (!g(S::op(reflect(r), a))) {
                while (r < size) {
                    push(r);
                    r = r << 1 | 1;
                    if (g(S::op(reflect(r), a))) a = S::op(reflect(r--), a);
                }
                return r + 1 - size;
            }
            a = S::op(reflect(r), a);
        } while ((r & -r) != r);
        return 0;
    }
};

template <typename S> struct matrix {
    using V = typename S::val_t;
    vector<vector<V>> val;
    matrix(int n, int m) : matrix(vector(n, vector(m, S::zero()))) {}
    matrix(const vector<vector<V>> &src) : val(src) {}
    vector<V> &operator[](int i) { return val[i]; }
    const vector<V> &operator[](int i) const { return val[i]; }
    int height() const { return val.size(); }
    int width() const { return val[0].size(); }
    static matrix id(int n) {
        matrix ret(n, n);
        for (int i : rep(n)) ret[i][i] = S::one();
        return ret;
    }
    void row_add(int i, int j, V a) {
        for (int k : rep(width())) { val[i][k] += val[j][k] * a; }
    }
    bool place_nonzero(int i, int j) {
        for (int k : rep(i, height())) {
            if (val[k][j] != S::zero()) {
                if (k > i) row_add(i, k, S::one());
                break;
            }
        }
        return val[i][j] != S::zero();
    }
    matrix upper_triangular() const {
        matrix ret(*this);
        for (int i = 0, j = 0; i < height() && j < width(); j++) {
            if (!ret.place_nonzero(i, j)) continue;
            for (int k : rep(i + 1, height())) ret.row_add(k, i, -ret[k][j] / ret[i][j]);
            i++;
        }
        return ret;
    }
    V det() const {
        V ret = S::one();
        matrix ut = upper_triangular();
        for (int i : rep(height())) ret *= ut[i][i];
        return ret;
    }
    matrix inv() const {
        matrix ex(height(), width() << 1);
        for (int i : rep(height())) {
            for (int j : rep(width())) { ex[i][j] = val[i][j]; }
        }
        for (int i : rep(height())) ex[i][width() + i] = S::one();
        matrix ut = ex.upper_triangular();
        for (int i : per(height())) {
            ut.row_add(i, i, S::one() / ut[i][i] - S::one());
            for (int j : rep(i)) ut.row_add(j, i, -ut[j][i] / ut[i][i]);
        }
        matrix ret(height(), width());
        for (int i : rep(height())) {
            for (int j : rep(width())) { ret[i][j] = ut[i][width() + j]; }
        }
        return ret;
    }
    matrix pow(ll k) const {
        matrix ret = matrix::id(height()), mul(*this);
        while (k) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    matrix &operator+=(const matrix &a) {
        for (int i : rep(height())) {
            for (int j : rep(width())) { val[i][j] += a[i][j]; }
        }
        return *this;
    }
    matrix &operator-=(const matrix &a) {
        for (int i : rep(height())) {
            for (int j : rep(width())) { val[i][j] -= a[i][j]; }
        }
        return *this;
    }
    matrix &operator*=(const matrix &a) {
        matrix res(height(), a.width());
        for (int i : rep(height())) {
            for (int j : rep(a.width())) {
                for (int k : rep(width())) { res[i][j] += val[i][k] * a[k][j]; }
            }
        }
        val.swap(res.val);
        return *this;
    }
    matrix &operator/=(const matrix &a) { return *this *= a.inv(); }
    bool operator==(const matrix &a) const { return val == a.val; }
    bool operator!=(const matrix &a) const { return rel_ops::operator!=(*this, a); }
    matrix operator+() const { return *this; }
    matrix operator-() const { return matrix(height(), width()) -= *this; }
    matrix operator+(const matrix &a) const { return matrix(*this) += a; }
    matrix operator-(const matrix &a) const { return matrix(*this) -= a; }
    matrix operator*(const matrix &a) const { return matrix(*this) *= a; }
    matrix operator/(const matrix &a) const { return matrix(*this) /= a; }
};

using mint = modint<998244353>;
struct mint_field {
    using val_t = mint;
    static val_t zero() { return 0; }
    static val_t one() { return 1; }
};

template <typename S> struct segtree {
    using V = typename S::val_t;
    int n, size;
    vector<V> val;
    segtree(int n) : segtree(vector(n, S::e())) {}
    segtree(const vector<V> &src) : n(src.size()) {
        for (size = 1; size < n; size <<= 1) {}
        val.resize(size << 1);
        copy(all(src), val.begin() + size);
        for (int i : per(1, size)) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    void set(int i, const V &a) {
        val[i += size] = a;
        while (i >>= 1) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    V get(int i) const { return val[i + size]; }
    V prod(int l, int r) const {
        V a = S::e(), b = S::e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = S::op(a, val[l++]);
            if (r & 1) b = S::op(val[--r], b);
        }
        return S::op(a, b);
    }
    template <typename F> int max_right(int l, F f) const {
        if (l == n) return n;
        V a = S::e();
        l += size;
        do {
            while (~l & 1) l >>= 1;
            if (!f(S::op(a, val[l]))) {
                while (l < size) {
                    l = l << 1;
                    if (f(S::op(a, val[l]))) a = S::op(a, val[l++]);
                }
                return l - size;
            }
            a = S::op(a, val[l++]);
        } while ((l & -l) != l);
        return n;
    }
    template <typename F> int min_left(int r, F f) const {
        if (r == 0) return 0;
        V a = S::e();
        r += size;
        do {
            r--;
            while (r > 1 && r & 1) r >>= 1;
            if (!f(S::op(val[r], a))) {
                while (r < size) {
                    r = r << 1 | 1;
                    if (f(S::op(val[r], a))) a = S::op(val[r--], a);
                }
                return r + 1 - size;
            }
            a = S::op(val[r], a);
        } while ((r & -r) != r);
        return 0;
    }
};

struct max_monoid {
    using val_t = ll;
    static val_t op(val_t a, val_t b) { return max(a, b); }
    static val_t e() { return 0; }
};

template <typename T, int SHIFT> struct persistent_array {
    using ptr = shared_ptr<persistent_array>;
    static constexpr int BASE = bit(SHIFT);
    static constexpr int MASK = BASE - 1;
    T val;
    array<ptr, BASE> ch;
    persistent_array(int n = 1, T val = T()) : val(val) {
        for (int i : rep(BASE)) {
            int m = (n >> SHIFT) + ((n & MASK) > i);
            if (m > 1 || m > 0 && i > 0) ch[i] = ptr(new persistent_array(m, val));
        }
    }
    persistent_array(T val, const array<ptr, BASE> &ch) : val(val), ch(ch) {}
    persistent_array(T val, const array<ptr, BASE> &ch, int i, ptr chp) : val(val), ch(ch) { this->ch[i] = chp; }
    T get(int i) const { return i > 0 ? ch[i & MASK]->get(i >> SHIFT) : val; }
    ptr setp(int i, T val) const {
        return ptr(i > 0 ? new persistent_array(this->val, ch, i & MASK, ch[i & MASK]->setp(i >> SHIFT, val))
                         : new persistent_array(val, ch));
    }
    persistent_array set(int i, T val) const { return *setp(i, val); }
};
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        for (ll x : rep(a + 1, c + 1)) {
            ll k = a * b / gcd(a * b, x);
            ll y = d - d % k;
            if (y > b) {
                cout << x << " " << y << endl;
                goto end;
            }
        }
        cout << "-1 -1" << endl;
    end:;
    }
}