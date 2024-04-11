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
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 1e5+10,mod = 1e9+7,inf = 1e9,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int tin[N],tout[N],T;
vector<int> adj[N];
bool gen[N],fl[N];
int cnt[N][2],par[N][20];
int a[N],b[N*2],h[N];
ll out[N],ans;
void dfs(int v,int p){
    tin[v] = T;
    b[T] = v;
    T++;
    par[v][0] = p;
    for(int u : adj[v]){
        if  (u == p) continue;
        h[u] = h[v]+1;
        dfs(u,v);
    }
    tout[v] = T;
    b[T] = v;
    T++;
}
bool cmp(pair<pll,int> x,pair<pll,int> y){
    if (x.X.X/sq != y.X.X/sq) return (x.X.X < y.X.X);
    if (x.X.Y != y.X.Y) return (x.X.Y < y.X.Y);
    return (x.Y < y.Y);
}
inline int lca(int u,int v){
    if (h[u] < h[v]) swap(u,v);
    repr(i,19,0)
        if (h[u]-h[v] >= (1 << i))
            u = par[u][i];
    if (v == u) return v;
    repr(i,19,0)
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    return par[v][0];
}
inline void add(int i){
    fl[b[i]] = !fl[b[i]];
    if (fl[b[i]]){
        cnt[a[b[i]]][gen[b[i]]]++;
        ans += cnt[a[b[i]]][1-gen[b[i]]];
    }
    else{
        cnt[a[b[i]]][gen[b[i]]]--;
        ans -= cnt[a[b[i]]][1-gen[b[i]]];
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> gen[i];
    vector<pll> fi;
    rep(i,1,n+1){
        int x;
        cin >> x;
        fi.pb({x,i});
    }
    sort(fi.begin(),fi.end());
    rep(i,0,n){
        int j = i+1;
        a[fi[i].Y] = j;
        i++;
        while (i < n && fi[i].X == fi[i-1].X) a[fi[i].Y] = j,i++;
        i--;
    }
    rep(i,1,n){
        int u,v;
        cin >> v >> u; 
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1,-1);
    rep(j,1,20){
        rep(i,2,n+1){
            if (h[i] < (1 << j)) continue;
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    int q;
    cin >> q;
    vector<pair<pll,int>> ve;
    ve.reserve(q);
    rep(i,0,q){
        int l,r;
        cin >> l >> r;
        if (tin[l] > tin[r]) swap(l,r);
        if (tin[r]+1 > tout[l]) ve.pb({{tout[l],tin[r]+1},i});
        else ve.pb({{tout[r],tout[l]+1},i});
    }
    sort(ve.begin(),ve.end(),cmp);
    int l = ve[0].X.X,r = ve[0].X.Y;
    rep(i,l,r){
        add(i);
        //debug(b[i]);
    }
    out[ve[0].Y] = ans;
    if (!((tin[b[l]] <= tin[b[r-1]] && tout[b[l]] >= tout[b[r-1]]) || (tin[b[l]] >= tin[b[r-1]] && tout[b[l]] <= tout[b[r-1]]))){
        int w = lca(b[l],b[r-1]);
        out[ve[0].Y] += cnt[a[w]][1-gen[w]];
    }
    rep(i,1,q){
        int L = ve[i].X.X,R = ve[i].X.Y;
        while (l < L){
            add(l);
            l++;
        }
        while (l > L){
            l--;
            add(l);
        }
        while (r < R){
            add(r);
            r++;
        }
        while (r > R){
            r--;
            add(r);
        }
        out[ve[i].Y] = ans;
        if (!((tin[b[l]] <= tin[b[r-1]] && tout[b[l]] >= tout[b[r-1]]) || (tin[b[l]] >= tin[b[r-1]] && tout[b[l]] <= tout[b[r-1]]))){
            int w = lca(b[l],b[r-1]);
            out[ve[i].Y] += cnt[a[w]][1-gen[w]];
        }
    }
    rep(i,0,q) cout << out[i] << endl;
    return 0;
}