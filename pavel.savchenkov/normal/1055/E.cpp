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



int n, s, m, k;
vi a;
vii segs;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> s >> m >> k;
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
    }
    segs.resize(s);
    forn(i, s) {
        cin >> segs[i].fst >> segs[i].snd;
        --segs[i].fst;
        --segs[i].snd;
    }
    return 1;
}

// can <= X
bool can(const int X) {
    vi good(n);
    forn(i, n) {
        good[i] = a[i] <= X;
    }

//    debug(X);

    vi id(n);
    int was = 0;
    forn(i, n) {
        if (good[i]) {
            id[i] = was;
            ++was;
        } else {
            id[i] = -1;
        }
    }

//    debug(good);
//    debug(id);

    vii nsegs;
    for (const auto& s : segs) {
        int l = s.fst;
        int r = s.snd;

        int L = n;
        int R = -1;
        for (int i = l; i <= r; ++i) {
            if (good[i]) {
                remin(L, id[i]);
                remax(R, id[i]);
            }
        }
        if (R == -1) {
            continue;
        }
        assert(L <= R);
        nsegs.pb(mp(L, R));
//        debug(L, R);
    }

    const int N = was;

    static const int MAXN = 1500 + 10;
    int dp[MAXN][MAXN];
    memset (dp, 0, sizeof dp);

    static int best[MAXN];
    memset (best, -1, sizeof best);
    for (const auto& s : nsegs) {
        int l = s.fst;
        int r = s.snd;

        for (int i = l; i <= r; ++i) {
            remax(best[i], r);
        }
    }

    forn(i, N + 1) {
        forn(cnt, sz(nsegs) + 1) {
            const int& cur_dp = dp[i][cnt];
            if (cnt <= m && cur_dp >= k) {
//                cerr << "can k-th <= " << X << endl;
                return 1;
            }
//            debug(i, cnt, cur_dp);
            int r = best[i];
            if (r != -1) {
                remax(dp[r + 1][cnt + 1], cur_dp + (r - i + 1));
            }
            remax(dp[i + 1][cnt], cur_dp);
        }
    }

    return 0;
}

int solve() {
    vi vals = a;
    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());

    int L = -1;
    int R = sz(vals);
    while (L != R - 1) {
        int M = (L + R) / 2;
        if (can(vals.at(M))) {
            R = M;
        } else {
            L = M;
        }
    }
    if (R == sz(vals)) {
        return -1;
    }
    return vals.at(R);
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
        auto ans = solve();
        cout << ans << endl;

//        break;
    }

    return 0;
}