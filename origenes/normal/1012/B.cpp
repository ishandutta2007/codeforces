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

const int maxn = 212345;

int n, m, q, ans;
bool vis[2 * maxn];
vector<int> G[maxn * 2];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = true;
    for (int v : G[u]) dfs(v);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    REP(i, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        v += maxn;
        G[u].pb(v);
        G[v].pb(u);
    }
    FOR(i, 1, n) if (!vis[i]) {
            ans++;
            dfs(i);
        }
    FOR(i, maxn + 1, maxn + m) if (!vis[i]) {
            ans++;
            dfs(i);
        }
    printf("%d\n", ans - 1);
    return 0;
}