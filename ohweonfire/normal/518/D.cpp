#include <cstdio>
#include <algorithm>
using namespace std;
int n,t;
double p,dp[2005][2005];
double pow(double x,int y)
{
    double ret=1.0;
    while(y)
    {
        if(y&1)
            ret*=x;
        x*=x;
        y>>=1;
    }
    return ret;
}
int main()
{
    scanf("%d%lf%d",&n,&p,&t);
    double ans=0.0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=t;j++)
            dp[i][j]=p*min(n*1.0,(dp[i-1][j-1]+1))+(1-p)*dp[i][j-1];
    printf("%.8lf\n",dp[n][t]);
    return 0;
}