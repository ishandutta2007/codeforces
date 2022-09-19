#include <bits/stdc++.h>

using namespace std;
const int c=505;
long long dp[c][c], alatt[c][c], po[c][c], mod=998244353;
bool v[c][c];

long long solve(int n, int x) {
    if (n==0) return 1;
    if (n==1) return 0;
    if (x<n) return po[x][n];
    if (!v[n][x]) {
        long long sum=0;
        for (int kis=0; kis<=n; kis++) sum+=alatt[n][kis]*po[n-1][kis]%mod*solve(n-kis, x-n+1)%mod;
        dp[n][x]=sum%mod;
        v[n][x]=1;
    }
    return dp[n][x];
}
int main()
{
    int n, x;
    cin >> n >> x;
    int s=max(n, x);
    for (int i=0; i<=s; i++) alatt[i][0]=1, po[i][0]=1;
    for (int i=1; i<=s; i++) for (int j=1; j<=s; j++) alatt[i][j]=(alatt[i-1][j]+alatt[i-1][j-1])%mod, po[i][j]=po[i][j-1]*i%mod;
    cout << solve(n, x);
    return 0;
}