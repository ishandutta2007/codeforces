#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
char str[MAXN];
int dp[MAXN][3];
int main()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i][0],dp[i-1][0]+(str[i]=='a'));
        dp[i][1]=max(dp[i][1],dp[i-1][0]+(str[i]=='b'));
        dp[i][1]=max(dp[i][1],dp[i-1][1]+(str[i]=='b'));
        dp[i][2]=max(dp[i][2],dp[i-1][0]+(str[i]=='a'));
        dp[i][2]=max(dp[i][2],dp[i-1][1]+(str[i]=='a'));
        dp[i][2]=max(dp[i][2],dp[i-1][2]+(str[i]=='a'));
    }
    int res=0;
    for(int j=0;j<3;j++)
        res=max(res,dp[n][j]);
    printf("%d\n",res);
    return 0;
}