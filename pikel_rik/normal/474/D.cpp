#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int k;
int dp[100001];

int main() {
    int t;
    cin >> t >> k;

    dp[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        dp[i] = dp[i-1];
        if (i - k >= 0)
            dp[i] = (dp[i] + dp[i-k]) % mod;
    }

    for (int i = 1; i <= 100000; i++) {
        dp[i] = (dp[i] + dp[i-1]) % mod;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;

        int ans = dp[b] - dp[a-1];

        if (ans >= 0)
            cout << ans << "\n";
        else
            cout << ans + mod << "\n";
    }
    return 0;
}