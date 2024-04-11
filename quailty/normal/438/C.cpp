#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
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
}p[205];
ll dp[205][205];
void dfs(int l,int r)
{
    if(dp[l][r]>=0)return;
    if(l==r-1)
    {
        dp[l][r]=1;
        return;
    }
    dp[l][r]=0;
    for(int i=l+1;i<r;i++)
        if((p[i]-p[l])*(p[l]-p[r])<0)
        {
            dfs(l,i);
            dfs(i,r);
            (dp[l][r]+=dp[l][i]*dp[i][r])%=Mod;
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    ll s=0;
    for(int i=0;i<n;i++)
        s+=p[i]*p[(i+1)%n];
    if(s<0)reverse(p,p+n);
    memset(dp,-1,sizeof(dp));
    dfs(0,n-1);
    printf("%I64d",dp[0][n-1]);
}