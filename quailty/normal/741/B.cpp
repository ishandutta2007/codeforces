#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
vector<int>e[MAXN];
int vis[MAXN],w[MAXN],b[MAXN];
int tmp[MAXN][MAXN],dp[MAXN];
vector<int>cw,cb;
void dfs(int u,int &tw,int &tb)
{
    vis[u]=1,tw+=w[u],tb+=b[u];
    cw.push_back(w[u]),cb.push_back(b[u]);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(vis[v])continue;
        dfs(v,tw,tb);
    }
}
int main()
{
    int n,m,c;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        cw.clear(),cb.clear();
        int tw=0,tb=0;
        dfs(i,tw,tb);
        cw.push_back(tw),cb.push_back(tb);
        for(int i=0;i<(int)cw.size();i++)
        {
            for(int j=0;j<=c;j++)
                tmp[i][j]=dp[j];
            for(int j=cw[i];j<=c;j++)
                tmp[i][j]=max(tmp[i][j],dp[j-cw[i]]+cb[i]);
        }
        for(int i=0;i<(int)cw.size();i++)
            for(int j=0;j<=c;j++)
                dp[j]=max(dp[j],tmp[i][j]);
    }
    return 0*printf("%d\n",dp[c]);
}