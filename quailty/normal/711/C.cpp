#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<60)-1;
ll c[105],p[105][105],dp[2][105][105];
inline void checkMin(ll &x,ll y)
{
    if(x>y)x=y;
}
int main()
{
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&c[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%I64d",&p[i][j]);
    int now=0,la=1;
    memset(dp[now],0x3f,sizeof(dp[now]));
    dp[now][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        memset(dp[now],0x3f,sizeof(dp[now]));
        for(int j=0;j<=n;j++)
            for(int k=0;k<=m;k++)
            {
                if(c[i])checkMin(dp[now][j+(c[i]!=k)][c[i]],dp[la][j][k]);
                else for(int l=1;l<=m;l++)
                    checkMin(dp[now][j+(l!=k)][l],dp[la][j][k]+p[i][l]);
            }
    }
    ll res=INF;
    for(int k=0;k<=m;k++)
        checkMin(res,dp[now][r][k]);
    printf("%I64d\n",(res<INF ? res : -1));
    return 0;
}