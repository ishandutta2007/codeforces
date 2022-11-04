#include<bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int ty[MAXN],x[MAXN],y[MAXN],d[MAXN];

vector<int> base;
inline void add(int x)
{
    for(auto &t:base)
        x=min(x,x^t);
    if(x)
    {
        for(auto &t:base)
            t=min(t,t^x);
        base.push_back(x);
    }
}
inline int query(int x)
{
    for(auto &t:base)
        x=min(x,x^t);
    return x;
}

vector<vector<int> > seg[MAXN<<1];
inline int getid(int l,int r)
{
    return (l+r+2)|(l<r);
}
void cover(int ql,int qr,int l,int r,vector<int> t)
{
    int n=getid(l,r);
    if(ql==l && qr==r)
    {
        seg[n].push_back(t);
        return;
    }
    int m=(l+r)/2;
    if(qr<=m)cover(ql,qr,l,m,t);
    else if(ql>m)cover(ql,qr,m+1,r,t);
    else
    {
        cover(ql,m,l,m,t);
        cover(m+1,qr,m+1,r,t);
    }
}

struct DSU
{
    int fa[MAXN],ra[MAXN],w[MAXN];
    stack<pair<int*,int> > stk;
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i,ra[i]=w[i]=0;
        while(!stk.empty())
            stk.pop();
    }
    int find(int x)
    {
        while(fa[x]!=x)x=fa[x];
        return x;
    }
    int get(int x)
    {
        int res=0;
        while(fa[x]!=x)
        {
            res^=w[x];
            x=fa[x];
        }
        return res;
    }
    bool merge(int x,int y,int z)
    {
        int fx=find(x),fy=find(y);
        if(fx==fy)return 0;
        if(ra[fx]<ra[fy])
        {
            stk.push({&w[fx],w[fx]});
            w[fx]=get(x)^get(y)^z;
            stk.push({&fa[fx],fa[fx]});
            fa[fx]=fy;
        }
        else
        {
            stk.push({&w[fy],w[fy]});
            w[fy]=get(x)^get(y)^z;
            stk.push({&fa[fy],fa[fy]});
            fa[fy]=fx;
            if(ra[fx]==ra[fy])
            {
                stk.push({&ra[fx],ra[fx]});
                ra[fx]++;
            }
        }
        return 1;
    }
    void rollback(int x)
    {
        while((int)stk.size()>x)
        {
            *stk.top().first=stk.top().second;
            stk.pop();
        }
    }
}dsu;

void solve(int l,int r)
{
    int n=getid(l,r),m=(l+r)/2,t=(int)dsu.stk.size();
    vector<int> tbase=base;
    for(int i=0;i<(int)seg[n].size();i++)
    {
        int x=seg[n][i][0],y=seg[n][i][1],w=seg[n][i][2];
        if(!dsu.merge(x,y,w))add(dsu.get(x)^dsu.get(y)^w);
    }
    if(l==r)
    {
        if(ty[l]==3)printf("%d\n",query(dsu.get(x[l])^dsu.get(y[l])));
    }
    else
    {
        solve(l,m);
        solve(m+1,r);
    }
    dsu.rollback(t);
    base=tbase;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    map<pair<int,int>,pair<int,int> > mp;
    for(int i=1;i<=m;i++)
    {
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        mp[{x,y}]={d,0};
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&ty[i]);
        if(ty[i]==1)
        {
            scanf("%d%d%d",&x[i],&y[i],&d[i]);
            mp[{x[i],y[i]}]={d[i],i};
        }
        else if(ty[i]==2)
        {
            scanf("%d%d",&x[i],&y[i]);
            pair<int,int> t=mp[{x[i],y[i]}];
            cover(t.second,i-1,0,q,{x[i],y[i],t.first});
            mp.erase({x[i],y[i]});
        }
        else scanf("%d%d",&x[i],&y[i]);
    }
    for(auto &t:mp)
        cover(t.second.second,q,0,q,{t.first.first,t.first.second,t.second.first});
    dsu.init(n);
    solve(0,q);
    return 0;
}