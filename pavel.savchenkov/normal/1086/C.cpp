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

string to_str(const vi& s) {
    string t;
    forn(i, sz(s)) {
        t += 'a' + s[i];
    }
    return t;
}

#define TEST 0

int k;
vi s, a, b;
int n;

bool read() {
#if !TEST
    if (!(cin >> k)) {
        return 0;
    }
    const auto get = [&]() -> vi {
        string s;
        cin >> s;
        vi ss;
        forn(i, sz(s)) {
            int c = s[i] - 'a';
            assert(0 <= c && c < k);
            ss.pb(s[i] - 'a');
        }
        return ss;
    };
    s = get();
    a = get();
    b = get();

    n = sz(s);
    assert(sz(a) == n);
    assert(sz(b) == n);
#else
    n = 4;
    k = 4;

    s.resize(n);
    a.resize(n);
    b.resize(n);
    while (1) {
        forn(i, n) {
            s[i] = rand() % k;
            a[i] = rand() % k;
            b[i] = rand() % k;
        }
        if (to_str(a) <= to_str(b)) {
            break;
        }
    }
#endif
    return 1;
}

vi complete(vi z) {
    assert(sz(z) == k);
    vi was(k, 0);
    for (int c : z) {
        if (c != -1) {
            was[c] = 1;
        }
    }
    vi rest;
    forn(c, k) {
        if (!was[c]) {
            rest.pb(c);
        }
    }
    forn(c, k) {
        if (z[c] == -1) {
            assert(!rest.empty());
            z[c] = rest.back();
            rest.pop_back();
        }
    }
    return z;
}

vi exact(const vi& from, const vi& to) {
    vi z(k, -1);
    vi was(k, 0);
    assert(sz(from) == sz(to));
    forn(i, sz(from)) {
        const int c1 = from[i];
        const int c2 = to[i];
        if (z[c1] == -1) {
            if (was[c2]) {
                return {};
            }
            was[c2] = 1;
            z[c1] = c2;
        }
        if (z[c1] != c2) {
            return {};
        }
    }
    return complete(z);
}

vi sub(const vi& s, int l, int r) {
    auto res = vi(begin(s) + l, begin(s) + (r + 1));
    assert(sz(res) == r - l + 1);
    return res;
}

void print(const vi& z) {
    string S;
    forn(i, n) {
        S += 'a' + z[s[i]];
    }
    string A = to_str(a);
    string B = to_str(b);

//    debug(s, a, b);
//    debug(z);

    assert(A <= S);
    assert(S <= B);

    assert(sz(z) == k);
    cout << "YES" << "\n";
    forn(i, k) {
        cout << char('a' + z[i]);
    }
    cout << "\n";
}

bool solve() {
    for (auto to : {a, b}) {
        auto z = exact(s, to);
        if (!z.empty()) {
            print(z);
            return 1;
        }
    }

    vi best_a(n, k);
    {
        vi z(k, -1);
        vi was(k, 0);
        forn(i, n) {
            const int c1 = s[i];
            const int c2 = a[i];
            if (z[c1] != -1) {
                if (z[c1] > c2) {
                    remin(best_a[i], z[c1]);
                }
                if (z[c1] != c2) {
                    break;
                }
                continue;
            }

            forn(c, c2 + 1, k) {
                if (!was[c]) {
                    remin(best_a[i], c);
                }
            }

            if (was[c2]) {
                break;
            }
            z[c1] = c2;
            was[c2] = 1;
        }
    }
//    debug(best_a);

    vi best_b(n, -1);
    {
        vi z(k, -1);
        vi was(k, 0);
        forn(i, n) {
            const int c1 = s[i];
            const int c2 = b[i];
            if (z[c1] != -1) {
                if (z[c1] < c2) {
                    remax(best_b[i], z[c1]);
                }
                if (z[c1] != c2) {
                    break;
                }
                continue;
            }

            forn(c, 0, c2) {
                if (!was[c]) {
                    remax(best_b[i], c);
                }
            }

            if (was[c2]) {
                break;
            }
            z[c1] = c2;
            was[c2] = 1;
        }
    }
//    debug(best_b);

    int lcp = 0;
    while (lcp < n && a[lcp] == b[lcp]) {
        ++lcp;
    }
    if (lcp == n) {
        assert(a == b);
        return 0;
    }
    assert(a[lcp] != b[lcp]);

    forn(i, lcp, n) {
        if (best_a[i] < k && (i > lcp || best_a[i] < b[i])) {
            auto aa = sub(a, 0, i);
            auto ss = sub(s, 0, i);
            aa[i] = best_a[i];
            auto z = exact(ss, aa);
            print(z);
            return 1;
        }
        if (best_b[i] >= 0 && (i > lcp || best_b[i] > a[i])) {
            auto bb = sub(b, 0, i);
            auto ss = sub(s, 0, i);
            bb[i] = best_b[i];
            auto z = exact(ss, bb);
            print(z);
            return 1;
        }
    }

    return 0;
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

#if TEST
    while (1) {
    read();

    solve();
}
#endif

    int T;
    cin >> T;
    forn(t, T) {
        assert(read());
        if (!solve()) {
            cout << "NO" << "\n";
        }
    }

    return 0;
}