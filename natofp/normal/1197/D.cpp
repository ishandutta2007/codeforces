#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=3e5+5;
long long int inf=-1e18-5;
long long int dp[nax][11];
long long int a[nax];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long int res=inf;
    for(int i=0;i<=m;i++) dp[0][i]=inf;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=inf;
            if(j==m-1)
            {
                dp[i][j]=a[i]-k;
                if(m==1)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i]-k);
                }
                else
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][0]+a[i]-k);
                }
            }
            else
            {
                dp[i][j]=a[i]+dp[i-1][j+1];
            }
            res=max(res,dp[i][j]);
        }
    }
    cout<<max(res,0LL);
    return 0;
}