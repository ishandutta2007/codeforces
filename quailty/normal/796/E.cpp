#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005],b[1005],dp[2][1005][55][55];
inline void checkMax(int &x,int y)
{
    if(x<y)x=y;
}
int main()
{
    int n,p,l;
    scanf("%d%d%d",&n,&p,&l);
    p=min((n+l-1)/l*2,p);
    int r;
    scanf("%d",&r);
    for(int i=1,t;i<=r;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }
    int s;
    scanf("%d",&s);
    for(int i=1,t;i<=s;i++)
    {
        scanf("%d",&t);
        b[t]=1;
    }
    int now=0,la=1;
    memset(dp[now],0xcf,(p+1)*sizeof(dp[0][0]));
    dp[now][0][0][0]=0;
    for(int _=1;_<=n;_++)
    {
        swap(now,la);
        memset(dp[now],0xcf,(p+1)*sizeof(dp[0][0]));
        for(int i=0;i<=p;i++)
            for(int j=0;j<=l;j++)
                for(int k=0;k<=l;k++)
                {
                    int tj=max(j-1,0),tk=max(k-1,0),ad=((a[_] && tj) || (b[_] && tk));
                    checkMax(dp[now][i][tj][tk],dp[la][i][j][k]+ad);
                    tj=l,tk=max(k-1,0),ad=(a[_] || (b[_] && tk));
                    checkMax(dp[now][i+1][tj][tk],dp[la][i][j][k]+ad);
                    tj=max(j-1,0),tk=l,ad=((a[_] && tj) || b[_]);
                    checkMax(dp[now][i+1][tj][tk],dp[la][i][j][k]+ad);
                    tj=l,tk=l,ad=(a[_] || b[_]);
                    checkMax(dp[now][i+2][tj][tk],dp[la][i][j][k]+ad);
                }
    }
    int res=0;
    for(int i=0;i<=p;i++)
        for(int j=0;j<=l;j++)
            for(int k=0;k<=l;k++)
                res=max(res,dp[now][i][j][k]);
    return 0*printf("%d\n",res);
}