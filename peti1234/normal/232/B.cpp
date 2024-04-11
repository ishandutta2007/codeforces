#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll c=102;
ll n, m, k, ert, kdp[c][c*c], ndp[c][c*c], fakt[c], inv[c], kh[c], nh[c], sum, x, y, mod=1000000007;
ll gyh(ll a, ll b) {
    ll ans=1;
    while(b) {
        if (b%2) ans*=a, ans%=mod;
        a*=a, a%=mod, b/=2;
    }
    return ans;
}
ll oszt(ll a) { return gyh(a, mod-2);}
ll alatt(ll a, ll b) {return fakt[a]*inv[b]%mod*inv[a-b]%mod;}
int main()
{
    cin >> n >> m >> k, kdp[0][0]=1, ndp[0][0]=1, fakt[0]=1, inv[0]=1, ert=m/n, x=m%n, y=n-x;
    for (int i=1; i<=n; i++) fakt[i]=fakt[i-1]*i%mod, inv[i]=oszt(fakt[i]);
    for (int i=0; i<=n; i++) kh[i]=gyh(alatt(n, i), ert), nh[i]=gyh(alatt(n, i), ert+1);
    for (int i=1; i<=n; i++) for (int j=0; j<=n; j++) for (int p=j; p<=k; p++) {
        kdp[i][p]+=kdp[i-1][p-j]*kh[j], kdp[i][p]%=mod;
        ndp[i][p]+=ndp[i-1][p-j]*nh[j], ndp[i][p]%=mod;
    }
    for (int i=0; i<=k; i++) sum+=ndp[x][i]*kdp[y][k-i]%mod;
    cout << sum%mod << "\n";
    return 0;
}