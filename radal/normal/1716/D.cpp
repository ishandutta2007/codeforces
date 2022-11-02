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
constexpr int N = 2e5+10,mod = 998244353,inf = 1e9+10,sq = 700;
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
int dp[N][3];
void solve(){
    int n,k;
    cin >> n >> k;
    rep(i,k,n+1) dp[i][0] = (i%k == 0);
    rep(j,1,sq){
        int d = j%3;
        rep(i,0,n+1){
            dp[i][d] = dp[i][(j-1+3)%3];
            if (i >= k+j){
                dp[i][d] = mkay(dp[i][d],dp[i-k-j][d]);
                int pr = d-2;
                if (pr < 0) pr += 3;
                dp[i][d] = mkay(dp[i][d],-dp[i-k-j][pr]);
            }
        }
    }
    rep(i,1,n+1) cout << dp[i][(sq-1)%3] << ' ';
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}