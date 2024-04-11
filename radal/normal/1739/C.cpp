#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 5e1+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
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

int c[N][N];
int dp[N][3]; //win lose draw
void solve(){
    dp[0][2] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i += 2){
        int j = i/2;
        dp[i][0] = mkay(c[j][i-1],dp[i-2][1]);
        dp[i][1] = mkay(c[j][i-2],dp[i-2][0]);
        dp[i][2] = 1;
    }
    cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    rep(i,0,N) c[0][i] = 1;
    rep(i,1,N) rep(j,i,N) c[i][j] = mkay(c[i-1][j-1],c[i][j-1]);
    while (T--){
        solve();
    }
    return 0;
}