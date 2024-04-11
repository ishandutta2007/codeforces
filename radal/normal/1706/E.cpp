#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10,sq = 500;
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
vector<int> adj[N],ve;
int pr[N],tin[N],par[N][20],T,sp[N][20][2],h[N];
int getpar(int v){
    if (v == pr[v]) return v;
    return pr[v] = getpar(pr[v]);
}
void dfs(int v){
    tin[v] = T;
    ve.pb(v);
    T++;
    for (int u : adj[v]){
        h[u] = h[v]+1;
        par[u][0] = v;
        dfs(u);
    }
}
int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if ((h[v]-h[u]) >= (1 << i)) v = par[v][i];
    }
    if (v == u) return u;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}
void solve(){
    ve.clear();
    T = 0;
    int n,m,q;
    cin >> n >> m >> q;
    rep(i,1,n+m+1){
        pr[i] = i;
        adj[i].clear();
        par[i][0] = 0;
    }
    int lst = -1;
    rep(i,1,m+1){
        int u,v;
        cin >> u >> v;
        u = getpar(u);
        v = getpar(v);
        if (u == v) continue;
        pr[u] = i+n;
        pr[v] = i+n;
        adj[i+n].pb(u);
        adj[i+n].pb(v);
        lst = i+n;
    }
    h[lst] = 0;
    dfs(lst);
    rep(j,1,20){
        rep(i,1,lst){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    rep(i,1,n+1){
        sp[i][0][0] = sp[i][0][1] = tin[i];
    }
    rep(j,1,20){
        rep(i,(1 << j),n+1){
            sp[i][j][0] = min(sp[i][j-1][0],sp[i-(1 << (j-1))][j-1][0]);
            sp[i][j][1] = max(sp[i][j-1][1],sp[i-(1 << (j-1))][j-1][1]);
        }
    }
    while (q--){
        int l,r;
        cin >> l >> r;
        if (r == l){
            cout << 0 << ' ';
            continue;
        }
        int mx = 0,mi = inf,cur = r;
        repr(i,19,0){
            if (cur-(1 << i)+1 >= l){
                mx = max(mx,sp[cur][i][1]);
                mi = min(mi,sp[cur][i][0]);
                cur -= (1 << i);
            }
            if (cur < l) break;
        }
        cout << lca(ve[mx],ve[mi])-n << ' ';
    }
    cout << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}