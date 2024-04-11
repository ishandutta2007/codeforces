#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
const ll mod=1000000007ll;
ll n,m;
ll a[N],b[N];
ll pref[N];
void solve(){
    int n,m;cin>>n>>m;
    vector<pair<ll,ll> >v;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i],v.push_back({a[i],b[i]});
    sort(v.begin(),v.end());
    for (int i=0;i<m;i++){
        pref[i+1]=(pref[i]+v[i].first);
    }
    ll res=0ll;
    for (int i=0;i<m;i++){
        ll b_val=v[i].second;
        pair<ll,ll>cur={b_val,0};
        int l=upper_bound(v.begin(),v.end(),cur)-v.begin();
        if (l<=i){
            if (n<=m-l){
                res=max(res,pref[m]-pref[m-n]);
            } else {
                res=max(res,pref[m]-pref[l]+(n-m+l+0ll)*b_val);
            }
        } else {
            if (n-1<=m-l){
                res=max(res,pref[m]-pref[m-n+1]+v[i].first);
            } else {
                res=max(res,pref[m]-pref[l]+v[i].first+b_val*(n-m+l-1ll));
            }
        }
    }
    cout<<res<<endl;
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