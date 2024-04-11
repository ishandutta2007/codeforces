#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr ull bit(int n) { return 1ull << n; }
constexpr ll sign(ll a) { return (a > 0) - (a < 0); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
constexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }
template <typename T> constexpr T sq(const T &a) { return a * a; }
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U> bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <typename T, typename U> bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
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
struct rep {
    struct itr {
        int v;
        itr(int v) : v(v) {}
        void operator++() { ++v; }
        int operator*() const { return v; }
        bool operator!=(const itr &i) const { return v != i.v; }
    };
    int l, r;
    rep(int r) : l(min(0, r)), r(r) {}
    rep(int l, int r) : l(min(l, r)), r(r) {}
    itr begin() const { return l; };
    itr end() const { return r; };
};
struct per {
    struct itr {
        int v;
        itr(int v) : v(v) {}
        void operator++() { --v; }
        int operator*() const { return v; }
        bool operator!=(const itr &i) const { return v != i.v; }
    };
    int l, r;
    per(int r) : l(min(0, r)), r(r) {}
    per(int l, int r) : l(min(l, r)), r(r) {}
    itr begin() const { return r - 1; };
    itr end() const { return l - 1; };
};
struct io_setup {
    static constexpr ll PREC = 20;
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
    bool operator==(const modint &a) const { return val == a.val; }
    bool operator!=(const modint &a) const { return rel_ops::operator!=(*this, a); }
    modint operator+() const { return *this; }
    modint operator-() const { return modint(-val); }
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
using mint = modint<998244353>;

int main() {
    ll n, m;
    cin >> n >> m;
    vll l(n), r(n);
    for (ll i : rep(n)) cin >> l[i] >> r[i];
    vector<mint> cnt(m + 1);
    for (ll g : rep(1, m + 1)) {
        ll m_ = fdiv(m, g);
        vector dp(n + 1, vector<mint>(m_ + 1));
        fill(all(dp[0]), 1);
        for (ll i : rep(n)) {
            ll l_ = cdiv(l[i], g), r_ = fdiv(r[i], g);
            if (l_ > r_) continue;
            for (ll j : rep(m_ + 1)) {
                if (j >= l_) dp[i + 1][j] += dp[i][j - l_];
                if (j > r_) dp[i + 1][j] -= dp[i][j - r_ - 1];
            }
            for (ll j : rep(m_)) dp[i + 1][j + 1] += dp[i + 1][j];
        }
        cnt[g] = dp[n][m_];
    }
    for (ll g : per(1, m + 1)) {
        for (ll i = g + g; i <= m; i += g) { cnt[g] -= cnt[i]; }
    }
    cout << cnt[1] << endl;
}