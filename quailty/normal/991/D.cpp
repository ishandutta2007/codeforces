#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char str[2][MAXN];
int dp[MAXN][4];
int main()
{
    scanf("%s%s",str[0]+1,str[1]+1);
    int n=strlen(str[0]+1);
    memset(dp,0xc0,sizeof(dp));
    dp[0][3]=0;
    for(int i=1;i<=n;i++)
    {
        if(str[0][i]=='0')
        {
            if(str[1][i]=='0')
            {
                dp[i][0]=max(dp[i][0],dp[i-1][0]);
                dp[i][0]=max(dp[i][0],dp[i-1][1]);
                dp[i][0]=max(dp[i][0],dp[i-1][2]);
                dp[i][0]=max(dp[i][0],dp[i-1][3]);
                dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
                dp[i][2]=max(dp[i][2],dp[i-1][0]+1);
                dp[i][3]=max(dp[i][3],dp[i-1][0]+1);
                dp[i][3]=max(dp[i][3],dp[i-1][1]+1);
                dp[i][3]=max(dp[i][3],dp[i-1][2]+1);
            }
            else
            {
                dp[i][2]=max(dp[i][2],dp[i-1][0]);
                dp[i][2]=max(dp[i][2],dp[i-1][1]);
                dp[i][2]=max(dp[i][2],dp[i-1][2]);
                dp[i][2]=max(dp[i][2],dp[i-1][3]);
                dp[i][3]=max(dp[i][3],dp[i-1][0]+1);
            }
        }
        else
        {
            if(str[1][i]=='0')
            {
                dp[i][1]=max(dp[i][1],dp[i-1][0]);
                dp[i][1]=max(dp[i][1],dp[i-1][1]);
                dp[i][1]=max(dp[i][1],dp[i-1][2]);
                dp[i][1]=max(dp[i][1],dp[i-1][3]);
                dp[i][3]=max(dp[i][3],dp[i-1][0]+1);
            }
            else
            {
                dp[i][3]=max(dp[i][3],dp[i-1][0]);
                dp[i][3]=max(dp[i][3],dp[i-1][1]);
                dp[i][3]=max(dp[i][3],dp[i-1][2]);
                dp[i][3]=max(dp[i][3],dp[i-1][3]);
            }
        }
    }
    int res=0;
    for(int j=0;j<4;j++)
        res=max(res,dp[n][j]);
    return 0*printf("%d\n",res);
}