#include <bits/stdc++.h>

using namespace std;
long long n, m, f, k, dp[100005][15][16], mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;
    f=(1<<(m-1));
    dp[0][0][0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            for (int mask=0; mask<f; mask++) {
                long long s=2*mask, pc=__builtin_popcount(mask), a=dp[i-1][j][mask], b=dp[i-1][j][mask+f];
                dp[i][j][s]=(a+b)%mod;
                dp[i][j+1][s+1]=(a*(pc+1)+b*(pc+2))%mod;
            }
        }
    }
    long long sum=0;
    for (int i=0; i<(1<<m); i++) {
        sum+=dp[n][k][i];
    }
    cout << sum%mod << "\n";
    return 0;
}