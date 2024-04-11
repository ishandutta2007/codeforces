#include <bits/stdc++.h>

using namespace std;

const int N = 14;

int n, m;
int edge[N][N];
int hasPath[N][N][1 << N];
int pref[1 << N];
int dp[1 << N];
pair<int, int> trace[1 << N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(hasPath, -1, sizeof hasPath);
    memset(pref, -1, sizeof pref);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[u][v] = edge[v][u] = 1;
        hasPath[u][v][0] = hasPath[v][u][0] = 0;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) continue; 
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) continue;
                if (i == j || hasPath[i][j][mask] == -1) continue;
                for (int k = 0; k < n; k++) {
                    if ((mask >> k) & 1 || !edge[j][k]) continue;
                    if (k == i && mask == 0) continue;
                    int newMask = mask | (1 << j);
                    if (hasPath[i][k][newMask] != -1) continue;
                    // if (mask == 8154 && newMask == 8186) {
                    //     cerr << "trace " << i << ' ' << j << ' ' << k << endl;
                    // }
                    hasPath[i][k][newMask] = mask;
                }
            }
        }
    }
    // cout << hasPath[4][5][4] << endl;
    pref[1] = dp[1] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (pref[mask] == -1) continue;
        for (int i = 0; i < n; i++) {
            if (((mask >> i) & 1) == 0) continue;
            for (int j = 0; j < n; j++) {
                if (((mask >> j) & 1) == 0) continue;

                int invMask = ((1 << n) - 1) ^ mask;
                for (int subMask = invMask; subMask > 0; subMask = (subMask - 1) & invMask) {
                    if (hasPath[i][j][subMask] == -1) continue;
                    int len = __builtin_popcount(subMask) + 1;
                    if (dp[mask | subMask] != -1 && dp[mask | subMask] <= dp[mask] + len) continue;
                    dp[mask | subMask] = dp[mask] + len;
                    pref[mask | subMask] = mask;
                    trace[mask | subMask] = {i, j};
                }
            }
        }
    }
    assert(pref[(1 << n) - 1] != -1);
    int curMask = (1 << n) - 1;
    vector<pair<int, int>> res;
    while (curMask > 1) {
        int u, v, mask;
        tie(u, v) = trace[curMask];
        // cerr << "curMask=" << curMask << ' ' << u << ' ' << v << ' '  << pref[curMask] << endl;
        mask = pref[curMask] ^ curMask;
        while (mask > 0) {
            int nxtMask = hasPath[u][v][mask];
            int k = log2(mask ^ nxtMask);
            // cerr << u << ' ' << v << ' ' << k << ' ' << mask << ' ' << nxtMask << endl;
            
            res.push_back({k + 1, v + 1});
            v = k;
            mask = nxtMask;
        }
        // cerr << u << ' ' << v  << endl;
        res.push_back({u + 1, v + 1});
        curMask = pref[curMask];
    }
    cout << res.size() << '\n';
    for (auto u : res) cout << u.first << ' ' << u.second << '\n';
    return 0;
}