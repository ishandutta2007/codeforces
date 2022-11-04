#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll Mod=1000000007LL;
ll a[MAXN],d[MAXN],add[MAXN];
vector<int>e[MAXN];
int fa[MAXN];
struct query
{
    int ty,u;
}t[MAXN];
int t_tag,in[MAXN],out[MAXN];
void dfs(int u)
{
    in[u]=++t_tag;
    for(int i=0;i<(int)e[u].size();i++)
        dfs(e[u][i]);
    out[u]=t_tag;
}
ll fp(ll a,ll k)
{
    ll res=1LL;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
struct node
{
    int l,r,m;
    ll v[2],lazy;
}s[MAXN<<2];
void push_up(int n)
{
    for(int i=0;i<2;i++)
        s[n].v[i]=(s[n<<1].v[i]+s[n<<1|1].v[i])%Mod;
}
void push_down(int n)
{
    if(s[n].lazy==1)return;
    for(int i=0;i<2;i++)
        s[n<<1].v[i]=s[n<<1].v[i]*s[n].lazy%Mod;
    s[n<<1].lazy=s[n<<1].lazy*s[n].lazy%Mod;
    for(int i=0;i<2;i++)
        s[n<<1|1].v[i]=s[n<<1|1].v[i]*s[n].lazy%Mod;
    s[n<<1|1].lazy=s[n<<1|1].lazy*s[n].lazy%Mod;
    s[n].lazy=1;
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    s[n].lazy=1;
    if(r-l==1)
    {
        s[n].v[0]=1;
        s[n].v[1]=0;
        return;
    }
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    push_up(n);
}
void update(int l,int r,ll v,int n,int ty)
{
    if(s[n].l==l && s[n].r==r)
    {
        if(ty==0)
        {
            s[n].v[0]=s[n].v[0]*v%Mod;
            s[n].v[1]=s[n].v[1]*v%Mod;
            s[n].lazy=s[n].lazy*v%Mod;
        }
        else
        {
            s[n].v[1]=(s[n].v[1]+v*s[n].v[0])%Mod;
        }
        return;
    }
    push_down(n);
    if(r<=s[n].m)update(l,r,v,n<<1,ty);
    else if(l>=s[n].m)update(l,r,v,n<<1|1,ty);
    else
    {
        update(l,s[n].m,v,n<<1,ty);
        update(s[n].m,r,v,n<<1|1,ty);
    }
    push_up(n);
}
ll query(int l,int r,int n,int ty)
{
    if(s[n].l==l && s[n].r==r)return s[n].v[ty];
    push_down(n);
    if(r<=s[n].m)return query(l,r,n<<1,ty);
    if(l>=s[n].m)return query(l,r,n<<1|1,ty);
    return (query(l,s[n].m,n<<1,ty)+query(s[n].m,r,n<<1|1,ty))%Mod;
}
int main()
{
    int q;
    scanf("%I64d%d",&a[1],&q);
    int n=1;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&t[i].ty,&t[i].u);
        if(t[i].ty==1)
        {
            add[i]=++n;
            fa[n]=t[i].u;
            e[t[i].u].push_back(n);
            scanf("%I64d",&a[n]);
        }
    }
    dfs(1);
    build(1,n+1,1);
    update(in[1],in[1]+1,a[1],1,1);
    for(int i=0;i<q;i++)
    {
        if(t[i].ty==1)
        {
            d[t[i].u]++;
            update(in[t[i].u],out[t[i].u]+1,fp(d[t[i].u],Mod-2),1,0);
            update(in[t[i].u],out[t[i].u]+1,d[t[i].u]+1,1,0);
            update(in[add[i]],in[add[i]]+1,a[add[i]],1,1);
        }
        else
        {
            ll tt=(fa[t[i].u] ? query(in[fa[t[i].u]],in[fa[t[i].u]]+1,1,0) : 1);
            ll res=query(in[t[i].u],out[t[i].u]+1,1,1);
            printf("%I64d\n",res*fp(tt,Mod-2)%Mod);
        }
    }
    return 0;
}