#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=400005;
int c[MAXN];
struct Edge
{
    int to,nxt;
}edge[MAXN<<1];
int head[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
int time_tag,in[MAXN],out[MAXN],p[MAXN];
void dfs(int u,int fa)
{
    in[u]=++time_tag;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
    }
    out[u]=time_tag;
}
struct node
{
    int l,r,m;
    ll v,lz;
}s[MAXN<<2];
void push_up(int n)
{
    s[n].v=(s[n<<1].v|s[n<<1|1].v);
}
void push_down(int n)
{
    if(!s[n].lz)return;
    s[n<<1].v=s[n<<1].lz=s[n].lz;
    s[n<<1|1].v=s[n<<1|1].lz=s[n].lz;
    s[n].lz=0;
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    s[n].lz=0;
    if(r-l==1)
    {
        s[n].v=(1LL<<c[p[l]]);
        return;
    }
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    push_up(n);
}
void update(int l,int r,int v,int n)
{
    if(s[n].l==l && s[n].r==r)
    {
        s[n].v=s[n].lz=(1LL<<v);
        return;
    }
    push_down(n);
    if(r<=s[n].m)update(l,r,v,n<<1);
    else if(l>=s[n].m)update(l,r,v,n<<1|1);
    else
    {
        update(l,s[n].m,v,n<<1);
        update(s[n].m,r,v,n<<1|1);
    }
    push_up(n);
}
ll query(int l,int r,int n)
{
    if(s[n].l==l && s[n].r==r)return s[n].v;
    push_down(n);
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return query(l,s[n].m,n<<1)|query(s[n].m,r,n<<1|1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        --c[i];
    }
    init();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    time_tag=0;
    dfs(1,0);
    for(int i=1;i<=n;i++)
        p[in[i]]=i;
    build(1,n+1,1);
    while(m--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int v,c;
            scanf("%d%d",&v,&c);
            --c;
            update(in[v],out[v]+1,c,1);
        }
        else
        {
            int v;
            scanf("%d",&v);
            ll t=query(in[v],out[v]+1,1);
            int res=0;
            for(int i=0;i<60;i++)
                if(t&(1LL<<i))res++;
            printf("%d\n",res);
        }
    }
    return 0;
}