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
const long long int N = 1e6+20,mod = 998244353 ,inf = 1e9+10,maxm= (1 << 21);
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
int pw[N];
int fac[N],inv[N];
inline int c(int r,int n){
    if (r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pw[0] = fac[0] = inv[0] = 1;
    rep(i,1,n+1){
        pw[i] = 1ll*3*pw[i-1]%mod;
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    int ans = 0,z = 1;
    rep(i,0,n){
        z *= -1;
        int g = c(i,n)*z;
        int x = mkay(poww(mkay(1,-pw[i]),n),-poww(-pw[i],n));
        ans = mkay(ans,1ll*x*g%mod);
    }
    ans = 1ll*3*ans%mod;
    z = 1;
    rep(i,1,n+1){
        ans = mkay(ans,1ll*z*c(i,n)*2%mod*pw[i]%mod*poww(pw[n],n-i)%mod);
        z *= -1;
    }
    cout << ans;
}