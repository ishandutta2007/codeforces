#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[5555][5555];

int main()
{
    int n,m; cin>>n>>m;
    int * a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        double x;
        cin>>x;
    }
    for(int i=1;i<=m;i++)
    {
        dp[0][i]=0;
        if(a[0]==i) dp[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==j)
            {
                for(int k=1;k<=j;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
                }
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++) ans=max(ans,dp[n-1][i]);
    cout<<n-ans;
    return 0;
}