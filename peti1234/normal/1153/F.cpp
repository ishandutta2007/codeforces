#include <bits/stdc++.h>

using namespace std;
long long mod=998244353, n, m, f, ans;
long long dp[4005][4005][2], fakt[4005];
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    cin >> n >> m >> ans, fakt[0]=1, f=2*n+1;
    for (long long i=1; i<=f; i++) fakt[i]=(fakt[i-1]*i)%mod;
    dp[0][0][0]=1;
    for (long long i=0; i<=f; i++) {
        for (long long j=0; j<=min(i, n); j++) {
            long long x=dp[i][j][0]%mod, y=dp[i][j][1]%mod;
            dp[i+1][j+1][0]+=x, dp[i+1][j+1][1]+=y;
            if (j) dp[i+1][j-1][0]+=x*j, dp[i+1][j-1][1]+=y*j;
            if (j>=m) dp[i+1][j][1]+=x;
        }
    }
    for (long long i=1; i<=n; i++) ans*=2, ans%=mod;
    ans*=fakt[n], ans%=mod, ans*=oszt(fakt[f]), ans%=mod, ans*=dp[f][0][1], ans%=mod;
    cout << ans << "\n";
    return 0;
}