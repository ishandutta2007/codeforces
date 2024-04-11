#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const ld inf=1e18;
const int N=500010;
ll f(ll r){
    ll x=0ll;
    for (ll i=30;i>=0;i--){
        x+=(1ll<<i);
        if (x*(x+1)>r) x-=(1ll<<i);
    }
    ll res=x;
    x=0ll;
    for (ll i=30;i>=0;i--){
        x+=(1ll<<i);
        if (x*(x+2)>r) x-=(1ll<<i);
    }
    res+=x;
    x=0ll;
    for (ll i=30;i>=0;i--){
        x+=(1ll<<i);
        if (x*x>r) x-=(1ll<<i);
    }
    res+=x;

    return res;
}
void solve(){
    ll l,r;cin>>l>>r;
    cout<<f(r)-f(l-1)<<'\n';


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

/**


**/