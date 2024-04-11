#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int cnt[505],dp[2][205][1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    int now=0,la=1;
    dp[now][0][0]=1;
    for(int i=1;i<=500;i++)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        for(int j=0;j<=n;j++)
            for(int k=0;k+j<=m;k++)
                dp[now][j][k+j]=(dp[now][j][k+j]+dp[la][j][k])%Mod;
        for(int p=1;p<=cnt[i];p++)
        {
            swap(now,la);
            memset(dp[now],0,sizeof(dp[now]));
            for(int j=0;j<=n;j++)
                for(int k=0;k<=m;k++)
                {
                    if(j<n)dp[now][j+1][k]=(dp[now][j+1][k]+dp[la][j][k])%Mod;
                    dp[now][j][k]=(dp[now][j][k]+1LL*(j+1)*dp[la][j][k])%Mod;
                    if(j>0)dp[now][j-1][k]=(dp[now][j-1][k]+1LL*j*dp[la][j][k])%Mod;
                }
        }
    }
    int res=0;
    for(int k=0;k<=m;k++)
        res=(res+dp[now][0][k])%Mod;
    printf("%d\n",res);
    return 0;
}