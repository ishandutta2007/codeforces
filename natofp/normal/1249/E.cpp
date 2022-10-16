#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

const int nax=2e5+5;

int a[nax];
int b[nax];
int dp[nax][2];

int n,c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n-1;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++) cin>>b[i];
    dp[1][1]=c;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][1],dp[i-1][0])+a[i-1];
        dp[i][1]=min(dp[i-1][0]+b[i-1]+c,dp[i-1][1]+b[i-1]);
    }
    for(int i=1;i<=n;i++) cout<<min(dp[i][0],dp[i][1])<<" ";
    return 0;
}