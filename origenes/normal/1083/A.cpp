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

ll w[maxn], dp[maxn], ans;
vector<pii> G[maxn];
int n;

void dfs(int u, int p) {
    dp[u] = w[u];
    ans = max(ans, w[u]);
    for (auto _v : G[u]) {
        int v = _v._1;
        if (v == p) continue;
        dfs(v, u);
        dp[v] -= _v._2;
        ans = max(ans, dp[v] + dp[u]);
        dp[u] = max(dp[u], dp[v] + w[u]);
    }
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld", w + i);
    FOR(i, 1, n - 1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].eb(v, w);
        G[v].eb(u, w);
    }
    dfs(1, 0);
    printf("%lld", ans);
}