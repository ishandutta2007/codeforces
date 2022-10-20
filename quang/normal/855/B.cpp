#include <bits/stdc++.h>

using namespace std;

const long long INF = 3e18 + 10;
const int N = 100010;

int n;
int a[N], b[4];
long long dp[4][N];

int main() {
    scanf("%d %d %d %d", &n, b + 1, b + 2, b + 3);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -INF;
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1ll * b[i] * a[j]);
            if (i >= 2) dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + 1ll * b[i] * a[j] + 1ll * b[i - 1] * a[j]);
            if (i >= 3) dp[i][j] = max(dp[i][j], dp[i - 3][j - 1] + 1ll * b[i] * a[j] + 1ll * b[i - 1] * a[j] + 1ll * b[i - 2] * a[j]);;
//            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[3][n] << endl;
    return 0;
}