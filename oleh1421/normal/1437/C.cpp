#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=210;
const int inf=1000000001;
int dp[N][N*2];
int t[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i];
    sort(t+1,t+n+1);
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n+n;j++){
            dp[i][j]=inf;
        }
    }
    for (int i=0;i<=n+n;i++) dp[0][i]=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n+n;j++){
            dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(t[i]-j));
        }
    }
    cout<<dp[n][n+n]<<endl;
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
/*
7
7 7 7 7 7 7 7
*/