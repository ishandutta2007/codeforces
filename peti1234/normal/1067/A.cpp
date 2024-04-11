#include <bits/stdc++.h>

using namespace std;
const int c=100002, p=201;
long long n, a, dp[c][p][2], ans, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> a;
    if (a>0) dp[1][a][0]=1;
    else for (int i=1; i<=p; i++) dp[1][i][0]=1;
    for (int i=2; i<=n; i++) {
        int x; cin >> x;
        if (x!=-1) {
            for (int j=x; j<=p; j++) dp[i][x][1]+=dp[i-1][j][1];
            dp[i][x][1]+=dp[i-1][x][0];
            for (int j=1; j<x; j++) dp[i][x][0]+=dp[i-1][j][0]+dp[i-1][j][1];
        } else {
            long long sum=0;
            for  (int j=p-1; j>=1; j--) sum+=dp[i-1][j][1], dp[i][j][1]+=sum, dp[i][j][1]+=dp[i-1][j][0];
            sum=0;
            for (int j=1; j<=p; j++) dp[i][j][0]+=sum, sum+=dp[i-1][j][0]+dp[i-1][j][1];
        }
        for (int j=1; j<p; j++) dp[i][j][0]%=mod, dp[i][j][1]%=mod;
    }
    for (int i=1; i<=200; i++) ans+=dp[n][i][1];
    cout << ans%mod << "\n";
    return 0;
}