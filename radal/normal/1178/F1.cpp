#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 5e2+20,mod = 998244353 ,inf = 1e9+10,maxm = (1 << 18)+10;
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
        k /= 2;
    }
    return z;
}
int dp[N][N],n,a[N],m;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
        dp[i][i+1] = 1;
        dp[i][i] = 1;
    }
    dp[n][n] = 1;
    repr(l,n-2,0){
        rep(r,l+2,n+1){
            int j = -1,mi = n+2;
            rep(i,l,r){
                if (a[i] < mi){
                    j = i;
                    mi = a[i];
                }
            }
            int sum1 = dp[l][j],sum2 = 0;
            rep(i,l,j){
                sum1 = mkay(sum1,1ll*dp[l][i+1]*dp[i+1][j]%mod);
            }
            rep(i,j,r){
                sum2 = mkay(sum2,1ll*dp[j+1][i+1]*dp[i+1][r]%mod);
            }
            dp[l][r] = 1ll*sum1*sum2%mod;
        }
    }
    cout << dp[0][n];
}