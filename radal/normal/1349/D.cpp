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
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 998244353,inf = 1e9,sq = 400;
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
int inv[N],dp[N],a[N],suf[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,s = 0;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        s += a[i];
    }
    rep(i,1,s+1)
        inv[i] = poww(i,mod-2);
    rep(i,s+1,n+1) 
        inv[i] = poww(i,mod-2);
    dp[0] = n-1;
    rep(i,1,s){
        int p1 = 1ll*i*inv[s]%mod;
        int p2 = 1ll*(s-i)*inv[s]%mod*(n-2)%mod*inv[n-1]%mod;
        int p3 = mkay(1,1ll*dp[i-1]*inv[s]%mod*i%mod);
        dp[i] = 1ll*p3*poww(mkay(1,-mkay(p1,p2)),mod-2)%mod;
    }
    repr(i,s-1,0) suf[i] = mkay(suf[i+1],dp[i]);
    int c = suf[0];
    int sum = 0;
    rep(i,0,n)
        sum = mkay(sum,suf[a[i]]);
    cout << 1ll * inv[n]*mkay(sum,-(1ll*c*(n-1)%mod))%mod;
}