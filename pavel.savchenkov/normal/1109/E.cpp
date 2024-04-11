#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif



#include <cstdio>
#include <iostream>
#include <cmath>
#include <utility>
#include <memory>
#include <memory.h>
#include <cstdlib>
#include <set>
#include <map>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <algorithm>
#include <complex>
#include <vector>
#include <random>
#include <ctime>
#include <ostream>
#include <queue>
#include <array>


using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vvi = std::vector<vi>;
using vii = std::vector<pii>;
using vll = std::vector<ll>;
using pll = std::pair<ll, ll>;

#define MAKE_FINAL_NAME_HELPER(A, B) A ## B
#define MAKE_FINAL_NAME(NAME, NUM) MAKE_FINAL_NAME_HELPER(NAME ## _, NUM)
#define ARGUMENTS_SIZE_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, COUNT, ...) COUNT
#define ARGUMENTS_SIZE(...) ARGUMENTS_SIZE_HELPER(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define SELECT_MACRO(NAME, ...) MAKE_FINAL_NAME(NAME, ARGUMENTS_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define pb push_back
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define mp(x, y) make_pair(x, y)
#define fst first
#define snd second

#define ford(...) SELECT_MACRO(ford, __VA_ARGS__)
#define ford_3(i, s, n) for (int i = int(n) - 1; i >= int(s); --i)
#define ford_2(i, n) ford_3(i, 0, n)

#define forn(...) SELECT_MACRO(forn, __VA_ARGS__)
#define forn_3(i, s, n) for (int i = int(s); i < int(n); ++i)
#define forn_2(i, n) forn_3(i, 0, n)

#define y1 y1___
#define prev prev___
#define next next___
#define hash hash___
#define left left___
#define right right___
#include <chrono>

template<typename T>
int sign(const T& t) {
    return (t > 0) - (t < 0);
}

template<typename T, typename U>
bool remax(T& a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T, typename U>
bool remin(T& a, U b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
T gcd(T a, T b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template<typename T>
T lcm(T a, T b) {
    a = std::abs(a);
    b = std::abs(b);
    return a / gcd(a, b) * b;
}

double get_time() {
    return static_cast<double>(clock()) / CLOCKS_PER_SEC;
}

long long current_nanoseconds() {
    return std::chrono::steady_clock::now().time_since_epoch().count();
}

#ifdef LOCAL
long long default_seed = 1;
#else
long long default_seed = current_nanoseconds();
#endif

uint32_t mrand_32t() {
    static std::mt19937 rng(default_seed);
    return rng();
}

uint64_t mrand_64t() {
    static std::mt19937_64 rng(default_seed);
    return rng();
}

template<typename T>
void make_unique(std::vector<T>& v) {
    std::sort(std::begin(v), std::end(v));
    v.erase(std::unique(std::begin(v), std::end(v)), std::end(v));
}

#include <sstream>

namespace std {

template<typename A, typename B>
string to_string(const pair <A, B>& p) {
    string str;
    str += "(";
    str += to_string(p.first);
    str += ", ";
    str += to_string(p.second);
    str += ")";
    return str;
}

string to_string(bool value) {
    return value ? "true" : "false";
}

template<typename T>
string to_string(const vector <T>& vec) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : vec) {
        if (!first) {
            str += ", ";
        }
        str += to_string(it);
        first = false;
    }
    str += " }";
    return str;
}

template<typename T>
string to_string(const set <T>& s) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : s) {
        if (!first) {
            str += ", ";
        }
        str += to_string(it);
        first = false;
    }
    str += " }";
    return str;
}


template<typename K, typename V>
string to_string(const map <K, V>& m) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : m) {
        if (!first) {
            str += ", ";
        }
        first = false;
        str += to_string(it.first);
        str += " -> ";
        str += to_string(it.second);
    }
    str += " }";
    return str;
}

string to_string(const string& s) {
    return "\"" + s + "\"";
}

string to_string(const char* s) {
    return to_string(string(s));
}

string to_string(char ch) {
    return "\'" + string(1, ch) + "\'";
}

template<size_t N>
string to_string(const bitset<N>& b) {
    string res(N, '0');
    for (size_t i = 0; i < N; ++i) {
        res[i] = '0' + b[i];
    }
    return res;
}

template <typename T>
string to_string(const T& t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}

}

void debug_out() {
    std::cerr << std::endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << " " << std::to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #define debug(...) std::cerr << "[" << #__VA_ARGS__ <<  "]:", debug_out(__VA_ARGS__);
#else
    #define eprintf(...)
    #define cerr if (false) cerr
    #define debug(...)
#endif

using namespace std;

/* *************************** TEMPLATE CODE ENDS HERE ******************************** */

#define assert(c) void(c)

int mul(int a, int b, int mod) {
    return a * 1ll * b % mod;
}

void add(int& a, int b, int mod) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int mpow(int a, int p, int mod) {
    int res = 1;
    for (; p > 0; p >>= 1, a = mul(a, a, mod)) {
        if (p & 1) {
            res = mul(res, a, mod);
        }
    }
    return res;
}

using Tp = int;
Tp gcdext (Tp a, Tp b, Tp &x, Tp &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    Tp res = gcdext (b, a % b, y, x);
    y -= x * (a / b);
    return res;
}

int inv(int a, int mod) {
    int x, y;
    auto g = gcdext(a, mod, x, y);
    assert(g == 1);

    int ans = (x % mod + mod) % mod;
    assert(mul(a, ans, mod) == 1);
    return ans;
}

int n, mod;
vi a;
int cnt_q;

bool read() {
    if (!(cin >> n >> mod)) {
        return 0;
    }
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
    }

    cin >> cnt_q;
    return 1;
}

