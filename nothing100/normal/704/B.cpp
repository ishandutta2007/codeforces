#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#define mo 1000000007
#define eps 1e-8
using namespace std;
long long dp[5100][5100];
int n,s,e,dan,x[5100],a[5100],b[5100],c[5100],d[5100],now,la;
int main()
{
    scanf("%d%d%d",&n,&s,&e);
    s--;
    e--;
    for (int i=0;i<n;i++) scanf("%d",&x[i]);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) scanf("%d",&c[i]);
    for (int i=0;i<n;i++) scanf("%d",&d[i]);
    for (int i=0;i<n;i++)
    for (int j=0;j<=n;j++) dp[i][j]=5000000000000000000;
    if (!s)
    {
        dp[0][0]=d[0];
        dan=1;
    }
    else if (!e)
    {
        dp[0][0]=b[0];
        dan=2;
    }
    else dp[0][1]=d[0]+b[0];
    for (int i=1;i<n;i++)
    if (i==s)
    {
        for (int j=0;j<=i;j++)
        {
            long long tmp=j*2+(dan!=0);
            if (tmp==0) continue;
            if (dan==2)
            {
                dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+tmp*(x[i]-x[i-1])+d[i]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+tmp*(x[i]-x[i-1])+c[i]);
            }
            else if (dan==0)
            {
                if (j) dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]+tmp*(x[i]-x[i-1])+c[i]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+tmp*(x[i]-x[i-1])+d[i]);
            }
        }
        if (dan==2) dan=0;
        else dan=1;
    }
    else if (i==e)
    {
        for (int j=0;j<=i;j++)
        {
            long long tmp=j*2+(dan!=0);
            if (tmp==0) continue;
            if (dan==1)
            {
                dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+tmp*(x[i]-x[i-1])+b[i]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+tmp*(x[i]-x[i-1])+a[i]);
            }
            else if (dan==0)
            {
                if (j) dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]+tmp*(x[i]-x[i-1])+a[i]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+tmp*(x[i]-x[i-1])+b[i]);
            }
        }
        if (dan==1) dan=0;
        else dan=2;
    }
    else
    {
        for (int j=0;j<=i;j++)
        {
            long long tmp=j*2+(dan!=0);
            if (tmp==0) continue;
            dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+b[i]+d[i]+tmp*(x[i]-x[i-1]));
            if (j) dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]+tmp*(x[i]-x[i-1])+a[i]+c[i]);
            if ((j)||(dan==1)) dp[i][j]=min(dp[i][j],dp[i-1][j]+tmp*(x[i]-x[i-1])+a[i]+d[i]);
            if ((j)||(dan==2)) dp[i][j]=min(dp[i][j],dp[i-1][j]+tmp*(x[i]-x[i-1])+c[i]+b[i]);
        }
    }
    //for (int i=0;i<n;i++)
    //for (int j=0;j<=i+1;j++)
    //printf("%d %d %I64d\n",i,j,dp[i][j]);
    printf("%I64d",dp[n-1][0]);
    return 0;
}