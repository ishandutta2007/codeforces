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

const ll MOD = 1000000007;
const int maxn = 3123;

int n;
ll D, dp[maxn][maxn];
vector<int> G[maxn];

ll inv(ll x) {
    ll ret = 1, b = MOD - 2;
    while (b) {
        if (b & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        b >>= 1;
    }
    return ret;
}

void dfs(int u) {
    REP(i, n + 1) dp[u][i] = 1;
    for (int v : G[u]) {
        dfs(v);
        REP(i, n + 1) dp[u][i] = dp[u][i] * dp[v][i] % MOD;
    }
    FOR(i, 1, n) dp[u][i] = (dp[u][i] + dp[u][i - 1]) % MOD;
}

int main() {
    scanf("%d%lld", &n, &D);
    FOR(i, 2, n) {
        int p;
        scanf("%d", &p);
        G[p].pb(i);
    }
    dfs(1);
    D--;
    ll ans = 0, now, d;
    REP(i, n + 1) {
        now = d = 1;
        REP(j, n + 1) {
            if (i == j) continue;
            now = now * (D - j) % MOD;
            d = d * (i - j) % MOD;
        }
        now = now * dp[1][i] % MOD;
        now = now * inv(d) % MOD;
        ans = ((ans + now) % MOD + MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}