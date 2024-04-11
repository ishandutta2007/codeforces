#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2005;
const int mod=998244353;
int a[nax];
ll k;
int n;
ll dp[nax][nax*2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    if(k==1)
    {
        cout<<0; return 0;
    }
    if(n==1)
    {
        cout<<0; return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][2000]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=-n;j<=n;j++)
        {
            int pos=j+2000;
            if(a[i]==a[i%n+1])
            {
                dp[i][pos]=((dp[i-1][pos]*k)%mod);
            }
            else
            {
                dp[i][pos]=dp[i-1][pos+1];
                dp[i][pos]+=dp[i-1][pos-1];
                dp[i][pos]%=mod;
                ll akt=(dp[i-1][pos]*(k-2))%mod;
                dp[i][pos]+=akt;
                dp[i][pos]%=mod;
            }
        }
    }
    ll ans=0;
    for(int i=2001;i<=4000;i++)
    {
        ans+=dp[n][i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}