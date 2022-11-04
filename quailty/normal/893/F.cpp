#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int a[MAXN],dep[MAXN];
vector<int> e[MAXN];
int rt[MAXN],tot;
int val[MAXN<<6],ls[MAXN<<6],rs[MAXN<<6];
void push_up(int n)
{
    val[n]=min(val[ls[n]],val[rs[n]]);
}
void update(int p,int v,int l,int r,int &n)
{
    n=++tot;
    if(l==r)
    {
        val[n]=v;
        return;
    }
    int m=(l+r)/2;
    if(p<=m)update(p,v,l,m,ls[n]);
    else update(p,v,m+1,r,rs[n]);
    push_up(n);
}
int merge(int u,int v)
{
    if(!u)return v;
    if(!v)return u;
    int t=++tot;
    ls[t]=merge(ls[u],ls[v]);
    rs[t]=merge(rs[u],rs[v]);
    if(ls[t] || rs[t])push_up(t);
    else val[t]=min(val[u],val[v]);
    return t;
}
int query(int ql,int qr,int l,int r,int n)
{
    if(!n)return INF;
    if(ql==l && qr==r)return val[n];
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,ls[n]);
    if(ql>m)return query(ql,qr,m+1,r,rs[n]);
    return min(query(ql,m,l,m,ls[n]),query(m+1,qr,m+1,r,rs[n]));
}
void dfs(int u,int f)
{
    update(dep[u],a[u],1,MAXN-1,rt[u]);
    for(auto &v:e[u])
    {
        if(v==f)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        rt[u]=merge(rt[u],rt[v]);
    }
}
int main()
{
    val[0]=INF;
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[r]=1,dfs(r,0);
    int m,la=0;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        int x=(p+la)%n+1,y=(q+la)%n;
        printf("%d\n",la=query(dep[x],min(MAXN-1,dep[x]+y),1,MAXN-1,rt[x]));
    }
    return 0;
}