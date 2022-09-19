#include <bits/stdc++.h>

using namespace std;
const int c=3000005;
long long n, q, fakt[c], inv[c], dp[c][3], o3, mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p>0) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(int a, int b) {
    if (a<b || a<0 || b<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
long long valt(long long a) {
    while (a>=mod) {
        a-=mod;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<3*n+5; i++) {
        fakt[i]=fakt[i-1]*i%mod;
    }
    inv[3*n+4]=oszt(fakt[3*n+4]);
    for (int i=3*n+3; i>=1; i--) {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    dp[0][0]=dp[0][1]=dp[0][2]=n;
    o3=oszt(3);
    for (int i=1; i<=3*n; i++) {
        long long a=dp[i-1][1], b=dp[i-1][2], x;
        x=valt((alatt(3*n+1, i+1)+2*a+b))*o3%mod;
        dp[i][0]=x, dp[i][1]=valt(x-a+mod), dp[i][2]=valt(x-a-b+2*mod);
    }
    for (int i=1; i<=q; i++) {
        int x;
        cin >> x;
        cout << dp[x][0] << "\n";
    }
    return 0;
}