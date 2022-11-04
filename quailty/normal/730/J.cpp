#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int INF=0x3f3f3f3f;
int a[MAXN],b[MAXN];
pair<int,int> dp[MAXN][MAXN*MAXN];
pair<int,int> operator + (const pair<int,int> &a,const pair<int,int> &b)
{
    return make_pair(a.first+b.first,a.second+b.second);
}
int main()
{
    int n,s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),s+=a[i];
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n*100;j++)
            dp[i][j]=make_pair(INF,INF);
    dp[0][0]=make_pair(0,0);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n*100;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=b[i])dp[i][j]=min(dp[i][j],dp[i-1][j-b[i]]+make_pair(1,-a[i]));
        }
    pair<int,int> res=make_pair(INF,INF);
    for(int j=s;j<=n*100;j++)
        res=min(res,dp[n][j]);
    return 0*printf("%d %d\n",res.first,s+res.second);
}