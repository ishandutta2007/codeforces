#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;

#define prev prev_______________________
#define next next_______________________
#define hash hash_______________________
#define y1 y1___________________________

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#define cerr if (0) cerr
#endif

using ld = long double;

const int MOD = 998244353;

void add(int& x, int y) {
    ((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
    return x * 1ll * y % MOD;
}

const int MAXN = 3e5 + 10;

int n;
vi g[MAXN];

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    forn(i, n) {
        g[i].clear();
    }
    forn(it, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    return 1;
}

int dp[MAXN][3];

void dfs(int v, int p) {
    vi sons;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        sons.pb(to);
        dfs(to, v);
    }

    vvi d(2, vi(2, 0));
    d[0][0] = 1;
    for (int to : sons) {
        vvi nd(2, vi(2, 0));

        forn(was1, 2) {
            forn(was2, 2) {
                forn(now, 3) {
                    int nwas1 = was1 || (now == 1);
                    if (now == 1 && was1) {
                        continue;
                    }
                    int nwas2 = was2 || (now == 2);
                    int cur = mul(d[was1][was2], dp[to][now]);
                    add(nd[nwas1][nwas2], cur);
                }
            }
        }

        d.swap(nd);
    }

    // eprintf("v = %d\n", v + 1);
    // forn(was1, 2) {
    //     forn(was2, 2) {
    //         eprintf("d[was1=%d][was2=%d] = %d\n", was1, was2, d[was1][was2]);
    //     }
    // }

    // 0
    forn(was2, 2) {
        add(dp[v][0], d[1][was2]);
    }
    add(dp[v][0], d[0][0]);

    // 1
    forn(was2, 2) {
        add(dp[v][1], d[0][was2]);
    }

    // 2
    forn(was2, 2) {
        add(dp[v][2], d[1][was2]);
    }

    // forn(c, 3) {
    //     eprintf("dp[v=%d][c=%d] = %d\n", v + 1, c, dp[v][c]);
    // }
}

void solve() {
    memset (dp, 0, sizeof dp);
    dfs(0, 0);

    int ans = dp[0][0];
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cout.precision(20);
    cout << fixed;

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    // freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();

        // break;
    }

    return 0;
}