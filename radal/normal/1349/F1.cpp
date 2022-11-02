#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 5e3+20,mod = 998244353,inf = 1e9+10;
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
int dp[N][N],fac[N],inv[N];;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    fac[0] = 1;
    inv[0] = 1;
    rep(i,1,n+1){
        dp[i][0] = 1;
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    rep(i,2,n+1){
        rep(j,1,i){
            dp[i][j] = mkay(1ll*dp[i-1][j]*(j+1)%mod,1ll*dp[i-1][j-1]*(i-j)%mod);
        }
    }
    rep(i,1,n+1){
        int ans = 0;
        rep(t,i,n+1)
            ans = mkay(ans,1ll*dp[t][i-1]*fac[n]%mod*inv[t]%mod);
        cout << ans << ' ';
    }
}