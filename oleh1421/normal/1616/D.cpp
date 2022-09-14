#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
const int N=1500010;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
int a[N];
int dp[N][3];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int x;cin>>x;
    for (int i=1;i<=n;i++) a[i]-=x;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<3;j++){
            dp[i][j]=-n-10;
        }
    }
    dp[0][0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=2;j++){
            if (dp[i][j]<0) continue;
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
            int sum=a[i+1];
            bool ok=true;
            for (int t=1;t<=j;t++){
                sum+=a[i+1-t];
                if (sum<0) ok=false;
            }
            if (ok){
                dp[i+1][min(j+1,2)]=max(dp[i+1][min(j+1,2)],dp[i][j]+1);
            }
        }
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**




**/