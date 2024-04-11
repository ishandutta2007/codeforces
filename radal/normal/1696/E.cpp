#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10;
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
int fac[N],inv[N],a[N];
inline int c(int r,int n){
    if (r > n || r < 0) return 0;
    return 1ll*fac[n]*inv[n-r]%mod*inv[r]%mod;
}
inline void solve(){
    fac[0] = inv[0] = 1;
    rep(i,1,N){
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    int n,ans = 0;
    cin >> n;
    n++;
    rep(i,0,n){
        cin >> a[i];
        ans = mkay(ans,c(i+1,a[i]+i));
    }
    cout << ans << endl;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int T = 1;
   //cin >> T;
   while (T--){
       solve();
   }
}