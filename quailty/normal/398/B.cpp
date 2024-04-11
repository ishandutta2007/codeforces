#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef double db;
int n;
set<int>x,y;
db dp[2005][2005];
bool vis[2005][2005];
void dfs(int x,int y)
{
    if(vis[x][y])return;
    vis[x][y]=1;
    db p1=((n-x)*(n-y)+0.0)/(n*n);
    db p2=(x*(n-y)+0.0)/(n*n);
    db p3=((n-x)*y+0.0)/(n*n);
    db p4=(x*y+0.0)/(n*n);
    if(x>0)
    {
        dfs(x-1,y);
        dp[x][y]+=(dp[x-1][y]+1.0)*p2;
    }
    if(y>0)
    {
        dfs(x,y-1);
        dp[x][y]+=(dp[x][y-1]+1.0)*p3;
    }
    if(x>0 && y>0)
    {
        dfs(x-1,y-1);
        dp[x][y]+=(dp[x-1][y-1]+1.0)*p4;
    }
    dp[x][y]+=p1;
    dp[x][y]/=(1-p1);
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int r,c;
        scanf("%d%d",&r,&c);
        x.insert(r);
        y.insert(c);
    }
    dp[0][0]=0.0;
    vis[0][0]=1;
    dfs(n-x.size(),n-y.size());
    printf("%.10f\n",dp[n-x.size()][n-y.size()]);
    return 0;
}