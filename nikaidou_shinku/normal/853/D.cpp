#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300005;
const int MAXT=105;
const int INF=0x3f3f3f3f;
inline void check_min(int &x,int y)
{
    x=(x<y ? x : y);
}
int dp[2][MAXT];
int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,INF,sizeof(dp));
    int now=0,la=1;
    dp[now][0]=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        a/=100;
        swap(now,la);
        memset(dp[now],INF,sizeof(dp[now]));
        for(int j=0;j<MAXT;j++)
        {
            if(j>=a)check_min(dp[now][j-a],dp[la][j]);
            else check_min(dp[now][0],dp[la][j]+(a-j)*100);
            check_min(dp[now][min(j+a/10,MAXT-1)],dp[la][j]+a*100);
        }
    }
    int res=INF;
    for(int i=0;i<MAXT;i++)
        res=min(res,dp[now][i]);
    printf("%d\n",res);
    return 0;
}