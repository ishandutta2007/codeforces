#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int l[MAXN],r[MAXN],c[MAXN<<1];
vector<int>e[MAXN<<1];
void dfs(int u,int d)
{
    c[u]=d;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(c[v])continue;
        dfs(v,3-d);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        e[l[i]].push_back(r[i]);
        e[r[i]].push_back(l[i]);
    }
    for(int i=1;i<=2*n;i+=2)
    {
        e[i].push_back(i+1);
        e[i+1].push_back(i);
    }
    for(int i=1;i<=2*n;i++)
        if(!c[i])dfs(i,1);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",c[l[i]],c[r[i]]);
    return 0;
}