#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e3+10,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
int dp[N][2*N],n,a[N];
inline int nxt(int i){
    if (i < n) return i+1;
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> n >> k;
    rep(i,1,n+1) cin >> a[i];
    dp[0][n] = 1;
    rep(i,1,n+1){
        int nx = nxt(i);
        if (a[i] == a[nx]){
            rep(j,n-i+1,n+i){
                dp[i][j] = 1ll*k*dp[i-1][j]%mod;
            }
            continue;
        }
        rep(j,n-i,n+i+1){
            if (j){
                dp[i][j] = mkay(dp[i-1][j-1],dp[i-1][j+1]);
                dp[i][j] = mkay(dp[i][j],1ll*(k-2)*dp[i-1][j]%mod);
            }
            else{
                dp[i][j] = mkay(dp[i-1][j+1],1ll*(k-2)*dp[i-1][j]%mod);
            }
        }
    }
    int ans = 0;
    rep(i,0,n) ans = mkay(ans,dp[n][i]);
    cout << ans;
    return 0;
}