#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234567;

int h[maxn], hh[maxn], dp[maxn][2], n, k;
vector<int> G[maxn];

void dfs1(int u, int now) {
    h[u] = now;
    if (G[u].empty()) {
        hh[u] = h[u];
    }
    for (int v : G[u]) {
        dfs1(v, now + 1);
        hh[u] = min(hh[u], hh[v]);
    }
}

void dfs2(int u) {
    if (G[u].empty()) {
        dp[u][1] = dp[u][0] = 1;
        return;
    }
    int mmax = 0;
    for (int v : G[u]) {
        dfs2(v);
        if (hh[v] - h[u] <= k) {
            dp[u][1] += dp[v][1];
            dp[u][0] += dp[v][1];
            mmax = max(mmax, dp[v][0] - dp[v][1]);
        } else {
            mmax = max(mmax, dp[v][0]);
        }
    }
    dp[u][0] += mmax;
}

int main() {
    scanf("%d%d", &n, &k);
    FOR(i, 2, n) {
        int p;
        scanf("%d", &p);
        G[p].pb(i);
    }
    reset(hh, 0x3f);
    dfs1(1, 1);
    dfs2(1);
    printf("%d\n", dp[1][0]);
    return 0;
}