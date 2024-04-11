#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n; cin>>n;
   string s; cin>>s;
    long long int * a=new long long int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long int> dp[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[i].push_back(0);
        }
    }
    if(s[0]=='h') dp[0][0]=a[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<4;j++) dp[i][j]=dp[i-1][j];
        if(s[i]!='h' && s[i]!='a' && s[i]!='r' && s[i]!='d') continue;
        else
        {
            if(s[i]=='h')
            {
                dp[i][0]+=a[i];
            }
            else if(s[i]=='a')
            {
                if(dp[i][0]==0) continue;
                else
                {
                    dp[i][1]=min(dp[i][1]+a[i],dp[i][0]);
                }
            }
            else if(s[i]=='r')
            {
                if(dp[i][1]==0) continue;
                else
                {
                    dp[i][2]=min(dp[i][2]+a[i],dp[i][1]);
                }
            }
            else
            {
                if(dp[i][1]==0) continue;
                else
                {
                    dp[i][3]=min(dp[i][3]+a[i],dp[i][2]);
                }
            }
        }
    }
    cout<<dp[n-1][3];
    return 0;
}