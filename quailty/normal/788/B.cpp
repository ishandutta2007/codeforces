#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
int vis[MAXN],loop[MAXN];
vector<int>e[MAXN];
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(!vis[v])dfs(v);
    }
}
int main()
{
    int n,m,lp=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==v)loop[u]=1,lp++;
        else
        {
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    for(int i=1;i<=n;i++)
        if(!e[i].empty() || loop[i])
        {
            dfs(i);
            break;
        }
    for(int i=1;i<=n;i++)
        if(!vis[i] && (!e[i].empty() || loop[i]))
            return 0*printf("0");
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int d=(int)e[i].size();
        res+=1LL*d*(d-1)/2;
    }
    res+=1LL*lp*(lp-1)/2;
    res+=1LL*lp*(m-lp);
    return 0*printf("%lld",res);
}