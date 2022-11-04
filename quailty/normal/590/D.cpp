#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=155;
const int INF=0x3f3f3f3f;
int a[MAXN],dp[2][MAXN][MAXN/2*MAXN];
int main()
{
    int n,k,s;
    scanf("%d%d%d",&n,&k,&s);
    s=min(s,n*(n-1)/2);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int _=0;_<2;_++)
        for(int i=0;i<=k;i++)
            for(int j=0;j<=s;j++)
                dp[_][i][j]=INF;
    int now=0,la=1;
    dp[now][0][0]=0;
    for(int _=1;_<=n;_++)
    {
        swap(now,la);
        for(int i=0;i<=k;i++)
            for(int j=0;j<=s;j++)
                dp[now][i][j]=INF;
        for(int i=0;i<=min(_,k);i++)
        {
            for(int j=0;j<=s;j++)
                dp[now][i][j]=min(dp[now][i][j],dp[la][i][j]);
            if(i<min(_,k))for(int j=0;j+_-i-1<=s;j++)
                dp[now][i+1][j+_-i-1]=min(dp[now][i+1][j+_-i-1],dp[la][i][j]+a[_]);
        }
    }
    int res=INF;
    for(int j=0;j<=s;j++)
        res=min(res,dp[now][k][j]);
    return 0*printf("%d",res);
}