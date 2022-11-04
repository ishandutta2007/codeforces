#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
const int Mod=1000000007;
int a[MAXN];
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
vector<int>r;
int vis[MAXN],dep[MAXN],time_tag;
void dfs(int u,int la,int pre,int d)
{
    if(vis[u])
    {
        if(vis[pre]>vis[u])r.push_back(d-dep[u]);
        return;
    }
    vis[u]=++time_tag;
    dep[u]=d;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(i!=(la^1))dfs(v,i,u,d+1);
    }
}
int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==a[i])r.push_back(1);
        else addedge(i,a[i]),addedge(a[i],i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i,-1,0,0);
    int res=1,sum=n;
    for(int i=0;i<(int)r.size();i++)
    {
        res=1LL*res*(fp(2,r[i])-2+Mod)%Mod;
        sum-=r[i];
    }
    res=1LL*res*fp(2,sum)%Mod;
    return 0*printf("%d\n",res);
}