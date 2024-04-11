
#include <bits/stdc++.h>

using namespace std;
const int c=202;
long long n, d, mod, alatt[c][c], dp[c][c], dp2[c][c], ans, o=0;
int main()
{
    cin >> n >> d >> mod;
    alatt[0][0]=1, dp[0][0]=1;
    for (int i=1; i<=n; i++) {
        alatt[i][0]=1;
        for (int j=1; j<=n; j++) {
            alatt[i][j]=(alatt[i-1][j]+alatt[i-1][j-1])%mod;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            for (int k=max(o, j-d+1-(i==n)); k<=j; k++) {
                dp[i][k+1]+=dp[i-1][j]*alatt[j][k];
                dp[i][k+1]%=mod;
            }
        }
    }
    ans=dp[n][1];
    for (int i=1; i<=n; i++) {
        for (int j=2; j<=n; j++) {
            for (int k=0; k+j<=d; k++) {
                ans+=dp[i-1][j]*dp[n-i][k];
                ans%=mod;
            }
        }
    }
    cout << ans*n*(n-1)*2%mod << "\n";
    return 0;
}