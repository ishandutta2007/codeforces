#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
vector<int>e[MAXN];
int fa[MAXN],dep[MAXN],cnt[MAXN],son[MAXN],time_tag;
int top[MAXN],in[MAXN],out[MAXN];
void dfs1(int u,int pre)
{
    dep[u]=dep[fa[u]=pre]+(cnt[u]=1);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==pre)continue;
        dfs1(v,u);
        cnt[u]+=cnt[v];
        if(cnt[v]>cnt[son[u]])son[u]=v;
    }
}
void dfs2(int u,int sp)
{
    top[u]=sp;
    in[u]=++time_tag;
    if(son[u])dfs2(son[u],sp);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v!=son[u] && v!=fa[u])dfs2(v,v);
    }
    out[u]=time_tag;
}
typedef pair<ll,ll> info;
#define ft first
#define sd second
info operator + (const info &a,const info &b)
{
    return make_pair(a.ft+b.ft,a.sd+b.sd);
}
struct node
{
    info v,lz;
    vector<info>c;
}s[MAXN<<1];
inline int getId(int l,int r)
{
    return (l+r)|(l<r);
}
inline void pushUp(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    int ls=getId(l,m),rs=getId(m+1,r);
    s[n].v=min(s[ls].v,s[rs].v);
}
inline void pushDown(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    int ls=getId(l,m),rs=getId(m+1,r);
    s[ls].v=s[ls].v+s[n].lz;
    s[ls].lz=s[ls].lz+s[n].lz;
    s[rs].v=s[rs].v+s[n].lz;
    s[rs].lz=s[rs].lz+s[n].lz;
    s[n].lz=make_pair(0,0);
}
void build(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(l==r)
    {
        s[n].c.push_back(info(INF,0));
        s[n].v=s[n].c.back();
        return;
    }
    build(l,m);
    build(m+1,r);
    pushUp(l,r);
}
void add(int p,info v,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(l==r)
    {
        s[n].c.push_back(v);
        s[n].v=s[n].c.back();
        return;
    }
    pushDown(l,r);
    if(p<=m)add(p,v,l,m);
    else add(p,v,m+1,r);
    pushUp(l,r);
}
void del(int p,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(l==r)
    {
        s[n].c.pop_back();
        s[n].v=s[n].c.back()+s[n].lz;
        return;
    }
    pushDown(l,r);
    if(p<=m)del(p,l,m);
    else del(p,m+1,r);
    pushUp(l,r);
}
void update(int ql,int qr,info v,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)
    {
        s[n].v=s[n].v+v;
        s[n].lz=s[n].lz+v;
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
info query(int ql,int qr,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)return s[n].v;
    pushDown(l,r);
    if(qr<=m)return query(ql,qr,l,m);
    if(ql>m)return query(ql,qr,m+1,r);
    return min(query(ql,m,l,m),query(m+1,qr,m+1,r));
}
info query(int u,int v,int n)
{
    int f1=top[u],f2=top[v];
    info res=make_pair(INF,0);
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        res=min(res,query(in[f1],in[u],1,n));
        u=fa[f1];
        f1=top[u];
    }
    if(dep[u]>dep[v])swap(u,v);
    return min(res,query(in[u],in[v],1,n));
}
int c[MAXN];
vector<int>res;
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<n;i++)
    {
        int v,u;
        scanf("%d%d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,n);
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    for(int i=m;i>=1;i--)
        add(in[c[i]],make_pair(i,i),1,n);
    for(int i=1;i<=q;i++)
    {
        int ty,v,u,k;
        scanf("%d",&ty);
        if(ty==1)
        {
            scanf("%d%d%d",&v,&u,&k);
            res.clear();
            while(k--)
            {
                info tmp=query(v,u,n);
                if(tmp.ft>=INF)break;
                res.push_back(tmp.sd);
                del(in[c[tmp.sd]],1,n);
            }
            printf("%d",(int)res.size());
            for(int i=0;i<(int)res.size();i++)
                printf(" %d",res[i]);
            printf("\n");
        }
        else
        {
            scanf("%d%d",&v,&k);
            update(in[v],out[v],make_pair(k,0),1,n);
        }
    }
    return 0;
}