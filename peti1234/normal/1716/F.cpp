#include <bits/stdc++.h>

using namespace std;
const int c=2005;
long long w, n, m, k, dp[c][c], oszt[c], mod=998244353;
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
    dp[0][0]=1;
    for (int i=1; i<c; i++) {
        oszt[i]=po(i, mod-2);
        for (int j=1; j<=i; j++) {
            dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*j)%mod;
        }
    }
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        long long ans=0, invm=po(m, mod-2), pm=(m+1)/2, ert=pm*po(m, n-1)%mod, alatt=n;
        for (int i=1; i<=k; i++) {
            ans=(ans+alatt*dp[k][i]%mod*ert)%mod;
            ert=ert*invm%mod*pm%mod;
            alatt=alatt*oszt[i+1]%mod*(n-i)%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}