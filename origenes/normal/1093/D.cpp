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
const ll MOD = 998244353;

vector<int> G[maxn];
char vis[maxn];
int cnt[3];
ll pw[maxn];

int t, n, m;

bool dfs(int u) {
    for (int v : G[u]) {
        if (vis[v]) {
            if (vis[v] == vis[u]) return false;
        } else {
            vis[v] = 3 - vis[u];
            cnt[vis[v]]++;
            if (!dfs(v)) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &t);
    pw[0] = 1;
    FOR(i, 1, 300000) pw[i] = pw[i - 1] * 2 % MOD;
    while (t--) {
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) {
            G[i].clear();
            vis[i] = 0;
        }
        REP(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
            G[v].pb(u);
        }
        ll ans = 1;
        FOR(i, 1, n) if (!vis[i]) {
                vis[i] = cnt[1] = 1;
                bool f = dfs(i);
                if (!f) ans = 0;
                ans = ans * (pw[cnt[1]] + pw[cnt[2]]) % MOD;
                cnt[1] = cnt[2] = 0;
            }
        printf("%lld\n", ans);
    }
}