#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=505;
int dp[N][N];

int main()
{
    memset(dp,0,sizeof dp);
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n;i++)
        {
            int j=i+len-1;
            if(j>=n) break;
            dp[i][j]=1+dp[i+1][j];
            for(int k=i+1;k<=j;k++)
            {
                if(s[k]==s[i])
                {
                    dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
                }
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}