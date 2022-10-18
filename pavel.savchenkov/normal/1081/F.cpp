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

#define TEST 0

#if TEST
string init_secret;
string secret;
#endif

void rev(string& s, int l, int r) {
    forn(i, l, r + 1) {
        s[i] ^= '0' ^ '1';
    }
}

int cnt(const string& s, int l, int r) {
    int ans = 0;
    forn(i, l, r + 1) {
        ans += s[i] == '1';
    }
    return ans;
}

int n, t0;

bool read() {
#if !TEST
    if (!(cin >> n >> t0)) {
        return 0;
    }
#else
    n = 1 + mrand_32t() % 10;
    secret = string(n, '0');
    forn(i, n) {
        secret[i] = '0' + mrand_32t() % 2;
    }

    n = sz(secret);
    t0 = cnt(secret, 0, n - 1);
    init_secret = secret;
#endif
    return 1;
}

int ask(int l, int r) {
    assert(0 <= l);
    assert(l <= r);
    assert(r < n);
#if !TEST
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int t;
    cin >> t;
    if (t == -1) {
        exit(0);
    }
    return t;
#else
    if (mrand_32t() % 2 == 0) {
        rev(secret, 0, r);
//        cerr << "rev " << 0 << " " << r << endl;
    } else {
        rev(secret, l, n - 1);
//        cerr << "rev " << l << " " << n - 1 << endl;
    }
    return cnt(secret, 0, n - 1);
#endif
}

string solve_even() {
    vii qs;
    string s(n, '0');
    int t = t0;
    forn(i, n) {
        while (1) {
            int tt = ask(i, i);
            if (abs(tt - t) % 2 == (i + 1) % 2) {
                const int y = cnt(s, 0, i - 1);
                const int p = i;
                rev(s, 0, i - 1);
                const int now = cnt(s, 0, i - 1);
                assert(now == p - y);
                const int val = tt - t - p + 2 * y - 1;
                if (val == 0) {
                    s[i] = '1';
                } else if (val == -2) {
                    s[i] = '0';
                } else {
                    debug(i, t, tt, val);
                    assert(0);
                }
                t = tt;
                qs.pb(mp(0, i));
                break;
            } else {
                qs.pb(mp(i, n - 1));
                t = tt;
            }
        }
    }

    for (const auto& q : qs) {
        int l, r;
        tie(l, r) = q;
        rev(s, l, r);
    }

    return s;
}

string solve_odd() {
    int t = t0;

    vi pref(n);

    vector<pii> qs0;
    {
        string s(n, '0');
        for (int i = 1; i < n; i += 2) {
            while (1) {
                int tt = ask(i - 1, i);
                if (abs(tt - t) % 2 == 0) {
                    const int y = cnt(s, 0, i - 2);
                    const int p = i - 1;
                    rev(s, 0, i - 2);
                    const int now = cnt(s, 0, i - 2);
                    assert(now == p - y);
                    const int val = tt - t - p + 2 * y - 2;
                    if (abs(val) % 2 != 0) {
                        assert(0);
                    }
                    const int x = (-val) / 2;
                    if (x == 0) {
                        s[i] = s[i - 1] = '1';
                    } else if (x == 1) {
                        s[i] = '1';
                        s[i - 1] = '0';
                    } else if (x == 2) {
                        s[i] = s[i - 1] = '0';
                    } else {
                        debug(x);
                        assert(0);
                    }
//                    debug("now:", s, secret, i, t, tt, x);
                    t = tt;
                    qs0.pb(mp(0, i));
                    break;
                } else {
                    t = tt;
                    qs0.pb(mp(i - 1, n - 1));
                }
            }
        }

        for (int i = 1; i < n; i += 2) {
            pref[i] = (s[i - 1] - '0') + (s[i] - '0');
            if (i > 1) {
                pref[i] += pref[i - 2];
            }
        }
        pref[n - 1] = t;

//        debug(s, secret, pref);
    }

    int another_t0 = t;

    vector<pii> qs1;
    {
        string s(n, '0');
        for (int i = n - 2; i > 0; i -= 2) {
            while (1) {
                debug(i);
                int tt = ask(i, i + 1);
                if (abs(tt - t) % 2 == 0) {
                    const int y = cnt(s, i + 2, n - 1);
                    const int p = n - 1 - (i + 1);
                    rev(s, i + 2, n - 1);
                    const int now = cnt(s, i + 2, n - 1);
                    assert(now == p - y);
                    const int val = tt - t - p + 2 * y - 2;
                    if (abs(val) % 2 != 0) {
                        assert(0);
                    }
                    const int x = (-val) / 2;
                    if (x == 0) {
                        s[i] = s[i + 1] = '1';
                    } else if (x == 1) {
                        s[i] = '1';
                        s[i + 1] = '0';
                    } else if (x == 2) {
                        s[i] = s[i + 1] = '0';
                    } else {
                        debug(x);
                        assert(0);
                    }
//                    debug(s, secret, i);
                    t = tt;
                    qs1.pb(mp(i, n - 1));
                    break;
                } else {
                    t = tt;
                    qs1.pb(mp(0, i + 1));
                }
            }
        }

//        debug(s, secret);
//        debug(qs1);

        for (const auto& q : qs1) {
            int l, r;
            tie(l, r) = q;
            rev(s, l, r);
        }

        vi suff(n);
        for (int i = n - 2; i > 0; i -= 2) {
            suff[i] = (s[i] - '0') + (s[i + 1] - '0');
            if (i < n - 2) {
                suff[i] += suff[i + 2];
            }
            pref[i - 1] = another_t0 - suff[i];
        }

//        debug(suff);
//        debug(pref);
    }

    string s(n, '0');
    forn(i, n) {
        int prev = 0;
        if (i > 0) {
            prev = pref[i - 1];
        }
        if (pref[i] > prev) {
            s[i] = '1';
        }
    }

    for (const auto& q : qs0) {
        int l, r;
        tie(l, r) = q;
        rev(s, l, r);
    }

    return s;
}

string solve() {
    if (n % 2 == 0) {
        return solve_even();
    } else {
        return solve_odd();
    }
}

int main() {
//    cin.tie(nullptr);
//    ios_base::sync_with_stdio(false);
//    cout.tie(nullptr);
//    cout.precision(12);
//    cout << fixed;

#ifdef LOCAL
    #define FILE_NAME "a"
//    assert(freopen(FILE_NAME ".in", "r", stdin));
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
    while (1) {
        read();

        auto ans = solve();

        if (ans != init_secret) {
            cout << "ans = " << ans << ", correct = " << init_secret << endl;
            return 0;
        } else {
            cout << "OK, ans = " << ans << endl;
        }
    }
#endif

    read();
    auto ans = solve();
    cout << "! " << ans << endl;

    return 0;
}