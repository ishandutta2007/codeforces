#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=11111;
int dp[N][2];
bool ok;

int main()
{
    int n; cin>>n;
    int res=0;
    for(int i=0;i<n;i++)
    {
        cin>>dp[i][0]>>dp[i][1];
    }
    res+=min(dp[0][0],dp[0][1])+1;
    if(dp[0][1]==dp[0][0]) ok=true;
    else ok=false;
    for(int i=1;i<n;i++)
    {
        int t=max(dp[i-1][0],dp[i-1][1]);
        if(min(dp[i][0],dp[i][1])>=max(dp[i-1][0],dp[i-1][1])) res+=min(dp[i][0],dp[i][1])-t+1;
        if(ok==true) res--;
        if(dp[i][0]==dp[i][1]) ok=true;
        else ok=false;
    }
    cout<<res;
    return 0;
}