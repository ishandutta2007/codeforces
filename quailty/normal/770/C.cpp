#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int color[MAXN],cycle;
vector<int>ord,e[MAXN];
void dfs(int u)
{
    if(color[u]==0)
    {
        color[u]=1;
        for(int i=0;i<(int)e[u].size();i++)
            dfs(e[u][i]);
        color[u]=2;
        ord.push_back(u);
    }
    else if(color[u]==1)
        cycle=1;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int>key(k);
    for(int i=0;i<k;i++)
        scanf("%d",&key[i]);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        e[i].resize(t);
        for(int j=0;j<t;j++)
            scanf("%d",&e[i][j]);
    }
    for(int i=0;i<k;i++)
        dfs(key[i]);
    if(cycle)printf("-1\n");
    else
    {
        printf("%d\n",(int)ord.size());
        for(int i=0;i<(int)ord.size();i++)
            printf("%d ",ord[i]);
    }
    return 0;
}