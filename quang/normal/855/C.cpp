#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long) u * v % MOD;
}

int n, m;
vector<int> a[N];
int dp[3][11][N];
int g[3][11][N];
int k, x;

void dfs(int u, int p) {
    dp[0][0][u] = k - 1;
    dp[1][1][u] = 1;
    dp[2][0][u] = m - k;
    for (int v : a[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        for (int i = x; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int foo = add(add(dp[0][j][v], dp[1][j][v]), dp[2][j][v]);
                g[0][i][u] = add(g[0][i][u], mul(dp[0][i - j][u], foo));
                g[1][i][u] = add(g[1][i][u], mul(dp[1][i - j][u], dp[0][j][v]));
                foo = add(dp[0][j][v], dp[2][j][v]);
                g[2][i][u] = add(g[2][i][u], mul(dp[2][i - j][u], foo));
            }
        }
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= x; j++) {
                dp[i][j][u] = g[i][j][u];
                g[i][j][u] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    scanf("%d %d", &k, &x);
    dfs(1, 0);
    int res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= x; j++) {
            res=  add(res, dp[i][j][1]);
        }
    }
    cout << res << endl;
//    for (int i = 1; i <= n; i++) {
//        cout << dp[0][0][i] <<" " << dp[1][0][i] << " " << dp[2][0][i] << endl;
//    }
    return 0;

}