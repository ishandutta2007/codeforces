#include <bits/stdc++.h>

using namespace std;
const long long mod=998244353, m=720720;
long long n, invn, db, a0, xx, yy, mod2, k, dp[m][18], ans;
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a0 >> xx >> yy >> k >> mod2;
    invn=po(n, mod-2), db=po(n, k-1);
    for (int i=1; i<=n; i++) {
        ans+=(a0/m)*m*k%mod*db%mod;
        dp[a0%m][0]=(dp[a0%m][0]+db)%mod;
        a0=(a0*xx+yy)%mod2;
    }
    for (int i=1; i<=k; i++) {
        for (int j=0; j<m; j++) {
            if (!dp[j][i-1]) continue;
            ans+=dp[j][i-1]*j%mod;
            dp[j][i]=(dp[j][i]+dp[j][i-1]*(n-1)%mod*invn)%mod;
            int s=j-j%i;
            dp[s][i]=(dp[s][i]+dp[j][i-1]*invn)%mod;
        }
    }
    cout << ans%mod << "\n";
    return 0;
}