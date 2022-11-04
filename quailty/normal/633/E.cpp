#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long double ldb;
const int MAXN = 1000005;
int v[MAXN],c[MAXN],mm[MAXN];
int rv[MAXN][21],rc[MAXN][21];
void initRMQ(int n,int b[],int dp[][21])
{
    mm[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        mm[i] = ((i&(i-1)) == 0) ? mm[i-1]+1 : mm[i-1];
        dp[i][0] = b[i];
    }
    for(int j = 1; j <= mm[n]; j++)
        for(int i = 1; i + (1<<j) -1 <= n; i++)
            dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int x,int y,int dp[][21])
{
    int k = mm[y-x+1];
    return max(dp[x][k],dp[y-(1<<k)+1][k]);
}
int p[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        c[i]=-c[i];
    }
    initRMQ(n,v,rv);
    initRMQ(n,c,rc);
    for(int l=n,r=n;l>=1;l--)
    {
        while(r>l && min(100*rmq(l,r-1,rv),-rmq(l,r-1,rc))>=min(100*rmq(l,r,rv),-rmq(l,r,rc)))r--;
        p[l]=min(100*rmq(l,r,rv),-rmq(l,r,rc));
    }
    sort(p+1,p+n+1,greater<int>());
    ldb res=0,buf=1.0*k/n;
    for(int i=n;i>=k;i--)
    {
        res+=p[i]*buf;
        buf*=1.0*(i-k)/(i-1);
    }
    printf("%.12f\n",(double)res);
    return 0;
}