#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=2005;
const db INF=1e9;
db p[MAXN],u[MAXN],dp[2][MAXN];
int num[2][MAXN];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%lf",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%lf",&u[i]);
    db l=0,r=4000;
    for(int _=0;_<50;_++)
    {
        db m=(l+r)/2;
        for(int j=0;j<=a;j++)
            dp[1][j]=-INF*(j>0),num[1][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=a;j++)
                dp[0][j]=dp[1][j],num[0][j]=num[1][j];
            for(int j=0;j<=a;j++)
            {
                if(dp[1][j]<dp[0][j]+u[i]-m)
                    dp[1][j]=dp[0][j]+u[i]-m,num[1][j]=num[0][j]+1;
                if(j>0 && dp[1][j]<dp[0][j-1]+p[i])
                    dp[1][j]=dp[0][j-1]+p[i],num[1][j]=num[0][j-1];
                if(j>0 && dp[1][j]<dp[0][j-1]+(p[i]+u[i]-p[i]*u[i])-m)
                    dp[1][j]=dp[0][j-1]+(p[i]+u[i]-p[i]*u[i])-m,num[1][j]=num[0][j-1]+1;
            }
        }
        if(num[1][a]<b)r=m;
        else l=m;
    }
    return 0*printf("%.12f",dp[1][a]+(l+r)/2*b);
}