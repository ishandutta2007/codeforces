#include <bits/stdc++.h>

using namespace std;
const int c=1005;
long long mod=998244353;
int n, k, t[c];
long long dp[c][c], kom[c][c], sum;

long long solve(int a)
{
    for (int i=1; i<=n; i++) {
        dp[i][1]=1;
        kom[i][1]=i;
    }
    int x=0;
    for (int i=1; i<=n; i++) {
        while(t[i]-t[x+1]>=a) {
            x++;
        }
        for (int j=2; j<=k; j++) {
            dp[i][j]=kom[x][j-1];
            kom[i][j]=kom[i-1][j]+dp[i][j];
            kom[i][j]%=mod;
        }
    }
    return kom[n][k];
}
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=100000/(k-1); i++) {
        sum+=solve(i);
    }
    cout << sum%mod;
    return 0;
}