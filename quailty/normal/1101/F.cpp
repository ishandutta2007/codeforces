#include<bits/stdc++.h>
using namespace std;
const int MAXN=405;
int a[MAXN],dp[MAXN][MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    ///k=0
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            dp[0][i][j]=a[j]-a[i];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=i,t=i;j<=n;j++)
            {
                while(t<j && max(dp[k-1][i][t],a[j]-a[t])>max(dp[k-1][i][t+1],a[j]-a[t+1]))t++;
                dp[k][i][j]=max(dp[k-1][i][t],a[j]-a[t]);
            }
    long long res=0;
    for(int i=1;i<=m;i++)
    {
        int s,f,c,r;
        scanf("%d%d%d%d",&s,&f,&c,&r);
        res=max(res,1LL*c*dp[r][s][f]);
    }
    printf("%lld\n",res);
    return 0;
}