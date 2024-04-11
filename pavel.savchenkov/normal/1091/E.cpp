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



int n;
vi d;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    d.resize(n);
    forn(i, n) {
        cin >> d[i];
    }
    return 1;
}

static const ll INF = 1e18;

struct segm_tree {
    vll t;
    int sz;

    explicit segm_tree(const vll& a) {
        sz = 1;
        while (sz < sz(a)) {
            sz *= 2;
        }
        t.assign(sz * 2, INF);
        forn(i, sz(a)) {
            t[sz + i] = a[i];
        }
        for (int v = sz - 1; v > 0; --v) {
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll get_min(int l, int r) {
        l += sz;
        r += sz;
        ll ans = INF;
        while (l <= r) {
            remin(ans, t[l]);
            remin(ans, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return ans;
    }
};

vll pref;

ll sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return pref.at(r + 1) - pref.at(l);
}

ll suff_sum(int from, int mn) {
    // min(d[i], mn), i >= from
    if (from >= n) {
        return 0;
    }
    int L = from - 1;
    int R = n;
    while (L != R - 1) {
        int M = (L + R) / 2;
        if (d[M] >= mn) {
            L = M;
        } else {
            R = M;
        }
    }

    ll ans = max(0, L - from + 1) * 1ll * mn;
    ans += sum(R, n - 1);

    return ans;
}

void solve() {
    sort(all(d));
    reverse(all(d));

    pref = vll(n + 1);
    forn(i, n) {
        pref[i + 1] = pref[i] + d[i];
    }

    vll bal_inc(n);
    forn(i, n) {
        const int k = (i + 1) + 1;
        ll cur = k * 1ll * (k - 1) + suff_sum(i + 1, k) - sum(0, i);
        bal_inc[i] = cur;
    }

    vll suff_min_bal_inc(n + 1, INF);
    ford(i, n) {
        suff_min_bal_inc[i] = suff_min_bal_inc[i + 1];
        remin(suff_min_bal_inc[i], bal_inc[i]);
    }

    ll sum_d = 0;
    forn(i, n) {
        sum_d += d[i];
    }

    vll bal0(n);
    vll bal1(n);
    forn(i, n) {
        const int k = i + 1;
        ll cur = k * 1ll * (k - 1) + suff_sum(i + 1, k) - sum(0, i);
        bal0[i] = cur;
        bal1[i] = bal0[i] + k;
    }

    segm_tree T_bal0(bal0);
    segm_tree T_bal1(bal1);

    set<int> ans;
    for (int dd = n, i = 0; dd >= 0; --dd) {
        while (i < n && dd < d[i]) {
            ++i;
        }

        if (suff_min_bal_inc[i] - dd < 0) {
//            debug(dd, suff_min_bal_inc[i] - dd);
            continue;
        }

        int j = dd - 1;
        if (T_bal1.get_min(0, j) < 0) {
//            debug(dd, T_bal1.get_min(0, j));
            continue;
        }

        if (T_bal0.get_min(j + 1, i - 1) + dd < 0) {
//            debug(dd, T_bal0.get_min(j + 1, i - 1) + dd);
            continue;
        }

        const int k = i + 1;
        ll cur_bal = k * 1ll * (k - 1) + suff_sum(i, k) - (sum(0, i - 1) + dd);
        if (cur_bal < 0) {
//            debug(dd, cur_bal);
            continue;
        }

        if ((sum_d + dd) % 2 != 0) {
//            debug(dd, sum_d);
            continue;
        }

        ans.insert(dd);
    }

    if (ans.empty()) {
        ans.insert(-1);
    }

    for (int dd : ans) {
        cout << dd << " ";
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

//        break;
    }

    return 0;
}