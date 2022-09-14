//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const int N=500010;
int dp[N];
int a[N];
void solve(){
    int n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    dp[0]=0;
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        int m=(x+a[i]-1)/a[i];
        if (i>=m){
            dp[i]=max(dp[i],dp[i-m]+1);
        }
    }
    cout<<dp[n]<<endl;
}
int32_t main()
{
//    freopen("cosmo.in","r",stdin);
//    freopen("cosmo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}