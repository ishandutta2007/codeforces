#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long int MOD=998244353;
const int N=1005;
long long int dp[N][2*N][4];
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2*N;j++)
        {
            for(int k=0;k<4;k++)
            {
                dp[i][j][k]=0;
            }
        }
    }
    int n,k;
    cin>>n>>k;
    dp[1][1][0]=1;
    dp[1][2][1]=1;
    dp[1][2][2]=1;
    dp[1][1][3]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j==1)
            {
                dp[i][j][0]=1;
                dp[i][j][1]=0;
                dp[i][j][2]=0;
                dp[i][j][3]=1;
            }
            else
            {
                for(int c=0;c<4;c++)
            {
                if(c==0)
                {
                    dp[i][j][c]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%MOD;
                }
                else if(c==1)
                {
                    dp[i][j][c]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-2][2]+dp[i-1][j-1][3])%MOD;
                }
                else if(c==2)
                {
                    dp[i][j][c]=(dp[i-1][j-1][0]+dp[i-1][j-2][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%MOD;
                }
                else if(c==3)
                {
                    dp[i][j][c]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%MOD;
                }
            }
            }
        }
    }
    long long int ans=0;
    for(int i=0;i<4;i++)
    {
        ans+=dp[n][k][i];
    }
    cout<<ans%MOD;
    return 0;
}