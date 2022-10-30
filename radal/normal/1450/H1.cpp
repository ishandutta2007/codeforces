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
const long long int N = 3e5+20,mod = 998244353 ,inf = 1e9,sq = 400;
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
int fac[N],inv[N],pw[N];
int pre[N],suf[N];
inline int c(int r,int n){
    if (r > n) return 0;
    return (1ll*fac[n]*inv[r]%mod)*inv[n-r]%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    string s;
    cin >> n >> m >> s;
    int o = 0, e = 0,t = 0,B = 0,q = 0;
    fac[0] = 1;
    inv[0] = 1;
    pw[0] = 1;
    rep(i,0,n){
        fac[i+1] = 1ll*(i+1)*fac[i]%mod;
        inv[i+1] = poww(fac[i+1],mod-2);
        pw[i+1] = pw[i]*2%mod;
        if (s[i] == 'w') continue;
        if (s[i] == 'b') B++;
        if (s[i] == '?') q++;
        if (i&1){
            if (s[i] == 'b') t--;
            else o++;
        }
        else{
            if (s[i] == 'b') t++;
            else e++;
        }
    }
    if(!o){
        int ans = 0;
        rep(i,0,e+1){
            if ((i+B)&1) continue;
            ans = mkay(1ll*c(i,e)*abs(t+i)%mod,ans);
        }
        cout << 1ll*ans*poww(poww(2,q),mod-2)%mod;
        return 0;
    }
    int sm0 = 2,sm1 = o*2;
    pre[0] = 2;
    pre[1] = o*2;
    rep(i,2,n+1){
        int C = c(i,o);
        if (i&1){
            sm1 = mkay(sm1,2*C%mod);
            pre[i] = mkay(pre[i-2],sm1);
        }
        else{
            sm0 = mkay(sm0,2*C%mod);
            pre[i] = mkay(pre[i-2],sm0);
        }
    }
    suf[o] = 2;
    suf[o-1] = 2*o;
    if (o&1){
        sm0 = o*2;
        sm1 = 2;
    }
    else{
        sm0 = 2;
        sm1 = o*2;
    }
    repr(i,o-2,0){
        int C = c(i,o);
        if (i&1){
            sm1 = mkay(sm1,2*C%mod);
            suf[i] = mkay(suf[i+2],sm1);
        }
        else{
            sm0 = mkay(sm0,2*C%mod);
            suf[i] = mkay(suf[i+2],sm0);
        }
    }
    int ans = 0;
    rep(x,0,e+1){
        int C = c(x,e);
        if (t+x <= 1){
            int g;
            if ((x+t)&1)
                g = mkay(suf[1],1ll*(-t-x-1)*pw[o-1]%mod);
            else
                g = mkay(suf[0],1ll*(-t-x-2)*pw[o-1]%mod);
            ans = mkay(ans,1ll*g*C%mod);
            continue;
        }
        int g = mkay(pre[t+x-2],suf[t+x+2]);
      //  g = mkay(g,pw[o-1]
        ans = mkay(ans,1ll*g*C%mod);
    }
    cout << 1ll*ans*poww(poww(2,q),mod-2)%mod;
}