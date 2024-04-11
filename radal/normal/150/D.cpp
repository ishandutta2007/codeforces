#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 2e2+10,mod = 1e9+7,inf = 1e9,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int dp[N][N][N][2];
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
        if (a[i] == -1) a[i] = -inf;
    }
    rep(i,0,n){
        rep(j,0,n+1)
            rep(k,0,n+2) rep(p,0,2) dp[i][j][k][p] = -inf;
        dp[i][i][0][0] = dp[i][i][0][1] = dp[i][i][n+1][0] = dp[i][i][n+1][1] = 0;
        
    }
    string s;
    cin >> s;
    repr(l,n-1,0){
        rep(r,l+1,n+1){
            dp[l][r][0][0] = 0;
            dp[l][r][0][1] = -inf;
            if (r-l == 1){
                dp[l][r][1][0] = 0;
                dp[l][r][1][1] = 0;
                dp[l][r][n+1][0] = max(a[1],0);
                dp[l][r][n+1][1] = a[1];
                continue;
            }
            int mx0 = 0,mx1 = -inf;
            rep(x,1,r-l+1){
                dp[l][r][x][0] = max(dp[l+1][r][x][0],dp[l][r-1][x][0]);
                rep(i,l,r-1){
                    dp[l][r][x][0] = max({dp[l][r][x][0],dp[l][i+1][x][0]+dp[i+1][r][n+1][0],dp[l][i+1][n+1][0]+dp[i+1][r][x][0]});
                    dp[l][r][x][1] = max({dp[l][r][x][1],dp[l][i+1][x][1]+dp[i+1][r][n+1][1],dp[l][i+1][n+1][1]+dp[i+1][r][x][1]});
                }
                if (x >= 2 && s[l] == s[r-1]){
                    dp[l][r][x][0] = max(dp[l][r][x][0],dp[l+1][r-1][x-2][1]);
                    dp[l][r][x][1] = max(dp[l][r][x][1],dp[l+1][r-1][x-2][1]);
                    if (x == 2){
                        dp[l][r][x][0] = max(dp[l][r][x][0],dp[l+1][r-1][n+1][1]);
                        dp[l][r][x][1] = max(dp[l][r][x][1],dp[l+1][r-1][n+1][1]);
                    }
                }
                mx0 = max(mx0,dp[l][r][x][0]+a[x]);
                mx1 = max(mx1,dp[l][r][x][1]+a[x]);
                if (dp[l][r][x][1] < 0) dp[l][r][x][1] = -inf;
                if (dp[l][r][x][0] < 0) dp[l][r][x][0] = -inf;
            }
            dp[l][r][n+1][0] = mx0;
            dp[l][r][n+1][1] = mx1;
        }
    }
    cout << dp[0][n][n+1][0];
}