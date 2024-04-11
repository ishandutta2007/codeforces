#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
vector<pair<int,ll> > e[MAXN];
ll dis[MAXN];
bool vis[MAXN];
void solve(int n,int st)
{
    for(int i=1;i<=n;i++)
        dis[i]=(1LL<<60)-1,vis[i]=0;
    priority_queue<pair<ll,int> > pq;
    pq.push({dis[st]=0,st});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i].first;
            ll c=e[u][i].second;
            if(!vis[v] && dis[v]>dis[u]+c)
            {
                dis[v]=dis[u]+c;
                pq.push({-dis[v],v});
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        e[u].push_back({v,2*w});
        e[v].push_back({u,2*w});
    }
    for(int i=1;i<=n;i++)
    {
        ll a;
        scanf("%lld",&a);
        e[n+1].push_back({i,a});
    }
    solve(n+1,n+1);
    for(int i=1;i<=n;i++)
        printf("%lld%c",dis[i]," \n"[i==n]);
    return 0;
}