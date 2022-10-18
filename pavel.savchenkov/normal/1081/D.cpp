#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif


#include <vector>

class DSU {
public:
    explicit DSU(int n = 0) : par(n, -1) {}

    int get(int x) {
        return par[x] < 0 ? x : par[x] = get(par[x]);
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (-par[x] < -par[y]) {
            std::swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return true;
    }

private:
    std::vector<int> par;
};


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

struct edge {
    int a, b, w;

    bool read() {
        if (!(cin >> a >> b >> w)) {
            return 0;
        }
        --a;
        --b;
        return 1;
    }

    bool operator < (const edge& e) const {
        return w < e.w;
    }

    int to(int x) const {
        assert(x == a || x == b);
        return (a ^ b) ^ x;
    }
};

int n, m, k;
vi xs;
vector<edge> es;

bool read() {
    if (!(cin >> n >> m >> k)) {
        return 0;
    }
    xs.resize(k);
    forn(i, k) {
        cin >> xs[i];
        --xs[i];
    }
    es.resize(m);
    forn(i, m) {
        assert(es[i].read());
    }
    return 1;
}

const int MAXN = 1e5 + 10;

vi g[MAXN];
bool marked[MAXN];
int sz[MAXN];

void dfs0(int v, int p) {
    sz[v] = marked[v];
    for (int id : g[v]) {
        int to = es[id].to(v);
        if (to == p) {
            continue;
        }
        dfs0(to, v);
        sz[v] += sz[to];
    }
}

void dfs1(int v, int p, int& best_id) {
    for (int id : g[v]) {
        int to = es[id].to(v);
        if (to == p) {
            continue;
        }
        if (1 <= sz[to] && sz[to] < sz(xs) && (best_id == -1 || es[best_id].w < es[id].w)) {
            best_id = id;
        }
        dfs1(to, v, best_id);
    }
}

void solve() {
    forn(i, n) {
        g[i].clear();
    }

    sort(all(es));

    DSU dsu(n);
    forn(i, sz(es)) {
        const auto& e = es[i];
        if (dsu.unite(e.a, e.b)) {
            g[e.a].pb(i);
            g[e.b].pb(i);
        }
    }

    memset (marked, 0, sizeof marked);
    for (int x : xs) {
        marked[x] = 1;
    }

    dfs0(0, 0);

    int best_id = -1;
    dfs1(0, 0, best_id);

    forn(it, k) {
        cout << es[best_id].w << " ";
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