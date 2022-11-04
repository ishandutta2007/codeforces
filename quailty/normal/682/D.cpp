#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1005],t[1005];
int dp[2][1005][1005];
int main()
{
    int n,m,k;
    scanf("%d%d%d%s%s",&n,&m,&k,s+1,t+1);
    int la=0,now=1;
    for(int _=0;_<k;_++)
    {
        swap(la,now);
        memset(dp[now],0,sizeof(dp[now]));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(s[i]==t[j])dp[now][i][j]=max(dp[now][i-1][j-1],dp[la][i-1][j-1])+1;
                else dp[now][i][j]=dp[la][i][j];
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[now][i][j]=max({dp[now][i][j],dp[now][i-1][j],dp[now][i][j-1]});
    }
    return 0*printf("%d",dp[now][n][m]);
}