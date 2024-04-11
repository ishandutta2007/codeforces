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


namespace suff_arr {

const int MAXN = 1e6 + 10;
const int LOG = 20;

string s;
int n;
int p[MAXN];
int lcp[MAXN];
int pos[MAXN];
int c[MAXN];

int table[LOG][MAXN];
int log2[MAXN];

void init() {
    forn(len, MAXN) {
        int j = 0;
        while ((1 << j) <= len) {
            ++j;
        }
        log2[len] = j - 1;
    }
}

const int INF = 1e9;

int get_min(int l, int r) {
    if (l > r) {
        return INF;
    }
    int len = r - l + 1;
    int k = log2[len];

    int ans = table[k][l];
    remin(ans, table[k][r - (1 << k) + 1]);

    return ans;
}

void print() {
#ifndef LOCAL
    return;
#endif
    eprintf("p:\n");
    forn(i, sz(s)) {
        eprintf("i=%d -- %d: %s, lcp=%d, c=%d\n", i, p[i], s.substr(p[i], sz(s) - p[i]).data(), lcp[i], c[p[i]]);
    }
    eprintf("\n");
}

void build(const string& s_) {
    static int cnt[MAXN];
    static int np[MAXN];
    static int nc[MAXN];

    debug(s_);

    s = s_;
    n = sz(s);

    memset (cnt, 0, sizeof cnt);
    for (char ch : s) {
        ++cnt[int(ch)];
    }
    forn(i, 256) {
        cnt[i + 1] += cnt[i];
    }
    forn(i, sz(s)) {
        p[--cnt[int(s[i])]] = i;
    }

    int cls = 1;
    c[p[0]] = cls - 1;
    for (int i = 1; i < n; ++i) {
        if  (s[p[i]] != s[p[i - 1]]) {
            ++cls;
        }
        c[p[i]] = cls - 1;
    }

    for (int len = 1; len <= n; len *= 2) {
        memset (cnt, 0, sizeof(int) * cls);
        forn(i, n) {
            ++cnt[c[i]];
        }
        forn(i, cls - 1) {
            cnt[i + 1] += cnt[i];
        }
        ford(i, n) {
            const int j = p[i];
            int j2 = (j - len + n) % n;
            np[--cnt[c[j2]]] = j2;
        }
        memcpy(p, np, sizeof(int) * n);

        cls = 1;
        nc[p[0]] = cls - 1;
        for (int i = 1; i < n; ++i) {
            if  (c[p[i]] != c[p[i - 1]] || c[(p[i] + len) % n] != c[(p[i - 1] + len) % n]) {
                ++cls;
            }
            nc[p[i]] = cls - 1;
        }
        memcpy(c, nc, sizeof(int) * n);
    }

    forn(i, n) {
        pos[p[i]] = i;
    }

    int pref = 0;
    forn(i, n) {
        int pi = pos[i];
        if (pi == n - 1) {
            continue;
        }
        int j = p[pi + 1];
        while (i + pref < n && j + pref < n && s[i + pref] == s[j + pref]) {
            ++pref;
        }
        lcp[pi] = pref;
        pref = max(0, pref - 1);
    }

//        print();

    forn(i, n - 1) {
        table[0][i] = lcp[i];
    }
    forn(k, 1, LOG) {
        forn(i, n - 1) {
            table[k][i] = table[k - 1][i];
            int j = i + (1 << (k - 1));
            remin(table[k][i], table[k - 1][min(n - 2, j)]);
        }
    }
}

int get_lcp(int i, int j) {
    if (i == j) {
        return INF;
    }

    int l = pos[i];
    int r = pos[j];
    if (l > r) {
        swap(l, r);
    }
    int ans = get_min(l, r - 1);

    debug(i, j, ans);

    return ans;
}

};

string s;
string t;

bool read() {
    if (!(cin >> s)) {
        return 0;
    }
    cin >> t;
    return 1;
}

bool check(int r0, int r1) {
    int pos0 = 0;
    int pos1 = -1;
    int ptr = 0;
    forn(i, sz(s)) {
        if (s[i] == '0') {
            if (suff_arr::get_lcp(pos0, ptr) < r0) {
                return 0;
            }
            ptr += r0;
        } else {
            if (pos1 == -1) {
                pos1 = ptr;
            }
            if (suff_arr::get_lcp(pos1, ptr) < r1) {
                return 0;
            }
            ptr += r1;
        }
        debug(i, ptr, r0, r1);
    }
    if (r0 == r1 && suff_arr::get_lcp(pos0, pos1) >= r0) {
        return 0;
    }
    debug(r0, r1);
    assert(ptr == sz(t));
    return 1;
}

void solve() {
    suff_arr::build(t + "|");

    if (s[0] != '0') {
        for (auto& c : s) {
            c ^= '0' ^ '1';
        }
    }

    vi cnt(2);
    for (const auto& c : s) {
        ++cnt[c - '0'];
    }

    int ans = 0;
    for (int r0 = 1; ; ++r0) {
        int rest = sz(t) - cnt[0] * r0;
        if (rest <= 0) {
            break;
        }
        if (rest % cnt[1] != 0) {
            continue;
        }
        int r1 = rest / cnt[1];

        if (check(r0, r1)) {
            ++ans;
        }
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

    suff_arr::init();

    while (read()) {
        solve();
    }

    return 0;
}