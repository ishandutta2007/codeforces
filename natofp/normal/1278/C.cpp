#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
int a[nax];
int dp[nax*6];

void solve()
{
    int res=1e9;
    int n; cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    int bal1=0;
    int bal2=0;
    for(int i=1;i<=2*n;i++)
    {
        if(a[i]==1) bal1++;
        else bal2++;
    }
    for(int i=0;i<=5*n;i++)
    {
        dp[i]=1e9;
    }
    int cur=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==1) cur++;
        else cur--;
        dp[2*n+cur]=min(n-i+1,dp[2*n+cur]);
    }
    dp[n*2]=0;
    res=min(res,dp[2*n+bal1-bal2]);
    for(int i=n+1;i<=2*n;i++)
    {
        if(a[i]==1) bal1--;
        else bal2--;
        res=min(res,i-n+dp[2*n+bal1-bal2]);
    }
    cout<<res<<"\n";
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}