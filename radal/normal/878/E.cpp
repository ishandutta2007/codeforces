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
int a[N],pw[N],inv[N],ps[N];
int n,q,jump[20][N],cal[20][N];;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    pw[0] = inv[0] = 1;
    rep(i,1,n+1){
        cin >> a[i];
        pw[i] = mkay(pw[i-1],pw[i-1]);
        inv[i] = poww(pw[i],mod-2);
        ps[i] = mkay(1ll*pw[i]*a[i]%mod,ps[i-1]);
        ll s = 0;
        repr(j,i,1){
            s = a[j]+2*s;
            if (s <= 0){
                jump[0][i] = j-1;
                break;
            }
            if (s >= inf){
                jump[0][i] = 0;
                break;
            }
            if (j < i && j-jump[0][j] > 30){
                jump[0][i] = 0;
                break;
            }
        }
        cal[0][i] = 1ll*mkay(ps[i],-ps[jump[0][i]])*inv[jump[0][i]]%mod;
    }
    rep(j,1,20){
        rep(i,1,n+1){
            jump[j][i] = jump[j-1][jump[j-1][i]];
            cal[j][i] = mkay(cal[j-1][i],cal[j-1][jump[j-1][i]]);
        }
    }
    while (q--){
        int l,r;
        cin >> l >> r;
        int ans = 0;
        repr(i,19,0){
            if (l <= jump[i][r]){
                ans = mkay(ans,cal[i][r]);
                r = jump[i][r];
            }
        }
        ans = mkay(ans,1ll*mkay(ps[r],-ps[l-1])*inv[l]%mod);
        cout << ans << endl;
    }
    return 0;
}