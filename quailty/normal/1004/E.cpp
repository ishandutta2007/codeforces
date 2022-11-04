#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
vector<pair<int,int> > e[MAXN];
int dis[MAXN],fa[MAXN],usd[MAXN];
void dfs(int u,int f,int &mx)
{
    fa[u]=f,mx=max(mx,dis[u]);
    for(auto &t:e[u])
    {
        int v=t.first;
        int c=t.second;
        if(v==f || usd[v])continue;
        dis[v]=dis[u]+c;
        dfs(v,u,mx);
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n-1;i++)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        e[u].push_back({v,d});
        e[v].push_back({u,d});
    }
    int mx;
    dfs(1,dis[1]=0,mx);
    int du=1;
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[du])
            du=i;
    dfs(du,dis[du]=0,mx);
    int dv=1;
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[dv])
            dv=i;
    vector<int> dia,len,dep;
    while(dv)
    {
        dia.push_back(dv);
        len.push_back(dis[dv]);
        usd[dv]=1;
        dv=fa[dv];
    }
    reverse(dia.begin(),dia.end());
    reverse(len.begin(),len.end());
    int d=(int)dia.size();
    k=min(k,d);
    for(int i=0;i<d;i++)
    {
        dis[dia[i]]=mx=0;
        dfs(dia[i],0,mx);
        dep.push_back(mx);
    }
    int res=INF;
    deque<pair<int,int> > dq;
    for(int i=0,j=0;i+k<=d;i++)
    {
        while(j<i+k)
        {
            while(!dq.empty() && dq.back().first<dep[j])
                dq.pop_back();
            dq.push_back({dep[j],j});
            j++;
        }
        while(dq.front().second<i)
            dq.pop_front();
        res=min(res,max({len[i],len.back()-len[i+k-1],dq.front().first}));
    }
    printf("%d\n",res);
    return 0;
}