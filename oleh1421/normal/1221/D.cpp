#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int dp[300001][3];
int a[300001];
int b[300001];
void solve(){
     int n;cin>>n;
     for (int i=0;i<=n;i++) dp[i][0]=1000000000000000001ll,dp[i][1]=1000000000000000001ll,dp[i][2]=1000000000000000001ll;
     for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
     dp[1][0]=0;
     dp[1][1]=b[1]*1ll;
     dp[1][2]=b[1]+b[1];
     for (int i=2;i<=n;i++){
         for (int j=0;j<3;j++){
             int minx=1000000000000000001ll;
             for (int t=0;t<3;t++){
                 if (a[i]+j!=a[i-1]+t) minx=min(minx,dp[i-1][t]+j*b[i]);
             }
             dp[i][j]=minx;
         }

     }
     cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}