#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 2e5+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
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

map<ll,int> tsu;
ll pr[N],su[N];
int a[N],pw[N],fac[N],inv[N];
int c(int r,int n){
    if (r < 0 || r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
inline void solve(){
    tsu.clear();
    int n;
    pw[0] = 1;
    fac[0] = 1;
    inv[0] = 1;
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
        pr[i] = pr[i-1]+a[i];
        pw[i] = mkay(pw[i-1],pw[i-1]);
        fac[i] = 1ll*fac[i-1]*i%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    su[n+1] = 0;
    repr(i,n,1){
        su[i] = su[i+1]+a[i];
        tsu[su[i]]++;
    }
    if (su[1] == 0){
        cout << pw[n-1]  << endl;
        return;
    }
    ll z = 1;
    rep(i,1,n+1){
        int t = 1;
        while (i < n && pr[i] == pr[i+1]){
            t++;
            i++;
        }
        if (su[i] < pr[i]) break;
        if (tsu[pr[i]] == 0){
            continue;
        }
        if (t == 1){
            if (pr[i] == su[i]){
                continue;
            }
            z = 1ll*(tsu[pr[i]]+1)*z%mod;
            continue;
        }
        if (su[i] != pr[i]){
            int tt = tsu[pr[i]];
            int su = 0;
            rep(j,0,t+1){
                su = mkay(su,1ll*c(j,t)*c(j,tt)%mod);
            }
            z = 1ll*z*su%mod;
            continue;
        }
        z = 1ll*z*pw[t]%mod;
        break;
    }
    cout << z << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}