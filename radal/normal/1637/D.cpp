#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e2+20,mod = 1e9+7,inf = 1e9+10,maxm= (1 << 21);
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
int a[N],b[N];
bitset<N*N> dp;
inline void solve(){
    int n;
    cin >> n;
    int ans = 0,s = 0;
    rep(i,0,n){
        cin >> a[i];
        ans += a[i]*a[i]*(n-2);
    }
    rep(i,0,n){
        cin >> b[i];
        ans += b[i]*b[i]*(n-2);
        if (b[i] > a[i]) swap(a[i],b[i]);
        s += a[i]+b[i];
    }
    if (n == 1){
        cout << 0 << endl;
        return;
    }
    dp.reset();
    dp[0] = 1;
    rep(i,0,n){
        dp = ((dp << a[i]) | (dp << b[i]));
    }
    int ans2 = inf;
    rep(i,0,s) if (dp[i]) ans2 = min(ans2,i*i+(s-i)*(s-i));
    cout << ans2+ans <<endl;
    return;
    /*rep(i,0,s){
        if (s-i < a[0] || i < b[0]){
            dp[0][i] = inf;
            continue;
        }
        dp[0][i] = b[0]*(i-b[0])+a[0]*(s-i-a[0]);
        if (i < a[0])
            continue;
        dp[0][i] = min(a[0]*(i-a[0])+b[0]*(s-i-b[0]),dp[0][i]);
    }
    int mi = inf;
    rep(i,1,n){
        rep(j,0,s){
            if (j < b[i] || s-j < a[i]){
                dp[i][j] = inf;
                continue;
            }
            dp[i][j] = b[i]*(j-b[i])+a[i]*(s-j-a[i])+dp[i-1][j];
            if (j == 5) debug(dp[i][j]);
            if (j < a[i]){
                if (i == n-1) mi = min(mi,dp[i][j]);
                continue;
            }
            dp[i][j] = min(dp[i][j],a[i]*(j-b[i])+b[i]*(s-j-a[i])+dp[i-1][j-b[i]+a[i]]);
            if (i == n-1){
                mi = min(mi,dp[i][j]);
                if (mi == 12) debug(j);
            }
        }
    }
    debug(mi);
    cout << ans+mi << endl;*/
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}