#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,m;
    cin>>n>>m;
    vector<bool> has(m+1);
    int mi=m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        has[a]=1;
        mi=min(mi,a);
    }
    vector<int> dp(m+1,m),cnt(m+1);
    for(int i=m;i>=mi;i--)
    {
        dp[i]=i;
        for(int j=i*2;j<=m;j+=i)
            dp[j]=min(dp[j],dp[j/i]);
    }
    int mx=0;
    for(int i=mi;i<=m;i++)
        if(has[i])++cnt[dp[i]],mx=max(mx,dp[i]);
    int res=mx-mi;
    for(int i=mi-1;i>=1;i--)
    {
        dp[i]=i;
        for(int j=i*2;j<=m;j+=i)
        {
            if(!has[j])dp[j]=min(dp[j],dp[j/i]);
            else
            {
                if(has[j])--cnt[dp[j]];
                dp[j]=min(dp[j],dp[j/i]);
                if(has[j])++cnt[dp[j]];
            }
        }
        while(!cnt[mx])mx--;
        res=min(res,mx-i);
    }
    cout<<res<<"\n";
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}