#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 1e3+10,mod = 998244353,inf = 1e9+10,sq = 700;
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
        k /= 2;
    } 
    return z; 
}
pll par[N];
int a[N][N];
int getpar(int v){
    if (par[v].X == v) return v;
    int p = getpar(par[v].X);
    par[v] = {p,par[par[v].X].Y^par[v].Y};
    return p;
}
void solve(){
    int n;
    cin >> n;
    rep(i,0,n){
        rep(j,0,n){
            cin >> a[i][j];
        }
        par[i] = {i,0};
    }
    rep(i,0,n){
        rep(j,i+1,n){
            if (a[i][j] == a[j][i]) continue;
            if (getpar(i) == getpar(j)) continue;
            if (a[i][j] > a[j][i]){
                int d = par[i].Y^par[j].Y^1;
                par[par[i].X] = {par[j].X,d};
                continue;
            }
            else{
                int d = par[i].Y^par[j].Y;
                par[par[i].X] = {par[j].X,d};
                continue;
            }
        }
    }
    rep(i,0,n){
        getpar(i);
        if (!par[i].Y) continue;
        rep(j,0,n) swap(a[i][j],a[j][i]);
    }
    rep(i,0,n){
        rep(j,0,n) cout << a[i][j] << ' ';
        cout << endl;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}