#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=2e5+10,mod=1e9+7,mx=1e6;
ll a[N],dp[N][2][3];
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
        }
        if (n == 1){
            cout << a[0] << endl;
            continue;
        }
        dp[0][0][1] = a[0];
        dp[0][0][2] = mx;
        dp[0][1][1] = mx;
        dp[0][1][2] = mx;
        rep(i,1,n){
            dp[i][0][1] = min(dp[i-1][1][2],dp[i-1][1][1])+a[i];
            dp[i][0][2] = dp[i-1][0][1]+a[i];
            dp[i][1][1] = min(dp[i-1][0][1],dp[i-1][0][2]);
            dp[i][1][2] = dp[i-1][1][1];
        }
        cout << min(min(dp[n-1][0][1],dp[n-1][0][2]),min(dp[n-1][1][1],dp[n-1][1][2])) << endl;

    }
    return 0;
}