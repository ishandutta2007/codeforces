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
const long long int N=5e4+20,mod = 1e9,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int n,m;
ll G,S;
pair<pll,pll> e[N];
int par[N];
set<pll> adj[N];
bool vis[N];
int mat[400][400];
ll mx = 0,x,y;
multiset<ll> st;
int getpar(int v){
    if (par[v] == v) return v;
    return par[v] = getpar(par[v]);
}
inline bool merge(int u,int v){
    if (getpar(u) == getpar(v)) return 0;
    par[par[u]] = par[v];
    return 1;
}
bool dfs(int v,int p){
    vis[v] = 1;
    for (pll u : adj[v]){
        if (u.X == p) continue;
        if (vis[u.X]){
            mx = u.Y;
            x = v;
            y = u.X;
            return 1;
        }
        if (dfs(u.X,v)){
            if (mx < u.Y){
                mx = u.Y;
                x = v;
                y = u.X;
            }
            return 1;
        }
    }
    return 0;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    cin >> n >> m >> G >> S;
    rep(i,1,n+1) par[i] = i;
    rep(i,0,m) cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X.X >> e[i].X.Y;
    sort(e,e+m);
    ll val = inf;
    int cnt = n;
    rep(i,0,m){
        int u = e[i].Y.X,v = e[i].Y.Y;
        if (u == v) continue;
        if (merge(u,v)){
            cnt--;
            adj[u].insert({v,e[i].X.Y});
            adj[v].insert({u,e[i].X.Y});
            mat[u][v] = e[i].X.Y;
            mat[v][u] = mat[u][v];
            st.insert(-e[i].X.Y);
        }
        else{
            adj[u].insert({v,e[i].X.Y});
            adj[v].insert({u,e[i].X.Y});
            if (mat[u][v]){
                if (mat[u][v] <= e[i].X.Y){
                    adj[u].erase({v,e[i].X.Y});
                    adj[v].erase({u,e[i].X.Y});
                    continue;
                }
                adj[u].erase({v,mat[u][v]});
                adj[v].erase({u,mat[u][v]});
                auto it = st.find(-mat[u][v]);
                st.erase(it);
                mat[u][v] = e[i].X.Y;
                mat[v][u] = mat[u][v];
                adj[v].insert({u,mat[u][v]});
                adj[u].insert({v,mat[u][v]});
                st.insert(-mat[u][v]);
                if (cnt == 1) val = min(val,G*e[i].X.X-S*(*(st.begin())));
                continue;
            }
            rep(i,1,n+1) vis[i] = 0;
            mx = 0;
            dfs(u,-1);
            mat[u][v] = e[i].X.Y;
            mat[v][u] = mat[u][v];
            adj[x].erase({y,mx});
            adj[y].erase({x,mx});
            mat[y][x] = 0;
            mat[x][y] = 0;
            st.insert(-e[i].X.Y);
            auto it = st.find(-mx);
            st.erase(it);
        }
        if (st.size() > n-1) cout << st.size() << " ";
        if (cnt == 1) val = min(val,G*e[i].X.X-S*(*(st.begin())));
    }
    if (cnt != 1){
        cout << -1;
        return 0;
    }
    cout << val;
    return 0;
}