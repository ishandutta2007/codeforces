#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const int INF = 1e9;

int n;
int a[N];
int dp[2][N];

int main() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    dp[0][n + 1] = 0;
    dp[1][n + 1] = 0;
    for (int i = n; i; i--) {
        dp[0][i] = max(dp[1][i + 1] + a[i], dp[0][i + 1] - a[i]);
        dp[1][i] = min(dp[0][i + 1] - a[i], dp[1][i + 1] + a[i]);
    }
    cout << (sum - dp[0][1]) / 2 << " " << (sum + dp[0][1]) / 2 << endl;
    return 0;
}