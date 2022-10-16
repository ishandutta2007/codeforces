#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;

ll dp[nax];
int skad[nax];
int team[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<pair<ll,int> > a;
    for(int i=0;i<n;i++)
    {
        ll x; cin>>x; a.push_back({x,i+1});
    }
    sort(a.begin(),a.end());
    dp[0]=0;
    dp[1]=1e18;
    dp[2]=1e18;
    skad[0]=-1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=1e18;
        for(int j=3;j<=5;j++)
        {
            if(j>i) break;
            if(dp[i-j]+a[i-1].first-a[i-j].first<dp[i])
            {
                skad[i]=i-j;
            }
            dp[i]=min(dp[i],dp[i-j]+a[i-1].first-a[i-j].first);
        }
    }
    int t=n;
    cout<<dp[n]<<" ";
    int licz=1;
    while(skad[n]!=-1)
    {
        int ile=skad[n];
        for(int i=n-1;i>=ile;i--) team[a[i].second]=licz;
        n=ile;
        licz++;
    }
    cout<<licz-1<<endl;
    for(int i=1;i<=t;i++) cout<<team[i]<<" ";
    return 0;
}