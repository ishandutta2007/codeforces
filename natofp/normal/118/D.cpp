#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e8;
int n1,n2,k1,k2;
ll dp[111][111][11][11];

ll solve(ll a,ll b,ll c,ll d)
{
    if(dp[a][b][c][d]!=-1) return dp[a][b][c][d];
    ll ans;
    if(a+b==0) ans=1;
    else
    {
        ans=0;
        if(a>0 && c>0) ans+=solve(a-1,b,c-1,k2)%mod;
        if(b>0 && d>0) ans+=solve(a,b-1,k1,d-1)%mod;
    }
    ans%=mod;
    dp[a][b][c][d]=ans;
    return dp[a][b][c][d];
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n1>>n2>>k1>>k2;
    cout<<solve(n1,n2,k1,k2);
    return 0;
}