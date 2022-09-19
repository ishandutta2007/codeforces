#include <bits/stdc++.h>

using namespace std;
const int c=5005;
long long n, fakt[c], alatt[c][c], po[c][c], dp[c][c], ans, mod;
int main()
{
    cin >> n >> mod;
    for (int i=0; i<=n; i++) {
        fakt[i]=(i==0 ? 1 : fakt[i-1]*i%mod);
        for (int j=0; j<=n; j++) {
            po[i][j]=(j==0 ? 1 : po[i][j-1]*i%mod);
            if (j<=i) {
                alatt[i][j]=(j==0 ? 1 : (alatt[i-1][j]+alatt[i-1][j-1])%mod);
            }
        }
    }
    for (int i=0; i<=n; i++) {
        dp[0][i]=1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            dp[i][j]=(dp[i][j-1]+i*dp[i-1][j-1])%mod;
        }
    }
    for (int i=0; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            long long veg=alatt[n][j]*alatt[j][i]%mod*dp[i][j]%mod*alatt[n-j][j-i]%mod*fakt[j-i]%mod;
            long long aa=j-i, ab=n-2*j+i, ba=i, bb=j-i, tam=po[j][ab]*po[n-1][bb]%mod;
            if (ab<0) continue;
            ans=(ans+tam*veg)%mod;
        }
    }
    cout << ans << "\n";
    return 0;
}