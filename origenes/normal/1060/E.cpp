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

const int maxn = 212345;

ll dp[maxn][2][3], dis[maxn][3];
bool vis[maxn];
vector<int> G[maxn];

void dfs(int u, int p) {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0][1] += dp[v][1][1];
        dp[u][1][1] += dp[v][0][1];
    }
    for (int v : G[u]) {
        if (v == p) continue;
        dp[u][0][0] += dp[v][0][0] + dp[v][0][1] + dp[v][0][2];
        dp[u][0][2] += dp[v][0][1] * (dp[u][0][1] - dp[v][1][1]);
    }
//    cout << u << endl;
//    REP(i, 3) cout << dp[u][0][i] << ' ';
//    cout << dp[u][1][1] << '\n';
    for (int v : G[u]) {
        if (v == p) continue;
        dis[u][0] += dis[v][0] + dis[v][1] + dis[v][2];
        dis[u][1] += dis[v][1] + dp[v][0][1] + dp[v][1][1];
        dis[u][2] += (dis[v][1] + dp[v][0][1] + dp[v][1][1]) * (dp[u][0][1] + dp[u][1][1] - dp[v][0][1] - dp[v][1][1]);
    }
//    REP(i, 3)
//        cout << dis[u][i] <<' ';
//    cout << endl;
    dp[u][1][1]++;
}

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, -1);
//    ll now = 0;
//    REP(i, 2) REP(j, 3) now += dp[1][i][j];
    ll ans = (dis[1][0] + dis[1][1] + dis[1][2] + dp[1][0][0] + dp[1][0][1] + dp[1][0][2]) / 2;
    printf("%lld\n", ans);
    return 0;
}