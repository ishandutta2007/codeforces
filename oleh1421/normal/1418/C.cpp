#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
int dp[N][2];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++){
        for (int j=0;j<2;j++){
            dp[i][j]=n;
        }
    }
    dp[0][1]=0;
    for (int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][0];
        if (i>1) dp[i][1]=min(dp[i][1],dp[i-2][0]);
        dp[i][0]=dp[i-1][1]+a[i];
        if (i>1) dp[i][0]=min(dp[i][0],dp[i-2][1]+a[i]+a[i-1]);
    }
    cout<<min(dp[n][0],dp[n][1])<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();

    }
    return 0;
}