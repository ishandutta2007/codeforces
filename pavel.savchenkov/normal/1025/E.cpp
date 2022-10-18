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

#define TEST 0

const int MAXN = 50 + 5;

int n, m;
int who[MAXN][MAXN];
pii dest[MAXN];

bool read() {
    memset (who, -1, sizeof who);

#if !TEST
    if (!(cin >> n)) {
        return 0;
    }
    cin >> m;
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        who[x][y] = i;
    }
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        dest[i] = mp(x, y);
    }
#else
    n = 2 + rand() % 10;
    m = 1 + rand() % n;
    assert(m <= n);
    vii poses;
    forn(x, n) forn(y, n) {
        poses.pb(mp(x, y));
    }
    random_shuffle(all(poses));
    forn(i, m) {
        int x, y;
        tie(x, y) = poses[i];
        who[x][y] = i;
    }
    random_shuffle(all(poses));
    forn(i, m) {
        dest[i] = poses[i];
    }
#endif
    return 1;
}

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool on(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

struct Move {
    pii from;
    pii to;

    void print() const {
        cout << from.fst + 1 << " " << from.snd + 1 << " " << to.fst + 1 << " " << to.snd + 1 << "\n";
    }
};

vector<Move> ans;

void make_move(pii from, pii to) {
    assert(on(from.fst, from.snd));
    assert(on(to.fst, to.snd));

    ans.pb(Move{from, to});
    assert(who[to.fst][to.snd] == -1);
    swap(who[from.fst][from.snd], who[to.fst][to.snd]);
}

int dist[MAXN][MAXN];
pii prev[MAXN][MAXN];

void move_someone(int X, int Y) {
    assert(X == 0);
    memset (dist, -1, sizeof dist);
    forn(y, Y) {
        dist[0][y] = 0;
    }
    dist[X][Y] = 0;
    queue<pii> q;
    q.push(mp(X, Y));
    pii from(-1, -1);
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if (who[x][y] != -1) {
            from = mp(x, y);
            break;
        }
        forn(d, 4) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (on(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                prev[nx][ny] = mp(x, y);
                q.push(mp(nx, ny));
            }
        }
    }
    assert(from.fst != -1);
    int cnt = dist[from.fst][from.snd];
    while (from != mp(X, Y)) {
        pii nxt = prev[from.fst][from.snd];
        make_move(from, nxt);
        from = nxt;
        --cnt;
    }
    assert(cnt == 0);
}

void print() {
#ifndef LOCAL
    return;
#endif
    ford(y, n) {
        forn(x, n) {
            cerr << who[x][y] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
}

void solve() {
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    ans.clear();
    forn(i, m) {
        move_someone(0, i);
    }

//    eprintf("make column\n");
//    print();

    vi perm(m);
    iota(all(perm), 0);
    sort(all(perm), [&](int i, int j) {
        int xi, yi;
        tie(xi, yi) = dest[i];

        int xj, yj;
        tie(xj, yj) = dest[j];

        if (xi != xj) {
            return xi < xj;
        }
        return yi < yj;
    });

    forn(i, m) {
        int y0 = -1;
        forn(y, m) {
            if (who[0][y] == perm[i]) {
                y0 = y;
                break;
            }
        }
        assert(y0 != -1);
        assert(y0 >= i);
        make_move(mp(0, y0), mp(1, y0));
        for (int y = y0 - 1; y >= i; --y) {
            make_move(mp(1, y + 1), mp(1, y));
        }
        for (int y = y0 - 1; y >= i; --y) {
            make_move(mp(0, y), mp(0, y + 1));
        }
        make_move(mp(1, i), mp(0, i));
    }

//    eprintf("make sorted column\n");
//    print();

    forn(i, m) {
        assert(who[0][i] == perm[i]);
    }

    //~ 5000 now

    const auto final = [&](int i) {
        int X, Y;
        tie(X, Y) = dest[perm[i]];

        if (X == 0) {
            assert(Y >= i);
            for (int y = i; y < Y; ++y) {
                make_move(mp(0, y), mp(0, y + 1));
            }
            return;
        }

        make_move(mp(0, i), mp(1, i));

        if (Y > i) {
            for (int y = i; y < Y; ++y) {
                make_move(mp(1, y), mp(1, y + 1));
            }
        } else {
            for (int y = i; y > Y; --y) {
                make_move(mp(1, y), mp(1, y - 1));
            }
        }
        for (int x = 1; x < X; ++x) {
            make_move(mp(x, Y), mp(x + 1, Y));
        }
    };

    for (int i = m - 1, j = m - 1; i >= 0; i = j) {
        while (j >= 0 && dest[who[0][i]].fst == dest[who[0][j]].fst) {
            --j;
        }

        int l = j + 1;
        int r = i;
        while (l <= r) {
            if (dest[who[0][l]].snd <= l) {
                final(l);
                ++l;
            } else {
                assert(dest[who[0][r]].snd >= r);
                final(r);
                --r;
            }
        }
    }

    vi ok(m);
    forn(x, n) forn(y, n) {
        if (who[x][y] != -1) {
            assert(dest[who[x][y]] == mp(x, y));
            ok[who[x][y]] = 1;
        }
    }
    assert(*min_element(all(ok)) > 0);

#if !TEST
    cout << sz(ans) << endl;
    for (const auto& a : ans) {
        a.print();
    }
#endif
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

        print();
        forn(i, m) {
            cerr << i << ": " << dest[i].fst << " " << dest[i].snd << endl;
        }

        solve();

        cerr << "OK n = " << n << endl;
    }
#endif

    while (read()) {
        solve();

//        break;
    }

    return 0;
}