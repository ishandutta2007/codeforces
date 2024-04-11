#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[3333][2];
ll a[3333],b[3333],c[3333];
int n;
ll solve(int pos,bool prev)
{
    if(dp[pos][prev]==-1)
    {
        ll res1,res2; res1=0; res2=0;
        if(pos!=n-1)
        {
            if(prev)
        {
            res1=solve(pos+1,1)+b[pos];
            res2=solve(pos+1,0)+c[pos];
        }
        else
        {
            res1=solve(pos+1,1)+a[pos];
            res2=solve(pos+1,0)+b[pos];
        }
        }
        else
        {
            if(prev) res1=b[pos];
            else res1=a[pos];
        }
        dp[pos][prev]=max(res1,res2);
    }
    return dp[pos][prev];
}

int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    cout<<solve(0,0);
    return 0;
}