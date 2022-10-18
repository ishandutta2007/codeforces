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


template<typename T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& vec) {
    os << "{ ";
    bool first = true;
    for (const auto& it : vec) {
        if (!first) {
            os << ", ";
        }
        os << it;
        first = false;
    }
    os << " }";
    return os;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const std::set<T>& s) {
    os << "{ ";
    bool first = true;
    for (const auto& it : s) {
        if (!first) {
            os << ", ";
        }
        os << it;
        first = false;
    }
    os << " }";
    return os;
}


template<typename K, typename V>
std::ostream& operator <<(std::ostream& os, const std::map<K, V>& m) {
    os << "{" << "\n";
    for (const auto& it : m) {
        os << " " << it.first << " -> " << it.second << "\n";
    }
    os << "}" << "\n";
    return os;
}

void debug_out() {
    std::cerr << std::endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << " " << H;
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

struct pnt {
    int x, y;

    pnt() {
        x = y = 0;
    }

    pnt(int x, int y) : x(x), y(y) {}

    bool read() {
        if (!(cin >> x >> y)) {
            return 0;
        }
        return 1;
    }

    ll operator % (const pnt& p) const {
        return x * 1ll * p.y - y * 1ll * p.x;
    }

    int type() const {
        if (y > 0 || (y == 0 && x >= 0)) {
            return 0;
        }
        return 1;
    }

    bool operator < (const pnt& p) const {
        if (type() != p.type()) {
            return type() < p.type();
        }
        ll prod = *this % p;
        return prod > 0;
    }

    bool operator <= (const pnt& p) const {
        return !(p < *this);
    }

    pnt operator - (const pnt& p) const {
        return pnt(x - p.x, y - p.y);
    }

    pnt operator + (const pnt& p) const {
        return pnt(x + p.x, y + p.y);
    }
};

int n;
vector<pnt> ps;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    ps.resize(n);
    forn(i, n) {
        assert(ps[i].read());
    }
    return 1;
}

ll C2(int cnt) {
    assert(cnt >= 0);
    return cnt * 1ll * (cnt - 1) / 2;
}

ll calc(int L, int R) {
    ll ans = C2(L);
    ans *= C2(R);
    return ans;
}

ll brut() {
    ll ans = 0;
    forn(i, n) forn(j, n) {
        if (i == j) {
            continue;
        }
        int L = 0;
        int R = 0;
        pnt dir = ps[j] - ps[i];
        forn(k, n) {
            if (k == i || k == j) {
                continue;
            }
            ll prod = dir % (ps[k] - ps[i]);
            assert(prod != 0);
            if (prod > 0) {
                ++L;
            } else {
                ++R;
            }
        }
        ans += calc(L, R);
    }
    return ans / 2;
}

ll get(vector<pnt> ps) {
    sort(all(ps));

    const auto after = [&](int pos, const pnt& vec) -> bool {
        if (pos + 1 == sz(ps)) {
            if (ps[pos] <= vec) {
                return 1;
            }
            if (vec <= ps[0]) {
                return 1;
            }
            return 0;
        }
        return (ps[pos] <= vec) && (vec <= ps[pos + 1]);
    };

    ll ans = 0;
    int j = 0;
    forn(i, sz(ps)) {
        const pnt vec = pnt(0, 0) - ps[i];
        int iters = 0;
        while (!after(j, vec)) {
            ++j;
            if (j == sz(ps)) {
                j = 0;
            }
            ++iters;
            assert(iters <= 5 * sz(ps));
        }

        // i + k == j
        int k = j - i;
        if (k < 0) {
            k += sz(ps);
        }
        assert(k >= 0);
        int L = k;
        int R = sz(ps) - 1 - L;
        assert(R >= 0);
        ans += calc(L, R);
    }
    return ans;
}

ll solve() {
//    return brut();

    ll ans = 0;
    forn(i, n) {
        vector<pnt> cur_ps;
        forn(j, n) {
            if (i != j) {
                cur_ps.pb(ps[j] - ps[i]);
            }
        }
        ans += get(cur_ps);
    }
    return ans / 2;
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
        ll ans = solve();
        cout << ans << endl;
    }

    return 0;
}