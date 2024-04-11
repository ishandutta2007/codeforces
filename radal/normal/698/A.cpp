#include <bits/stdc++.h>
#pragma GCC target ("avx2")
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
const int N=2e3+30;
ll a[N],dp[N][3];
int main(){
    ll n;
    cin >> n;
    rep (i,0,n){
        cin >> a[i];
    }
    if (a[0] == 3 || a[0] == 1){
        dp[0][1] = 1;
    }
    if (a[0] == 3 || a[0] == 2){
        dp[0][2] = 1;
    }
    rep (i,1,n){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if (a[i] == 1 || a[i] == 3){
            dp[i][1] = max(dp[i-1][0],dp[i-1][2])+1;
        }
        if (a[i] == 2 || a[i] == 3){
            dp[i][2] = max(dp[i-1][0],dp[i-1][1])+1;
        }
    }
   // debug(dp[1][2]);
    cout << n - max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    return 0;
}