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


using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<pii>;

#define MAKE_FINAL_NAME_HELPER(A, B) A ## B
#define MAKE_FINAL_NAME(NAME, NUM) MAKE_FINAL_NAME_HELPER(NAME ## _, NUM)
#define ARGUMENTS_SIZE_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, COUNT, ...) COUNT
#define ARGUMENTS_SIZE(...) ARGUMENTS_SIZE_HELPER(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define SELECT_MACRO(NAME, ...) MAKE_FINAL_NAME(NAME, ARGUMENTS_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define pb push_back
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define mp(x, y) make_pair(x, y)

#define ford(...) SELECT_MACRO(ford, __VA_ARGS__)
#define ford_3(i, s, n) for (int i = int(n) - 1; i >= int(s); --i)
#define ford_2(i, n) ford_3(i, 0, n)

#define forn(...) SELECT_MACRO(forn, __VA_ARGS__)
#define forn_3(i, s, n) for (int i = int(s); i < int(n); ++i)
#define forn_2(i, n) forn_3(i, 0, n)

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #define debug(x) cerr << #x " = " << x << endl;
#else
    #define eprintf(...)
    #define cerr if (false) cerr
    #define debug(x)
#endif

#include <ostream>
#include <ctime>

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
    return b ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * (b / gcd(a, b));
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

double get_time() {
    return static_cast<double>(clock()) / CLOCKS_PER_SEC;
}

uint32_t mrand_32t() {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    return rng();
}

uint64_t mrand_64t() {
    static std::random_device rd;
    static std::mt19937_64 rng(rd());
    return rng();
}

/* *************************** TEMPLATE CODE ENDS HERE ******************************** */


struct pnt {
    ll x, y;

    pnt() = default;

    pnt(ll x, ll y) : x(x), y(y) {}

    bool read() {
        if (!(cin >> x >> y)) {
            return 0;
        }
        return 1;
    }

    ll operator % (const pnt& p) const {
        return x * p.y - y * p.x;
    }

    bool operator < (const pnt& p) const {
        return mp(x, y) < mp(p.x, p.y);
    }

    pnt operator - (const pnt& p) const {
        return pnt(x - p.x, y - p.y);
    }

    void print() const {
        cout << x << " " << y << endl;
    }
};

int n;
ll S;
vector<pnt> ps;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> S;
    ps.resize(n);
    forn(i, n) {
        assert(ps[i].read());
    }
    return 1;
}

struct seg {
    int i, j;

    pnt vec() const {
        return ps[j] - ps[i];
    }

    bool operator < (const seg& s) const {
        return vec() % s.vec() > 0;
    }
};

void solve() {
    S *= 2;

    vector<seg> segs;
    forn(i, n) forn(j, n) {
        if (ps[i] < ps[j]) {
            segs.pb(seg{i, j});
        }
    }
    sort(all(segs));
    assert(sz(segs) == n * (n - 1) / 2);

    cerr << "segs:" << endl;
    for (const auto& s : segs) {
        cerr << s.i << " " << s.j << endl;
    }
    cerr << endl;

    vi order(n);
    iota(all(order), 0);
    const auto vec0 = segs[0].vec();
    sort(all(order), [&](int k1, int k2) -> bool {
       const auto vec1 = ps[k1] - ps[segs[0].i];
       const auto vec2 = ps[k2] - ps[segs[0].i];
       const auto val1 = vec0 % vec1;
       const auto val2 = vec0 % vec2;
       if (val1 == val2) {
           return ps[k1] < ps[k2];
       }
       return val1 < val2;
    });
    vi pos(n, -1);
    forn(i, n) {
        pos[order[i]] = i;
    }

    const auto check = [&](int i, int j, int k) -> bool {
        ll area = (ps[j] - ps[i]) % (ps[k] - ps[i]);
        area = abs(area);
        if (area == S) {
            cout << "Yes" << endl;
            ps[i].print();
            ps[j].print();
            ps[k].print();
            return 1;
        }
        return 0;
    };

    for (const auto& s : segs) {
        eprintf("next seg:\n");
        debug(order);

        const auto vec = s.vec();
        const auto area = [&](int k) -> ll {
            return vec % (ps[k] - ps[s.i]);
        };

        const auto find_last = [&](const ll upper) -> int {
            int L = -1;
            int R = n;
            while (L != R - 1) {
                int M = (L + R) / 2;
                if (area(order[M]) < upper) {
                    L = M;
                } else {
                    R = M;
                }
            }
            return L;
        };

        int left = find_last(-S + 1);
        if (left > -1) {
            if (check(s.i, s.j, order[left])) {
                return;
            }
        }

        int right = find_last(S + 1);
        if (right > -1) {
            if (check(s.i, s.j, order[right])) {
                return;
            }
        }

#ifdef LOCAL
        assert(is_sorted(all(order), [&](int i, int j) { return area(i) < area(j); }));
#endif

        assert(pos[s.j] == pos[s.i] + 1);
        swap(order[pos[s.i]], order[pos[s.j]]);
        swap(pos[s.i], pos[s.j]);
    }

    cout << "No" << endl;
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