#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int long long
int dp[300011];
vector<int>g[300011];
int res=0;
void dfs(int v,int pr){
    ///calc dp[v][1]
    vector<int>u;
    for (auto to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        u.push_back(dp[to]);
    }
    sort(u.begin(),u.end());
    reverse(u.begin(),u.end());
    if (u.empty()) dp[v]=1;
    else if (u.size()==1){
        dp[v]=u[0]+1;
        res=max(res,u[0]+1);
    } else {
        dp[v]=u[0]+(int)u.size();
        res=max(u[0]+u[1]+(int)u.size()-(pr==0),res);
    }
}
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n+1;i++) g[i].clear(),dp[i]=0;
    res=0;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

}
///AAABABB