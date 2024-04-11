#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mod=998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long int * dp;
    dp=new long long int[n+1];
    dp[0]=0;
    long long sum=0;
    long long w=0;
    for(int i=1;i<=n;i++)
    {

        dp[i]=sum;
        w*=2;
        w+=a[i-1];
        w%=mod;
        dp[i]+=w; dp[i]%=mod;
        sum+=dp[i];



    }
    cout<<dp[n]%mod;
    return 0;
}