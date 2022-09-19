#include <bits/stdc++.h>

using namespace std;
const int c=15;
long long n, n2, m, len[c], g[c], dp[1<<c][c], sum[1<<c], ans, mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    n2=(1<<n);
    for (int i=0; i<n; i++) {
        cin >> len[i] >> g[i];
        dp[1<<i][i]=1;
    }
    for (int mask=1; mask<n2; mask++) {
        for (int i=0; i<n; i++) {
            if (mask & (1<<i)) {
                sum[mask]+=len[i];
            }
        }
        for (int ut=0; ut<n; ut++) {
            if (!(mask & (1<<ut))) continue;
            for (int kov=0; kov<n; kov++) {
                if (mask & (1<<kov)) continue;
                int ert=mask+(1<<kov);
                if (g[ut]!=g[kov]) {
                    dp[ert][kov]=(dp[ert][kov]+dp[mask][ut])%mod;
                }
            }
            if (sum[mask]==m) {
                ans=(ans+dp[mask][ut])%mod;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}