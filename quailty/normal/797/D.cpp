#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int in[MAXN],v[MAXN],l[MAXN],r[MAXN],e[MAXN][2];
set<int> ok;
void dfs(int u)
{
    if(v[u]>=l[u] && v[u]<=r[u])ok.insert(v[u]);
    for(int i=0;i<2;i++)
    {
        int t=e[u][i];
        if(t<0)continue;
        if(!i)l[t]=l[u],r[t]=min(r[u],v[u]-1);
        else l[t]=max(l[u],v[u]+1),r[t]=r[u];
        dfs(t);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        for(int j=0;j<2;j++)
        {
            scanf("%d",&e[i][j]);
            if(e[i][j]>0)in[e[i][j]]++;
        }
    }
    int rt=0;
    for(int i=1;i<=n;i++)
        if(!in[i])rt=i;
    assert(rt);
    l[rt]=-INF,r[rt]=INF;
    dfs(rt);
    int res=0;
    for(int i=1;i<=n;i++)
        res+=(ok.find(v[i])==ok.end());
    return 0*printf("%d\n",res);
}