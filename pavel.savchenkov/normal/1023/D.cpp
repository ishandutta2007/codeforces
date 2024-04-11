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


struct SegmTree {
    vi t;
    int sz;

    SegmTree(int n = 0) {
        sz = 1;
        while (sz < n) sz *= 2;
        t.assign(sz * 2, -1);
    }

    void push(int v) {
        if (t[v] == -1) {
            return;
        }
        t[v * 2] = t[v * 2 + 1] = t[v];
        t[v] = -1;
    }

    void put(int v, int tl, int tr, int l, int r, int val) {
        l = max(l, tl);
        r = min(r, tr);
        if (l > r) {
            return;
        }

        if (l == tl && r == tr) {
            t[v] = val;
            return;
        }

        push(v);

        int tm = (tl + tr) >> 1;
        put(v * 2, tl, tm, l, r, val);
        put(v * 2 + 1, tm + 1, tr, l, r, val);
    }

    void put(int l, int r, int val) {
        put(1, 0, sz - 1, l, r, val);
    }

    int get(int v, int tl, int tr, int pos) {
        if (tl == tr || t[v] != -1) {
            return t[v];
        }

        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            return get(v * 2, tl, tm, pos);
        } else {
            return get(v * 2 + 1, tm + 1, tr, pos);
        }
    }

    int get(int pos) {
        return get(1, 0, sz - 1, pos);
    }
};

int n, q;
vi a;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> q;
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
        --a[i];
    }
    return 1;
}

struct Seg {
    int l{-1};
    int r{-1};
};

vi solve() {
    if (*max_element(all(a)) == -1) {
        forn(i, n) {
            a[i] = q - 1;
        }
        return a;
    }

    vi left(q, n);
    vi right(q, -1);
    forn(i, n) {
        if (a[i] == -1) {
            continue;
        }
        remin(left[a[i]], i);
        remax(right[a[i]], i);
    }

    vector<Seg> segs(q);
    vi who_start(n, -1);
    vi who_end(n, -1);
    forn(i, q) {
        int l = left[i];
        int r = right[i];
        if (l <= r) {
            segs[i] = Seg{l, r};
            who_start[l] = i;
            who_end[r] = i;
        }
    }

    for (int i = 0, j = 0; i < n; ) {
        if (a[i] != -1) {
            ++i;
            continue;
        }
        j = i;
        while (j < n && a[j] == -1) {
            ++j;
        }
        // [i, j)
        if (i > 0) {
            int id = who_end[i - 1];
            if (id != -1) {
                remax(segs[id].r, j - 1);
            }
        } else if (j < n) {
            int id = who_start[j];
            if (id != -1) {
                remin(segs[id].l, i);
            }
        } else {
            assert(0);
        }
        i = j;
    }

    int max_alive = -1;
    forn(i, q) {
        if (segs[i].l != -1) {
            remax(max_alive, i);
        }
    }
    assert(max_alive != -1);

    forn(i, max_alive) {
        if (segs[i].l == -1) {
            segs[i] = segs[max_alive];
        }
    }

    int pos_empty = -1;
    forn(i, n) {
        if (a[i] == -1) {
            pos_empty = i;
            break;
        }
    }
    if (max_alive != q - 1 && pos_empty == -1) {
        return {};
    }
    forn(i, max_alive + 1, q) {
        segs[i] = Seg{pos_empty, pos_empty};
    }

    SegmTree T(n);
    forn(i, q) {
        T.put(segs[i].l, segs[i].r, i);
    }
    vi got_a(n);
    forn(i, n) {
        got_a[i] = T.get(i);
        if (a[i] != -1 && got_a[i] != a[i]) {
            return {};
        }
    }

    return got_a;
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
        vi ans = solve();
        if (ans.empty()) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            assert(sz(ans) == n);
            forn(i, n) {
                cout << ans[i] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}