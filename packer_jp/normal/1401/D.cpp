#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int x) { return (x > 0) - (x < 0); }
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

template<int MOD = 1000000007>
struct mod_int {
    int val;
    mod_int(long long val_ = 0) : val(val_ % MOD) { if (val < 0) { val += MOD; }}
    bool operator==(const mod_int &rhs) const { return val == rhs.val; }
    bool operator!=(const mod_int &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    mod_int &operator+=(const mod_int &rhs) {
        if ((val += rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator-=(const mod_int &rhs) {
        if ((val += MOD - rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator*=(const mod_int &rhs) {
        val = (int) ((long long) val * rhs.val % MOD);
        return *this;
    }
    mod_int &operator/=(const mod_int &rhs) { return *this *= rhs.inv(); }
    mod_int operator+() const { return *this; }
    mod_int operator-() const { return -val; }
    mod_int operator++() { return *this += 1; }
    mod_int operator--() { return *this -= 1; }
    mod_int operator++(signed) {
        const mod_int ret(*this);
        ++*this;
        return ret;
    }
    mod_int operator--(signed) {
        const mod_int ret(*this);
        --*this;
        return ret;
    }
    mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }
    mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }
    mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }
    mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }
    mod_int inv() const {
        assert(val != 0);
        int a = val, b = MOD, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(x -= t * u, u);
        }
        return x;
    }
    mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::istream &operator>>(std::istream &is, mod_int &rhs) {
        long long v;
        is >> v;
        rhs = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &rhs) { return os << rhs.val; }
    struct combination {
        std::vector<mod_int> fact{1, 1}, f_inv{1, 1}, inv{0, 1};
        void calc(int n) {
            while (fact.size() <= n) {
                int i = fact.size();
                fact.push_back(fact[i - 1] * i);
                inv.push_back(-inv[MOD % i] * (MOD / i));
                f_inv.push_back(f_inv[i - 1] * inv[i]);
            }
        }
        mod_int P(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[n - r]); }
        mod_int C(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[r] * f_inv[n - r]); }
        mod_int H(int n, int r) { return C(n + r - 1, r); }
    };
};
using mint = mod_int<>;
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vvint G(n, vint());
        rep(i, n - 1) {
            int u, v;
            cin >> u >> v, u--, v--;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        vint w;
        auto dfs = [&](auto &&self, int cur, int par) -> int {
            int ret = 1;
            rep(i, G[cur].size()) {
                if (G[cur][i] == par) { continue; }
                int nxt = self(self, G[cur][i], cur);
                ret += nxt;
                w.emplace_back(nxt * (n - nxt));
            }
            return ret;
        };
        dfs(dfs, 0, -1);
        sort(all(w)), reverse(all(w));
        int m;
        cin >> m;
        vint p(m);
        rep(i, m) { cin >> p[i]; }
        sort(all(p)), reverse(all(p));
        vector<mint> x(n - 1, 1);
        if (m >= n - 1) {
            rep(i, m - (n - 2)) { x[0] *= p[i]; }
            rep(i, n - 2) { x[i + 1] = p[i + m - (n - 2)]; }
        } else {
            rep(i, m) { x[i] = p[i]; }
        }
        mint ans = 0;
        rep(i, n - 1) { ans += x[i] * w[i]; }
        cout << ans << endl;
    }
}