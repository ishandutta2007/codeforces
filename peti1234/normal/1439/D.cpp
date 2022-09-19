
#include <bits/stdc++.h>

using namespace std;
const int c=502;
long long fakt[c], inv[c], mod, n, m, tele[c], cnt[c], dp[c][c], db[c][c];
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<b || b<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
long long s(long long ert) {
    return ert*(ert+1)/2;
}
int main()
{
    cin >> n >> m;
    mod=1000000009;
    cin >> mod;
    fakt[0]=inv[0]=cnt[0]=db[0][0]=1;
    for (int i=1; i<=n+1; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            tele[i]+=alatt(i-1, j)*(i+1)%mod*((tele[j]*cnt[i-1-j]+cnt[j]*tele[i-1-j])%mod+cnt[j]*cnt[i-1-j]%mod*(s(j)+s(i-1-j))%mod*oszt(i+1)%mod)%mod;
            cnt[i]+=alatt(i-1, j)*cnt[j]%mod*cnt[i-1-j]%mod*(i+1)%mod;
        }
        tele[i]%=mod;
        cnt[i]%=mod;
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            for (int k=0; k+j<=m; k++) {
                if (i+k<=n) {
                    db[i+k+1][j+k]+=alatt(m-j, k)*db[i][j]%mod*cnt[k];
                    db[i+k+1][j+k]%=mod;
                    dp[i+k+1][j+k]+=alatt(m-j, k)*((cnt[k]*dp[i][j]%mod)+db[i][j]*tele[k]%mod)%mod;
                    dp[i+k+1][j+k]%=mod;
                }
            }
        }
    }
    cout << dp[n+1][m] << "\n";
    return 0;
}