#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
const ll mod=998244353ll;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
ll f[N];
ll rf[N];
ll p[N];
ll C(int n,int k){
    return (f[n]*((rf[n-k]*rf[k])%mod))%mod;
}
ll F(ll n,ll k){
    return (2ll*C(n,k)*binpow(n-k,n))%mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;cin>>n>>k;
    f[0]=1ll;
    p[0]=1ll;
    for (ll i=1;i<=n;i++){
        p[i]=(p[i-1]*2ll)%mod;
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n]=binpow(f[n],mod-2ll);
    for (ll i=n;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    if (k>=n){
        cout<<0<<endl;
        return 0;
    }
    if (k==0){
        cout<<f[n]<<endl;
        return 0;
    }
    ll res=0ll;
    for (ll i=k;i<=n;i++){
        if (i%2==k%2) res+=(F(n,i)*C(i,k))%mod;
        else res+=((mod-F(n,i))*C(i,k))%mod;
    }
    cout<<res%mod<<endl;

    return 0;
}