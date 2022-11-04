#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005],res[100005];
int dp[100005][3][2],pre[100005][3][2];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    reverse(s+1,s+n+1);
    memset(dp,0xcf,sizeof(dp));
    dp[0][0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<2;k++)
            {
                if(dp[i][j][k]<dp[i-1][j][k])
                {
                    dp[i][j][k]=dp[i-1][j][k];
                    pre[i][j][k]=j*2+k;
                }
                int tj=(j+s[i]-'0')%3,tk=(s[i]=='0');
                if(dp[i][tj][tk]<dp[i-1][j][k]+1)
                {
                    dp[i][tj][tk]=dp[i-1][j][k]+1;
                    pre[i][tj][tk]=j*2+k;
                }
            }
    if(dp[n][0][0]<0)
    {
        int zr=0;
        for(int i=1;i<=n;i++)
            zr|=(s[i]=='0');
        printf("%d\n",zr-1);
    }
    else
    {
        int ns=0,nk=0,len=0;
        for(int i=n;i>0;i--)
        {
            int ts=pre[i][ns][nk]/2,tk=pre[i][ns][nk]%2;
            if(dp[i-1][ts][tk]<dp[i][ns][nk])res[len++]=s[i];
            ns=ts,nk=tk;
        }
        printf("%s\n",res);
    }
    return 0;
}