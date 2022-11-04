#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
const int DEG=17;
vector<pair<int,int> >e[MAXN];
int key[MAXN],p[MAXN],in[MAXN],out[MAXN],time_tag;
int dep[MAXN],dis[MAXN],fa[MAXN][DEG];
void dfs1(int u)
{
    for(int i=1;i<DEG;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    p[in[u]=++time_tag]=u;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(v==fa[u][0])continue;
        dis[v]=dis[u]+e[u][i].second;
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dfs1(v);
    }
    out[u]=time_tag;
}
struct info
{
    int len,cnt,kid;
    info operator + (const info &t)const
    {
        if(len<t.len)return t;
        if(len>t.len)return *this;
        return info{len,cnt+t.cnt,kid};
    }
}s[MAXN<<2];
int lz[MAXN<<2];
inline void pushUp(int n)
{
    s[n]=s[n<<1]+s[n<<1|1];
}
inline void pushDown(int n)
{
    if(!lz[n])return;
    s[n<<1].len+=lz[n];
    s[n<<1|1].len+=lz[n];
    lz[n<<1]+=lz[n];
    lz[n<<1|1]+=lz[n];
    lz[n]=0;
}
void build(int l,int r,int n)
{
    if(l==r)
    {
        s[n]=(key[p[l]] ? info{dis[p[l]],1,p[l]} : info{-INF,0,0});
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    pushUp(n);
}
void update(int ql,int qr,int v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        s[n].len+=v;
        lz[n]+=v;
        return;
    }
    pushDown(n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,v,l,m,n<<1);
    else if(ql>m)update(ql,qr,v,m+1,r,n<<1|1);
    else
    {
        update(ql,m,v,l,m,n<<1);
        update(m+1,qr,v,m+1,r,n<<1|1);
    }
    pushUp(n);
}
info query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return s[n];
    pushDown(n);
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,n<<1);
    if(ql>m)return query(ql,qr,m+1,r,n<<1|1);
    return query(ql,m,l,m,n<<1)+query(m+1,qr,m+1,r,n<<1|1);
}
inline int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=0,d=dep[u]-dep[v];d;i++,d>>=1)
        if(d&1)u=fa[u][i];
    if(u==v)return u;
    for(int i=DEG-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int dp[MAXN];
void cal(int u,int n)
{
    info tmp=query(1,n,1,n,1);
    int g=u;
    for(int i=DEG-1;i>=0;i--)
    {
        int t=fa[g][i];
        if(!t)continue;
        if(query(in[t],out[t],1,n,1).len<tmp.len)g=t;
    }
    if(query(in[g],out[g],1,n,1).len<tmp.len)g=fa[g][0];
    int h=query(in[g],out[g],1,n,1).kid;
    for(int i=DEG-1;i>=0;i--)
    {
        int t=fa[h][i];
        if(dep[t]<=dep[g])continue;
        if(query(in[t],out[t],1,n,1).cnt<tmp.cnt)h=t;
    }
    if(query(in[h],out[h],1,n,1).cnt<tmp.cnt)h=fa[h][0];
    dp[u]++,dp[h]++,dp[lca(u,h)]--,dp[fa[lca(u,h)][0]]--;
}
void dfs2(int u,int n)
{
    if(key[u])cal(u,n);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(v==fa[u][0])continue;
        update(1,n,e[u][i].second,1,n,1);
        update(in[v],out[v],-2*e[u][i].second,1,n,1);
        dfs2(v,n);
        update(1,n,-e[u][i].second,1,n,1);
        update(in[v],out[v],2*e[u][i].second,1,n,1);
    }
}
void dfs3(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(v==fa[u][0])continue;
        dfs3(v);
        dp[u]+=dp[v];
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        key[t]=1;
    }
    for(int i=1;i<=n-1;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[a].push_back(make_pair(b,c));
        e[b].push_back(make_pair(a,c));
    }
    dfs1(1);
    build(1,n,1);
    dfs2(1,n);
    dfs3(1);
    int res=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(key[i])continue;
        if(res<dp[i])res=dp[i],cnt=0;
        if(res==dp[i])cnt++;
    }
    return 0*printf("%d %d",res,cnt);
}