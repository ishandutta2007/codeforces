#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>g[200001];
ll sum[200001];
ll a[200001];
bool used[200001];
void dfsinit(int v,int pr){
     sum[v]=a[v];
     used[v]=true;
     for (auto to:g[v]){
        if (to!=pr && !used[to]){
            dfsinit(to,v);
            sum[v]+=sum[to];
        }
     }
}
ll res=0ll;
ll dp[200001];
ll maxx=0ll;
void dfs(int v,int pr){
     ll lastV=sum[v];
     ll lastPr=sum[pr];
     sum[pr]-=sum[v];
     sum[v]+=sum[pr];
     res-=lastV+lastPr;
     res+=sum[v]+sum[pr];
     maxx=max(maxx,res);
     for (auto to:g[v]){
        if (to!=pr) dfs(to,v);
     }
     res-=sum[v]+sum[pr];
     res+=lastV+lastPr;
     sum[v]=lastV;
     sum[pr]=lastPr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    ll s=0ll;
    for (int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfsinit(1,0);
    for (int i=1;i<=n;i++) res+=sum[i];
    maxx=res;
    for (auto to:g[1]) dfs(to,1);
    cout<<maxx-s;
    return 0;
}
/*
9 12
3 2 4 1 5 6 3 6 8
0 0 0 0 1 2 3 4 6
*/