#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 4e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
int par[N][20],n,h[N];
vector<int> adj[N],be[N],cr[N];
vector<pll> Q[N];
int low[N][20],tin[N],tout[N],T;
int ans[N],fen[N],perv[N];

inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0) if ((h[v]-h[u])&(1 << i)) v = par[v][i];
    if (u == v) return u;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}

inline int lift(int v,int k){
    while (k){
        int i = __builtin_ctz((k&(-k)));
        v = low[v][i];
        k -= (1 << i);
    }
    return v;
}

void upd(int l){
    for (; l < 2*n+1; l |= (l+1))
        fen[l]++;
}
int que(int l,int r){
    int ans = 0;
    r--;
    for (; r >= 0; r = (r&(r+1))-1)
        ans += fen[r];
    l--;
    for (; l >= 0; l = (l&(l+1))-1)
        ans -= fen[l];
    return ans;
}

void dfs2(int v){
    for (pll p : Q[v]) if (tin[p.Y] < tin[v]) perv[p.X] = que(tin[p.Y],tout[p.Y]);
    for (int u : cr[v]) upd(tin[u]);
    for (int u : adj[v])
        dfs2(u);
    for (pll p : Q[v]){
        if (tin[p.Y] < tin[v] && perv[p.X] != que(tin[p.Y],tout[p.Y])){
            ans[p.X]--;
        }
    }
}
void dfs(int v){
    low[v][0] = v;
    tin[v] = T;
    T++;
    for (int u : adj[v]){
        dfs(u);
        if (h[low[u][0]] < h[low[v][0]]) low[v][0] = low[u][0];
    }
    for (int u : be[v]) if (h[u] < h[low[v][0]]) low[v][0] = u;
    tout[v] = T;
    T++;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,2,n+1){
        cin >> par[i][0];
        h[i] = h[par[i][0]]+1;
        adj[par[i][0]].pb(i);
    }
    rep(j,1,20){
        rep(i,2,n+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    int m;
    cin >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        if (h[u] > h[v]) swap(u,v);
        int w = lca(u,v);
        if (w == u){
            be[v].pb(u);
            continue;
        }
        be[v].pb(w);
        be[u].pb(w);
        cr[v].pb(u);
        cr[u].pb(v);
    }
    dfs(1);
    rep(j,1,20){
        rep(i,1,n+1){
            low[i][j] = low[low[i][j-1]][j-1];
        }
    }
    int q;
    cin >> q;
    rep(i,0,q){
        int u,v,w;
        cin >> u >> v;
        if (h[u] > h[v]) swap(u,v);
        w = lca(u,v);
        if (h[low[v][19]] > h[w] || h[low[u][19]] > h[w]){
            ans[i] = -1;
            continue;
        }
        if (w == u){
            int cur = v;
            repr(j,19,0){
                if (low[cur][j] != cur && (!j || h[low[cur][j]] != h[low[cur][j-1]]) && h[low[cur][j]] > h[w]){
                    ans[i] += (1 << j);
                    cur = low[cur][j];
                }
            }
            ans[i]++;
            continue;
        }
        int cur = v,a,b;
        repr(j,19,0){
            if (low[cur][j] != cur && (!j || h[low[cur][j]] != h[low[cur][j-1]]) &&  h[low[cur][j]] > h[w]){
                ans[i] += (1 << j);
                cur = low[cur][j];
            }
        }
        ans[i]++;
        a = ans[i];
        cur = u;
        repr(j,19,0){
            if (low[cur][j] != cur && (!j || h[low[cur][j]] != h[low[cur][j-1]]) && h[low[cur][j]] > h[w]){
                ans[i] += (1 << j); 
                cur = low[cur][j];
            }
        }
        ans[i]++;
        b = ans[i]-a;
        int x = lift(v,a-1);
        int y = lift(u,b-1);
        Q[x].pb({i,y});
        Q[y].pb({i,x});
    }
    dfs2(1);
    rep(i,0,q) cout << ans[i] << endl;
}