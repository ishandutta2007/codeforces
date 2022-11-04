#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int DEG=20;
vector<pair<int,ll> >e[MAXN];
int fa[MAXN][DEG],sum[MAXN];
ll x[MAXN],len[MAXN][DEG];
void dfs(int u)
{
    for(int i=1;i<DEG;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
        len[u][i]=len[u][i-1]+len[fa[u][i-1]][i-1];
    }
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(v==fa[u][0])continue;
        fa[v][0]=u;
        len[v][0]=e[u][i].second;
        dfs(v);
    }
}
void go(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(v==fa[u][0])continue;
        go(v);
        sum[u]+=sum[v];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&x[i]);
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=2;i<=n;i++)
    {
        int p,w;
        scanf("%d%d",&p,&w);
        e[p].push_back(make_pair(i,w));
    }
    fa[1][0]=0;
    len[1][0]=1000000000000LL;
    dfs(1);
    for(int i=1;i<=n;i++)
        sum[i]=0;
    for(int i=1;i<=n;i++)
    {
        int p=i;
        sum[fa[p][0]]++;
        for(int j=DEG-1;j>=0;j--)
            if(x[i]>=len[p][j])
            {
                x[i]-=len[p][j];
                p=fa[p][j];
            }
        sum[fa[p][0]]--;
    }
    go(1);
    for(int i=1;i<=n;i++)
        printf("%d%s",sum[i],(i<n ? " " : "\n"));
    return 0;
}