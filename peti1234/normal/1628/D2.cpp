#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long w, n, m, k;
long long fakt[c], inv[c], mod=1e9+7, d2=(mod+1)/2;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<0 || b<0 || a<b) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        long long ans=0;
        for (int i=1; i<=m; i++) {
            ans=(ans+i*alatt(n, m-i))%mod;
        }
        for (int i=1; i<n; i++) {
            ans=ans*d2%mod;
        }
        ans=ans*k%mod;
        cout << ans << "\n";
    }
    return 0;
}