#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=998244353ll;
const int N=200010;
ll a[N];
ll b[N];
ll pref[N];
ll f[N];
ll rf[N];
ll d[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>d[i];
    sort(d+1,d+n+1);
    pref[0]=0ll;
    for (int i=1;i<=n;i++){
        pref[i]=(pref[i-1]+d[i])%mod;
    }
    f[0]=rf[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
        rf[i]=binpow(f[i],mod-2);
    }
    for (int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        int ind=lower_bound(d+1,d+n+1,b[i])-d-1;
        if (n-ind<a[i]){
            cout<<0<<endl;
            continue;
        }
        ll x=n-ind;
        ll sum=(pref[n]-pref[ind]+mod)%mod;
        ll res=((((x-a[i])*sum)%mod)*binpow(x,mod-2ll))%mod;
        ll sum1=pref[ind];
        if (x<n) res+=((((x-a[i]+1ll)*sum1)%mod)*binpow(x+1ll,mod-2ll))%mod;
        cout<<res%mod<<endl;

    }
    return 0;
}