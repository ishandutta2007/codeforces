#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
map<pair<int,int>,int> mp;
inline int get_id(int x,int y)
{
    pair<int,int> t=make_pair(x,y);
    if(!mp[t])mp[t]=(int)mp.size();
    return mp[t];
}
int r[MAXN],c[MAXN],dis[MAXN];
vector<pair<int,int> > edge[MAXN];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&r[i],&c[i]);
        get_id(r[i],c[i]);
    }
    int ost=50000;
    for(int i=1;i<=k;i++)
    {
        edge[i].push_back(make_pair(r[i]+k,0));
        edge[i].push_back(make_pair(c[i]+k+n,0));
        edge[r[i]+k+ost].push_back(make_pair(i,0));
        edge[c[i]+k+n+ost].push_back(make_pair(i,0));
        for(int j=0;j<4;j++)
        {
            int tr=r[i]+d[j][0],tc=c[i]+d[j][1];
            pair<int,int> t=make_pair(tr,tc);
            if(mp.find(t)!=mp.end())
                edge[i].push_back(make_pair(mp[t],0));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=-2;j<=2;j++)
            if(i+j>=1 && i+j<=n)
                edge[i+k].push_back(make_pair(i+j+k+ost,1));
    for(int i=1;i<=m;i++)
        for(int j=-2;j<=2;j++)
            if(i+j>=1 && i+j<=m)
                edge[i+k+n].push_back(make_pair(i+j+k+n+ost,1));
    pair<int,int> ed=make_pair(n,m);
    if(mp.find(ed)==mp.end())
    {
        mp[ed]=k+n+m+1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<2;j++)
            {
                pair<int,int> t=make_pair(i,m-j);
                if(mp.find(t)!=mp.end())
                    edge[mp[t]].push_back(make_pair(k+n+m+1,1));
            }
        for(int i=1;i<=m;i++)
            for(int j=0;j<2;j++)
            {
                pair<int,int> t=make_pair(n-j,i);
                if(mp.find(t)!=mp.end())
                    edge[mp[t]].push_back(make_pair(k+n+m+1,1));
            }
    }
    int s=get_id(1,1),t=get_id(n,m);
    memset(dis,INF,sizeof(dis));
    dis[s]=0;
    deque<int> q;
    q.push_back(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop_front();
        for(int i=0;i<(int)edge[u].size();i++)
        {
            int v=edge[u][i].first,t=edge[u][i].second;
            if(dis[v]>dis[u]+t)
            {
                dis[v]=dis[u]+t;
                if(t)q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    printf("%d\n",(dis[t]<INF ? dis[t] : -1));
    return 0;
}