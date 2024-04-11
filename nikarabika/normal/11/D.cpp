#include <bits/stdc++.h>

using namespace std;

const int maxn = 19;
long long dp[1 << maxn][19];
bool adj[maxn][maxn];
int n, m;

bool is1(int mask, int idx) {
    return (mask >> idx) & 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi][se] = adj[se][fi] = 1;
    }
    // dp[mask][t]
    for (int mask = 1; mask < (1 << n); mask++) {
        int s;
        for (int i = n - 1; i >= 0; i--)
            if ((mask >> i) & 1) {
                s = i;
                break;
            }
        if (mask == (1 << s)) {
            dp[mask][s] = 1;
            continue;
        }
        for (int t = 0; t < s; t++) if ((mask >> t) & 1)
            for (int u = 0; u < n; u++) if ((mask >> u) & 1)
                if (adj[u][t])
                    dp[mask][t] += dp[mask ^ (1 << t)][u];
    }
    long long ans = 0;
    for (int u = 0; u < n; u++)
        for (int v = 0; v < u; v++) if (adj[u][v])
            for (int mask = (1 << u); mask < (1 << (u+1)); mask++)
                if (is1(mask, u) and is1(mask, v) and __builtin_popcount(mask) > 2) {
                    ans += dp[mask][v];
                }
    cout << ans/2 << endl;
    return 0;
}