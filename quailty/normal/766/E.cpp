#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int a[MAXN],p[MAXN];
ll cnt[MAXN][20][2],res[MAXN][20];
vector<int>e[MAXN];
void dfs(int u,int fa)
{
    p[u]=p[fa]^a[u];
    for(int i=0;i<20;i++)
        res[u][i]+=(a[u]>>i&1),cnt[u][i][p[u]>>i&1]++;
    for(int _=0;_<(int)e[u].size();_++)
    {
        int v=e[u][_];
        if(v==fa)continue;
        dfs(v,u);
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<2;j++)
                res[u][i]+=cnt[u][i][j]*cnt[v][i][j^1^(a[u]>>i&1)];
            for(int j=0;j<2;j++)
                cnt[u][i][j]+=cnt[v][i][j];
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    ll sum=0;
    for(int u=1;u<=n;u++)
        for(int i=0;i<20;i++)
            sum+=(res[u][i]<<i);
    return 0*printf("%lld",sum);
}