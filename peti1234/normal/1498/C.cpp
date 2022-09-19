#include <bits/stdc++.h>

using namespace std;
const int c=1002, mod=1e9+7;
long long dp[c][c], kom[c][c], w, n, k, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        sum=1;
        if (k>1) {
            sum+=n;
        }
        for (int i=0; i<=n+1; i++) {
            for (int j=0; j<=k+1; j++) {
                dp[i][j]=0;
            }
        }
        for (int i=1; i<=n; i++) {
            dp[i][1]=1;
        }
        for (int j=2; j<k; j++) {
            if (j%2==0) {
                for (int i=n-1; i>=1; i--) {
                    dp[i][j]=(dp[i+1][j]+dp[i+1][j-1])%mod;
                    sum+=dp[i][j];
                }
            } else {
                for (int i=2; i<=n; i++) {
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
                    sum+=dp[i][j];
                }
            }
        }
        cout << sum%mod << "\n";
    }
    return 0;
}