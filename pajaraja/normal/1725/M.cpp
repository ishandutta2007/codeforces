#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
vector<int> g[2*MAXN];
vector<long long> w[2*MAXN];
bool vi[2*MAXN];
long long dist[2*MAXN];
void dijkstra()
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,1});
    fill(dist,dist+2*MAXN,-1);
    while(!pq.empty())
    {
        pair<long long,int> pi=pq.top();
        int u=pi.second; long long wt=pi.first;
        pq.pop();
        if(vi[u]) continue;
        vi[u]=true; dist[u]=wt;
        for(int i=0;i<g[u].size();i++) pq.push({dist[u]+w[u][i],g[u][i]});
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v; long long wt;
        scanf("%d%d%lld",&u,&v,&wt);
        g[u].push_back(v);
        w[u].push_back(wt);
        g[v+n].push_back(u+n);
        w[v+n].push_back(wt);
    }
    for(int i=1;i<=n;i++) {g[i].push_back(i+n); w[i].push_back(0);}
    dijkstra();
    for(int i=2;i<=n;i++) printf("%lld ",dist[n+i]);
}