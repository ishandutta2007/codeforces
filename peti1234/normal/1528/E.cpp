#include <bits/stdc++.h>

using namespace std;
const int c=1000005, mod=998244353;
long long inv2=499122177, inv6=166374059;
long long a2(long long a) {
    return a*(a+1)%mod*inv2%mod;
}
long long a3(long long a) {
    return a*(a+1)%mod*(a+2)%mod*inv6%mod;
}
long long dp[c], sum[c], n, ans;
int main()
{
    cin >> n;
    if (n==1) {
        cout << 5 << "\n";
        return 0;
    }
    dp[0]=1, sum[0]=1;
    for (int i=1; i<=n; i++) {
        dp[i]=(dp[i-1]+a2(sum[i-1])-(i>=2 ? a2(sum[i-2]) : 0)+mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    ans=(2*(dp[n]-dp[n-1]+mod+a3(dp[n-1])+dp[n-1]*a2(sum[n-2])%mod+a2(dp[n-1])*sum[n-2]%mod)+dp[n-1])%mod;
    for (int i=1; i<n; i++) {
        ans+=dp[i-1]*(dp[n-i]-dp[n-i-1]+mod)%mod;
    }
    cout << ans%mod << "\n";
    return 0;
}