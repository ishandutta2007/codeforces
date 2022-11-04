#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int t[MAXN],dp[2][MAXN];
int main()
{
    int a,b,h,w,n;
    scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    sort(t+1,t+n+1,greater<int>());
    int now=0,la=1;
    for(int i=0;i<=n;i++)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        if(i==0)dp[now][h]=w;
        else
        {
            for(int j=0;j<MAXN;j++)
            {
                int tj=min(1LL*MAXN-1,1LL*j*t[i]);
                dp[now][tj]=max(dp[now][tj],dp[la][j]);
                dp[now][j]=max(1LL*dp[now][j],min(1LL*MAXN-1,1LL*dp[la][j]*t[i]));
            }
        }
        for(int j=a;j<MAXN;j++)
            if(dp[now][j]>=b)return 0*printf("%d",i);
        for(int j=b;j<MAXN;j++)
            if(dp[now][j]>=a)return 0*printf("%d",i);
    }
    return 0*printf("-1");
}