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
constexpr int N = 1e5+10,mod = 777777777,inf = 1e9+10;
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
bool good[3][3];
int seg[N*4][3][3];

void build(int l,int r,int v = 1){
    if (r-l == 1){
        rep(i,0,3) seg[v][i][i] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    rep(i,0,3){
        rep(j,0,3){
            rep(k,0,3){
                if (!good[j][k]) continue;
                rep(g,0,3){
                    seg[v][i][g] = mkay(seg[v][i][g],1ll*seg[u][i][j]*seg[u|1][k][g]%mod);
                }
            }
        }
    }
}

void upd(int l,int r,int p,int x,int v = 1){
    if (r-l == 1){
        if (!x){
            rep(i,0,3) seg[v][i][i] = 1;
            return;
        }
        rep(i,0,3) seg[v][i][i] = 0;
        seg[v][x-1][x-1] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    rep(i,0,3) rep(j,0,3) seg[v][i][j] = 0;
    rep(i,0,3){
        rep(j,0,3){
            rep(k,0,3){
                if (!good[j][k]) continue;
                rep(g,0,3){
                    seg[v][i][g] = mkay(seg[v][i][g],1ll*seg[u][i][j]*seg[u|1][k][g]%mod);
                }
            }
        }
    }
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,0,3)
        rep(j,0,3)
            cin >> good[i][j];
    build(0,n);
    while (q--){
        int v,t;
        cin >> v >> t;
        v--;
        upd(0,n,v,t);
        int ans = 0;
        rep(i,0,3){
            rep(j,0,3){
                ans = mkay(ans,seg[1][i][j]);
            }
        }
        cout << ans << endl;
    }
}