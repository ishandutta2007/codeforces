#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n, k;
long long a[N];
long long sum[N];
bool dp[N][N];

bool check(long long u) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 0; x < i; x++) {
                long long tot = sum[i] - sum[x];
                if ((tot & u) == u) {
                    dp[i][j] |= dp[x][j - 1];
                }
            }
        }
    }
    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    long long res = 0;
    for (int i = 60; i >= 0; i--) {
        long long foo = res | (1ll << i);
        if (check(foo)) {
            res = foo;
        }
    }
    cout << res << endl;
    return 0;
}