#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
const int Mod=1000000007;
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
    if(x<0)x+=Mod;
}
int dp[2][MAXN];
int main()
{
    int r,g;
    scanf("%d%d",&r,&g);
    int h=0;
    while(h*(h+1)/2<=r+g)h++;
    h--;
    int now=1,la=0;
    memset(dp,0,sizeof(dp));
    dp[now][0]=1;
    for(int i=1;i<=h;i++)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        for(int j=0;j<=min(i*(i-1)/2,r);j++)
        {
            if(j+i<=r)add(dp[now][j+i],dp[la][j]);
            if(i*(i-1)/2-j+i<=g)add(dp[now][j],dp[la][j]);
        }
    }
    int res=0;
    for(int i=0;i<=r;i++)
        add(res,dp[now][i]);
    printf("%d\n",res);
    return 0;
}