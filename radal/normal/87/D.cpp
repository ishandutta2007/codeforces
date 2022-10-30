#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
pll oldcomp[N];
ll ans[N],par[N];
pair<pll,pll> edge[N];
vector<int> comp[N];
vector<int> adj[N];
int n,vis[N],child[N],b[N];
int getpar(int x){
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}
void merge(int u,int v,int w){
    if (getpar(u) == getpar(v)) return;
    int szv = comp[par[v]].size(),szu = comp[par[u]].size();
    //if(oldcomp[v].Y != w){
        oldcomp[v].X = szv;
        oldcomp[v].Y = w;
   // }
    //if (oldcomp[u].Y != w){
        oldcomp[u].X = szu;
        oldcomp[u].Y = w;
   // }
    if (szu < szv) swap(v,u);
    u = par[u];
    v = par[v];
    int sz = comp[v].size();
    while (sz){
        sz--;
        comp[u].pb(comp[v][sz]);
        par[comp[v][sz]] = u;
        comp[v].pop_back();
    }
    return;
}
void dfs(int v,int w,int p){
    child[v] = 0;
    vis[v] = w;
    int sz = adj[v].size();
    for (int u : adj[v]){
        if (u != p){
            dfs(u,w,v);
            child[v] += child[u];
        }
    }
    child[v]+=comp[v].size();
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n){
        cin >> edge[i].Y.X >> edge[i].Y.Y >> edge[i].X.X;
        edge[i].X.Y = i;
        comp[i].pb(i);
        par[i] = i;
    }
    comp[n].pb(n);
    par[n] = n;
    sort(edge+1,edge+n);
    rep(i,1,n){
        int w = edge[i].X.X;
        int ind = i;
        while (ind < n && edge[ind].X.X == w){
            int v = edge[ind].Y.Y,u = edge[ind].Y.X;
            getpar(v);
            getpar(u);
            if (b[par[v]] != w){
                adj[par[v]].clear();
                b[par[v]] = w;
            }
            if (b[par[u]] != w){
                adj[par[u]].clear();
                b[par[u]] = w;
            }
            adj[par[v]].pb(par[u]);
            adj[par[u]].pb(par[v]);
            ind++;
        }
        rep(j,i,ind){
            if (vis[par[edge[j].Y.Y]] != w){
                dfs(par[edge[j].Y.Y],w,-1);
            }
            int v = edge[j].Y.X, u = edge[j].Y.Y;
            ans[edge[j].X.Y] = min(child[par[v]],child[par[u]]);
        }
        ind = i;
        while (ind  < n && edge[ind].X.X == w){
            merge(edge[ind].Y.X,edge[ind].Y.Y,w);
            ind++;
        }
        rep(j,i,ind){
            int v = edge[j].Y.Y;
            getpar(v);
            ans[edge[j].X.Y] *= (comp[par[v]].size() - ans[edge[j].X.Y]);
        }
        i = ind-1;
    }
    vector<int> ve;
    ll mx = 0;
    rep (i,1,n){
        if (ans[i] > mx){
            mx = ans[i];
            ve.clear();
            ve.pb(i);
        }
        else if (ans[i] == mx){
            ve.pb(i);
        }
    }
    cout << 2*mx << ' ' << ve.size() << endl;
    for(int u : ve) cout << u << endl;
    return 0;
}