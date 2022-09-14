
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
const ll mod=1000000007ll;
int a[N];
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1ll))%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll C(int n,int k){
    if (k>n || k<0) return 0ll;
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=rf[0]=1ll;
    for (ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod,rf[i]=binpow(f[i],mod-2);
//    for (int i=1;i<=n;i++) cout<<f[i]<<" "<<rf[i]<<" "<<(f[i]*rf[i])%mod<<endl;
    ll res=0ll;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        int r=upper_bound(a+1,a+n+1,a[i]+k)-a-1;
//        cout<<i<<" "<<r<<endl;
        ll cnt=r-i;
        res+=C(cnt,m-1);
        res%=mod;
    }
    cout<<res<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
//3 1 5 4 2 2
//3 1 1