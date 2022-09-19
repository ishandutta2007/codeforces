#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
long long mod=998244353, sum, ert;
long long dp[5001][5001], hatv[5001];
long long oszt(long long a)
{
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    cin >> n >> m >> k;
    dp[1][1]=n, hatv[0]=1;
    for (int i=2; i<=k; i++) for (int j=1; j<=i; j++) dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*(n-j+1))%mod;
    for (int i=1; i<=k; i++) {
        hatv[i]=(hatv[i-1]*m)%mod, ert=dp[k][i];
        ert*=oszt(hatv[i]), ert%=mod;
        sum+=ert;
    }
    cout << sum%mod << "\n";
}