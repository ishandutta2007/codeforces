#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=100005;
int a[MAXN],b[MAXN],l[MAXN],cnt[MAXN],dep[MAXN];
vector<int>e[MAXN];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+(cnt[u]=1);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&l[i]);
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    dfs(1,0);
    db res=0;
    for(int i=1;i<n;i++)
    {
        if(dep[a[i]]<dep[b[i]])swap(a[i],b[i]);
        res+=6.0*l[i]*cnt[a[i]]/(n-1)*(n-cnt[a[i]])/n;
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int r,w;
        scanf("%d%d",&r,&w);
        res-=6.0*l[r]*cnt[a[r]]/(n-1)*(n-cnt[a[r]])/n;
        l[r]=w;
        res+=6.0*l[r]*cnt[a[r]]/(n-1)*(n-cnt[a[r]])/n;
        printf("%.10f\n",res);
    }
    return 0;
}