#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
#define ft first
#define sd second
vector<pair<int,int> >edge,sedge,res;
int fa[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)fa[i]=i;
}
int Find(int x)
{
    return x==fa[x] ? x : fa[x]=Find(fa[x]);
}
bool Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return 0;
    return fa[x]=y,1;
}
int vis[MAXN],id[MAXN][2],st;
vector<int>lef,rig,bot;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge.push_back(make_pair(u,v));
    }
    int s,t,ds,dt;
    scanf("%d%d%d%d",&s,&t,&ds,&dt);
    Init(n);
    for(int i=0;i<m;i++)
    {
        int u=edge[i].ft,v=edge[i].sd;
        if(u==s || u==t || v==s || v==t)
            sedge.push_back(edge[i]);
        else if(Union(u,v))
            res.push_back(edge[i]);
    }
    memset(id,-1,sizeof(id));
    st=-1;
    for(int i=0;i<(int)sedge.size();i++)
    {
        int u=sedge[i].ft,v=sedge[i].sd;
        if((u==s && v==t) || (u==t && v==s))st=i;
        else if(u==s || v==s)id[Find(u==s ? v : u)][0]=i;
        else if(u==t || v==t)id[Find(u==t ? v : u)][1]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int t=Find(i);
        if(vis[t])continue;
        vis[t]=1;
        if(id[t][0]>=0 && id[t][1]>=0)bot.push_back(t);
        else if(id[t][0]>=0)lef.push_back(t);
        else if(id[t][1]>=0)rig.push_back(t);
    }
    if(bot.empty() && st<0)return 0*printf("No\n");
    for(int i=0;i<(int)lef.size();i++)
    {
        res.push_back(sedge[id[lef[i]][0]]);
        ds--;
    }
    for(int i=0;i<(int)rig.size();i++)
    {
        res.push_back(sedge[id[rig[i]][1]]);
        dt--;
    }
    if(bot.empty())
    {
        res.push_back(sedge[st]);
        ds--,dt--;
    }
    else
    {
        res.push_back(sedge[id[bot[0]][0]]);
        res.push_back(sedge[id[bot[0]][1]]);
        ds--,dt--;
        for(int i=1;i<(int)bot.size();i++)
        {
            if(ds>0)
            {
                res.push_back(sedge[id[bot[i]][0]]);
                ds--;
            }
            else
            {
                res.push_back(sedge[id[bot[i]][1]]);
                dt--;
            }
        }
    }
    if(ds>=0 && dt>=0)
    {
        printf("Yes\n");
        for(int i=0;i<(int)res.size();i++)
            printf("%d %d\n",res[i].first,res[i].second);
    }
    else printf("No\n");
    return 0;
}