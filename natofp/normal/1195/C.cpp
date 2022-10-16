#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5+5;
long long int res=0;
vector<long long int> a,b;
vector<long long int> dp(nax,0);
vector<long long int> dp2(nax,0);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n; cin>>n;
    a.resize(n+1);
    b.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    dp[n]=a[n];
    dp2[n]=b[n];
    long long int maxa=a[n];
    long long int maxb=b[n];
    res=max(maxa,maxb);
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=a[i]+maxb;
        dp2[i]=b[i]+maxa;
        maxa=max(maxa,dp[i]);
        maxb=max(maxb,dp2[i]);
        res=max(res,dp[i]);
        res=max(res,dp2[i]);
    }
    cout<<res;
    return 0;
}