#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
inline void update(int &x,int y)
{
    (x<y) && (x=y);
}
int dp[2][65][3];
int main()
{
    int n,now=0,la=1;
    scanf("%d",&n);
    for(int j=-30;j<=30;j++)
        for(int k=0;k<3;k++)
            dp[now][j+30][k]=-INF;
    dp[now][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        for(int j=-30;j<=30;j++)
            for(int k=0;k<3;k++)
                dp[now][j+30][k]=-INF;
        int a;
        scanf("%d",&a);
        for(int j=-30;j<=30;j++)
        {
            update(dp[now][j+30][0],dp[la][j+30][0]);
            update(dp[now][max(j,a)+30][1],dp[la][j+30][0]+a);
            update(dp[now][max(j,a)+30][1],dp[la][j+30][1]+a);
            update(dp[now][j+30][2],dp[la][j+30][1]);
            update(dp[now][j+30][2],dp[la][j+30][2]);
        }
    }
    int res=-INF;
    for(int j=-30;j<=30;j++)
        for(int k=1;k<3;k++)
            res=max(res,dp[now][j+30][k]-j);
    return 0*printf("%d\n",res);
}