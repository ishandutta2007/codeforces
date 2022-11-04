#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<62)-1;
ll p[5005],dp[2][5005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&p[i]);
    for(int _=0;_<2;_++)
        for(int j=0;j<=m*k;j++)
            dp[_][j]=-INF;
    int now=1,la=0;
    dp[now][0]=0;
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        for(int j=0;j<=m*k;j++)
            dp[now][j]=-INF;
        for(int j=0;j<=m*k;j++)
        {
            if(j%m==0)dp[now][j]=max(dp[now][j],dp[la][j]);
            if(j>=1)dp[now][j]=max(dp[now][j],dp[la][j-1]+p[i]);
        }
    }
    return 0*printf("%I64d",dp[now][m*k]);
}