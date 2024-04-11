#include <bits/stdc++.h>

using namespace std;
long long n, m, sum, mod=998244353;
string a, b;
long long dp[3002][3002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    n=a.size(), m=b.size();
    for (long long i=0; i<=m; i++) dp[0][i]=1;
    for (long long i=1; i<n; i++) dp[i][m]=2*dp[i-1][m]%mod;
    for (long long i=1; i<=n; i++) {
        for (long long j=0; j<m; j++) {
            if (a[i-1]==b[j]) {
                dp[i][j]+=dp[i-1][j+1]; dp[i][j]%=mod;
                if (j+1>=i) dp[i][j-i+1]+=dp[i-1][j-i+1], dp[i][j-i+1]%=mod;
            }
            if (i+j>m) dp[i][j]+=dp[i-1][j], dp[i][j]%=mod;
        }
    }
    for (long long i=m; i<=n; i++) sum+=dp[i][0];
    cout << sum%mod << "\n";
    return 0;
}