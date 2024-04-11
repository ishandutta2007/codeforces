#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=105;

long long int dp[nax][2];
int mod=1e9+7;

int main()
{
    memset(dp,0,sizeof dp);
    int n,k,d;
    cin>>n>>k>>d;
    dp[0][0]=1;
    dp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int last=1;last<=d-1;last++)
        {
            if(last>i) break;
            dp[i][0]+=dp[i-last][0];
            dp[i][0]%=mod;
        }
        for(int last=1;last<=k;last++)
        {
            if(last>i) break;
            if(last>=d)
            {
                dp[i][1]+=dp[i-last][0];
                dp[i][1]+=dp[i-last][1];
                dp[i][1]%=mod;
            }
            else
            {
                dp[i][1]+=dp[i-last][1];
                dp[i][1]%=mod;
            }
        }

    }
    cout<<dp[n][1];
    return 0;

}