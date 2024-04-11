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


using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vvi = std::vector<vi>;
using vii = std::vector<pii>;

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


template<typename T>
int sign(const T& t) {
    return (t > 0) - (t < 0);
}

template<typename T>
bool remax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool remin(T& a, T b) {
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


namespace std {

template<typename A, typename B>
string to_string(const pair<A, B>& p) {
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

string to_string(const char* s) {
    return string(s);
}

template<typename T>
string to_string(const vector<T>& vec) {
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
string to_string(const set<T>& s) {
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
string to_string(const map<K, V>& m) {
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

const int MOD = 1e9 + 7;

void add(int& x, int y) {
    ((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
    return x * 1ll * y % MOD;
}

int n, k;
vi a;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> k;
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
    }
    return 1;
}

struct SegmTree {
    vi t;
    int sz;

    SegmTree(int n = 0) {
        sz = 1;
        while (sz < n) sz *= 2;
        t.assign(sz * 2, 0);
    }

    int get_max(int l, int r) {
        l += sz;
        r += sz;
        int res = 0;
        while (l <= r) {
            remax(res, t[l]);
            remax(res, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }

    void upd(int pos, int val) {
        int v = sz + pos;
        remax(t[v], val);
        v >>= 1;
        while (v) {
            t[v] = 0;
            remax(t[v], t[v * 2]);
            remax(t[v], t[v * 2 + 1]);
            v >>= 1;
        }
    }
};

int brut_calc(const vi& a) {
    int ans = 0;
    forn(i, sz(a)) {
        int mx = a[i];
        for (int j = i; j < sz(a); ++j) {
            remax(mx, a[j]);
            add(ans, mx);
        }
    }
    return ans;
}

const int INF = int(1e9) + 10;

int calc(const vi& a) {
    vi st;
    int ans = 0;

//    debug(a);

    const auto push = [&](int pos, int val) {
        while (!st.empty() && val >= a[st.back()]) {
            int l = (sz(st) == 1) ? 0 : (st[sz(st) - 2] + 1);
            int r = pos - 1;
            int mid = st.back();
            assert(l <= mid);
            assert(mid <= r);
            st.pop_back();

            int coef = mul(mid - l + 1, r - mid + 1);

//            debug(l, mid, r, coef);

            add(ans, mul(coef, a[mid]));
        }
        st.pb(pos);
    };

    forn(i, sz(a)) {
        push(i, a[i]);
    }
    push(sz(a), INF);

//    debug(ans);

    return ans;
}

void solve() {
    SegmTree T(n);
    forn(i, n) {
        T.upd(i, a[i]);
    }

    int ans = 0;
    forn(rem, k - 1) {
        vi cur;
        for (int i = rem; i + (k - 1) < n; i += k - 1) {
            cur.pb(T.get_max(i, i + (k - 1)));
        }

        int cur_ans = calc(cur);
        add(ans, cur_ans);
    }

    cout << ans << endl;
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

//        break;
    }

    return 0;
}