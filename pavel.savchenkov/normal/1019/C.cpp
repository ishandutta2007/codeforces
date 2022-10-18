
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
#define SELECT_MACROS(NAME, ...) MAKE_FINAL_NAME(NAME, ARGUMENTS_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define pb push_back
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define mp(x, y) make_pair(x, y)

#define ford(...) SELECT_MACROS(ford, __VA_ARGS__)
#define ford_3(i, s, n) for (int i = int(n) - 1; i >= int(s); --i)
#define ford_2(i, n) ford_3(i, 0, n)

#define forn(...) SELECT_MACROS(forn, __VA_ARGS__)
#define forn_3(i, s, n) for (int i = int(s); i < int(n); ++i)
#define forn_2(i, n) forn_3(i, 0, n)

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...)
    #define cerr if (false) cerr
#endif

const int MAXN = int(1e6 + 10);

int n, m;
vi g[MAXN];
vi gt[MAXN];

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    cin >> m;
    forn(i, n) {
        g[i].clear();
        gt[i].clear();
    }
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
        gt[b].pb(a);
    }
    return 1;
}

bool alive[MAXN];
bool taken[MAXN];

void solve(int v) {
    if (v == n) {
        return;
    }
    if (!alive[v]) {
        solve(v + 1);
        return;
    }
    for (int to : g[v]) {
        alive[to] = 0;
    }
    solve(v + 1);
    taken[v] = 1;
    for (int from : gt[v]) {
        if (taken[from]) {
            taken[v] = 0;
            break;
        }
    }
}

void solve() {
    memset (taken, 0, sizeof taken);
    memset (alive, 1, sizeof alive);
    solve(0);

    vi ans;
    forn(v, n) {
        if (taken[v]) {
            ans.pb(v);
        }
    }

    cout << sz(ans) << endl;
    for (int v : ans) {
        cout << v + 1 << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

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