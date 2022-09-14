//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2000010;
#define int ll
int a[N];
int b[N];
int pos[N];
ll n,m;
ll n1,m1,g;
ll inv[N];
ll K[N];
ll I[N];
int cnt=0;
ll get(ll T){
    ll cur=T;
    for (int i=1;i<=cnt;i++) if (n*K[i]+I[i]<=T) cur-=((T-I[i])/n-K[i])/m1+1ll;
    return cur;
 
}
void solve(){
    cin>>n>>m;
    ll k;cin>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i],pos[b[i]]=i;
    for (ll i=0;i<m1;i++) inv[i]=-1;
    g=__gcd(n,m);
    n1=n/g;
    m1=m/g;
    for (ll i=0;i<m1;i++){
        inv[n1*i%m1]=i;
    }
    for (ll i=1;i<=n;i++){
        if (!pos[a[i]]) continue;
        ll j=pos[a[i]];
        ll x=((j-i)%m+m)%m;
        if (x%g) continue;
        x/=g;
//        cout<<i<<" "<<x<<endl;
        ll k=inv[(x%m1+m1)%m1];
        cnt++;
        K[cnt]=k;
        I[cnt]=i;
    }
    ll L=k-1ll;
    ll R=k*max(n,m);
    while (R-L>1){
        ll mid=(L+R)/2ll;
        if (get(mid)>=k) R=mid;
        else L=mid;
    }
    cout<<R<<endl;
 
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}