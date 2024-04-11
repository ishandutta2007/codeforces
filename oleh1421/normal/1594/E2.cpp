//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
#define endl '\n'
const int N=1000010;
const ll mod=1000000007;
ll fxd[62];
vector<ll> get(ll u,ll bt,vector<pair<ll,int> >v){
    if (v.empty()){
        vector<ll>dp(6,fxd[bt]);
        return dp;
    }
    if (bt==1){
        vector<ll>dp(6,0);
        dp[v[0].second]=1;
        return dp;
    }
    vector<pair<ll,int> >L;
    vector<pair<ll,int> >R;
    int block=-1;
    for (auto cur:v){
        ll ind=cur.first;
        if (ind==u) {
            block=cur.second;
            continue;
        }
        while (ind/2>u) ind/=2;
        if (ind==u*2) L.push_back(cur);
        else R.push_back(cur);
    }
    vector<ll>dp0=get(u*2ll,bt-1,L);
    vector<ll>dp1=get(u*2ll+1,bt-1,R);
    vector<ll>dp(6,0);
    for (int i=0;i<6;i++){
        dp[i]=0;
        for (int j=0;j<6;j++){
            if (i==j || i+j==5) continue;
            for (int t=0;t<6;t++){
                if (t==i || i+t==5) continue;
                dp[i]=(dp[i]+dp0[j]*dp1[t])%mod;
            }
        }
    }
    if (block!=-1){
        for (int i=0;i<6;i++){
            if (i!=block) dp[i]=0;
        }
    }
    return dp;
}
void solve(){
    ll k;cin>>k;
    fxd[1]=1;
    for (int i=2;i<=k;i++){
        fxd[i]=fxd[i-1]*fxd[i-1]%mod*16ll%mod;
    }
    int n;cin>>n;
    vector<pair<ll,int> >v;
    for (int i=1;i<=n;i++){
        ll x;cin>>x;
        string col;cin>>col;
        int num;
        if (col=="white") num=0;
        else if (col=="yellow") num=5;
        else if (col=="green") num=1;
        else if (col=="blue") num=4;
        else if (col=="orange") num=2;
        else num=3;
        v.push_back({x,num});
    }
    sort(v.begin(),v.end());
    vector<ll>ans=get(1,k,v);
    ll res=0ll;
    for (ll i:ans) res+=i;
    cout<<res%mod<<endl;

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