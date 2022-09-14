#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int n,k;
int a[10001];
int dp[5002][5002];
int32_t main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    a[n+1]=2000000001;
    dp[0][0]=0;
    for (int i=1;i<=n+1;i++){
        for (int j=0;j<i;j++){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            int ind=upper_bound(a+1,a+n+2,a[i]+5)-a;
            dp[ind][j+1]=max(dp[ind][j+1],dp[i][j]+(ind-i));
            dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
        }

    }
    cout<<dp[n+1][k];
    return 0;
}