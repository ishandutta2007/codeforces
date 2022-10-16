#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
vector<pii> adj[nax];
vector<pair<pii, int> > edges;
vector<pair<pii, int> > elves;
int n, m;

int par[nax];
int sz[nax];
int f(int x){
    if(par[x] == x) return x;
    return par[x] = f(par[x]);
}

void u(int x, int y){
    x = f(x);
    y = f(y);
    if(x != y){
        if(sz[x] > sz[y]) swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
    }
}

void ini(){
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

vector<int> g[nax];
int col[nax];
bool vis[nax];

bool wa = false;

void dfs(int v, int c){
    vis[v] = true;
    col[v] = c;
    for(int x : g[v]){
        if(vis[x] && col[x] == col[v]) wa = true;
        if(vis[x] == false) dfs(x, c ^ 1);
    }
}

map<pii, int> odp;

void go(int v, int p){
    for(pii cur : adj[v]){
        int to = cur.st;
        int val = cur.nd;
        if(to == p) continue;
        if(val >= 0){
            odp[mp(v, to)] = val;
        }
        else{
            int x1 = f(v);
            int x2 = f(to);
            x1 = col[x1];
            x2 = col[x2];
            int w = 0;
            if(x1 != x2) w = 1;
            odp[mp(v, to)] = w;
        }
        go(to, v);
    }
}

void solve(){
    odp.clear();
    cin >> n >> m;
    ini();
    wa = false;
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }
    edges.clear();
    elves.clear();
    for(int i=1;i<n;i++){
        int x, y, v; cin >> x >> y >> v;
        edges.pb(mp(mp(x, y), v));
        adj[x].pb(mp(y, v));
        adj[y].pb(mp(x, v));
        if(v >= 0 && __builtin_popcount(v) % 2 == 0) u(x, y);
    }
    for(int i=1;i<=m;i++){
        int x, y, z; cin >> x >> y >> z;
        elves.pb(mp(mp(x, y), z));
        if(z == 0) u(x, y);
    }
    for(int i=1;i<=n;i++) g[i].clear();
    for(auto cur : edges){
        if(cur.nd >= 0 && __builtin_popcount(cur.nd) % 2 == 1){
            int x1 = f(cur.st.st);
            int x2 = f(cur.st.nd);
            if(x1 == x2){
                cout << "NO" << "\n";
                return;
            }
            g[x1].pb(x2);
            g[x2].pb(x1);
        }
    }
    for(auto cur : elves){
        if(cur.nd >= 0 && __builtin_popcount(cur.nd) % 2 == 1){
            int x1 = f(cur.st.st);
            int x2 = f(cur.st.nd);
            if(x1 == x2){
                cout << "NO" << "\n";
                return;
            }
            g[x1].pb(x2);
            g[x2].pb(x1);
        }
    }

    for(int i=1;i<=n;i++){
        vis[i] = false;
        col[i] = -1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i] == false){
            dfs(i, 0);
        }
    }
    if(wa){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    go(1, 1);
    for(auto cur : odp){
        cout << cur.st.st << " " << cur.st.nd << " " << cur.nd << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}