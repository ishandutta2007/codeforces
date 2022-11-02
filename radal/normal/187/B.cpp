#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=60+5,mod = 1e9+7,inf=1e12,maxq = 5e5+30,maxm = 1e3+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int mat[N][N][N];
int dp[maxm][N][N];
int d[N][N][N][N];
int n,m,r;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // memset(dp,63,sizeof dp);
    memset(d,63,sizeof d);
    cin >> n >> m >> r;
    rep(i,1,m+1) rep(j,1,n+1) rep(k,1,n+1) cin >> mat[i][j][k];
    rep(i,1,n+1) rep(j,1,n+1) rep(k,1,m+1) d[0][i][j][k] = mat[k][i][j];
    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1){
        if (i != j){
            rep(x,1,m+1){
                d[k][i][j][x] = min(d[k-1][i][j][x],d[k-1][i][k][x]+d[k-1][k][j][x]);
            }
        }
    }
    rep(i,1,n+1) rep(j,1,n+1){
        if (i != j){
            rep(k,1,m+1){
                if (k > 1){
                    if (dp[0][i][j] > d[n][i][j][k]) dp[0][i][j] = d[n][i][j][k];
                }
                else  dp[0][i][j] = d[n][i][j][k];
            }
        }
        else dp[0][i][j] = 0;
    }
    rep(k,1,1001){
        rep(i,1,n+1){
            rep(j,1,n+1){
                dp[k][i][j] = dp[k-1][i][j];
                if (i == j) continue;
                rep(y,1,n+1) if (dp[k-1][i][y]+dp[0][y][j] < dp[k][i][j]) dp[k][i][j] = dp[k-1][i][y]+dp[0][y][j];
            }
        }
    }
    int x,y,z;
    rep(i,0,r){
        cin >> x >> y >> z;
        cout << dp[z][x][y] << endl;
    }
    return 0;
}