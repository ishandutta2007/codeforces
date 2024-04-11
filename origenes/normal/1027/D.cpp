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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

bool vis[maxn];
int p[maxn], c[maxn], a[maxn], n, cost[maxn];
ll ans;

int query(int u) {
    return p[u] == u ? u : p[u] = query(p[u]);
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    if (a[u] == u) {
        cost[u] = c[u];
        return;
    }
    p[u] = query(a[u]);
    dfs(a[u]);
    if (query(a[u]) == u) {
        cost[u] = c[u];
        for (int v = a[u]; v != u; v = a[v]) {
            p[v] = u;
            cost[u] = min(cost[u], c[v]);
        }
    }
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) p[i] = i;
    FOR(i, 1, n) scanf("%d", &c[i]);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) if (!vis[i]) dfs(i);
    reset(vis, 0);
    FOR(i, 1, n) {
        int u = query(i);
        if (!vis[u]) {
            ans += cost[u];
            vis[u] = true;
        }
    }
    printf("%lld\n", ans);
    return 0;
}