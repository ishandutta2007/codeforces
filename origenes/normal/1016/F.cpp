#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 312345;
const ll inf = 0x3f3f3f3f3f3f3f3f;

vector<pii> G[maxn];
ll dp[maxn], diff = inf, mmax = -inf;
int sz[maxn], clk_in[maxn], n, m, clk_out[maxn], clk, f[maxn];

void dfs1(int u, int p) {
    f[u] = p;
    clk_in[u] = clk++;
    sz[u] = 1;
    for (pii _v : G[u]) {
        int v = _v._1, w = _v._2;
        if (v == p) continue;
        dp[v] = dp[u] + w;
        dfs1(v, u);
        sz[u] += sz[v];
    }
    clk_out[u] = clk++;
}

inline bool check(int u, int v) {
    return clk_in[u] <= clk_in[v] && clk_out[u] >= clk_out[v];
}

void dfs(int u, int p) {
    diff = min(diff, max(0LL, -(mmax - dp[u])));
    if (p != -1 && f[p] != -1) diff = min(diff, max(0LL, -(dp[f[p]] - dp[u])));
    for (pii _v : G[u]) {
        int v = _v._1, w = _v._2;
        if (v == p) continue;
        if (!check(v, n)) {
            diff = min(diff, max(0LL, -(mmax + w - dp[u])));
            mmax = max(mmax, w + dp[u]);
            if (p != -1) diff = min(diff, max(0LL, -(w - dp[u] + dp[p])));
        }
    }
    for (pii _v : G[u]) {
        int v = _v._1;
        if (v == p) continue;
        if (check(v, n)) dfs(v, u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    FOR(_i, 1, n - 1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].pb(mp(v, w));
        G[v].pb(mp(u, w));
    }
    dfs1(1, -1);
    ll ans = dp[n];
    FOR(i, 1, n) {
        if (!check(i, n) && sz[i] > 1) {
            diff = 0;
            break;
        }
    }
    if (diff) dfs(1, -1);
    REP(i, m) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", min(ans, ans - diff + x));
    }
    return 0;
}