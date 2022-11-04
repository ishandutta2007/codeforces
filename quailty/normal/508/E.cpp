#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=605;
int p[MAXN],q[MAXN];
int dp[MAXN][MAXN];
void dfs(int l,int r)
{
    if(r==l)dp[l][r]=(p[l]==1);
    if(dp[l][r]>=0)return;
    dp[l][r]=0;
    int d=2*(r-l)+1;
    if(p[l]<=d && d<=q[l])
    {
        dfs(l+1,r);
        dp[l][r]|=dp[l+1][r];
    }
    for(int m=l;m<r;m++)
    {
        dfs(l,m);
        dfs(m+1,r);
        dp[l][r]|=dp[l][m]&dp[m+1][r];
    }
}
char str[MAXN<<1];
void dfs2(int l,int r,int x)
{
    if(r==l)
    {
        str[x]='(';
        str[x+1]=')';
        return;
    }
    int d=2*(r-l)+1;
    if(p[l]<=d && d<=q[l] && dp[l+1][r])
    {
        str[x]='(';
        str[x+d]=')';
        dfs2(l+1,r,x+1);
        return;
    }
    for(int m=l;m<r;m++)
        if(dp[l][m] && dp[m+1][r])
        {
            dfs2(l,m,x);
            dfs2(m+1,r,x+2*(m-l+1));
            break;
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i],&q[i]);
    memset(dp,-1,sizeof(dp));
    dfs(0,n-1);
    if(!dp[0][n-1])printf("IMPOSSIBLE");
    else
    {
        dfs2(0,n-1,0);
        printf("%s",str);
    }
    return 0;
}