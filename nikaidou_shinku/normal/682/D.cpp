#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
char s[1005],t[1005];
int dp[2][1005][1005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s%s",s+1,t+1);
    int la=0,now=1;
    for(int _=0;_<2;_++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[_][i][j]=-INF;
    for(int _=0;_<k;_++)
    {
        swap(la,now);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[now][i][j]=-INF;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(i)dp[la][i][j]=max(dp[la][i][j],dp[la][i-1][j]);
                if(j)dp[la][i][j]=max(dp[la][i][j],dp[la][i][j-1]);
            }
        if(_==0)
        {
            for(int i=0;i<=n;i++)dp[now][i][0]=0;
            for(int j=0;j<=m;j++)dp[now][0][j]=0;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(s[i]==t[j])dp[now][i][j]=max(dp[now][i-1][j-1],dp[la][i-1][j-1])+1;
                else dp[now][i][j]=max(0,dp[la][i][j]);
            }
        }
    int res=-INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            res=max(res,dp[now][i][j]);
    printf("%d\n",res);
    return 0;
}