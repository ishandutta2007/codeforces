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

const int JOIN = 0;
const int CANCEL = 1;
const int ASK = 2;

struct Query {
    int type;
    int t;
    int d;
    int i;
};

vector<Query> qs;

bool read() {
    int q;
    if (!(cin >> q)) {
        return 0;
    }
    qs.resize(q);
    forn(it, q) {
        string type;
        cin >> type;
        if (type == "+") {
            int t, d;
            cin >> t >> d;
            qs[it] = Query{JOIN, t, d, -1};
        } else if (type == "-") {
            int i;
            cin >> i;
            qs[it] = Query{CANCEL, -1, -1, i};
        } else if (type == "?") {
            int t;
            cin >> t;
            qs[it] = Query{ASK, t, -1, -1};
        } else {
            assert(0);
        }
    }
    return 1;
}

const int INF = 1e9;

struct knight {
    int t, d;

    bool operator < (const knight& k) const {
        return mp(t, d) < mp(k.t, k.d);
    }
};

vector<knight> ks;

struct node {
    ll t;
    ll sum;

    node() {
        t = 0;
        sum = 0;
    }

    node(int pos) {
        t = ks[pos].t + ks[pos].d;
        sum = ks[pos].d;
    }

    ll get_end(ll t0) const {
        if (sum == 0) {
            return t0;
        }

        ll end1 = t;
        ll end2 = t0 + sum;
        return max(end1, end2);
    }

    void print() const {
        eprintf("sum=%lld, t=%lld\n", sum, t);
    }
};

node merge(const node& a, const node& b) {
    node res;
    res.t = b.get_end(a.t);
    res.sum = a.sum + b.sum;
    return res;
}

struct segm_tree {
    vector<node> t;
    int sz;

    segm_tree(int n = 0) {
        sz = 1;
        while (sz < n) sz *= 2;
        t.resize(sz * 2);
    }

    ll get_end(int v, int tl, int tr, int r, ll t0) {
        if (r < tl) {
            return t0;
        }

        if (tr <= r) {
            return t[v].get_end(t0);
        }

        int tm = (tl + tr) >> 1;
        t0 = get_end(v * 2, tl, tm, r, t0);
        t0 = get_end(v * 2 + 1, tm + 1, tr, r, t0);
        return t0;
    }

    ll get_end(int r) {
        auto t0 = get_end(1, 0, sz - 1, r, 0);
//        debug(r, t0);
        return t0;
    }

    void upd(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            if (t[v].sum == 0) {
                t[v] = node(pos);
            } else {
                t[v] = node();
            }
            return;
        }

        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            upd(v * 2, tl, tm, pos);
        } else {
            upd(v * 2 + 1, tm + 1, tr, pos);
        }
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }

    void upd(int pos) {
        upd(1, 0, sz - 1, pos);
    }

    void print() const {
        forn(v, 1, sz * 2) {
            eprintf("v = %d: ", v);
            t[v].print();
        }
    }
};

void solve() {
    for (const auto& q : qs) {
        if (q.type == JOIN) {
            ks.pb(knight{q.t, q.d});
        }
    }
    sort(all(ks));

    segm_tree T(sz(ks));

    for (const auto& q : qs) {
        if (q.type == ASK) {
            int pos = lower_bound(all(ks), knight{q.t, INF}) - ks.begin();
            --pos;

            auto start_t = T.get_end(pos);
            auto ans = start_t - q.t;
            remax(ans, 0);
            cout << ans << "\n";
//            cerr << "ans = " << ans << endl;
        } else if (q.type == JOIN) {
            int pos = lower_bound(all(ks), knight{q.t, q.d}) - ks.begin();
            T.upd(pos);
        } else if (q.type == CANCEL) {
            int pos = q.i - 1;
            pos = lower_bound(all(ks), knight{qs[pos].t, qs[pos].d}) - ks.begin();
            T.upd(pos);
        }

//        eprintf("----\n");
//        T.print();
    }
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