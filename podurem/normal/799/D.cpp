#include <bits/stdc++.h>

#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stdout)
typedef long long ll;

using namespace std;

const int dd = (int)1e5 + 7;

int A[dd];
int dp[60][dd];

int main() {
    int a, b, h, w, n;
    scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &A[i]);

    sort(A, A + n);
    reverse(A, A + n);


    dp[0][1] = 1;
    for (int i = 0; i < min(n, 50); ++i) {
        for (int j = 1; j < dd; ++j) {
            dp[i + 1][j] = max(1ll * dp[i + 1][j], min(1ll * dd, 1ll * dp[i][j] * A[i]));
            dp[i + 1][min(1ll * dd - 1, 1ll * j * A[i])] = max(dp[i + 1][min(1ll * dd - 1, 1ll * j * A[i])], dp[i][j]);
        }
    }

    for (int ans = 0; ans <= n; ++ans) {

        int H = (a + h - 1) / h;
        int W = (w + b - 1) / w;

        int ok = 0;
        for (int i = H; i < dd; ++i) if (dp[ans][i] >= W) ok = 1;
        if (ok) return 0 * printf("%d", ans);

        H = (w + a - 1) / w, W = (h + b - 1) / h;
        for (int i = H; i < dd; ++i) if (dp[ans][i] >= W) ok = 1;
        if (ok) return 0 * printf("%d", ans);
    }
    puts("-1");
    return 0;
}