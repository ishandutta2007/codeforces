#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 5e5+10,mod = 998244353,inf = 1e9+10;
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
int n,a[N],fac[N],inv[N];
inline int nxt(int i){
    if (i < n) return i+1;
    return 1;
}
inline int c(int r,int n){
    if (r > n || n < 0) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int k,cnt = 0;
    cin >> n >> k;
    fac[0] = inv[0] = 1;
    rep(i,1,n+1){
        cin >> a[i];
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    rep(i,1,n+1) if (a[i] == a[nxt(i)]) cnt++;
    n -= cnt;
    int ans = poww(k,n);
    rep(i,0,n+1){
        if (2*i > n) break;
        int cal = 1ll*c(i,n)*c(i,n-i)%mod*poww(k-2,n-2*i)%mod;
        ans = mkay(ans,-cal);
    }
    ans = 1ll*ans*inv[2]%mod;
    ans = 1ll*ans*poww(k,cnt)%mod;
    cout << ans;
    return 0;
}