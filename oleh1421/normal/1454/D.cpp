//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int cnt[N];
int a[N];
int val[N];
void solve(){
    ll n;cin>>n;
    vector<pair<ll,ll> >p;
    ll d=2;
    while (d*d<=n){
        int cnt=0;
        while (n%d==0){
            n/=d;
            cnt++;
        }
        if (cnt) p.push_back({d,cnt});
        d++;
    }
    if (n>1) p.push_back({n,1});
    ll mx=0;
    for (auto cur:p) mx=max(mx,cur.second);
    vector<ll>ans(mx,1ll);
    for (auto cur:p){
        for (int i=1;i<=cur.second;++i){
            ans[mx-i]*=cur.first*1ll;
        }
    }
    cout<<ans.size()<<endl;
    for (ll x:ans) cout<<x<<" ";
    cout<<endl;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}