#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr ll N = 1e3+10,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int mod){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}
int dp[N][N][11],ans[N][N][11];
int md,inv[11];
int c(int r,int n){
    if (r < 0 || r > n) return 0;
    int ans = 1;
    rep(i,1,r+1) ans = 1ll*ans*inv[i]%md;
    repr(i,n,n-r+1) ans = 1ll*ans*i%md;
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,d;
    cin >> n >> d >> md;
    if (n < 3){
        cout << 1;
        return 0;
    }
    if (n <= d || (n-1-d)%(d-1)){
        cout << 0;
        return 0;
    }
    rep(i,1,d+1) inv[i] = poww(i,md-2,md);
    dp[1][n][d-1] = 1;
    rep(i,0,n+1) dp[1][i][0] = 1;
    rep(i,2,n+1){
        rep(j,1,n+1){
            rep(k,1,d+1){
                if (j+k > i){
                    dp[i][j][k] = dp[i][j-1][k];
                    continue;
                }
                if (k*j < i-1){
                    dp[i][j][k] = 0;
                    continue;
                }
                dp[i][j][k] = dp[i][j-1][k];
                rep(t,1,k+1){
                    if (t*j+k-t > i-1) break;
                    int tmp = dp[j][n][d-1]+t-1;
                    if (tmp >= md) tmp -= md;
                    int calc = c(t,tmp);
                    dp[i][j][k] += 1ll*dp[i-j*t][j-1][k-t]*calc%md;
                    if (dp[i][j][k] >= md) dp[i][j][k] -= md;
                }
            }
        }
    }
    if (n&1){
        cout << dp[n][n/2][d];
        return 0;
    }
    int ans = dp[n][n/2-1][d];
    int calc = dp[n][n/2][d]-ans-dp[n/2][n][d-1];
    calc %= md;
    if (calc < 0) calc += md;
    calc = 1ll*calc*inv[2]%md;
    ans += calc;
    if (ans >= md) ans -= md;
    ans += dp[n/2][n][d-1];
    if (ans >= md) ans -= md;
    cout << ans;
    return 0;
}