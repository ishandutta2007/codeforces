//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 18;
int dis[maxn][maxn],
    cost[1 << maxn],
    srcs[1 << maxn],
    dp[1 << maxn],
    par[1 << maxn],
    n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        fi--, se--;
        dis[fi][se] = th;
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = 1e9;
        bool valid = true;
        for (int i = 0; i < n and valid; i++)
            if (((mask >> i) & 1))
                for (int j = 0; j < n and valid; j++)
                    if (((mask >> j) & 1 ^ 1)) {
                        if (dis[i][j])
                            valid = false;
                        cost[mask] += dis[j][i];
                    }
        int u = __builtin_ctz(mask);
        int nmask = mask & (mask - 1);
        int curs = srcs[nmask];
        curs |= 1 << u;
        for (int i = 0; i < n; i++) {
            if (((curs >> i) & 1) and dis[u][i])
                curs ^= 1 << i;
            if (((mask >> i) & 1) and dis[i][u] and ((curs >> u) & 1))
                curs ^= 1 << u;
        }
        srcs[mask] = curs;
        if (!valid) continue;

        for (; curs; curs = srcs[mask] & (curs - 1)) {
            int curval;
            if ((curval = dp[mask ^ curs] + cost[mask ^ curs]) < dp[mask])
                dp[mask] = curval, par[mask] = curs;
        }
    }
    int ans[n];
    memset(ans, 1, sizeof ans);
    int mask = (1 << n) - 1;
    while (mask) {
        for (int i = 0; i < n; i++)
            ans[i] -= (mask >> i) & 1;
        mask ^= par[mask];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
	return 0;
}