#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=200010;
int a[N];
vector<int>g[N];
int dp[N];
void dfs(int v,int pr){
    dp[v]=a[v];
    for (auto to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        dp[v]+=max(0,dp[to]);
    }
}
int res[N];
void solve(int v,int pr){
    res[v]=dp[v];
    if (pr){
        if (dp[v]>=0) res[v]=max(res[v],res[pr]);
        else res[v]+=max(0,res[pr]);
    }
    for (auto to:g[v]){
        if (to==pr) continue;
        solve(to,v);
    }
}
int main()
{
//    freopen("three.in","r",stdin);
//    freopen("three.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]=(a[i]==0 ? -1 : 1);
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;
    dfs(1,0);
//    cout<<dp[1]<<endl;
    solve(1,0);
    for (int i=1;i<=n;i++) cout<<res[i]<<" ";
    return 0;
}