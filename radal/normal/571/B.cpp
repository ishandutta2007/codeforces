#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=3e5+30,mod = 1e9+7,inf=1e18;
ll dp[5300][5300],a[N];
int main(){
    ll n,k;
    cin >> n >> k;
    rep (i,0,n) cin >> a[i];
    sort(a,a+n);
    if (!(n%k)){
        ll ans=0;
        ll t=n/k;
        for (int i=0; i < n-t+1; i+=t){
            ans+=a[i+t-1]-a[i];
         //   debug(a[i+t-1])
           // debug(a[i]);
        }
        cout << ans;
        return 0;
    }
    ll t = n/k;
    ll ans=inf;
    rep (i,1,n/t+1) dp[i][0] = dp[i-1][0] + a[i*t-1] - a[i*t-t];
    rep(i,1,n/(t+1)+1) dp[0][i] = dp[0][i-1]+a[i*(t+1)-1] - a[i*(t+1)-t-1];
    rep(i,1,n/t+1){
        rep(j,1,n/(t+1)+1){
                dp[i][j] = min(dp[i-1][j] + a[i*t+j*(t+1)-1] - a[i*t+j*(t+1)-t],dp[i][j-1]+a[i*t+j*(t+1)-1] - a[i*t+j*(t+1)-t-1]);
          //          debug(a[i*t+j*(t+1)-1]);
           //       debug(a[i*t+j*(t+1)-t-1]);
            //        debug(dp[i][j-1]);
                if(i*t+j*(t+1) == n){
                    ans = min(ans,dp[i][j]);
                    //if (dp[i][j] == 0) cout << i << ' ' << j << endl; 
                //debug(j);
                }
                //debug(i);debug(dp[i][j]);
            
        }
    }
    ll p =n-k*t;
    cout << dp[(n-p*(t+1))/t][p];
}