#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int MAXK=505;
const int INF=0x3f3f3f3f;
map<int,int> e[MAXK*MAXK];
int dis[MAXK*MAXK],vis[MAXK*MAXK];
void dijkstra(int s,int n)
{
    for(int i=0;i<n;i++)
        dis[i]=INF,vis[i]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({dis[s]=0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        for(auto& [v,c] : e[u])
        {
            if(dis[v]>dis[u]+c)
            {
                dis[v]=dis[u]+c;
                pq.push({-dis[v],v});
            }
        }
    }
}
void solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m=(k+1)*(k+1);
    for(int i=0;i<m;i++)
        e[i].clear();
    auto get=[k](int x,int y) {
        return x*(k+1)+y;
    };
    for(int i=0;i<k;i++)
        for(int j=0;j<=k;j++)
        {
            e[get(i,j)][get(i+1,j)]=0;
            e[get(i+1,j)][get(i,j)]=0;
        }
    for(int i=0;i<=k;i++)
        for(int j=0;j<k;j++)
        {
            e[get(i,j)][get(i,j+1)]=0;
            e[get(i,j+1)][get(i,j)]=0;
        }
    for(int i=1;i<=n;i++)
    {
        int r[2],c[2];
        scanf("%d%d%d%d",&r[0],&c[0],&r[1],&c[1]);
        for(int _=0;_<2;_++)
        {
            if(r[0]==r[1])
            {
                int tc=min(c[0],c[1]);
                e[get(r[0]-1,tc)][get(r[0],tc)]++;
                e[get(r[0],tc)][get(r[0]-1,tc)]++;
            }
            else
            {
                int tr=min(r[0],r[1]);
                e[get(tr,c[0]-1)][get(tr,c[0])]++;
                e[get(tr,c[0])][get(tr,c[0]-1)]++;
            }
            for(int i=0;i<2;i++)
                r[i]=k+1-r[i],c[i]=k+1-c[i];
        }
    }
    dijkstra(get(k/2,k/2),m);
    int res=INF;
    for(int i=0;i<=k;i++)
    {
        res=min(res,dis[get(0,i)]);
        res=min(res,dis[get(k,i)]);
        res=min(res,dis[get(i,0)]);
        res=min(res,dis[get(i,k)]);
    }
    printf("%d\n",n-res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}