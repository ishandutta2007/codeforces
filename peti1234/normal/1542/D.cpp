#include <bits/stdc++.h>

using namespace std;
const int c=505;
long long n, t[c], dp[c][c], ans, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        if (c=='+') {
            cin >> t[i];
        }
    }
    for (int s=1; s<=n; s++) {
        if (t[s]) {
            for (int i=0; i<=n; i++) {
                for (int j=0; j<=n; j++) {
                    dp[i][j]=0;
                }
            }
            dp[0][0]=1;
            for (int i=1; i<=n; i++) {
                if (i==s) {
                    for (int j=0; j<=n; j++) {
                        dp[i][j]=dp[i-1][j];
                    }
                    continue;
                }
                if (t[i]>t[s] || (i>s && t[i]==t[s])) {
                    for (int j=0; j<=n; j++) {
                        dp[i][j]=2*dp[i-1][j]%mod;
                    }
                } else if (t[i]) {
                    for (int j=0; j<=n; j++) {
                        if (j) {
                            dp[i][j]+=dp[i-1][j-1];
                        }
                        dp[i][j]+=dp[i-1][j];
                        dp[i][j]%=mod;
                    }
                } else {
                    if (i<s) {
                        for (int j=0; j<=n; j++) {
                            dp[i][j]=dp[i-1][j]+dp[i-1][j+1];
                            dp[i][j]%=mod;
                        }
                        dp[i][0]+=dp[i-1][0];
                        dp[i][0]%=mod;
                    } else {
                        for (int j=0; j<=n; j++) {
                            dp[i][j]=dp[i-1][j]+dp[i-1][j+1];
                            dp[i][j]%=mod;
                        }
                    }
                }
            }
            for (int i=0; i<=n; i++) {
                ans+=dp[n][i]*t[s];
                ans%=mod;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
1
+1
*/