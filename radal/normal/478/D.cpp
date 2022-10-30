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
const long long int N=2e5+30,mod = 1e9+7,inf=1e18;
ll dp[N][2][2],a[N];
int main(){
    ll r,g,h;
    cin >> r >> g;
    h = sqrt(2*(r+g));
    if (r+g == 1 || r&h == 0){
        cout << 1;
        return 0;
    }
    //debug(h);
    if (h*h == 2*(r+g)) h--;
    if (h*(h+1)/2 > r+g) h--;
    rep (i,1,r+1) {
        dp[i][1][0] = 1;
        ll R = r-i;
        ll G = h*(h+1)/2 - R-1;
        if (g-G > 0) dp[i][1][1] = 1;
        if (g-G < 0) dp[i][1][0] = 0;
    }
    dp[0][1][1] = 1;
   // debug(dp[1][1][0]);
    rep(j,2,h+1){
        rep(i,0,r+1){
            dp[i][0][1] = dp[i][1][1];
            dp[i][0][0] = dp[i][1][0];
            if (i >= j){
                if (i-j >= j-1) dp[i][1][0] = (dp[i-j][0][0]+dp[i-j][0][1])%mod;
                else dp[i][1][0] = dp[i-j][0][1];
            //    if (i == 4 && j == 3) debug(dp[i-j][0][0]);
            }
            else{
                dp[i][1][0] = 0;
            }
            ll R = r-i;
            ll G = h*(h+1)/2 - R-j*(j+1)/2;
            if (g-G > 0){
                dp[i][1][1] = (dp[i][0][1]+dp[i][0][0])%mod;
            }
            else{
                dp[i][1][1] = 0;
            }
            //if (h*(h+1)/2 - j*(j+1)/2 > g) dp[i][1][0] = 0;
            //if (i == 1 && j == 2){ debug(j);debug(dp[i][1][0]);}
        }
    }
    debug(dp[r][1][0]);
    cout << (dp[r][1][1]+dp[r][1][0])%mod;
}