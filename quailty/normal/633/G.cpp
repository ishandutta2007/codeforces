#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
const int MAXN=100005;
const int MAXM=1005;
vector<int>e[MAXN];
int m,a[MAXN],v[MAXN],in[MAXN],out[MAXN];
void dfs(int u,int fa,int &t)
{
    v[in[u]=++t]=a[u]%m;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u,t);
    }
    out[u]=t;
}
bitset<MAXM>all,pri;
bool is_prime(int x)
{
    if(x<2)return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
struct node
{
    int l,r,m,lz;
    bitset<MAXM>v;
}s[MAXN<<2];
void push_up(int n)
{
    s[n].v=s[n<<1].v|s[n<<1|1].v;
}
void modify(int n,int v)
{
    s[n].v=((s[n].v<<v)|(s[n].v>>(m-v)))&all;
    s[n].lz=(s[n].lz+v)%m;
}
void push_down(int n)
{
    if(!s[n].lz)return;
    modify(n<<1,s[n].lz);
    modify(n<<1|1,s[n].lz);
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
        s[n].v[v[l]]=1;
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
        modify(n,v);
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
bitset<MAXM> query(int l,int r,int n)
{
    if(s[n].l==l && s[n].r==r)return s[n].v;
    push_down(n);
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return query(l,s[n].m,n<<1)|query(s[n].m,r,n<<1|1);
}
int main()
{
    int n;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        all[i]=1;
        pri[i]=is_prime(i);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int t=0;
    dfs(1,0,t);
    build(1,n+1,1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int ty,v;
        scanf("%d%d",&ty,&v);
        if(ty==1)
        {
            int x;
            scanf("%d",&x);
            update(in[v],out[v]+1,x%m,1);
        }
        else printf("%d\n",(query(in[v],out[v]+1,1)&pri).count());
    }
    return 0;
}