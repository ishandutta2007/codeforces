#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<long double,long double> pld;
const long long int N = 1e5+10,mod = 1e9+7,inf = 1e9,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int fac[N],inv[N],dp[N],vis[N],F,out[N];
vector<int> tajz[N];
void calc(int n){
    if (vis[n] == F) return;
    vis[n] = F;
    if (F > n){
        dp[n] = 0;
        return;
    }
    if (F == n){
        dp[n] = 1;
        return;
    }
    int ans = 1ll*fac[n-1]*inv[F-1]%mod*inv[n-F]%mod;
    for (int u : tajz[n]){
        calc(n/u);
        ans = mkay(ans,-dp[n/u]);
    }
    dp[n] = ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    fac[0] = inv[0] = 1;
    rep(i,1,N-5){
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    rep(i,2,N-5)
        for (int j = 1; j*i < N-5; j++)
            tajz[i*j].pb(i);
    vector<pair<pll,int> > ve;
    rep(i,0,q){
        int n,f;
        cin >> n >> f;
        ve.pb({{f,n},i});
    }
    sort(ve.begin(),ve.end());
    rep(i,0,q){
        int n = ve[i].X.Y,f = ve[i].X.X;
        F = f;
        calc(n);
        out[ve[i].Y] = dp[n];
    }
    rep(i,0,q) cout << out[i] << endl;
}