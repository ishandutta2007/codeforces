#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 312345;

int n, m, q, r;
int p[maxn], dp[maxn][2], pre[maxn][2];
bool vis[maxn];
vector<int> G[maxn], cc;

inline void upd(int u, int now, int v) {
    if (now > dp[u][0]) {
        dp[u][1] = dp[u][0], pre[u][1] = pre[u][0];
        dp[u][0] = now, pre[u][0] = v;
    }
    else if (now > dp[u][1]) dp[u][1] = now, pre[u][1] = v;
}

void dfs(int u, int par) {
    vis[u] = true;
    for (int v : G[u]) if (v != par) {
            dfs(v, u);
            upd(u, dp[v][0] + 1, v);
        }
}

inline bool cmp(int u, int r) {
    return dp[u][0] + dp[u][1] > dp[r][0] + dp[r][1] || (dp[u][0] + dp[u][1] == dp[r][0] + dp[r][1] && dp[u][0] < dp[r][0]);
}

void dfs2(int u, int par) {
    if (par) {
        if (pre[par][0] != u) upd(u, dp[par][0] + 1, par);
        else upd(u, dp[par][1] + 1, par);
    }
    if (cmp(u, r)) r = u;
    for (int v : G[u]) if (v != par)
            dfs2(v, u);
    cc.eb(u);
}

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].eb(v);
        G[v].eb(u);
    }
    FOR(i, 1, n) if (!vis[i]) {
            dfs(i, 0);
            r = i;
            cc.clear();
            dfs2(i, 0);
            for (auto u : cc) p[u] = r;
        }
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x;
            scanf("%d", &x);
            printf("%d\n", dp[Find(x)][0] + dp[Find(x)][1]);
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            int u = Find(x), v = Find(y);
            if (u == v) continue;
            int tu = dp[u][0] + 1, tv = dp[v][0] + 1;
            upd(u, tv, v); upd(v, tu, u);
            cmp(u, v) ? p[v] = u : p[u] = v;
        }
    }
}