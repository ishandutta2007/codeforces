#include <bits/stdc++.h>

using namespace std;
long long dp[10000005], n, x, y, sok=1e15;
int main()
{
    cin >> n >> x >> y;
    for (int i=1; i<=n+1; i++) dp[i]=sok;
    for (int i=1; i<=n; i++) {
        dp[i]=min({dp[i], dp[i-1]+x, dp[i+1]+x});
        if (2*i<=n+2) {
            dp[2*i]=dp[i]+y;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}