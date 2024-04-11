#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=505;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
}r[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d%I64d",&r[i].x,&r[i].y);
    for(int i=1;i<=m;i++)
        scanf("%I64d%I64d",&b[i].x,&b[i].y);
    Point o=Point(-1000000001,-1000000001);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if((r[i]-o)*(r[j]-o)<=0)continue;
            for(int k=1;k<=m;k++)
                if((r[i]-o)*(b[k]-o)>0
                && (r[j]-r[i])*(b[k]-r[i])>0
                && (o-r[j])*(b[k]-r[j])>=0)
                    dp[i][j]++;
            dp[j][i]=-dp[i][j];
        }
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                res+=(dp[i][j]+dp[j][k]+dp[k][i]==0);
    return 0*printf("%d",res);
}