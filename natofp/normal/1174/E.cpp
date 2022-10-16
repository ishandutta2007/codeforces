#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int roz=21;
const int nax=1e6+5;
int mod=1e9+7;

int dp[nax][roz][2];

int f(int n,int x,int y)
{
    int pot2=(1<<x);
    int pot3=1;
    if(y==1) pot3=3;
    return n/(pot2*pot3);
}

int main()
{
    int n; cin>>n;
    int x=1;
    int licz=0;
    while(x*2<=n)
    {
        x*=2;
        licz++;
    }
    dp[1][licz][0]=1;
    if(x/2*3<=n)
    {
        dp[1][licz-1][1]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=licz;j++)
        {
            for(int k=0;k<=1;k++)
            {
                int ile=f(n,j,k);
                if(ile>=i)
                {
                    long long int res=(long long int)dp[i-1][j][k]*(ile-i+1);
                    res%=mod;
                    dp[i][j][k]+=res;
                    if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
                }
                if(k==0)
                {
                    int ile=f(n,j,0);
                    int ile2=f(n,j,1);
                    if(ile>=i)
                    {
                        long long int res=(long long int)dp[i-1][j][k+1]*(ile-ile2);
                        res%=mod;
                        dp[i][j][k]+=res;
                        if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
                    }
                }
                if(1)
                {
                    int ile=f(n,j,k);
                    int ile2=f(n,j+1,k);
                    if(ile>=i)
                    {
                        long long int res=(long long int)dp[i-1][j+1][k]*(ile-ile2);
                        res%=mod;
                        dp[i][j][k]+=res;
                        if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
                    }
                }
            }
        }
    }
    cout<<dp[n][0][0];
    return 0;
}