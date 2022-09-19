#include <bits/stdc++.h>

using namespace std;
long long mod=1000000007;
long long n, m;
long long dp[100001][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    dp[1][0]=2;
    dp[1][1]=0;
    for (int i=2; i<=max(n, m); i++) {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=dp[i-1][0];
    }
    long long sum=dp[n][0]+dp[n][1]+dp[m][0]+dp[m][1]-2;
    cout << sum%mod << "\n";
    return 0;
}