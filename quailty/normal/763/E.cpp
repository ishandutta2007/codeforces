#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
vector<int>e[MAXN];
int ql[MAXN],qr[MAXN],res[MAXN];
struct DSU
{
    int n,fa[MAXN],cnt;
    void Init(int _n)
    {
        n=_n,cnt=0;
        for(int i=1;i<=n;i++)fa[i]=i;
    }
    int Find(int x)
    {
        return fa[x]==x ? x : fa[x]=Find(fa[x]);
    }
    void Union(int x,int y)
    {
        x=Find(x),y=Find(y);
        if(x==y)return;
        fa[x]=y,cnt++;
    }
}dsu;
int cut[MAXN],tmp[MAXN][5],id[MAXN];
void solve(int l,int r,vector<int>t)
{
    if(r-l<10)
    {
        for(int ii=0;ii<(int)t.size();ii++)
        {
            int i=t[ii];
            dsu.Init(r-l+1);
            for(int u=ql[i];u<=qr[i];u++)
                for(int _=0;_<(int)e[u].size();_++)
                {
                    int v=e[u][_];
                    if(v>=ql[i] && v<=qr[i])dsu.Union(u-l+1,v-l+1);
                }
            res[i]=(qr[i]-ql[i]+1)-dsu.cnt;
        }
        return;
    }
    int m=(l+r)/2;
    dsu.Init(m-l+1);
    for(int u=m;u>=l;u--)
    {
        for(int _=0;_<(int)e[u].size();_++)
        {
            int v=e[u][_];
            if(v>=u && v<=m)dsu.Union(u-l+1,v-l+1);
        }
        cut[u]=dsu.cnt;
        for(int i=0;i<5;i++)
        {
            int rt=dsu.Find(m-l+i-3);
            if(!id[rt])id[rt]=i+1;
            tmp[u][i]=id[rt];
        }
        for(int i=0;i<5;i++)
            id[dsu.Find(m-l+i-3)]=0;
    }
    dsu.Init(r-m);
    for(int u=m+1;u<=r;u++)
    {
        for(int _=0;_<(int)e[u].size();_++)
        {
            int v=e[u][_];
            if(v>=m+1 && v<=u)dsu.Union(u-m,v-m);
        }
        cut[u]=dsu.cnt;
        for(int i=0;i<5;i++)
        {
            int rt=dsu.Find(i+1);
            if(!id[rt])id[rt]=i+1;
            tmp[u][i]=id[rt]+5;
        }
        for(int i=0;i<5;i++)
            id[dsu.Find(i+1)]=0;
    }
    vector<int>tl,tr;
    for(int ii=0;ii<(int)t.size();ii++)
    {
        int i=t[ii];
        if(qr[i]<=m)tl.push_back(i);
        else if(ql[i]>m)tr.push_back(i);
        else
        {
            res[i]=qr[i]-ql[i]+1-cut[ql[i]]-cut[qr[i]];
            dsu.Init(10);
            for(int j=0;j<5;j++)
                dsu.fa[j+1]=tmp[ql[i]][j];
            for(int j=0;j<5;j++)
                dsu.fa[j+6]=tmp[qr[i]][j];
            for(int u=max(ql[i],m-4);u<=m;u++)
                for(int _=0;_<(int)e[u].size();_++)
                {
                    int v=e[u][_];
                    if(v>=m+1 && v<=min(qr[i],m+5))dsu.Union(u-m+5,v-m+5);
                }
            res[i]-=dsu.cnt;
        }
    }
    solve(l,m,tl);
    solve(m+1,r,tr);
}
int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d",&ql[i],&qr[i]);
    vector<int>t(q);
    for(int i=0;i<q;i++)
        t[i]=i+1;
    solve(1,n,t);
    for(int i=1;i<=q;i++)
        printf("%d\n",res[i]);
    return 0;
}