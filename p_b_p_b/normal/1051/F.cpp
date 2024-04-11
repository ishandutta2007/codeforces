#include<bits/stdc++.h>
#define sz 100020
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO{
    inline FastIO& operator>>(int& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
    {
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
            while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,m;
struct hh{int t;ll w;int nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t,ll w)
{
    edge[++ecnt]=(hh){t,w,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,w,head[t]};
    head[t]=ecnt;
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define v edge[i].t
int fa[sz][20],dep[sz];
ll ddep[sz];
bool vis[sz];
bool is[sz];
int cnt;
ll dis[66][sz];
struct hhh{int x;ll d;};
struct cmp{const bool operator () (const hhh &x,const hhh &y){return x.d>y.d;}};
void dijkstra(int S,int id)
{
    memset(dis[id],0x3f,sizeof(dis[id]));
    dis[id][S]=0;
    priority_queue<hhh,vector<hhh>,cmp>q;
    q.push((hhh){S,0});
    while (!q.empty())
    {
        hhh x=q.top();q.pop();
        if (dis[id][x.x]!=x.d) continue;
        go(x.x)
            if (dis[id][v]>x.d+edge[i].w) 
                dis[id][v]=x.d+edge[i].w,q.push((hhh){v,dis[id][v]});
    }
}
void init()
{
    for (int i=1;i<=17;i++)
        for (int x=1;x<=n;x++)
            fa[x][i]=fa[fa[x][i-1]][i-1];
}
void dfs(int x,int f)
{
    vis[x]=1;dep[x]=dep[fa[x][0]=f]+1;
    go(x) if (v!=f)
    {
        if (vis[v]) is[v]=is[x]=1;
        else ddep[v]=ddep[x]+edge[i].w,dfs(v,x);
    }
}
int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=17;i>=0;i--) if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if (x==y) return x;
    for (int i=17;i>=0;i--)	if (fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int main()
{
    file();
    int i,j,k,x,y,z,Q;
    read>>n>>m;
    while (m--) read>>x>>y>>z,make_edge(x,y,z);
    dfs(1,0);init();
    for (i=1;i<=n;i++) if (is[i]) dijkstra(i,++cnt);
    read>>Q;
    while (Q--)
    {
        read>>x>>y;
        z=lca(x,y);
        ll ans=ddep[x]+ddep[y]-2*ddep[z];
        for (i=1;i<=cnt;i++) ans=min(ans,dis[i][x]+dis[i][y]);
        printf("%lld\n",ans);
    }
}