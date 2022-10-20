#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int MOD = 998244353;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, m;
int c[N];
int dp[N][N], sum[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) dp[i][j] = sum[i][j] = 1;
            else dp[i][j] = sum[i][j] = 0;
        }
    }
    for (int len = 1; len <= m; len++) {
        for (int l = 1; l + len - 1 <= m; l++) {
            int r = l + len - 1;
            int minId = l;
            for (int i = l + 1; i <= r; i++) {
                if (c[i] < c[minId]) minId = i;
            }

            dp[l][r] = mul(sum[l][minId - 1], sum[minId + 1][r]);
            for (int i = l; i <= r + 1; i++) {
                sum[l][r] = add(sum[l][r], mul(dp[l][i - 1], dp[i][r]));
            }
        }
    }
    cout << dp[1][m] << endl;
    return 0;
}