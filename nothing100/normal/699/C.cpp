#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#define mo 1000000007
using namespace std;
int n,a[100],dp[100][3],ans;
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    dp[0][0]=1;
    dp[0][1]=mo;
    dp[0][2]=mo;
    if (a[0]==1) dp[0][2]=0;
    else if (a[0]==2) dp[0][1]=0;
    else if (a[0]==3)
    {
        dp[0][2]=0;
        dp[0][1]=0;
    }
    for (int i=1;i<n;i++)
    {
        dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
        dp[i][0]=min(dp[i][0],dp[i-1][2])+1;
        dp[i][1]=mo;
        dp[i][2]=mo;
        if (a[i]==1) dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
        else if (a[i]==2) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        else if (a[i]==3)
        {
            dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }
    }
    ans=min(dp[n-1][0],dp[n-1][1]);
    ans=min(ans,dp[n-1][2]);
    printf("%d",ans);
    return 0;
}