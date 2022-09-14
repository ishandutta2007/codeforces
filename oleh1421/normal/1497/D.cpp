//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=5010;
int tag[N];
ll s[N];
ll dp[2][N][2];
ll dp1[2][N][2];
ll mx[N];
ll mx1[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>tag[i];
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=0;i<2;i++){
        for (int j=0;j<=n;j++){
            dp[i][j][0]=dp[i][j][1]=-1000000000000000001ll;
            dp[i][j][0]=dp[i][j][1]=0;
        }
    }
    for (int i=1;i<=n;i++){
        mx[i]=-1000000000000000001ll;
        mx1[i]=mx[i];
    }
    ll res=0;

    for (int i=1;i<=n;i++){
        for (int j=0;j<=n;j++){
            for (int t=0;t<2;t++){
                dp[i%2][j][t]=-1000000000000000001ll;
                dp1[i%2][j][t]=0;
            }
        }
        for (int j=i-1;j>=1;j--){
            dp1[i%2][j][0]=max({dp1[(i-1)%2][j][0],dp[(i-1)%2][j][1],mx[j],0ll});
            dp1[i%2][j][1]=max({dp1[i%2][j+1][1],dp[i%2][j+1][0],0ll});
            if (tag[i]==tag[j]) continue;
            ///calc dp[i][j]
            dp[i%2][j][0]=max({dp1[(i-1)%2][j][0],dp[(i-1)%2][j][1],mx[j],0ll})+abs(s[i]-s[j]);
            ///calc dp[j][i]
            dp[i%2][j][1]=max({dp1[i%2][j+1][1],dp[i%2][j+1][0],0ll})+abs(s[i]-s[j]);
            mx[i]=max(mx[i],dp[i%2][j][0]);
            mx1[j]=max(mx1[j],dp[i%2][j][1]);
            res=max(res,dp[i%2][j][0]);
            res=max(res,dp[i%2][j][1]);
        }
    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            if (tag[i]!=tag[j]) res=max(res,dp[i][j]);
//        }
//    }
    cout<<res<<endl;

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}