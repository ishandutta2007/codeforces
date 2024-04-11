#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=500005;
int p[MAXN],r[MAXN];
int edge_tot,head[MAXN*25],ind[MAXN*25],nxt[MAXN*65],to[MAXN*65];
void add_edge(int u,int v)
{
    ind[v]++;
    to[edge_tot]=v;
    nxt[edge_tot]=head[u];
    head[u]=edge_tot++;
}
int node_tot,rt[MAXN],ls[MAXN*25],rs[MAXN*25];
void build(int l,int r,int &n)
{
    n=++node_tot;
    if(l==r)
    {
        add_edge(n,l);
        return;
    }
    int m=(l+r)/2;
    build(l,m,ls[n]);
    build(m+1,r,rs[n]);
    add_edge(n,ls[n]);
    add_edge(n,rs[n]);
}
void mark(int p,int l,int r,int ln,int &n)
{
    n=++node_tot;
    ls[n]=ls[ln];
    rs[n]=rs[ln];
    if(l==r)return;
    int m=(l+r)/2;
    if(p<=m)mark(p,l,m,ls[ln],ls[n]);
    else mark(p,m+1,r,rs[ln],rs[n]);
    add_edge(n,ls[n]);
    add_edge(n,rs[n]);
}
void link(int ql,int qr,int l,int r,int n,int u)
{
    if(qr<ql)return;
    if(ql==l && qr==r)
    {
        add_edge(u,n);
        return;
    }
    int m=(l+r)/2;
    if(qr<=m)link(ql,qr,l,m,ls[n],u);
    else if(ql>m)link(ql,qr,m+1,r,rs[n],u);
    else
    {
        link(ql,m,l,m,ls[n],u);
        link(m+1,qr,m+1,r,rs[n],u);
    }
}
void solve(int n)
{
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
        if(p[i]>0)add_edge(p[i],i);
    node_tot=n;
    build(1,n,rt[0]);
    for(int i=1;i<=n;i++)
    {
        rt[i]=rt[i-1];
        int up=(p[i]>0 ? p[i]-1 : n);
        if(i<=up)
        {
            link(1,i-1,1,n,rt[i],i);
            link(i+1,up,1,n,rt[i],i);
        }
        else link(1,up,1,n,rt[i],i);
        if(p[i]>0)mark(p[i],1,n,rt[i-1],rt[i]);
    }
    queue<int>q;
    for(int i=1;i<=node_tot;i++)
        if(!ind[i])q.push(i);
    int chk=n;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u<=n)r[u]=chk--;
        for(int i=head[u];~i;i=nxt[i])
        {
            int v=to[i];
            if((--ind[v])==0)q.push(v);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    solve(n);
    for(int i=1;i<=n;i++)
        printf("%d%c",r[i]," \n"[i==n]);
    return 0;
}