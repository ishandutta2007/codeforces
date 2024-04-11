#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;
const int nax=1e3+7;
long long int dp[nax][nax];
int n;
long long int policz(int i,int j)
{
    if(i>n || j<0 || j>i) dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];
    // dp[i+1][j+1] i dp[i][j-1];
    long long int res1,res2,res3;
    if(i+1<=n && j-1>=0)
    {
        res1=policz(i+1,j+1)+policz(i,j-1);
        res2=1LL+policz(i+2,j+2)+policz(i+1,j)+policz(i,j-1);
        res3=1LL+policz(i+1,j+1)+policz(i+1,j)+policz(i,j-2);
        dp[i][j]=max(res1,res2);
        dp[i][j]=max(dp[i][j],res3);
        dp[i][j]%=mod;
    }
    else if(i+1<=n)
    {
        res1=policz(i+1,j+1);
        dp[i][j]=max(res1,1LL+policz(i+2,j+2)+policz(i+1,j));
        dp[i][j]%=mod;
    }
    else if(j-1>=0)
    {
        res1=policz(i,j-1);
        dp[i][j]=max(res1,1LL+policz(i+1,j)+policz(i,j-2));
        dp[i][j]%=mod;
    }
    else dp[i][j]=0;
    return dp[i][j];
}

int main()
{
    cin>>n;
    for(int i=0;i<nax;i++)
    {
        for(int j=0;j<nax;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<policz(0,0);

    return 0;
}