#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int INF=0x3f3f3f3f;
int a[MAXN],dp[2][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,INF,sizeof(dp));
    int now=0,la=1;
    dp[now][0]=0;
    for(int i=1;i<=n+1;i++)
    {
        swap(now,la);
        memset(dp[now],INF,sizeof(dp[now]));
        for(int j=0;j<=n;j++)
        {
            int k=min(j,a[i]);
            dp[now][k]=min(dp[now][k],dp[la][j]+1);
            if(a[i]<=n)dp[now][a[i]]=min(dp[now][a[i]],dp[la][j]+max(0,a[i]-j));
        }
    }
    printf("%d\n",dp[now][0]);
    return 0;
}