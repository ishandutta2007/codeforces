#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[3001];
int c[3001];
int dp[4][3001];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=c[i];
        for(int j=2;j<=3;j++)
        {
            dp[j][i]=1111111111;
            for(int k=1;k<i;k++)
        {
            if(s[k]<s[i]) dp[j][i]=min(dp[j][i],dp[j-1][k]+c[i]);
        }
        }
    }
    int x= *min_element(dp[3]+1,dp[3]+n+1);
    if(x==1111111111) x=-1;
    cout<<x;
    return 0;
}