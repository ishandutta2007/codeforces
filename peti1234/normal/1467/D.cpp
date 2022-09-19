#include <bits/stdc++.h>

using namespace std;
const int c=5002;
long long mod=1000000007, n, k, q, dp[c][c], db[c], t[c], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> q;
    for (int i=1; i<=n; i++) {
        dp[i][0]=1;
    }
    for (int j=1; j<=k; j++) {
        for (int i=1; i<=n; i++) {
            dp[i][j]=(dp[i-1][j-1]+dp[i+1][j-1])%mod;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            db[i]+=dp[i][j]*dp[i][k-j];
            db[i]%=mod;
        }
        //cout << i << " " << db[i] << "\n";
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i]*db[i];
        sum%=mod;
    }
    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        sum-=t[a]*db[a]%mod;
        t[a]=b;
        sum+=t[a]*db[a]+mod;
        sum%=mod;
        cout << sum << "\n";
    }
    return 0;
}