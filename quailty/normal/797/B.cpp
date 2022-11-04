#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN],dp[MAXN][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            dp[i][j]=max(dp[i][j],dp[i-1][j^(a[i]&1)]+a[i]);
        }
    return 0*printf("%lld\n",dp[n][1]);
}