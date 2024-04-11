#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int fwd[MAXN],ind[MAXN],vis[MAXN],pre[MAXN];
int tot,cir[MAXN],ker[MAXN],lef[MAXN],usd[MAXN];
void dfs(int u,int la)
{
    if(vis[u])
    {
        if(!cir[u])
        {
            ker[++tot]=u;
            cir[u]=tot;
        }
        return;
    }
    pre[u]=la;
    vis[u]=1;
    dfs(fwd[u],u);
    cir[u]=cir[fwd[u]];
}
int cnt,reu[MAXN],rev[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&fwd[i]);
        ind[fwd[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i,0);
    for(int i=1;i<=n;i++)
        if(!ind[i])lef[cir[i]]=i;
    for(int i=1;i<=tot;i++)
    {
        if(!lef[i])lef[i]=ker[i];
        else usd[lef[i]]=1;
    }
    for(int i=1,j=2;i<=tot;i++,j++)
    {
        if(j>tot)j=1;
        if(ker[i]!=lef[j])
        {
            cnt++;
            reu[cnt]=ker[i];
            rev[cnt]=lef[j];
        }
    }
    for(int i=1;i<=n;i++)
        if(!ind[i] && !usd[i])
        {
            cnt++;
            reu[cnt]=ker[1];
            rev[cnt]=i;
        }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
        printf("%d %d\n",reu[i],rev[i]);
    return 0;
}