#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 1e5+10,mod = 1e9+7,inf = 1e9+10;
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
int par[N][20],d[N];
ll h[N];
int tin[N],sz[N],T,seg[N*4][2];
vector<int> ve;
vector<pll> adj[N];
void dfs(int v,int p){
    par[v][0] = p;
    ve.pb(v);
    sz[v] = 1;
    tin[v] = T;
    T++;
    for (pll u : adj[v]){
        if (u.X == p) continue;
        d[u.X] = d[v]+1;
        h[u.X] = h[v]+u.Y;
        dfs(u.X,v);
        sz[v] += sz[u.X];
    }
}
inline int lca(int u,int v){
    if (d[u] > d[v]) swap(u,v);
    repr(i,19,0)
        if(d[v]-d[u] >= (1 << i))
            v = par[v][i];
    if (u == v) return u;
    repr(i,19,0)
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    return par[v][0];
}

void upd(int l,int r,int p,int v = 1){
    if (r-l == 1){
        if (seg[v][0] == -1)
            seg[v][0] = seg[v][1] = l;
        else
            seg[v][0] = seg[v][1] = -1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,u);
    else upd(m,r,p,u|1);
    if (seg[u][0] != -1)
        seg[v][0] = seg[u][0];
    else
        seg[v][0] = seg[u|1][0];
    if (seg[u|1][1] != -1)
        seg[v][1] = seg[u|1][1];
    else
        seg[v][1] = seg[u][1];
    return;
}

int que(int l,int r,int s,int e,bool f,int v = 1){
    if (s <= l && r <= e) return seg[v][f];
    if (s >= r || l >= e || s >= e) return -1;
    int m = (l+r) >> 1,u = (v << 1);
    int x;
    if (f){
        x = que(m,r,s,e,f,u|1);
        if (x != -1) return x;
        return que(l,m,s,e,f,u);
    }
    x = que(l,m,s,e,f,u);
    if (x != -1) return x;
    return que(m,r,s,e,f,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(seg,-1,sizeof seg);
    int n;
    cin >> n;
    rep(i,1,n){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(1,0);
    rep(j,1,20){
        rep(i,2,n+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    int cnt = 0;
    ll s = 0;
    int q;
    cin >> q;
    while (q--){
        char c;
        cin >> c;
        if (c == '?'){
            cout << s/2 << endl;
            continue;
        }
        int v;
        cin >> v;
        if (c == '-'){
            cnt--;
            upd(0,n,tin[v]);
            if (cnt <= 1){
                s = 0;
                continue;
            }
            int l = que(0,n,0,tin[v],1);
            if (l == -1) l = que(0,n,0,n,1);
            int u = ve[l];
            int w = lca(u,v);
            s -= (h[v]+h[u]-2*h[w]);
            int r = que(0,n,tin[v],n,0);
            if (r == -1) r = que(0,n,0,n,0);
            u = ve[r];
            w = lca(u,v);
            s -= (h[v]+h[u]-2*h[w]);
            w = lca(ve[l],ve[r]);
            s += (h[ve[l]]+h[ve[r]]-2*h[w]);
            continue;
        }
        cnt++;
        upd(0,n,tin[v]);
        if (cnt == 1){
            s = 0;
            continue;
        }
        int l = que(0,n,0,tin[v],1),r = que(0,n,tin[v]+1,n,0);
        if (l == -1) l = que(0,n,0,n,1);
        if (r == -1) r = que(0,n,0,n,0);
        l = ve[l],r = ve[r];
        int w = lca(l,r);
        s -= (h[l]+h[r]-2*h[w]);
        w = lca(l,v);
        s += (h[l]+h[v]-2*h[w]);
        w = lca(r,v);
        s += (h[r]+h[v]-2*h[w]);
    }
    return 0;
}