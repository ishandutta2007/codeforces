#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[200001][3];
ll mod=1000000007ll;
int main()
{
   int n,l,r;cin>>n>>l>>r;
   ll x0=r/3-(l-1)/3;
   ll x1=(r+2)/3-(l+1)/3;
   ll x2=(r+1)/3-l/3;
   dp[0][0]=1ll;
   for (int i=0;i<n;i++){
       dp[i+1][0]=(dp[i][0]*x0+dp[i][1]*x2+dp[i][2]*x1)%mod;
       dp[i+1][1]=(dp[i][0]*x1+dp[i][1]*x0+dp[i][2]*x2)%mod;
       dp[i+1][2]=(dp[i][1]*x1+dp[i][2]*x0+dp[i][0]*x2)%mod;
   }
   cout<<dp[n][0];
   return 0;
}
/*
4
GSGS
*/