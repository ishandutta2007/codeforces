#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
constexpr ll N = 3e5+20,mod = 1e9+7,inf = 1e18+10,maxm = 1e6;
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
ll fac[N];
inline void solve(){
    fac[0] = 1;
    rep(i,1,16) fac[i] = fac[i-1]*i;
    ll n; cin >> n;
    int y = (1 << 16);
    int ans = __builtin_popcountll(n);
    rep(i,0,y){
        ll s = 0;
        rep(j,0,16){
            if (i&(1 << j)){
                s += fac[j];
                if (s > n) break;
            }
        }
        if (s > n) continue;
        ans = min(ans,__builtin_popcountll(i)+__builtin_popcountll(n-s));
    }
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}