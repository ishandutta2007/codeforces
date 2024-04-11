#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
vector<int>e[MAXN],vis,spe,siz;
int dfs(int u)
{
    if(vis[u])return 0;
    int now=(vis[u]=1);
    for(int i=0;i<(int)e[u].size();i++)
        now+=dfs(e[u][i]);
    return now;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        int c;
        scanf("%d",&c);
        spe.push_back(c);
    }
    vis.resize(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=0;i<k;i++)
        siz.push_back(dfs(spe[i]));
    sort(siz.begin(),siz.end(),greater<int>());
    int sum=0;
    for(int i=0;i<k;i++)
        sum+=siz[i];
    siz[0]+=n-sum;
    int res=0;
    for(int i=0;i<k;i++)
        res+=siz[i]*(siz[i]-1)/2;
    printf("%d\n",res-m);
    return 0;
}