#include <iostream>
#include <bits/stdc++.h>

using namespace std;


const int N=5005;
int n,k;
int dp[N][N];
vector<int>a;

int main()
{
    a.push_back(-555);
    int n,k; cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<=k;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++)
    {
        int t=a[i];
        int c=i;
        while(t-a[c-1]<=5) c--;
        c--;
        for(int j=k;j>=1;j--)
        {
            dp[i][j]=max(dp[i-1][j],dp[c][j-1]+i-c);
        }

    }
    int res=0;
    for(int i=1;i<=k;i++) res=max(res,dp[n][i]);
    cout<<res;

    0;
}