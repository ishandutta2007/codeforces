#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=5e2+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
int dp[N][N][21];
int r[N][N],d[N][N];
int main(){
    memset(dp,63,sizeof dp);
    int n,m,k;
    cin >> n >> m >> k;
    rep(i,0,n) rep(j,0,m-1) cin >> r[i][j];
    rep(i,0,n-1) rep(j,0,m) cin >> d[i][j];
    if(k%2){
        rep(i,0,n){
            rep(j,0,m) cout << -1 << ' ';
            cout << endl;
        }
        return 0;
    }
    rep(i,0,n) rep(j,0,m) dp[i][j][0] = 0;
    k/=2;
    rep(x,1,k+1){
        rep(i,0,n){
            rep(j,0,m){
                if (i) dp[i][j][x] = min(dp[i][j][x],d[i-1][j]+dp[i-1][j][x-1]);
                if (j) dp[i][j][x] = min(dp[i][j][x],r[i][j-1]+dp[i][j-1][x-1]);
                if (i < n-1) dp[i][j][x] = min(dp[i][j][x],d[i][j]+dp[i+1][j][x-1]);
                if (j < m-1) dp[i][j][x] = min(dp[i][j][x],r[i][j]+dp[i][j+1][x-1]);
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m) cout << 2*dp[i][j][k] << ' ';
        cout << endl;
    }
    return 0;
}