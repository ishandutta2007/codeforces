#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int dp[101];
    dp[0]=1;
    for(int i=0;i<=100;i++)
    {
        if(i>=3)
        {
            if(dp[i-3]==1) dp[i]=1;
        }
        if(i>=7)
        {
            if(dp[i-7]==1) dp[i]=1;
        }
    }
    int n; cin>>n;
    while(n--)
    {
        int x; cin>>x;
        if(dp[x]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}