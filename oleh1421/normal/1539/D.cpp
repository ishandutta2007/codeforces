#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500055;
const ll mod=1000000007;
const ll inf=1e18;
pair<ll,ll>a[N];
int n;
bool ok(ll x){
    ll sum=0ll;
    vector<pair<ll,ll> >C;
    for (int i=1;i<=n;i++){
        sum+=a[i].second;
        if (sum>=x){
            C.push_back({a[i].first,a[i].second-sum+x});
            break;
        } else C.push_back(a[i]);
    }
    sum=0;
    for (int i=1;i<=n;i++) sum+=a[i].second;
    sum-=x;
    for (auto cur:C){
        if (cur.first>sum) return false;
        sum+=cur.second;
    }
    return true;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        sum+=a[i].second;
    }
    ll ans=0;
    for (int it=60;it>=0;it--){
        if (ans+(1ll<<it)<=sum && ok(ans+(1ll<<it))) ans+=(1ll<<it);
    }
    cout<<sum*2ll-ans<<endl;

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
//7
//3 6 5 6 2 1 3
//1 1 1 1 -1 -1 1
//3 1 1 1
/**
18
6 18 17 5 18 11 13 1 17 3 18 12 8 16 8 6 8 9


-1 1 1 -1 1 1 1 -1 1 -1 1 1 1 1 1 -1 1 1


**/
//k*d-d=2
//d*(k-2)=2
//k>1
//d=2