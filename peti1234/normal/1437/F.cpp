#include <bits/stdc++.h>

using namespace std;
const long long mod=998244353, c=5002;
long long n, dp[c][c], t[c], kom[c], pos[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    dp[0][0]=1, kom[0]=1;
    for (int i=1; i<=n; i++) {
        kom[i]=kom[i-1];
        for (int j=0; j<i; j++) {
            if (t[i]>=2*t[j]) pos[i]=j;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j]=(kom[pos[j]]+dp[i-1][j]*(pos[j]-i+2))%mod;
        }
        kom[0]=0;
        for (int j=1; j<=n; j++) {
            kom[j]=(kom[j-1]+dp[i][j])%mod;
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}
/*
2
1 2
*/