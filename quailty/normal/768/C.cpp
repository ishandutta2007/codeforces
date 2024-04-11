#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[2][1<<10];
int main()
{
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    int now=0,la=1;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        dp[now][a]++;
    }
    while(k--)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        int sum=0;
        for(int i=0;i<=1023;i++)
        {
            dp[now][i]+=(dp[la][i]+sum%2)/2;
            dp[now][i^x]+=(dp[la][i]+1-sum%2)/2;
            sum+=dp[la][i];
        }
    }
    for(int i=1023;i>=0;i--)
        if(dp[now][i])
        {
            printf("%d ",i);
            break;
        }
    for(int i=0;i<=1023;i++)
        if(dp[now][i])
        {
            printf("%d\n",i);
            break;
        }
    return 0;
}