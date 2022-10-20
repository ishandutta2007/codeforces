#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
long long dp[2][N], mx[2][N];

void go(long long *dp, long long *mx) {
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (a[i] > cur) {
            cur = a[i];
        } else {
            cur++;
            dp[i] += cur - a[i];
        }
        mx[i] = cur;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    go(dp[0], mx[0]);
    reverse(a + 1, a + n + 1);
    go(dp[1], mx[1]);
    reverse(dp[1] + 1, dp[1] + n + 1);
    reverse(mx[1] + 1, mx[1] + n + 1);
    reverse(a + 1, a + n + 1);
//    for (int i = 1; i <= n; i++) {
//        cout << i << " " << dp[1][i] << " " << mx[1][i] << endl;
//    }

    long long res = (1ll << 60);
    for (int i = 1; i <= n; i++) {
        res = min(res, dp[0][i] + dp[1][i] - min(mx[0][i], mx[1][i]) + a[i]);
    }
    cout << res << endl;
    return 0;
}