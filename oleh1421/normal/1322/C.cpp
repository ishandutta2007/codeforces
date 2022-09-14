//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll mod=1000000007ll;
const int N=600010;
ll c[N];
vector<int>g[N];
vector<int>rg[N];
int cnt[N];
map<vector<int>,ll>mp;
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>c[i],g[i].clear(),rg[i].clear();
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        ll sum=0ll;
        for (auto to:g[i]) sum+=c[to];
        res=__gcd(res,sum);
    }
    mp.clear();
    for (int i=1;i<=n;i++){
        if (rg[i].empty()) continue;
        sort(rg[i].begin(),rg[i].end());
        mp[rg[i]]+=c[i];
    }
    for (auto cur:mp){
        res=__gcd(res,cur.second);
    }
    cout<<res<<endl;
}
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}