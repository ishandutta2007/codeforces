#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
}p[2505];
db dp[2505][2505][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int len=1;len<=n;len++)
        for(int i=0;i<n;i++)
        {
            int j=(i+len-1)%n;
            if(len==1)dp[i][j][0]=dp[i][j][1]=0;
            else
            {
                dp[i][j][0]=max(dp[(i+1)%n][j][0]+(p[i]-p[(i+1)%n]).len(),dp[(i+1)%n][j][1]+(p[i]-p[j]).len());
                dp[i][j][1]=max(dp[i][(j-1+n)%n][0]+(p[j]-p[i]).len(),dp[i][(j-1+n)%n][1]+(p[j]-p[(j-1+n)%n]).len());
            }
        }
    db res=0;
    for(int i=0;i<n;i++)
        res=max({res,dp[i][(i+n-1)%n][0],dp[i][(i+n-1)%n][1]});
    return 0*printf("%.10f\n",res);
}