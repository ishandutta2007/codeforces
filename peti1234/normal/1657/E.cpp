#include <bits/stdc++.h>

using namespace std;
const int c=255;
long long n, k, dp[c][c], alatt[c][c], po[c][c*c], sum, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i<=max(n, k); i++) {
        po[i][0]=1, alatt[i][0]=1;
        for (int j=1; j<=n*n; j++) {
            po[i][j]=po[i][j-1]*i%mod;
        }
        for (int j=1; j<=n; j++) {
            alatt[i][j]=(alatt[i-1][j-1]+alatt[i-1][j])%mod;
        }
    }
    dp[0][1]=1;
    for (int i=1; i<=k; i++) {
        for (int el=1; el<=n; el++) {
            for (int db=0; el+db<=n; db++) {
                dp[i][el+db]=(dp[i][el+db]+dp[i-1][el]*alatt[n-el][db]%mod*po[i][db*(n-el-db)+db*(db-1)/2])%mod;
            }
        }
    }
    cout << dp[k][n] << "\n";
    return 0;
}