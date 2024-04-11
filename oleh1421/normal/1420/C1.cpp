#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

const int N=500010;
const ll inf=1000000000000000001ll;
ll dp[N][2];
ll a[N];
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++){
        for (int j=0;j<2;j++){
            dp[i][j]=-inf;
        }
    }
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]-a[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}