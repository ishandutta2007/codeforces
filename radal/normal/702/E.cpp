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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
int f[N][35];
ll sm[N][35],mi[N][35];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    rep(i,0,n)
        cin >> f[i][0];
    rep(i,0,n){
        cin >> sm[i][0];
        mi[i][0] = sm[i][0];
    }
    rep(j,1,35){
        rep(i,0,n){
            f[i][j] = f[f[i][j-1]][j-1];
            mi[i][j] = min(mi[i][j-1],mi[f[i][j-1]][j-1]);
            sm[i][j] = sm[i][j-1]+sm[f[i][j-1]][j-1];
        }
    }
    rep(j,0,n){
        ll ans1 = 0,ans2 = inf;
        int cur = j;
        ll kk = k;
        repr(i,34,0){
            if (k >= (1ll << i)){
                k -= (1ll << i);
                ans1 += sm[cur][i];
                ans2 = min(ans2,mi[cur][i]);
                cur = f[cur][i];
            }
        }
        k = kk;
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}