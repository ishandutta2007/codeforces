#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int dp[35][35][55];

void zrob()
{
    for(int i=0;i<=30;i++)
    {
        for(int j=0;j<=30;j++)
        {
            for(int k=0;k<=50;k++)
            {
                if(k==i*j || k==0 || i==0 || j==0)
                {
                    dp[i][j][k]=0;
                }
                else if(k>i*j) dp[i][j][k]=1e9;
                else
                {
                    dp[i][j][k]=1000000000;
                    for(int m=0;m<=k;m++)
                    {
                        for(int x=1;x<=i-1;x++)
                        {
                            dp[i][j][k]=min(dp[i][j][k],dp[x][j][m]+dp[i-x][j][k-m]+j*j);
                        }
                        for(int y=1;y<=j-1;y++)
                        {
                            dp[i][j][k]=min(dp[i][j][k],dp[i][y][m]+dp[i][j-y][k-m]+i*i);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    zrob();
    int t; cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<dp[a][b][c]<<endl;
    }
    return 0;
}