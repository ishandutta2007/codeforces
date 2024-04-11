#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXM=600005;
const int INF=0x3f3f3f3f;
vector<int> e[MAXM];
int top[MAXM],fa[MAXM],dep[MAXM],siz[MAXM];
int son[MAXM],in[MAXM],out[MAXM],idx[MAXM],time_tag;
void dfs1(int u)
{
    siz[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa[u])continue;
        fa[v]=u;
        dep[v]=dep[u]+1;
        dfs1(v);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
void dfs2(int u,int sp)
{
    top[u]=sp;
    idx[in[u]=++time_tag]=u;
    if(son[u])dfs2(son[u],sp);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==son[u] || v==fa[u])continue;
        dfs2(v,v);
    }
    out[u]=time_tag;
}
int lca_dis(int u,int v,int on)
{
    int res=0,f1=top[u],f2=top[v];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
            swap(f1,f2),swap(u,v);
        res+=dep[u]-dep[f1]+1;
        u=fa[f1],f1=top[u];
    }
    if(dep[u]>dep[v])swap(u,v);
    return (on ? res+dep[v]-dep[u] : u);
}
struct info
{
    int v,c;
    info(){}
    info(int _v,int _c):v(_v),c(_c){}
    info operator + (const info &rhs)const
    {
        if(v>rhs.v)return (*this);
        if(v<rhs.v)return rhs;
        return info(v,c+rhs.c);
    }
};
info val[MAXM<<2];
int lz[MAXM<<2];
void push_up(int n)
{
    val[n]=val[n<<1]+val[n<<1|1];
}
void push_down(int n)
{
    if(!lz[n])return;
    val[n<<1].v+=lz[n];
    val[n<<1|1].v+=lz[n];
    lz[n<<1]+=lz[n];
    lz[n<<1|1]+=lz[n];
    lz[n]=0;
}
void build(int l,int r,int n)
{
    val[n]=info(-INF,0);
    lz[n]=0;
    if(l==r)return;
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
}
void activate(int p,int v,int l,int r,int n)
{
    if(l==r)
    {
        val[n]=info(v,1);
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(p<=m)activate(p,v,l,m,n<<1);
    else activate(p,v,m+1,r,n<<1|1);
    push_up(n);
}
void update(int ql,int qr,int v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        val[n].v+=v;
        lz[n]+=v;
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,v,l,m,n<<1);
    else if(ql>m)update(ql,qr,v,m+1,r,n<<1|1);
    else
    {
        update(ql,m,v,l,m,n<<1);
        update(m+1,qr,v,m+1,r,n<<1|1);
    }
    push_up(n);
}
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=2;i<=m+1;i++)
    {
        int f;
        scanf("%d",&f);
        e[f].push_back(i+m);
        e[i+m].push_back(f);
        e[i+m].push_back(i);
        e[i].push_back(i+m);
    }
    time_tag=0;
    dfs1(1);
    dfs2(1,1);
    int dl=1,dr=1,dlen=0,c=1;
    build(1,time_tag,1);
    activate(in[1],lca_dis(1,c,1),1,time_tag,1);
    for(int i=2;i<=m+1;i++)
    {
        for(int j=m;j>=0;j-=m)
        {
            int dt=i+j;
            if(lca_dis(dl,dt,1)>dlen)
                dlen=lca_dis(dl,dt,1),dr=dt;
            if(lca_dis(dt,dr,1)>dlen)
                dlen=lca_dis(dt,dr,1),dl=dt;
        }
        if(dep[dl]<dep[dr])swap(dl,dr);
        int dm=dl,dt=lca_dis(dl,dr,1)/2;
        while(dt>0)
        {
            if(top[dm]==dm)dt--,dm=fa[dm];
            else if(dt>=dep[dm]-dep[top[dm]])
                dt-=dep[dm]-dep[top[dm]],dm=top[dm];
            else break;
        }
        dm=idx[in[dm]-dt];
        int lca=lca_dis(c,dm,0);
        for(int j=-1;j<=1;j+=2)
        {
            while(c!=lca)
            {
                update(1,time_tag,j,1,time_tag,1);
                update(in[c],out[c],-2*j,1,time_tag,1);
                c=fa[c];
            }
            c=dm;
        }
        activate(in[i],lca_dis(i,c=dm,1),1,time_tag,1);
        printf("%d\n",val[1].c);
    }
    return 0;
}