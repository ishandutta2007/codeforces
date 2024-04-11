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
const long long int N = 5e3+20,mod = 998244353 ,inf = 1e9+10,maxm= (1 << 21);
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
int inv[N],fac[N],rev[N];
int s[N][N];
inline int c(int r,int n){
    if (r > n) return 0;
    int g = 1;
    repr(i,n,n-r+1){
        g = 1ll*g*i%mod;
    }
    return g;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    fac[0] = 1;
    rev[0] = 1;
    rep(i,0,k+1){
        inv[i] = poww(poww(m,i),mod-2);
        if (i){
            fac[i] = 1ll*i*fac[i-1]%mod;
            rev[i] = poww(i,mod-2);
        }
    }
    s[0][0] = 1;
    rep(i,1,k+1){
        rep(j,1,k+1){
            s[i][j] = mkay(1ll*s[i-1][j-1]*(n-i+1)%mod,1ll*s[i][j-1]*i%mod);
        }
    }
    int ans = 0;
    rep(i,1,k+1){
        ans = mkay(ans,1ll*inv[i]*s[i][k]%mod);
    }
    cout << ans;

}