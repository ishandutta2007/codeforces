#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,m,b,mod;

const int N=505;
int dp[2][N][N];

int main()
{
    cin>>n>>m>>b>>mod;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int t=i%2;
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=b;k++)
            {
                dp[t][j][k]=dp[(t+1)%2][j][k];
                if(k>=a[i] && j>0) dp[t][j][k]+=dp[t][j-1][k-a[i]];
                dp[t][j][k]%=mod;
            }
        }
    }
   int ans=0;
   for(int k=0;k<=b;k++)
   {
       ans+=dp[n%2][m][k];
       ans%=mod;
   }
   cout<<ans;
    return 0;
}