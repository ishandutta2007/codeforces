#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
//int x[300001];
//int y[300001];
int cnt[20001];
void F(int x){
    while (x){
        cout<<x<<" ";
        cnt[x]++;
        if (x%2) x--;
        else x/=2;
    }
}
ll f(ll x,ll n){
    ll cnt=0;
    ll res=0ll;
    while (x<=n){
        res+=min(n-x+1,(1ll<<cnt));
        cnt++;
        x*=2ll;
    }
    return res;
}
void solve(){
    ll n,k;cin>>n>>k;
    //cout<<f(k,n);
    ll l=0;
    ll r=1000000000000000001ll;
    while (r-l>1){
        ll m=(l+r)/2ll;
        ll cur=m*2ll+1ll;
        if (f(cur,n)>=k) l=m;
        else r=m;
    }
    ll res=l+l+1;
    l=1;
    r=1000000000000000001ll;
    while (r-l>1){
        ll m=(l+r)/2ll;
        ll cur=m*2ll;
        if (f(cur,n)+f(cur+1ll,n)>=k) l=m;
        else r=m;
    }
    if (f(l+l,n)+f(l+l+1ll,n)>=k) res=max(res,l+l);
    cout<<res<<endl;
    //for (int i=2;i<=n;i+=2) cout<<i<<" "<<cnt[i]<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}