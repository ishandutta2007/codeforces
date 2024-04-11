#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
int dp[300001][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=0;
    dp[0][1]=0;
    a[0]=0;
    for (int i=1;i<=n;i++){
        if (a[i]>a[i-1]){
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=dp[i-1][1]+1;
            if (i>=2 && a[i-2]<a[i]) dp[i][1]=max(dp[i][1],dp[i-2][0]+1);
        } else {
            dp[i][0]=1;
            if (i>=2 && a[i-2]<a[i]) dp[i][1]=dp[i-2][0]+1;
            else dp[i][1]=1;
        }
    }
    int maxx=0;
    for (int i=1;i<=n;i++){
        maxx=max(maxx,dp[i][0]);
        maxx=max(maxx,dp[i][1]);
    }cout<<maxx;
    return 0;
}