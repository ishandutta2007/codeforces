#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e5+5;

const int mod=1e9+7;

ll dp[nax][2];

int main()
{
    ll n,m;  cin>>n>>m;
    dp[1][0]=1;
    dp[1][1]=0;
    for(int i=2;i<nax;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][0]%=mod;
        dp[i][1]=dp[i-1][0];
        dp[i][1]%=mod;
    }
    ll ile=dp[n][0]+dp[n][1];
    ile*=2; ile%=mod;
    ll ans=dp[m][0]+dp[m][1];
    ans*=2;
    ans%=mod;
    ans+=(ile-2);
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}