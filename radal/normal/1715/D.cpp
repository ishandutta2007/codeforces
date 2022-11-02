#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
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
        k /= 2;
    } 
    return z; 
}
vector<int> adj[N][30];
int ans[N][30],out[N];
vector<pair<pll,int>> e;
void rlx1(int v,int j){
    if (ans[v][j] != -1) return;
    ans[v][j] = 1;
    out[v] |= (1 << j);
}
void rlx0(int v,int j){
    if (ans[v][j] != -1) return;
    ans[v][j] = 0;
    for (int u : adj[v][j]) rlx1(u,j);
}
void solve(){
    memset(ans,-1,sizeof ans);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        e.pb({{u,v},w});
        rep(j,0,30){
            if (w&(1 << j)){
                if (u != v){
                    adj[u][j].pb(v);
                    adj[v][j].pb(u);
                }
                else{
                    rlx1(u,j);
                }
            }
        }
    }
    for (auto p : e) if (p.X.X == p.X.Y){
        rep(j,0,30){
            if (p.Y&(1 << j)) continue;
            rlx0(p.X.X,j);
        }
    }
    rep(j,0,30){
        for (auto p : e){
            if (p.Y&(1 << j)) continue;
            rlx0(p.X.X,j);
            rlx0(p.X.Y,j);
        }
        rep(i,1,n+1){
            if (ans[i][j] == -1){
                rlx0(i,j);
            }
        }
    }
    rep(i,1,n+1) cout << out[i] << ' ';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
//    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}