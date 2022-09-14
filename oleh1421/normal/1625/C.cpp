#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
using namespace std;
const int N=510;
const int K=210;
const ll mod=1000000007;
const int inf=1000000001;
const ld eps=1e-8;
const ld PI=3.1415926535897932384626433832795;
int cnt[35];
int dp[N][N];
int a[N],d[N];
void solve(){
    int n,l,k;cin>>n>>l>>k;
    for (int i=1;i<=n;i++) cin>>d[i];

    for (int i=1;i<=n;i++) cin>>a[i];

    n++;
    d[n]=l;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=inf;
        }
    }
    dp[1][0]=0;
    for (int i=2;i<=n;i++){
        for (int j=0;j<=k;j++){
            for (int t=i-1;t>=max(1,i-j-1);t--) {
//                cout<<dp[t][j-(i-t-1)]+a[t]*(d[i]-d[t])<<endl;
                dp[i][j]=min(dp[i][j],dp[t][j-(i-t-1)]+a[t]*(d[i]-d[t]));
            }
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<a[i-1]*(d[i]-d[i-1])<<endl;
        }
    }
    int res=inf;
    for (int i=0;i<=k;i++) res=min(res,dp[n][i]);
    cout<<res<<endl;
}
int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;

}

/**

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/