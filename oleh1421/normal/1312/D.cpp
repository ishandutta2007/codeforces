//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll mod=998244353;
const int N=400010;
int a[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (binpow(a,b-1ll)*a)%mod;
    else return binpow((a*a)%mod,b/2ll);
}
ll f[N];
ll rf[N];
ll C(int n,int k){
    if (k>n) return 0ll;
    return (((f[n]*rf[k])%mod)*rf[n-k])%mod;
}
int32_t main(){
//    freopen("accounts.in","r",stdin);
//    freopen("accounts.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    if (n==2){
        cout<<0;
        return 0;
    }
    f[0]=1ll;
    for (ll i=1ll;i<=m;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[m]=binpow(f[m],mod-2ll);
    for (ll i=m-1ll;i>=0;i--){
        rf[i]=(rf[i+1]*(i+1ll))%mod;
    }
    ll res=0ll;
    for (ll mx=1;mx<=m;mx++){
        res+=(C(mx-1,n-2)*(n-2ll));
        res%=mod;
//        cout<<mx-1<<" "<<n-1<<" "<<C(mx-1,n-1)<<endl;
    }
    res*=binpow(2ll,n-3ll);
    res%=mod;
    cout<<res;
    return 0;
}