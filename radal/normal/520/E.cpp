#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 3e5+20,mod = 1e9+7,inf = 1e9+10;
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
int fac[N],inv[N];
inline int c(int r,int n){
    if (r < 0 || r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,k;
    string s;
    cin >> n >> k >> s;
    int ans = 0,sm = 0;
    fac[0] = inv[0] = 1;
    rep(i,0,n){
        fac[i+1] = 1ll*(i+1)*fac[i]%mod;
        inv[i+1] = poww(fac[i+1],mod-2);
        sm += (s[i]-'0');
    }
    int z = 1;
    rep(i,0,n){
        sm -= (s[n-i-1]-'0');
        ans = mkay(ans,1ll*z*sm%mod*c(k-1,n-i-2)%mod);
        ans = mkay(ans,1ll*z*(s[n-i-1]-'0')%mod*c(k,n-i-1)%mod);
        z = 1ll*z*10%mod;
    }
    cout << ans;
    return 0;
}