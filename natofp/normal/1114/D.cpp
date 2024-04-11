#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=5005;
int dp[N][N];

int main()
{
    memset(dp,0,sizeof dp);
    int n; cin>>n;
    vector<int> a;
    int x; cin>>x;
    a.push_back(x);
    for(int i=1;i<n;i++)
    {
        int x; cin>>x;
        if(x!=a.back()) a.push_back(x);
    }
    n=a.size();
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int len=1;len<n;len++)
    {
        for(int i=0;i+len<n;i++)
        {
            int j=i+len;
            if(a[i]==a[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout<<n-(dp[0][n-1]+1)/2;
    return 0;
}