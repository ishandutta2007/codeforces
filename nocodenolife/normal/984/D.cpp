#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int max(long long int a, long long int b, long long int c)
{
    if(a>b)
    {
        return a>c?a:c;
    }
    else
        return b>c?b:c;
}
int main() {
    int n;
    cin>>n;
    long long int dp[n][n];
    for(int i=0;i<n;i++)
    {
        cin>>dp[i][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            dp[i+j][j] = dp[i+j-1][j]^dp[i+j][j+1];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            dp[i+j][j] = max(dp[i+j-1][j],dp[i+j][j+1],dp[i+j][j]);
        }
    }
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<dp[r-1][l-1]<<endl;
    }
    return 0;
}