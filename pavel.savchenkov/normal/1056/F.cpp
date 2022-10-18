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

struct task {
    int a;
    int p;

    bool read() {
        if (!(cin >> a >> p)) {
            return 0;
        }
        return 1;
    }

    bool operator < (const task& t) const {
        int L = a * 9 + a * 10;
        int R = t.a * 9 + t.a * 10;
        return L > R;
    }
};

int n;
double C, T;
vector<task> ts;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> C >> T;
    ts.resize(n);
    forn(i, n) {
        assert(ts[i].read());
    }
    return 1;
}

int solve() {
    sort(all(ts));
    assert(sz(ts) == n);

    forn(i, n) {
        debug(ts[i].a, ts[i].p);
    }

    static const int MAXN = 100 + 5;
    static const int MAXP = 10;
    static const int MAXSUM = MAXN * MAXP;
    static const double INF = 1e20;

    static double dp[MAXN][MAXN][MAXSUM];
    forn(i, n + 1) {
        forn(was, i + 1) {
            forn(sum, was * MAXP + 1) {
                dp[i][was][sum] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    static double coef[MAXN];
    forn(was, MAXN) {
        if (was == 0) {
            coef[was] = 0.9;
        } else {
            coef[was] = coef[was - 1] * 0.9;
        }
    }

    static const double EPS = 1e-9;

    const auto check = [&](double t, double dp_val, int was) -> bool {

        if (t < -EPS || t > T + EPS) {
            return 0;
        }
        remax(t, 0);
        remin(t, T);

        double s = 1 + C * t;
        double spend = t + (1 / s) * dp_val + 10 * was;

        debug(t, dp_val, was);
        if (spend <= T + EPS) {
            return 1;
        }
        return 0;
    };

    int ans = 0;
    forn(i, n + 1) {
        forn(was, i + 1) {
            forn(sum, was * MAXP + 1) {
                const auto cur_dp = dp[i][was][sum];
                if (cur_dp > INF / 2) {
                    continue;
                }

                {
                    double a = C;
                    double b = 1 + 10 * was * C - C * T;
                    double c = cur_dp + 10 * was - T;

                    double D = b * b - 4 * a * c;
                    if (D >= -EPS) {
                        remax(D, 0.0);

                        double x1 = (-b - sqrt(D)) / 2 / a;
                        double x2 = (-b + sqrt(D)) / 2 / a;

                        if (check(x1, cur_dp, was) || check(x2, cur_dp, was)) {
                            remax(ans, sum);
                        }
                    }

                    if (check(0, cur_dp, was)) {
                        remax(ans, sum);
                    }
                }
                if (i == n) {
                    continue;
                }

                debug(i, was, sum, cur_dp);

                // do not take
                remin(dp[i + 1][was][sum], cur_dp);

                // take
                remin(dp[i + 1][was + 1][sum + ts[i].p], cur_dp + ts[i].a / coef[was]);
            }
        }
    }

    return ans;
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

    int tc;
    cin >> tc;
    forn(it, tc) {
        assert(read());
        auto ans = solve();
        cout << ans << endl;

//        break;
    }

    return 0;
}