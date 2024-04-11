#include <bits/stdc++.h>

using namespace std;
const int c=23, c2=1<<c;
int n, db[c][26], ert[c2];
long long dp[c2], ans, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (auto x:s) {
            db[i][(x-'a')]++;
        }
    }
    for (int i=1; i<(1<<n); i++) {
        dp[i]=1;
    }
    for (int j=0; j<26; j++) {
        for (int i=0; i<c2; i++) ert[i]=c2;
        for (int i=1; i<(1<<n); i++) {
            int x=__builtin_ctz(i), el=i-(1<<x);
            ert[i]=min(ert[el], db[x][j]);
            dp[i]=dp[i]*(ert[i]+1)%mod;
        }
    }
    for (int i=1; i<(1<<n); i++) {
        if (__builtin_popcount(i)%2==0) {
            dp[i]=mod-dp[i];
        }
    }
    for (int j=0; j<n; j++) {
        for (int i=0; i<(1<<n); i++) {
            if (i & (1<<j)) {
                dp[i]=(dp[i]+dp[i-(1<<j)])%mod;
            }
        }
    }
    for (int i=0; i<(1<<n); i++) {
        long long sum=0;
        for (int j=0; j<n; j++) {
            if (i & (1<<j)) {
                sum+=j+1;
            }
        }
        sum*=__builtin_popcount(i);
        ans=(ans^(sum*dp[i]));
    }

    cout << ans << "\n";
    return 0;
}