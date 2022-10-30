#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 5e2+30,inf = 1e10,mod=1e9+7;
int c[N],dp[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n;
    rep (i,0,n) cin >> c[i];
    rep(i,0,n){
        dp[i][i+1] = 1;
        if (i < n-1){
            if (c[i] == c[i+1]) dp[i][i+2] = 1;
            else dp[i][i+2] = 2;
        }
    }
    repr (l,n-3,0){
        rep(r,l+3,n+1){
            dp[l][r] = dp[l+1][r]+1;
            if (c[l] == c[l+1]) dp[l][r] = min(dp[l][r],1+dp[l+2][r]);
            rep(m,l+2,r){
                
                if (c[l] == c[m]){
                    dp[l][r] = min(dp[l][r],dp[l+1][m]+dp[m+1][r]);
                }
            }
        }
    }
    cout << dp[0][n];
}