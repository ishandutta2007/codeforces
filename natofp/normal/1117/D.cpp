#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=1e9+7;
vector<long long int> dp(1e6+5,0);
unordered_map<long long int,long long int> a;
long long int n,m;

long long int ile(long long int dist)
{
    if(dist<=1000) return dp[dist];
    ll mid=dist/2;
    ll res=0;
    if(a[mid-1]==0) a[mid-1]=ile(mid-1);
    if(a[dist-mid]==0) a[dist-mid]=ile(dist-mid);
    res+=a[mid-1]*a[dist-mid];
    res%=mod;
    for(int i=0;i<m;i++)
    {
        ll p,r;
        p=mid-i-1;
        r=dist-(mid-i+m-1);
        if(a[p]==0) a[p]=ile(p);
        if(a[r]==0) a[r]=ile(r);
        res+=a[p]*a[r];
        res%=mod;
    }
    return res;
}


int main()
{
    cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=1000;i++)
    {
        dp[i]+=dp[i-1];
        if(i>=m) dp[i]+=dp[i-m];
        dp[i]%=mod;
    }
    cout<<ile(n);
    return 0;
}