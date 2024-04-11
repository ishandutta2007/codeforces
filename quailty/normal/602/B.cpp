#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int a[MAXN];
int dp[2][MAXN][20];
int mm[MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    dp[1][0][0]=INF;
    for(int i=1;i<=n;i++)
    {
        mm[i]=((i&(i-1))==0) ? mm[i-1]+1 : mm[i-1];
        dp[0][i][0]=a[i];
        dp[1][i][0]=a[i];
    }
    for(int j=1;j<=mm[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            dp[0][i][j]=max(dp[0][i][j-1],dp[0][i+(1<<(j-1))][j-1]);
            dp[1][i][j]=min(dp[1][i][j-1],dp[1][i+(1<<(j-1))][j-1]);
        }
}
int check(int x,int y)
{
    int k=mm[y-x+1];
    return max(dp[0][x][k],dp[0][y-(1<<k)+1][k])-min(dp[1][x][k],dp[1][y-(1<<k)+1][k]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    initRMQ(n);
    int res=0,r=1;
    for(int i=1;i<=n;i++)
    {
        while(r<=n && check(i,r)<=1)r++;
        res=max(res,r-i);
    }
    printf("%d\n",res);
    return 0;
}