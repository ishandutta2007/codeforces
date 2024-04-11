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

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

void add(int& x, int y) {
    ((x += y) >= MOD) && (x -= MOD);
}

void sub(int& x, int y) {
    add(x, -y + MOD);
}

int mul(int x, int y) {
    return x * 1ll * y % MOD;
}

int n;
int val[MAXN];
vi g[MAXN];

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    forn(i, n) {
        cin >> val[i];
        val[i] = (val[i] % MOD + MOD) % MOD;
    }
    forn(i, n) {
        g[i].clear();
    }
    forn(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    return 1;
}

struct Dp {
    int val[2];

    Dp() {
        memset (val, 0, sizeof val);
    }

    int& operator[](int i) {
        return val[i];
    }

    void print() const {
        forn(c, 2) {
            eprintf("%d ", val[c]);
        }
        eprintf("\n");
    }
};

Dp dp[MAXN];
int sz[MAXN];

void dfs0(int v, int p) {
    sz[v] = 1;
    dp[v] = Dp();
    dp[v][0] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs0(to, v);
        sz[v] += sz[to];
        forn(c, 2) {
            add(dp[v][c], dp[to][c ^ 1]);
        }
    }
}

int ans;

void dfs1(int v, int p, Dp up) {
    int plus = 0;
    int minus = 0;

    eprintf("\n");
    eprintf("v=%d, dp:\n", v + 1);
    dp[v].print();
    eprintf("up:\n");
    up.print();

    // from up
    add(plus, mul(up[0], sz[v]));
    add(minus, mul(up[1], sz[v]));

    // from v to up
    add(plus, n - sz[v]);

    // from to --> v
    for (int to : g[v]) {
        if  (to == p) {
            continue;
        }

        // plus
        {
            int coef = dp[to][1];
            coef = mul(coef, n - sz[to]);
            add(plus, coef);
        }
        // minus
        {
            int coef = dp[to][0];
            coef = mul(coef, n - sz[to]);
            add(minus, coef);
        }
    }

    eprintf("v=%d, plus=%d, minus=%d\n", v + 1, plus, minus);

    add(ans, mul(plus, val[v]));
    add(ans, mul(minus, MOD - val[v]));

    forn(c, 2) {
        add(up[c], dp[v][c]);
    }
    sub(up[0], 1);

    for (int to : g[v]) {
        if  (to == p) {
            continue;
        }

        Dp nup = up;
        forn(c, 2) {
            sub(nup[c], dp[to][c ^ 1]);
        }
        swap(nup[0], nup[1]);
        add(nup[0], 1);
        dfs1(to, v, nup);
    }
}

void solve() {
    dfs0(0, 0);

    ans = 0;
    Dp up;
    up[0] = 1;
    dfs1(0, 0, up); 

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();

//        break;
    }

    return 0;
}