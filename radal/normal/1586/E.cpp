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
const int N = 3e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
vector<int> G[N];
vector<pll > adj[N];
bool vis[N],e[N];
int T,tin[N],tout[N],par[N];
vector<int> ve[N];
int f,r;
void pre(int v){
    tin[v] = T;
    T++;
    vis[v] = 1;
    for(int u : G[v]){
        if (vis[u]) continue;
        adj[v].pb({u,r});
        adj[u].pb({v,r});
        r++;
        par[u] = v;
        pre(u);
    }
    tout[v] = T;
    T++;
}
void que(int v,int u,int j){
    ve[j].pb(v);
    if (v == u) return;
    if (tin[v] < tin[u] && tout[v] > tout[u]){
        for (pll w : adj[v]){
            if (w.X == par[v] || tin[w.X] > tin[u] || tout[w.X] < tout[u]) continue;
            e[w.Y] = 1-e[w.Y];
            que(w.X,u,j);
            return;
        }
    }
    else{
        for (pll w : adj[v]){
            if (w.X == par[v]){
                e[w.Y] = 1-e[w.Y];
                que(w.X,u,j);
                return;
            }
        }
    }
}
void dfs(int v){
    int cnt = 0,w = 0;
    for (auto u : adj[v]){
        if (u.X != par[v]){
            dfs(u.X);
            if (e[u.Y]) cnt++;
        }
        else if (e[u.Y]) w = 1;
    }
    f += (cnt+1)/2;
    if ((cnt&1) && w){
        f--;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    T = 1;
    par[1] = -1;
    pre(1);
    int q;
    cin >> q;
    rep(i,0,q){
        int u,v;
        cin >> u >> v;
        que(u,v,i);
    }
    dfs(1);
    if (f){
        cout << "NO" << endl << f << endl;
        return 0;
    }
    cout << "YES" << endl;
    rep(i,0,q){
        cout << ve[i].size() << endl;
        for (int u : ve[i]) cout << u << ' ';
        cout << endl;
    }
}