#include <bits/stdc++.h>

using namespace std;
const int c=405;
long long n, mod, ans, dp[c][c], fakt[c], inv[c], t[c];
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(int a, int b) {
    if (a<b || a<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    cin >> n >> mod;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    t[1]=1, dp[0][0]=1;
    for (int i=2; i<=n; i++) {
        t[i]=t[i-1]*2%mod;
    }
    for (int i=0; i<n; i++) {
        // i+1-tol valameddig van egy blokk;
        for (int j=0; j<=i; j++) {
            // eddig j szinezett mezo van
            for (int h=1; i+h<=n; h++) {
                // h mezot kell kiszinezni
                dp[i+h+1][j+h]+=dp[i][j]*t[h]%mod*alatt(j+h, j)%mod;
                dp[i+h+1][j+h]%=mod;
            }
        }
    }
    for (int i=0; i<=n; i++) {
        ans+=dp[n+1][i];
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}
/*
3 100000007
*/