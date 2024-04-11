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
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e18+10,sq = 300,maxm= 700+2;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
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
    if (r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
inline int s(int k,int n){
    int z = poww(-1,(k&1));
    int ans = 0;
    rep(i,0,k+1){
        ans = mkay(ans,1ll*z*poww(i,n)*c(i,k)%mod);
        z *= -1;
    }
    return 1ll*inv[k]*ans%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    fac[0] = 1;
    inv[0] = 1;
    rep(i,1,k+1){
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    int sum = 0;
    rep(i,0,n){
        int w;
        cin >> w;
        sum = mkay(sum,w);
    }
    cout << 1ll*sum*mkay(s(k,n),1ll*(n-1)*s(k,n-1)%mod)%mod;
    return 0;
}