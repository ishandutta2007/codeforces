#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int dp[4001];

int main() {
    int n;
    cin >> n;

    cin >> a >> b >> c;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -10000;
        if (i >= a)
            dp[i] = 1 + dp[i-a];
        if (i >= b)
            dp[i] = max(dp[i], 1 + dp[i-b]);
        if (i >= c)
            dp[i] = max(dp[i], 1 + dp[i-c]);
    }

    cout << dp[n];
    return 0;
}