#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=5010;
int dp[N][N];
void solve(){
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    s="."+s;
    t="."+t;
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s[i]==t[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1])-1);
            res=max(res,dp[i][j]);
        }
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}