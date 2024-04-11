#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
vector<pair<int,int> >g[300001];
int w[300001];
int dp[300001];
int dp1[300001];
int res=0;
void dfs(int v,int pr){
     vector<pair<int,int> >x;
     for (auto to:g[v]){
        if (to.first!=pr){
            x.push_back(to);
            dfs(to.first,v);
        }
     }
     dp[v]=w[v];
     vector<int>st;
     for (auto i:x){
         int to=i.first;
         int cost=i.second;
         if (dp[to]>=cost){
             st.push_back(dp[to]-cost);
         }
     }
     sort(st.begin(),st.end());
     reverse(st.begin(),st.end());
     if (!st.empty()) dp[v]=st[0]+w[v];
     dp1[v]=dp[v];
     if ((int)st.size()>1){
        dp1[v]=max(dp1[v],st[0]+st[1]+w[v]);
     }
     res=max(res,dp1[v]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>w[i];
    }
    for (int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfs(1,0);
    cout<<res;
    return 0;
}