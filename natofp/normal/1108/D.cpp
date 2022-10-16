#include <iostream>
#include <bits/stdc++.h>

using namespace std;


const int N=200005;
int dp[N][3];

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    dp[0][0]=dp[0][1]=dp[0][2]=1;
    if(s[0]=='B') dp[0][0]=0;
    else if(s[0]=='G') dp[0][1]=0;
    else dp[0][2]=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='B')
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+1;
        }
        else if(s[i]=='G')
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+1;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+1;
        }
        else
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+1;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }
    }
    int res=1e9;
    res=min(res,dp[n-1][0]);
    res=min(res,dp[n-1][1]);
    res=min(res,dp[n-1][2]);
    cout<<res<<endl;
    string ans="";
    string x;
    if(dp[n-1][0]<dp[n-1][1] && dp[n-1][0]<dp[n-1][2]) x="B";
    else if(dp[n-1][1]<dp[n-1][0] && dp[n-1][1]<dp[n-1][2]) x="G";
    else x="R";
    ans+=x;
    for(int i=n-2;i>=0;i--)
    {
        if(x=="B")
        {
            if(dp[i][1]<dp[i][2])
            {
                x="G"; ans+=x; continue;
            }
            else
            {
                x="R"; ans+=x; continue;
            }
        }
        if(x=="G")
        {
            if(dp[i][0]<dp[i][2])
            {
                x="B";; ans+=x; continue;
            }
            else
            {
                x="R"; ans+=x; continue;
            }
        }
        if(x=="R")
        {
            if(dp[i][0]<dp[i][1])
            {
                x="B"; ans+=x; continue;
            }
            else
            {
                x="G"; ans+=x; continue;
            }
        }
    }
    for(int i=n-1;i>=0;i--) cout<<ans[i];
    return 0;
}