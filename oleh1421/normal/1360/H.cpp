//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
ll a[N];
int n,m;
bool ok(ll x){
    ll ind=lower_bound(a+1,a+n+1,x)-a-1;
    ll ind1=upper_bound(a+1,a+n+1,x)-a;
    return ((x-ind)<=((1ll<<m)-x-1ll-(n-ind1+1ll)));
}
bool check(ll x){
    int ind=lower_bound(a+1,a+n+1,x)-a;
    int ind1=upper_bound(a+1,a+n+1,x)-a;
    return (ind==ind1);
}
void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        a[i]=0ll;
        for (int j=0;j<m;j++){
            char c;cin>>c;
            a[i]*=2ll;
            a[i]+=(c-'0');
        }
    }
    sort(a+1,a+n+1);
    ll l=0ll;
    ll r=(1ll<<m);
    while (r-l>1){
        ll m=(l+r)/2ll;
        if (ok(m)) l=m;
        else r=m;
    }
    while (!check(l)) l--;
//    cout<<l<<endl;
    for (ll i=m-1;i>=0;i--) cout<<((l>>i)&1ll);
    cout<<endl;
//    int n;cin>>n;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            char c;cin>>c;
//            a[i][j]=(c-'0');
//        }
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4 3
000
111
100
011
*/