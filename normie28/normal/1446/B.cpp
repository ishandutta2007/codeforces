#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
string s,t;
int n,m,i,j,k,u,v,a,b,res=0;
int main()
{
    cin>>n>>m>>s>>t;
    for (i=n-1;i>=0;i--) for (j=m-1;j>=0;j--)
    {
        if (i<n-1) dp[i][j]=max(dp[i][j],dp[i+1][j]-1);
        if (j<m-1) dp[i][j]=max(dp[i][j],dp[i][j+1]-1);
        if ((i<n-1)and(j<m-1)and(s[i+1]==t[j+1]))
        {
            dp[i][j]=max(dp[i][j],dp[i+1][j+1]+2);
        }
        if (s[i]!=t[j]) res=max(res,dp[i][j]-2);
        else res=max(res,dp[i][j]+2);
    }
    cout<<res;
}