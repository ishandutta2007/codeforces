#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=6e5+10;
int n,m,f[M],tag[M];
int de[M],tot,son[M][2],dis[M],rt[M];
vector<pair<int,int> >v[M];
pair<int,int>a[M];
struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void work(int x,int val){tag[x]+=val,a[x].first+=val;}
void spread(int x){if (tag[x])work(son[x][0],tag[x]),work(son[x][1],tag[x]),tag[x]=0;}

int merge(int x,int y)
{
    if (!x||!y)return x+y;
    if (a[x].first>a[y].first)swap(x,y);
    spread(x);
    son[x][1]=merge(son[x][1],y);
    if (dis[son[x][1]]>dis[son[x][0]])swap(son[x][0],son[x][1]);
    dis[x]=dis[son[x][1]]+1;
    return x;
}

void dfs(int u,int fa)
{
    de[u]=de[fa]+1;
    for (int i=0;i<v[u].size();i++)
    {
        a[++tot]=v[u][i];
        dis[tot]=1,rt[u]=merge(rt[u],tot);
    }int sum=0;
    for (int i=head[u];i;i=e[i].next)
    {
        int to=e[i].to;if (to==fa)continue;
        dfs(to,u);work(rt[to],-f[to]);
        rt[u]=merge(rt[u],rt[to]),sum+=f[to];
    }
    work(rt[u],sum);
    while(rt[u]&&de[u]<=de[a[rt[u]].second])
        {spread(rt[u]),rt[u]=merge(son[rt[u]][0],son[rt[u]][1]);}
    if (!rt[u]){puts("-1");exit(0);}
    f[u]=a[rt[u]].first;
}

signed main()
{
    n=read(),m=read();tot=n,de[1]=1;
    for (int i=1;i<n;i++)
    {
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    for (int i=1;i<=m;i++)
    {
        int a=read(),b=read(),k=read();
        v[a].push_back(make_pair(k,b));
    }int ans=0;
    for (int i=head[1];i;i=e[i].next)
    {
        int to=e[i].to;
        dfs(to,1);
        ans+=f[to];
    }cout<<ans;
    return 0;
}