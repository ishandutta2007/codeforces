#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
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
const long long int N = 5e3+20,mod = 1e9+7,inf = 1e18+10,sq = 300,maxm= 700+2;
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
int pw[N],inv[N];
int C[N][N];
inline int c(int r,int n){
    if (r > n) return 0;
    int z = 1;
    repr(i,n,n-r+1) z = 1ll*z*i%mod;
    rep(i,1,r+1) z = 1ll*z*inv[i]%mod;
    return z;
}
inline int s(int k){
    int z = poww(-1,(k&1));
    int ans = 0;
    rep(i,0,k+1){
        ans = mkay(ans,1ll*z*pw[i]*C[i][k]%mod);
        z *= -1;
    }
    return 1ll*ans%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    inv[0] = 0;
    pw[0] = 0;
    rep(i,0,k+1) C[0][i] = 1;
    rep(i,1,k+1){
        rep(j,i,k+1) C[i][j] = mkay(C[i-1][j-1],C[i][j-1]);
    }
    rep(i,1,k+1){
        inv[i] = poww(i,mod-2);
        pw[i] = poww(i,k);
    }
    int ans = 0;
    rep(i,1,k+1){
        ans = mkay(ans,1ll*c(i,n)*s(i)%mod*poww(2,n-i)%mod);
    }
    cout << ans;
    return 0;
}