#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define dump(a) cerr << #a " = " << (a) << endl
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int bit(int n) { return 1LL << n; }
int sign(int a) { return (a > 0) - (a < 0); }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> T sq(T a) { return a * a; }
template<typename T> void fin(T a) {
    cout << a << endl;
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
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template<typename T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {
    os << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    }
} setup;

template<int MOD = 1000000007>
struct mod_int {
    int v;
    mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}
    static int mod() { return MOD; }
    int val() const { return v; }
    mod_int &operator+=(const mod_int &a) {
        if ((v += a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    mod_int &operator-=(const mod_int &a) {
        if ((v += MOD - a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    mod_int &operator*=(const mod_int &a) {
        v = (int) ((long long) v * a.v % MOD);
        return *this;
    }
    mod_int &operator/=(const mod_int &a) { return *this *= a.inv(); }
    mod_int operator+() const { return *this; }
    mod_int operator-() const { return -v; }
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
    mod_int inv() const {
        int a = v, b = MOD, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b), std::swap(x -= t * u, u);
        }
        return x;
    }
    mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul, n >>= 1;
        }
        return ret;
    }
    friend bool operator==(const mod_int &a, const mod_int &b) { return a.v == b.v; }
    friend bool operator!=(const mod_int &a, const mod_int &b) { return std::rel_ops::operator!=(a, b); }
    friend mod_int operator+(mod_int a, const mod_int &b) { return a += b; }
    friend mod_int operator-(mod_int a, const mod_int &b) { return a -= b; }
    friend mod_int operator*(mod_int a, const mod_int &b) { return a *= b; }
    friend mod_int operator/(mod_int a, const mod_int &b) { return a /= b; }
    friend std::istream &operator>>(std::istream &is, mod_int &a) {
        long long v;
        is >> v, a = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &a) { return os << a.v; }
};
using mint = mod_int<>;

struct rolling_hash {
    using ull = unsigned long long;
    static constexpr ull MASK30 = (1ULL << 30) - 1;
    static constexpr ull MASK31 = (1ULL << 31) - 1;
    static constexpr ull MOD = (1ULL << 61) - 1;
    static constexpr ull POSITIVIZER = MOD << 2;
    static std::vector<ull> pow_base;
    int n;
    std::vector<ull> hash;
    static void push_pow(int n) {
        while (pow_base.size() <= n) { pow_base.push_back(calc_mod(mul(pow_base.back(), pow_base[1]))); }
    }
    static ull rng() {
        std::random_device rd;
        return std::uniform_int_distribution<ull>(MOD >> 1, MOD - 1)(rd);
    }
    static ull mul(ull a, ull b) {
        ull au = a >> 31;
        ull ad = a & MASK31;
        ull bu = b >> 31;
        ull bd = b & MASK31;
        ull mid = ad * bu + au * bd;
        return (au * bu << 1) + (mid >> 30) + ((mid & MASK30) << 31) + ad * bd;
    }
    static ull calc_mod(ull val) {
        val = (val & MOD) + (val >> 61);
        if (val >= MOD) { val -= MOD; }
        return val;
    }
    static ull connect(ull lhs, ull rhs, int rn) {
        push_pow(rn);
        return calc_mod(mul(lhs, pow_base[rn]) + rhs);
    }
    template<typename T> rolling_hash(const std::vector<T> &src) : n(src.size()), hash(n + 1) {
        for (int i = 0; i < src.size(); i++) { hash[i + 1] = calc_mod(mul(hash[i], pow_base[1]) + src[i]); }
        push_pow(n);
    }
    ull get_hash(int l, int r) const { return calc_mod(POSITIVIZER - mul(hash[l], pow_base[r - l]) + hash[r]); }
};
std::vector<rolling_hash::ull> rolling_hash::pow_base{1, rng()};
using rh = rolling_hash;

template<typename F> long long discrete_binary_search(long long ok, long long ng, F is_ok) {
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
}

signed main() {
    int n, q;
    cin >> n >> q;
    string s0, t;
    cin >> s0 >> t;
    vector<string> s{s0};
    while (s.size() - 1 < n && s.back().length() < 1000000) {
        string prev = s.back();
        string cur = prev;
        cur.push_back(t[s.size() - 1]);
        cur.append(prev);
        s.emplace_back(cur);
    }
    int m = s.size();
    auto to_vec = [](string s) -> vint {
        vint ret;
        for (char c:s) { ret.emplace_back(c); }
        return ret;
    };
    vector ap(26, vector<mint>(n + 1));
    rep(i, n) {
        ap[t[i] - 'a'][i + 1] = 1;
    }
    rep(i, 26) {
        rep(j, n) {
            ap[i][j + 1] += ap[i][j] * 2;
        }
    }
    while (q--) {
        int k;
        string w;
        cin >> k >> w;
        int p = discrete_binary_search(m - 1, -1, [&](int x) {
            return s[x].size() >= w.size();
        });
        if (k < p) {
            cout << 0 << endl;
            continue;
        }
        rolling_hash wh(to_vec(w));
        rolling_hash sh(to_vec(s[p]));
        mint ans = 0;
        rep(i, s[p].size() - w.size() + 1) {
            if (wh.get_hash(0, w.size()) == sh.get_hash(i, i + w.size())) { ans++; }
        }
        ans *= mint(2).pow(k - p);
        rep(i, 26) {
            rep(j, w.size()) {
                if (rh::connect(rh::connect(sh.get_hash(s[p].size() - j, s[p].size()), i + 'a', 1),
                                sh.get_hash(0, w.size() - j - 1), w.size() - j - 1) == wh.get_hash(0, w.size())) {
                    ans += ap[i][k] - ap[i][p] * mint(2).pow(k - p);
                }
            }
        }
        cout << ans << endl;
    }
}