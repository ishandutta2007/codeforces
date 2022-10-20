#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

int n, m, k;
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                dp[i][j] = m;
            } else if (j >= i) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = add(dp[i - 1][j], mul(m - 1, dp[i - 1][j - 1]));
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}