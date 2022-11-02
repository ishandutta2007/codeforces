#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
constexpr int N = 1e6+20,mod = 998244353 ,inf = 2e9+10,maxm = (1 << 10)+10;
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
int a[N];
ll dp[N][2];
inline void solve(){
    int g = 0,n,m;
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,m){
        int x;
        cin >> x;
        g = gcd(x,g);
    }
    rep(i,0,g){
        dp[i][1] = -inf;
        dp[i][0] = 0;
    }
    rep(i,0,n){
        int x = i%g;
        ll ss = dp[x][0];
        dp[x][0] = max(dp[x][0]+a[i],dp[x][1]-a[i]);
        dp[x][1] = max(ss-a[i],dp[x][1]+a[i]);
    }
    ll s1 = 0,s0 = 0;
    rep(i,0,g){
        s1 += dp[i][1];
        s0 += dp[i][0];
    }
    cout << max(s1,s0) << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}