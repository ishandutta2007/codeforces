#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
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
typedef pair<long double,long double> pld;
const long long int N = 6e5+10,mod = 998244353,inf = 1e9,sq = 700,maxm = 2e5+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline ll poww(ll n,ll k,int m){
    ll c = 1;
    n %= m;
    while (k){
        if (k&1) c = (c*n)%m;
        n = (n*n)%m;
        k >>= 1;
    }
    return c;
}
int a[N],tin[N],tout[N],T;
vector<int> adj[N];
int c[N],ans[N],h[N];
int s[N],f[N];
int par[N][20];
pair<pll,pair<pll,int> > Q[N];
void dfs(int v,int p){
    a[T] = v;
    tin[v] = T;
    par[v][0] = p;
    T++;
    for (int u : adj[v]){
        if (u != p){
            h[u] = h[v]+1;
            dfs(u,v);
        }
    }
    a[T] = v;
    tout[v] = T;
    T++;
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0)
        if (h[v]-h[u] >= (1 << i)) v = par[v][i];
    if (u == v) return v;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}
inline bool cmp(pair<pll,pair<pll,int> > x,pair<pll,pair<pll,int> > y){
    x.X.X /= sq;
    y.X.X /= sq;
    if (x.X.X&1) x.X.Y *= (-1);
    if (y.X.X&1) y.X.Y *= (-1);
    return (x < y);
}
inline void add(int i){
    if (f[c[a[i]]]){
        s[c[a[i]]/sq]--;
        f[c[a[i]]] = 0;
    }
    else{
        s[c[a[i]]/sq]++;
        f[c[a[i]]] = 1;
    }
}
inline int que(int l,int r){
    if (r-l < sq){
        rep(i,l,r)
            if (f[i]) return i;
        return -1;
    }
    int L = l/sq*sq+sq,R = (r-1)/sq*sq;
    while (l < L){
        if (f[l]) return l;
        l++;
    }
    while (r > R){
        r--;
        if (f[r]) return r;
    }
    while (L < R){
        if (s[L/sq])
            rep(i,L,L+sq) if (f[i]) return i;
        L += sq;
    }
    return -1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,1,n+1) cin >> c[i];
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    rep(j,1,20)
        rep(i,2,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    rep(i,0,q){
        int u,v,l,r;
        cin >> u >> v >> l >> r;
        if (tin[v] < tin[u]) swap(u,v);
        if (tout[u] < tin[v]+1)
            Q[i] = {{tout[u],tin[v]+1},{{l,r+1},i}};
        else
            Q[i] = {{tout[v],tout[u]+1},{{l,r+1},i}};
    }
    sort(Q,Q+q,cmp);
    int l = Q[0].X.X,r = Q[0].X.Y;
    rep(i,l,r)
        add(i);
    int u = a[l],v = a[r-1];
    int w = lca(u,v);
    if (u != w && v != w) add(tin[w]);
    ans[Q[0].Y.Y] = que(Q[0].Y.X.X,Q[0].Y.X.Y);
    if (u != w && v != w) add(tin[w]);
    rep(i,1,q){
        int L = Q[i].X.X,R = Q[i].X.Y;
        while (l > L){
            l--;
            add(l);
        }
        while (l < L){
            add(l);
            l++;
        }
        while (r < R){
            add(r);
            r++;
        }
        while (r > R){
            r--;
            add(r);
        }
        u = a[l],v = a[r-1],w = lca(u,v);
        if (u != w && v != w) add(tin[w]);
        ans[Q[i].Y.Y] = que(Q[i].Y.X.X,Q[i].Y.X.Y);
        if (u != w && v != w) add(tin[w]);
    }
    rep(i,0,q) cout << ans[i] << endl;
    return 0;
}