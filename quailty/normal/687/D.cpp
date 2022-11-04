#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXM=600005;
struct Edge
{
    int u,v,w,id;
    bool operator < (const Edge &t)const
    {
        return w>t.w;
    }
};
int fa[MAXN],ra[MAXN],w[MAXN];
void Reset(int x)
{
    fa[x]=x,ra[x]=w[x]=0;
}
void Init(int n)
{
    for(int i=1;i<=n;i++)Reset(i);
}
int Find(int x)
{
    if(x!=fa[x])
    {
        int fx=Find(fa[x]);
        w[x]^=w[fa[x]];
        fa[x]=fx;
    }
    return fa[x];
}
int Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy)return w[x]^w[y]^1;
    if(ra[fx]<=ra[fy])
    {
        fa[fx]=fy;
        w[fx]=w[x]^w[y]^1;
        if(ra[fx]==ra[fy])ra[fy]++;
    }
    else
    {
        fa[fy]=fx;
        w[fy]=w[x]^w[y]^1;
    }
    return 2;
}
vector<Edge>seg[MAXM<<1];
int getId(int l,int r)
{
    return (l+r)|(l<r);
}
void build(vector<Edge>&edg,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    for(int i=0;i<(int)edg.size();i++)
    {
        int t=Union(edg[i].u,edg[i].v);
        if(t>=1)
        {
            seg[n].push_back(edg[i]);
            if(t==1)break;
        }
    }
    for(int i=0;i<(int)edg.size();i++)
        Reset(edg[i].u),Reset(edg[i].v);
    if(l==r)return;
    vector<Edge>lef,rig;
    for(int i=0;i<(int)edg.size();i++)
    {
        if(edg[i].id<=m)lef.push_back(edg[i]);
        else rig.push_back(edg[i]);
    }
    edg.clear();
    build(lef,l,m);
    build(rig,m+1,r);
}
vector<Edge> query(int ql,int qr,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)return seg[n];
    if(qr<=m)return query(ql,qr,l,m);
    if(ql>=m+1)return query(ql,qr,m+1,r);
    vector<Edge>res=query(ql,m,l,m),tmp=query(m+1,qr,m+1,r);
    for(int i=0;i<(int)tmp.size();i++)res.push_back(tmp[i]);
    return res;
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    vector<Edge>e(m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        e[i].id=i+1;
    }
    Init(n);
    sort(e.begin(),e.end());
    build(e,1,m);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        Init(n);
        e=query(l,r,1,m);
        sort(e.begin(),e.end());
        int res=-1;
        for(int i=0;i<(int)e.size();i++)
            if(Union(e[i].u,e[i].v)==1)
            {
                res=e[i].w;
                break;
            }
        printf("%d\n",res);
    }
    return 0;
}