vii factor(int num) {
    vii f;
    for (int x = 2; x * x <= num; ++x) {
        if (num % x == 0) {
            int d = 0;
            while (num % x == 0) {
                num /= x;
                ++d;
            }
            f.pb(mp(x, d));
        }
    }
    if (num > 1) {
        f.pb(mp(num, 1));
    }
    return f;
}

vii f_mod;
vi ps;

struct number {
    int x;
    vi degs;

    number() {
        x = 1;
        degs.assign(sz(ps), 0);
    }

    explicit number(int num) : number() {
        forn(i, sz(ps)) {
            while (num % ps[i] == 0) {
                num /= ps[i];
                ++degs[i];
            }
        }
        assert(gcd(num, mod) == 1);
        x = num;
    }

    number& operator *= (const number& n) {
        x = mul(n.x, x, mod);
        assert(sz(degs) == sz(n.degs));
        forn(i, sz(degs)) {
            degs[i] += n.degs[i];
        }
        return *this;
    }

    number& operator /= (const number& n) {
        int inv_nx = inv(n.x, mod);
        x = mul(x, inv_nx, mod);
        assert(sz(degs) == sz(n.degs));
        forn(i, sz(degs)) {
            degs[i] -= n.degs[i];
            assert(degs[i] >= 0);
        }
        return *this;
    }

    int val() const {
        int res = x;
        forn(i, sz(ps)) {
            res = mul(res, mpow(ps[i], degs[i], mod), mod);
        }
        return res;
    }
};

void precalc() {
    f_mod = factor(mod);
    ps.clear();
    forn(i, sz(f_mod)) {
        ps.pb(f_mod[i].fst);
    }
}

struct segm_tree {
    vi sum;
    vector<number> to_push;
    vi vv;
    int sz;

    explicit segm_tree(const vi& a) {
        sz = 1;
        while (sz < sz(a)) sz *= 2;

        sum.assign(sz * 2, 0);
        to_push.assign(sz * 2, number());
        vv.assign(sz * 2, 1);

//        cerr << "assign DONE" << endl;

        forn(i, sz(a)) {
            to_push[sz + i] = number(a[i]);
        }

//        cerr << "to_push DONE" << endl;

        forn(i, sz) {
            sum[sz + i] = to_push[sz + i].val();
        }

//        cerr << "sum DONE" << endl;

        for (int v = sz - 1; v > 0; --v) {
            upd(v);
        }

        forn(i, sz * 2) {
            vv[i] = to_push[i].val();
        }
    }

    void upd(int v) {
        sum[v] = sum[v * 2];
        add(sum[v], sum[v * 2 + 1], mod);
    }

    void push(int v) {
        assert(v < sz);
        int val = vv[v]; //to_push[v].val();
        for (int u = v * 2; u <= v * 2 + 1; ++u) {
            to_push[u] *= to_push[v];
            vv[u] = mul(vv[u], val, mod);
            sum[u] = mul(sum[u], val, mod);
        }
        to_push[v] = number();
        vv[v] = 1;
    }

    void go_mul(int v, int tl, int tr, int l, int r, const number& x, const int& x_val) {
        remax(l, tl);
        remin(r, tr);
        if (l > r) {
            return;
        }

        if (l == tl && r == tr) {
            to_push[v] *= x;
            vv[v] = mul(vv[v], x_val, mod);
            sum[v] = mul(sum[v], x_val, mod);
            return;
        }

        push(v);

        int tm = (tl + tr) >> 1;
        go_mul(v * 2, tl, tm, l, r, x, x_val);
        go_mul(v * 2 + 1, tm + 1, tr, l, r, x, x_val);

        upd(v);
    }

    void go_mul(int l, int r, number x) {
        go_mul(1, 0, sz - 1, l, r, x, x.val());
    }

    void go_div(int v, int tl, int tr, int pos, const number& x) {
        if (tl == tr) {
            assert(tl == pos);
            to_push[v] /= x;
            vv[v] = to_push[v].val();
            sum[v] = to_push[v].val();
            return;
        }

        push(v);

        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            go_div(v * 2, tl, tm, pos, x);
        } else {
            go_div(v * 2 + 1, tm + 1, tr, pos, x);
        }

        upd(v);
    }

    void go_div(int pos, number x) {
        go_div(1, 0, sz - 1, pos, x);
    }

    int get_sum(int v, int tl, int tr, int l, int r) {
        remax(l, tl);
        remin(r, tr);
        if (l > r) {
            return 0;
        }

        if (l == tl && r == tr) {
            return sum[v];
        }

        push(v);

        int tm = (tl + tr) >> 1;

        int ans = get_sum(v * 2, tl, tm, l, r);
        add(ans, get_sum(v * 2 + 1, tm + 1, tr, l, r), mod);

        upd(v);

        return ans;
    }

    int get_sum(int l, int r) {
        return get_sum(1, 0, sz - 1, l, r);
    }
};

void solve() {
    precalc();

//    cerr << "precalc DONE" << endl;

    segm_tree T(a);

//    cerr << "segm_tree DONE" << endl;

    forn(it, cnt_q) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            --r;

            T.go_mul(l, r, number(x));
        } else if (t == 2) {
            int p, x;
            cin >> p >> x;
            --p;

            T.go_div(p, number(x));
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;

            int ans = T.get_sum(l, r);

            cout << ans << "\n";
        } else {
            assert(0);
        }
    }

    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(12);
    cout << fixed;

#ifdef LOCAL
    #define FILE_NAME "a"
    assert(freopen(FILE_NAME ".in", "r", stdin));
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

    return 0;
}