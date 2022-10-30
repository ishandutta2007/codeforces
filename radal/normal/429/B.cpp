#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=1e3+30,mod = 1e9+7,inf=1e18;
ll dp[N][N],a[N][N],ul[N][N],ur[N][N],dl[N][N],dr[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin >> n >> m;
    rep (i,0,n){
        rep (j,0,m){
            cin >> a[i][j];
        }
    }
    ul[0][0] = a[0][0];
    ur[0][m-1] = a[0][m-1];
    dl[n-1][0] = a[n-1][0];
    dr[n-1][m-1] = a[n-1][m-1];
    rep (i,1,m){
        ul[0][i] = ul[0][i-1] + a[0][i];
        ur[0][m-i-1] = ur[0][m-i] + a[0][m-1-i];
        dl[n-1][i] = dl[n-1][i-1] + a[n-1][i];
        dr[n-1][m-i-1] = dr[n-1][m-i] + a[n-1][m-i-1];
    }
    rep (i,1,n){
        ul[i][0] = ul[i-1][0] + a[i][0];
        dl[n-i-1][0] = dl[n-i][0] + a[n-i-1][0];
        ur[i][m-1] = ur[i-1][m-1] + a[i][m-1];
        dr[n-i-1][m-1] = dr[n-i][m-1] + a[n-1-i][m-1];
    }
    rep (i,1,n-1){
        rep (j,1,m-1){
            ul[i][j] = max(ul[i][j-1],ul[i-1][j]) + a[i][j];
            dl[n-i-1][j] = max(dl[n-1-i][j-1],dl[n-i][j]) + a[n-1-i][j];
            ur[i][m-1-j] = max(ur[i][m-j],ur[i-1][m-1-j]) + a[i][m-1-j];
            dr[n-i-1][m-1-j] = max(dr[n-i-1][m-j],dr[n-i][m-1-j]) + a[n-i-1][m-1-j];
       //     debug(n-1-i);debug(j);debug(dl[n-i-1][j]);
        }
    }
   // debug(dr[2][2]);
   // debug(ul[0][2]);
   // debug(dl[3][1]);
   // debug(ur[1][3]);
    ll ans = 0;
    rep(i,1,n-1){
        rep (j,1,m-1){
          //  debug(dr[i+1][j]);
            dp[i][j] = max(ul[i-1][j]+dr[i+1][j]+ur[i][j+1]+dl[i][j-1],ul[i][j-1]+dr[i][j+1]+ur[i-1][j]+dl[i+1][j]);
         //   cout << dp[i][j] << "  ";
            ans = max(ans,dp[i][j]);
        }
       // cout << endl;
    }
    cout << ans;
    return 0;
}