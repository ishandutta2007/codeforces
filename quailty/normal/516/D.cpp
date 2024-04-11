#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<62)-1;
#define ft first
#define sd second
vector<pair<int,ll> >e[MAXN];
ll v[MAXN<<1],lz[MAXN<<1];
inline int getId(int l,int r)
{
    return (l+r)|(l<r);
}
inline void pushUp(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    int ls=getId(l,m),rs=getId(m+1,r);
    v[n]=max(v[ls],v[rs]);
}
inline void pushDown(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    int ls=getId(l,m),rs=getId(m+1,r);
    v[ls]+=lz[n];
    lz[ls]+=lz[n];
    v[rs]+=lz[n];
    lz[rs]+=lz[n];
    lz[n]=0;
}
ll a[MAXN];
void build(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    lz[n]=0;
    if(l==r)
    {
        v[n]=a[l];
        return;
    }
    build(l,m);
    build(m+1,r);
    pushUp(l,r);
}
void update(int ql,int qr,ll v,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)
    {
        ::v[n]+=v;
        lz[n]+=v;
        return;
    }
    pushDown(l,r);
    if(qr<=m)update(ql,qr,v,l,m);
    else if(ql>m)update(ql,qr,v,m+1,r);
    else
    {
        update(ql,m,v,l,m);
        update(m+1,qr,v,m+1,r);
    }
    pushUp(l,r);
}
int in[MAXN],out[MAXN],time_tag;
void dfs1(int u,int fa,ll dep)
{
    in[u]=++time_tag;
    if((int)e[u].size()==1)a[in[u]]=dep;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==fa)continue;
        dfs1(v,u,dep+e[u][i].sd);
    }
    out[u]=time_tag;
}
ll dis[MAXN];
void dfs2(int u,int fa,int n)
{
    dis[u]=v[getId(1,n)];
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==fa)continue;
        update(1,n,e[u][i].sd,1,n);
        update(in[v],out[v],-2*e[u][i].sd,1,n);
        dfs2(v,u,n);
        update(1,n,-e[u][i].sd,1,n);
        update(in[v],out[v],2*e[u][i].sd,1,n);
    }
}
priority_queue<ll>pq[MAXN];
int sz[MAXN];
void dfs3(int u,int fa,ll L)
{
    while(!pq[u].empty())pq[u].pop();
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==fa)continue;
        dfs3(v,u,L);
        if(pq[u].size()<pq[v].size())pq[u].swap(pq[v]);
        while(!pq[v].empty())
        {
            pq[u].push(pq[v].top());
            pq[v].pop();
        }
    }
    while(!pq[u].empty() && pq[u].top()>dis[u]+L)pq[u].pop();
    pq[u].push(dis[u]);
    sz[u]=(int)pq[u].size();
}
int ptr;
char buff[10000000];
inline ll getLL()
{
    char ch;
    while((ch=buff[ptr++])<'0' || ch>'9');
    ll res=ch-'0';
    while((ch=buff[ptr++])>='0' && ch<='9')
        res=res*10+ch-'0';
    return res;
}
void Print(int x)
{
    if(x==0)return;
    Print(x/10);
    putchar(x%10+'0');
}
int main()
{
    fread(buff,1,sizeof(buff),stdin);
    int n=getLL();
    for(int i=1;i<=n-1;i++)
    {
        int x=getLL(),y=getLL();
        ll v=getLL();
        e[x].push_back(make_pair(y,v));
        e[y].push_back(make_pair(x,v));
    }
    for(int i=1;i<=n;i++)a[i]=-INF;
    dfs1(1,0,0);
    build(1,n);
    dfs2(1,0,n);
    int rt=1;
    for(int i=1;i<=n;i++)
        if(dis[rt]>dis[i])rt=i;
    int q=getLL();
    while(q--)
    {
        ll L=getLL();
        dfs3(rt,0,L);
        int res=0;
        for(int i=1;i<=n;i++)
            res=max(res,sz[i]);
        Print(res);
        puts("");
    }
    return 0;
}