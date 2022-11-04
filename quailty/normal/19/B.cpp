#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
const ll INF=(1LL<<62)-1;
int t[MAXN],c[MAXN];
ll dp[2][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&t[i],&c[i]);
    for(int j=0;j<=n;j++)
        dp[1][j]=(j>0)*INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[0][j]=dp[1][j];
        for(int j=0;j<=n;j++)
        {
            int g=min(n,j+t[i]+1);
            dp[1][g]=min(dp[1][g],dp[0][j]+c[i]);
        }
    }
    return 0*printf("%lld",dp[1][n]);
}