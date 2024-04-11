#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int dp[MAXN][2][2];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>s; n=s.size();
        for(int i=0;i<=n;i++) dp[i][0][0]=dp[i][1][0]=dp[i][0][1]=dp[i][1][1]=MAXN;
        dp[0][1][1]=0;
        for(int i=0;i<n;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) for(int l=0;l<2;l++)
        {
            if((i<=0 || s[i]!=s[i-1] || k==1 || j==1) && (i<=1 || s[i]!=s[i-2] || j==1 || l==1)) dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][k][l]+j);
        }
        int res=MAXN;
        for(int j=0;j<2;j++) for(int k=0;k<2;k++) res=min(res,dp[n][j][k]);
        cout<<res<<endl;
    }
}