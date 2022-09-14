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
const int N=500010;
const ll mod=998244353;
const ll inf=2000000000000000000;
vector<int>g[N];
int a[N];
int x[N];
int xr=0;
bool dp[N];
bool ans=false;
void dfs(int v,int pr){
    x[v]=a[v];
    dp[v]=false;
    int cnt=0;
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
            x[v]^=x[to];
            dp[v]|=dp[to];
            cnt+=dp[to];
        }
    }
    dp[v]|=(x[v]==xr);
    if (x[v]==0 && dp[v]) ans=true;
    if (cnt>=2) ans=true;
}
void solve(){
    int n,k;cin>>n>>k;
    xr=0;
    for (int i=1;i<=n;i++) cin>>a[i],xr^=a[i],g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (xr==0){
        cout<<"YES\n";
        return;
    }
    if (k==2){
        cout<<"NO\n";
        return;
    }
    ans=false;
    dfs(1,0);
    if (ans) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}