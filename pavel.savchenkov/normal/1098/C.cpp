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
ll s;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> s;
    return 1;
}

ll lower_bound(int n, int b) {
    if (b == 1) {
        return n * 1ll * (n + 1) / 2;
    }

    assert(b >= 2);
    ll ans = 0;
    ll rest = n - 1;
    ll cur = 1;
    for (int h = 1; cur > 0; ++h) {
        ans += h * cur;

        cur *= b;
        remin(cur, rest);
        rest -= cur;
    }
    return ans;
}

ll upper_bound(int n, int b) {
    return n * 1ll * (n + 1) / 2;
}

int ptr;
vi p;

void build(int n, int b, ll s, int par) {
    s -= n;
    int v = ptr++;
    p[v] = par;
    --n;

    if (n == 0) {
        assert(s == 0);
        return;
    }

//    eprintf("build: n = %d, v = %d, par = %d, s = %lld\n", n, v, par, s);

    if (lower_bound(n, b) <= s) {
        build(n, b, s, v);
        return;
    }

    const auto lower = [&](int sons, int n) {
        assert(n >= 1);
        assert(sons <= n);

        int cnt0 = n / sons;
        int cnt1 = (n + sons - 1) / sons;

        int c1 = n % sons;
        int c0 = sons - c1;

        return lower_bound(cnt1, b) * c1 + lower_bound(cnt0, b) * c0;
    };

    const auto upper = [&](int sons, int n) {
        assert(n >= 1);
        assert(sons <= n);

        int cnt0 = n / sons;
        int cnt1 = (n + sons - 1) / sons;

        int c1 = n % sons;
        int c0 = sons - c1;

        return upper_bound(cnt1, b) * c1 + upper_bound(cnt0, b) * c0;
    };

    for (int bb = 2; bb <= b && bb <= n; ++bb) {
        int best_x = -1;
        for (int x = 1; n - x >= bb - 1 && x <= (n - x) / (bb - 1) + 5; ++x) {
            ll from = lower(bb - 1, n - x);
            ll to = upper(bb - 1, n - x);

            from += lower_bound(x, b);
            to += upper_bound(x, b);

            if (from <= s && s <= to) {
                best_x = x;
                break;
            }
        }

        if (best_x == -1) {
            continue;
        }

        vi sons;
        sons.pb(best_x);

        {
            int nn = n - best_x;
            int cnt0 = nn / (bb - 1);
            int cnt1 = (nn + (bb - 1) - 1) / (bb - 1);

            int c1 = nn % (bb - 1);
            int c0 = (bb - 1) - c1;

            forn(it, c0) {
                sons.pb(cnt0);
            }
            forn(it, c1) {
                sons.pb(cnt1);
            }
        }

        for (int son : sons) {
            s -= lower_bound(son, b);
        }
//        debug(s, sons);
        assert(s >= 0);

        for (int son : sons) {
            ll from = lower_bound(son, b);
            ll to = upper_bound(son, b);

            ll cur = from;
            ll delta = min(s, to - from);
            cur += delta;
            s -= delta;

            build(son, b, cur, v);
        }
//        debug(s, sons);
        assert(s == 0);
        return;
    }

    assert(0);
}

bool solve() {
    if (s > upper_bound(n, 1)) {
        return 0;
    }
    int b = 1;
    while (b <= n - 1 && s < lower_bound(n, b)) {
        ++b;
    }
    if (b == n) {
        return 0;
    }

    ptr = 0;
    p.assign(n, -1);
    build(n, b, s, -1);

    cout << "Yes" << endl;
    forn(i, 1, n) {
        cout << p[i] + 1 << " ";
    }
    cout << endl;
    return 1;
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
        if (!solve()) {
            cout << "No" << endl;
        }
    }

    return 0;
}