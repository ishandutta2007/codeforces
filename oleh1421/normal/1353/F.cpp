#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=998244353ll;
const int N=110;
ll a[N][N];
ll dp[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            a[i][j]-=i+j;
        }
    }
    ll res=1000000000000000001ll;
    for (int it=1;it<=n;it++){
        for (int jt=1;jt<=m;jt++){

            for (int i=1;i<=n;i++){
                if (a[i][1]>=a[it][jt]) dp[i][1]=dp[i-1][1]+a[i][1]-a[it][jt];
                else dp[i][1]=1000000000000000001ll;
            }
            for (int i=1;i<=m;i++){
                if (a[1][i]>=a[it][jt]) dp[1][i]=dp[1][i-1]+abs(a[it][jt]-a[1][i]);
                else dp[1][i]=1000000000000000001ll;
            }
            for (int i=2;i<=n;i++){
                for (int j=2;j<=m;j++){
                    if (a[i][j]>=a[it][jt]) dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j]-a[it][jt];
                    else dp[i][j]=1000000000000000001ll;
                }
            }
            res=min(res,dp[n][m]);
//            if (dp[n][m]==6){
//                cout<<a[it][jt]<<endl;
//                for (int i=1;i<=n;i++){
//                    for (int j=1;j<=m;j++){
//                        cout<<a[i][j]<<" ";
//                    }
//                    cout<<endl;
//                }
//                for (int i=1;i<=n;i++){
//                    for (int j=1;j<=m;j++){
//                        cout<<abs(a[i][j]-a[it][jt])<<" ";
//                    }
//                    cout<<endl;
//                }
//                //return;
//            }
        }
    }
    cout<<res<<endl;

//1 2 3 4
//5 6 7 8
//9 10 11 12
}
int main()
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