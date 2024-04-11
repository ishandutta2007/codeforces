#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
db dp[2005][2005];
bool vis[2005][2005];
int main()
{
    int n,t;
    db p;
    scanf("%d%lf%d",&n,&p,&t);
    dp[0][0]=1.0;
    for(int i=1;i<=t;i++)
    {
        dp[i][0]=(1-p)*dp[i-1][0];
        for(int j=1;j<n;j++)
        {
            dp[i][j]=p*dp[i-1][j-1]+(1-p)*dp[i-1][j];
        }
        dp[i][n]=p*dp[i-1][n-1]+dp[i-1][n];
    }
    db res=0.0;
    for(int i=0;i<=n;i++)
    {
        res+=i*dp[t][i];
    }
    printf("%.8f\n",res);
    return 0;
}