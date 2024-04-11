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

uint32_t mrand_32t() {
    static std::random_device rd;
    // TODO: seed with 19937 bits, not with 32
    static std::mt19937 rng(rd());
    return rng();
}

uint64_t mrand_64t() {
    static std::random_device rd;
    // TODO: seed with 19937 bits, not with 32
    static std::mt19937_64 rng(rd());
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

#define TEST 0

#if TEST

const int MAXN = 600 + 10;

bool G[MAXN][MAXN];
#endif

int n;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
#if TEST
    int m;
    cin >> m;
    memset (G, 0, sizeof G);
    forn(it, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a][b] = G[b][a] = 1;
    }
#endif
    return 1;
}

int ask(vi vs) {
    sort(all(vs));
    vs.resize(unique(all(vs)) - vs.begin());

#if TEST
    int m = 0;
    for (int v : vs) {
        for (int u : vs) {
            m += G[v][u];
        }
    }
    assert(m % 2 == 0);
    return m / 2;
#else
    cout << "? " << sz(vs) << endl;
    for (int v : vs) {
        cout << v + 1 << " ";
    }
    cout << endl;

    int m;
    cin >> m;
    if (m == -1) {
        exit(0);
    }
    return m;
#endif
}

struct Ans {
    bool ok;
    vi vs;

    void print() const {
        if (ok) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
        cout << sz(vs) << endl;
        for (int v : vs) {
            cout << v + 1 << " ";
        }
        cout << endl;
    }
};

void append(vi& a, const vi& b) {
    for (const auto& x : b) {
        a.pb(x);
    }
}

vi merge(const vi& a, const vi& b) {
    vi c = a;
    append(c, b);
    return c;
}

Ans solve() {
    const auto get_edge = [&](const vi& vs, int v) {
        int L = -1;
        int R = sz(vs);
        while (L != R - 1) {
            int M = (L + R) / 2;
            auto cur = vi(vs.begin(), vs.begin() + (M + 1));
            cur.pb(v);
            if (ask(cur) > 0) {
                R = M;
            } else {
                L = M;
            }
        }
        if (R == sz(vs)) {
            return -1;
        }
        return vs.at(R);
    };

    vvi g(n);

    const function<bool(int, int, vi&, vi&)> dfs = [&](int v, int want, vi& was, vi& path) -> bool {
        assert(!was[v]);
        was[v] = 1;
        path.pb(v);
        if (v == want) {
            return 1;
        }

        for (int u : g[v]) {
            if (!was[u]) {
                if (dfs(u, want, was, path)) {
                    return 1;
                }
            }
        }

        assert(path.back() == v);
        path.pop_back();
        return 0;
    };

    const auto addE = [&](int v, int u) {
        if (v == -1 || u == -1) {
            return;
        }
        g[v].pb(u);
        g[u].pb(v);
    };

    vi left;
    vi right;
    left.pb(0);
    vi used(n, 0);
    used[0] = 1;

    vi pref;

    while (1) {
        vi rest;
        forn(v, n) {
            if (!used[v]) {
                rest.pb(v);
            }
        }
        if (rest.empty()) {
            break;
        }

        vi lr = left;
        append(lr, right);
        const int base = ask(lr);

        int L = -1;
        int R = sz(rest);
        while (L != R - 1) {
            int M = (L + R) / 2;
            const int old = sz(lr);
            append(lr, vi(rest.begin(), rest.begin() + (M + 1)));
            int xxx = ask(vi(rest.begin(), rest.begin() + (M + 1)));
            if (ask(lr) > base + xxx) {
                R = M;
            } else {
                L = M;
            }
            lr.resize(old);
        }
        if (R == sz(rest)) {
            append(pref, left);
            left.clear();
            right.clear();
            const int v = rest.at(0);
            used[v] = 1;
            left.pb(v);
            continue;
        }

        const int v = rest.at(R);
        used[v] = 1;

        int Lv = get_edge(left, v);
        int Rv = get_edge(right, v);

        if (Lv != -1 && Rv != -1) {
            vi was(n, 0);
            vi path;
            bool found = dfs(Lv, Rv, was, path);
            assert(found);
            path.pb(v);
            return Ans{false, path};
        }

        addE(Lv, v);
        addE(Rv, v);
        if (Lv != -1) {
            right.pb(v);
        } else if (Rv != -1) {
            left.pb(v);
        } else {
            while(1);
        }
    }

    append(pref, left);
    return Ans{true, pref};
}

int main() {
//    cin.tie(nullptr);
//    ios_base::sync_with_stdio(false);
//    cout.tie(nullptr);
//    cout.precision(12);
//    cout << fixed;

#if TEST
    #define FILE_NAME "a"
    assert(freopen(FILE_NAME ".in", "r", stdin));
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    read();
    auto ans = solve();
    ans.print();

    return 0;
}