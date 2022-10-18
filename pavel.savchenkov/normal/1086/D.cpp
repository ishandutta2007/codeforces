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

int code(char ch) {
    if (ch == 'R') {
        return 0;
    }
    if (ch == 'P') {
        return 1;
    }
    if (ch == 'S') {
        return 2;
    }
    assert(0);
    return -1;
}

struct query {
    int pos;
    int nw;

    bool read() {
        if (!(cin >> pos)) {
            return 0;
        }
        --pos;
        char ch;
        cin >> ch;
        nw = code(ch);
        return 1;
    }
};

int n;
vi a;
vector<query> qs;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    int q;
    cin >> q;

    string s;
    cin >> s;
    assert(sz(s) == n);
    a.resize(n);
    forn(i, sz(s)) {
        a[i] = code(s[i]);
    }

    qs.resize(q);
    forn(i, q) {
        assert(qs[i].read());
    }
    return 1;
}

const int INF = 1e9;

struct node {
    array<int, 3> l{};
    array<int, 3> r;
    array<int, 3> cnt;

    node() {
        clear();
    }

    node(int pos, int c) {
        clear();

        l[c] = pos;
        r[c] = pos;
        cnt[c] = 1;
    }

    void clear() {
        forn(c, 3) {
            r[c] = -1;
            l[c] = INF;
            cnt[c] = 0;
        }
    }

    void merge(const node& other) {
        forn(c, 3) {
            cnt[c] += other.cnt[c];
            remin(l[c], other.l[c]);
            remax(r[c], other.r[c]);
        }
    }

    void print() const {
//        debug(l, r, cnt);
    }
};

struct segm_tree {
    vector<node> t;
    int sz;

    segm_tree(int n = 0) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        t.resize(sz * 2);
    }

    void put(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = node(pos, val);
            return;
        }

        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            put(v * 2, tl, tm, pos, val);
        } else {
            put(v * 2 + 1, tm + 1, tr, pos, val);
        }
        t[v] = t[v * 2];
        t[v].merge(t[v * 2 + 1]);
    }

    void put(int pos, int val) {
        put(1, 0, sz - 1, pos, val);
    }

    node get(int v, int tl, int tr, int l, int r) {
        remin(r, tr);
        remax(l, tl);

        if (l > r) {
            return node();
        }

        if (l == tl && r == tr) {
            return t[v];
        }

        int tm = (tl + tr) >> 1;
        node L = get(v * 2, tl, tm, l, r);
        node R = get(v * 2 + 1, tm + 1, tr, l, r);

        L.merge(R);

        return L;
    }

    node get(int l, int r) {
        return get(1, 0, sz - 1, l, r);
    }
};

bool inter(const pii& a, const pii& b) {
    return max(a.fst, b.fst) < min(a.snd, b.snd);
}

void solve() {
    segm_tree T(n);
    forn(i, n) {
        T.put(i, a[i]);
    }

    const auto ask = [&]() {
        int ans = 0;
        node z = T.get(0, n - 1);
//        z.print();

        forn(C, 3) {
            const int bad = (C + 1) % 3;
            const int good = (C + 2) % 3;

            int b = z.l[bad];
            int g = z.l[good];

            vii segs;
            if (b < g) {
                segs.pb(mp(b, g + 1));
            }

            b = z.r[bad];
            g = z.r[good];
            if (g < b) {
                segs.pb(mp(g, b + 1));
            }

            vi cc;
            for (const auto& s : segs) {
                cc.pb(s.fst);
                cc.pb(s.snd);
            }
            cc.pb(0);
            cc.pb(n);

            make_unique(cc);

            forn(i, sz(cc) - 1) {
                int l = cc[i];
                int r = cc[i + 1];
                pii seg(l, r);

                bool ok = 1;
                for (const auto& s : segs) {
                    if (inter(seg, s)) {
                        ok = 0;
                        break;
                    }
                }
                if (!ok) {
                    continue;
                }

                node cur = T.get(l, r - 1);
                ans += cur.cnt[C];
            }
        }

        return ans;
    };

    cout << ask() << "\n";
    for (const auto& q : qs) {
        T.put(q.pos, q.nw);
        cout << ask() << "\n";
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