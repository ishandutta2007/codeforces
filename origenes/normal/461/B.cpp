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

const int maxn = 112345;
const ll MOD = 1e9 + 7;

vector<int> G[maxn];
int x[maxn], n;
ll dp[maxn][2];

void dfs(int u, int par) {
    if (x[u]) {
        dp[u][1] = 1;
        for (int v : G[u]) if (v != par) {
                dfs(v, u);
                dp[u][1] = dp[u][1] * (dp[v][0] + dp[v][1]) % MOD;
            }
    } else {
        dp[u][0] = 1;
        for (int v : G[u]) if (v != par) {
                dfs(v, u);
                dp[u][1] = (dp[u][1] * (dp[v][0] + dp[v][1]) + dp[u][0] * dp[v][1]) % MOD;
                dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;
            }
    }
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n - 1) {
        int p;
        scanf("%d", &p);
        G[i].eb(p);
        G[p].eb(i);
    }
    REP(i, n) scanf("%d", x + i);
    dfs(0, -1);
    printf("%lld", dp[0][1]);
}