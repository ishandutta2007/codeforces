#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15;
const int SZ=1024;
int dp[MAXN][MAXN];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    t*=SZ;
    dp[1][1]=t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(dp[i][j]>SZ)
            {
                int tmp=dp[i][j]-SZ;
                dp[i+1][j]+=tmp/2;
                dp[i+1][j+1]+=tmp/2;
                dp[i][j]=SZ;
            }
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            res+=(dp[i][j]==SZ);
    printf("%d\n",res);
    return 0;
}