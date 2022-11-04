#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
int dp[MAXN];
int solve()
{
    int res=0;
    for(int i=1;i<=1000000;i++)
    {
        for(int j=2*i;j<=1000000;j+=i)
            if(dp[j]>0)dp[j]=max(dp[j],dp[i]+1);
        res=max(res,dp[i]);
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    int in;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&in);
        dp[in]=1;
    }
    printf("%d\n",solve());
    return 0;
}