#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long int tab[1001][1001];
vector<long long int>dp(1001,0);
long long int  suma(int i,int ak,int n)
{
    if(ak<=0) return 0;
    long long int w=0;
    for(int j=i+ak;j<=(n-1);j++)
    {
     long long int x=tab[j-i-1][ak-1];
     w+=((x*(dp[j+1]))%mod);
    }
    return w;
}

int main()
{

    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        tab[i][0]=1;
        tab[i][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            tab[i][j]=(tab[i-1][j-1]+tab[i-1][j])%mod;
    }

     int * a;
     a=new int[n];
     for(int i=0;i<n;i++) cin>>a[i];

     dp[n]=1;
     for(int k=n-1;k>=0;k--)
     {
         dp[k]=dp[k+1]+suma(k,a[k],n);
         dp[k]%=mod;
     }
    cout<<(dp[0]-1+mod)%mod;
    return 0;
}