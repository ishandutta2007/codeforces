#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=400010;
const int W=3010;
const ll mod=998244353;
int p[N];
int q[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>p[i],p[i]++,q[p[i]]=i;
    p[0]=n+1;
    q[n+1]=0;
    k--;
    for (int i=1;i<n;i++){
        if (q[p[i]+1]>=q[p[i+1]+1]) {
            k--;
        }
    }
    if (k<0){
        cout<<0<<endl;
        return;
    }
    ll res=1ll;
    for (ll i=n+1;i<=n+k;i++) {
        res*=i;
        res%=mod;
    }
    for (int i=1;i<=k;i++){
        res*=binpow(i,mod-2);
        res%=mod;
    }
    cout<<res<<endl;


}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}