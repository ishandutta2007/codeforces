#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int INF=0x3f3f3f3f;
int c[MAXN],dp[MAXN][MAXN];
void dfs(int l,int r)
{
    if(dp[l][r]<INF)return;
    if(r<=l)
    {
        dp[l][r]=1;
        return;
    }
    int tl=l,tr=r;
    while(tl<tr && c[tl]==c[tr])
    {
        tl++,tr--;
        dfs(tl,tr);
        dp[l][r]=min(dp[l][r],dp[tl][tr]);
    }
    for(int k=l;k<r;k++)
    {
        dfs(l,k);
        dfs(k+1,r);
        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    memset(dp,INF,sizeof(dp));
    dfs(1,n);
    printf("%d\n",dp[1][n]);
    return 0;
}