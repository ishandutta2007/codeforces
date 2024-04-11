#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int u[MAXN],v[MAXN],b[MAXN],c[MAXN];
vector<int>e[MAXN];
bool dfs(int u,int fa)
{
    if(c[u]!=c[fa])return 0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(b[v] || v==fa)continue;
        if(!dfs(v,u))return 0;
    }
    return 1;
}
bool check(int u)
{
    b[u]=1;
    bool isok=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        isok&=dfs(v,v);
    }
    b[u]=0;
    return isok;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        e[u[i]].push_back(v[i]);
        e[v[i]].push_back(u[i]);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n-1;i++)
        if(c[u[i]]!=c[v[i]])
        {
            if(check(u[i]))return 0*printf("YES\n%d",u[i]);
            if(check(v[i]))return 0*printf("YES\n%d",v[i]);
            return 0*printf("NO");
        }
    return 0*printf("YES\n1");
}