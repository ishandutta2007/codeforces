#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int dp[3][1005],a[26];
char s[1005];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    for(int i=0;i<26;i++)
        scanf("%d",&a[i]);
    memset(dp[0],0,sizeof(dp[0]));
    memset(dp[1],0xc0,sizeof(dp[1]));
    memset(dp[2],0x3f,sizeof(dp[2]));
    dp[0][0]=1,dp[1][0]=dp[2][0]=0;
    for(int i=1;i<=n;i++)
    {
        int len=i;
        for(int j=i;j>=1;j--)
        {
            len=min(len,a[s[j]-'a']);
            if(i-j+1>len)break;
            dp[0][i]=(dp[0][i]+dp[0][j-1])%Mod;
            dp[1][i]=max(dp[1][i],max(dp[1][j-1],i-j+1));
            dp[2][i]=min(dp[2][i],dp[2][j-1]+1);
        }
    }
    for(int i=0;i<3;i++)
        printf("%d\n",dp[i][n]);
    return 0;
}