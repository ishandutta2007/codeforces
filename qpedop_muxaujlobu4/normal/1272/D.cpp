#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <string>
using namespace std;
long long a[200000];
long long dp[200000][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    dp[0][0]=1;
    dp[0][1]=0;
    if(a[1]>a[0]){
        dp[1][0]=2;
        dp[1][1]=1;
    }
    else {
       dp[1][0]=1;
       dp[1][1]=1;
    }
    for(int i=2;i<n;++i){
        dp[i][0]=dp[i][1]=1;
        if(a[i]>a[i-1])dp[i][0]=dp[i-1][0]+1;
        if(a[i]>a[i-1]&&a[i-1]>a[i-2])dp[i][1]=dp[i-1][1]+1;
        dp[i][1]=max(dp[i][1],dp[i-1][0]);
        if(a[i]>a[i-1]&&(i==2||a[i-1]>a[i-3]))dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
        if(a[i]>a[i-2])dp[i][1]=max(dp[i][1],dp[i-2][0]+1);
        dp[i][1]=max(dp[i][1],dp[i-1][0]);
    }
    long long res=0;
    for(int i=0;i<n;++i){
        res=max(dp[i][0],res);
        res=max(dp[i][1],res);
    }
    cout<<res;
    return 0;
}