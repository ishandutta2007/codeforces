#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=3010;
vector<int>g[N];
vector<pair<int,int> >q[N];
int p[N][N];
ll sz[N][N];
void dfsinit(int v,int pr,int cur,int root){
    p[root][v]=pr;
    sz[root][v]=1;
    q[cur].push_back({root,v});
    for (auto to:g[v]){
        if (to==pr) continue;
        dfsinit(to,v,cur+1,root);
        sz[root][v]+=sz[root][to];
    }
}
ll dp[N][N];
int32_t main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i=1;i<=n;i++){
        dfsinit(i,-1,0,i);
    }
    for (auto cur:q[0]) dp[cur.first][cur.second]=0;
    ll maxx=0;
    for (int len=1;len<n;len++){
        for (auto cur:q[len]){
            int u=cur.first;
            int v=cur.second;
            ///calc dp[u][v]
            dp[u][v]=sz[u][v]*sz[v][u]+max(dp[p[v][u]][v],dp[u][p[u][v]]);
            maxx=max(maxx,dp[u][v]);
            //cout<<u<<" "<<v<<" "<<dp[u][v]<<endl;
        }
    }
    cout<<maxx;

    return 0;
}
//0 0 1