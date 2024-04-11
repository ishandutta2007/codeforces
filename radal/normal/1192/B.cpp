#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 1e9+7,inf = 4e18+10,sq = 400;
inline int mkay(int a,ll b){
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
ll h[N];
vector<pair<int,ll> > adj[N];
ll W;
int n,q,T,tin[N],tout[N],sz,par[N];
ll seg[N*4][4][4],lz[N*4];
vector<ll> ve;
pair<pll,ll> e[N];
void dfs(int v,int p){
    tin[v] = T;
    par[v] = p;
    ve.pb(v);
    T++;
    for (auto u : adj[v]){
        if (u.X == p) continue;
        h[u.X] = h[v]+u.Y;
        dfs(u.X,v);
        ve.pb(v);
        T++;
    }
    tout[v] = T;
}
inline void pass(int v,ll x){
    seg[v][0][1] += x;
    seg[v][1][2] -= 2*x;
    seg[v][2][3] += x;
    seg[v][0][2] -= x;
    seg[v][1][3] -= x;
    lz[v] += x;
    return;
}
void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v][0][1] = ve[l];
        seg[v][1][2] = -2*ve[l];
        seg[v][2][3] = ve[l];
        seg[v][0][2] = -ve[l];
        seg[v][1][3] = -ve[l];
        seg[v][0][3] = 0;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    rep(i,0,4){
        rep(j,i,4){
            seg[v][i][j] = -inf;
            rep(k,i,j+1){
                seg[v][i][j] = max(seg[v][i][j],seg[u][i][k]+seg[u|1][k][j]);
            }
        }
    }
}

void upd(int l,int r,int s,int e,ll x,int v = 1){
    if (s <= l && r <= e){
        pass(v,x);
        return;
    }
    if (s >= r || l >= e)  return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        pass(u,lz[v]);
        pass(u|1,lz[v]);
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    rep(i,0,4){
        rep(j,i,4){
            seg[v][i][j] = -inf;
            rep(k,i,j+1){
                seg[v][i][j] = max(seg[v][i][j],seg[u][i][k]+seg[u|1][k][j]);
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> W;
    rep(i,0,n-1){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        e[i] = {{u,v},w};
    }
    dfs(1,0);
    rep(i,0,n-1) if (par[e[i].X.X] == e[i].X.Y) swap(e[i].X.X,e[i].X.Y);
    sz = ve.size();
    rep(i,0,sz)
        ve[i] = h[ve[i]];
    build (0,sz);
    ll lst = 0;
    while (q--){
        int d;
        ll E;
        cin >> d >> E;
        E = (E+lst)%W;
        d = (d+lst)%(n-1);
        upd(0,sz,tin[e[d].X.Y],tout[e[d].X.Y],E-e[d].Y);
        e[d].Y = E;
        lst = seg[1][0][3];
        cout << lst << endl;
    }
}