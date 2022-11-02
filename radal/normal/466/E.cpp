#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int h[N],k;
int par[N][20],pa[N];
vector<int> adj[N];
pll t2[N],q[N];
bool vis[N];
void dfs(int v,int p){
    par[v][0] = p;
    vis[v] = 1;
    for (int u : adj[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        dfs(u,v);
    }
}
int getpar(int u){
    if (pa[u] == u) return u;
    return pa[u] = getpar(pa[u]);
}
int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if (h[v]-h[u] < (1 << i)) continue;
        v = par[v][i];
    }
    if (v == u) return v;
    repr(i,19,0){
        if (par[u][i] == par[v][i]) continue;
        u = par[u][i];
        v =  par[v][i];
    }
    return par[v][0];
}
int main(){
    int n;
    cin >> n >> k;
    rep(i,1,n+1) pa[i] = i;
    int z = 1,ind = 0;
    rep(i,0,k){
        int t;
        cin >> t;
        if (t == 1){
            int x,y;
            cin >> x >> y;
            par[x][0] = y;
            pa[x] = pa[y];
            adj[x].pb(y);
            adj[y].pb(x);
        }
        if (t == 2){
            int y;
            cin >> y;
            t2[z] = {y,getpar(y)};
            z++;
        }
        if (t == 3){
            int x,y;
            cin >> x >>y;
            q[ind] = {x,y};
            ind++;
        }
    }
    rep(i,1,n+1){
        if (vis[i]) continue;
        dfs(getpar(i),-1);
    }
    rep(j,1,20){
        rep(i,1,n+1){
            if (h[i] < (1 << j)) continue;
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    rep(i,0,ind){
        pll p = t2[q[i].Y];
        if (getpar(p.X) != getpar(q[i].X)){
            cout << "NO" << endl;
            continue;
        }
        if (lca(p.X,q[i].X) == q[i].X && lca(p.Y,q[i].X) == p.Y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}