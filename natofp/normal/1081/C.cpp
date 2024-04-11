#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int mod=998244353;
    long long int n,m,k;
    cin>>n>>m>>k;
    vector<long long int> dp[n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++) dp[i].push_back(0);
    }
    dp[1][0]=m;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
            if(j>=1)
            {
            dp[i][j]+=dp[i-1][j-1]*(m-1);
            dp[i][j]%=mod;
            }

        }
    }
    cout<<dp[n][k];
    return 0;
}