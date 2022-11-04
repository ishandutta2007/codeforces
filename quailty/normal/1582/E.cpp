#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXK=505;
ll a[MAXN],pre[MAXN],dp[MAXN][MAXK];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),pre[i]=pre[i-1]+a[i];
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<MAXK;j++)
            dp[i][j]=0;
    for(int i=n;i>=1;i--)
        dp[i][1]=max(dp[i+1][1],a[i]);
    for(int j=2;j<MAXK;j++)
        for(int i=n;i>=1;i--)
        {
            dp[i][j]=dp[i+1][j];
            if(i+j<=n && dp[i+j][j-1]>pre[i+j-1]-pre[i-1])
                dp[i][j]=max(dp[i][j],pre[i+j-1]-pre[i-1]);
        }
    int res=0;
    for(int j=1;j<MAXK;j++)
        if(dp[1][j])res=j;
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}