#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=200005;
const db INF=1e20;
db a[MAXN],b[MAXN];
db dp[2][MAXN];
db get_f(db x,int n)
{
    for(int i=1;i<=n;i++)
        b[i]=a[i]-x;
    for(int i=1;i<=n;i++)
    {
        if(dp[0][i-1]>0)
            dp[0][i]=dp[0][i-1]+b[i];
        else
            dp[0][i]=b[i];
        if(dp[1][i-1]<0)
            dp[1][i]=dp[1][i-1]+b[i];
        else
            dp[1][i]=b[i];
    }
    db res=0.0;
    for(int i=1;i<=n;i++)
    {
        res=max(res,fabs(dp[0][i]));
        res=max(res,fabs(dp[1][i]));
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    db Max=-INF,Min=INF;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
        Max=max(Max,a[i]);
        Min=min(Min,a[i]);
    }
    db l=Min,r=Max;
    for(int tt=1;tt<=200;tt++)
    {
        db m1=(2*l+r)/3.0;
        db m2=(l+2*r)/3.0;
        if(get_f(m1,n)>get_f(m2,n))l=m1;
        else r=m2;
    }
    printf("%.12f\n",get_f((l+r)/2.0,n));
    return 0;
}