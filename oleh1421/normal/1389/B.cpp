#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int dp[N][6][2];
int a[N];
void solve(){
    int n,k,z;cin>>n>>k>>z;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=k;i++){
        for (int j=0;j<6;j++){
            for (int t=0;t<2;t++){
                dp[i][j][t]=-1000000001;
            }
        }
    }
    dp[0][0][1]=a[1];
    for (int i=0;i<k;i++){
        for (int j=0;j<=z && i-2*j>=0;j++){
            for (int t=0;t<2;t++){
//                cout<<i<<" "<<j<<" "<<t<<" "<<dp[i][j][t]<<endl;
                int pos=i-2*j+1;
                if (pos<n){
                    dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][t]+a[pos+1]);
                }
                if (pos>1 && j<z && t==1){
                    dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][t]+a[pos-1]);
                }

            }
        }
    }
    int res=0;
    for (int i=0;i<=z;i++){
        res=max(res,dp[k][i][0]);
        res=max(res,dp[k][i][1]);
    }
    cout<<res<<endl;
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