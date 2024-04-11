#include <bits/stdc++.h>

using namespace std;
long long mod=1000000007, ans=1, n, ert, dp[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, ert=n;
    dp[0]=1, dp[1]=1;
    for (int i=2; i<=n; i++) {
        dp[i]=((i-1)*dp[i-2]+dp[i-1])%mod;
    }
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        if (x==2) ans*=ert, ans%=mod, ert--;
    }
    cout << ans*dp[ert]%mod << "\n";
    return 0;
}