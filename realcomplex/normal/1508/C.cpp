#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;

set<int> E[N];

struct edge{
    int uu;
    int vv;
    int weight;
    bool operator<(const edge &ee) const {
        return weight < ee.weight;
    }
};

int par[N];
ll sz[N];
ll edg[N];

int fin(int x){
    if(par[x] == x) return x;
    return par[x]=fin(par[x]);
}

bool big[N];

bool unite(int a, int b){
    a = fin(a);
    b = fin(b);
    if(a == b) return false;
    par[a]=b;
    sz[b] += sz[a];
    big[b] |= big[a];
    return true;
}

set<int> vis;

int u[N], v[N], w[N];

vector<pii> T[N];
int dep[N];
const int LOG = 19;
int up[LOG][N];
int tin[N];
int tout[N];
int ti;

void dfs1(int u, int pa){
    ti++;
    tin[u]=ti;
    up[0][u]=pa;
    for(int i = 1; i < LOG; i ++ ){
        up[i][u]=up[i-1][up[i-1][u]];
    }
    for(auto x : T[u]){
        if(x.fi == pa) continue;
        dep[x.fi] = dep[u] + x.se;
        dfs1(x.fi, u);
    }
    tout[u]=ti;
}

bool is_par(int x, int y){
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y){
    if(is_par(x,y)) return x;
    for(int lg = 18; lg >=0 ;lg -- ){
        if(!is_par(up[lg][x], y)){
            x = up[lg][x];
        }
    }
    return up[0][x];
}

void dfs(int node){
    int las = 0;
    int nex;
    while(1){
        auto it = vis.upper_bound(las);
        if(it == vis.end()) break;
        nex = *it;
        if(!E[node].count(nex)){
            vis.erase(nex);
            unite(node, nex);
            T[node].push_back(mp(nex, 1));
            T[nex].push_back(mp(node, 1));
            dfs(nex);
        }
        las = nex;
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    vector<edge> lis;
    int xr = 0;
    for(int i = 1; i <= m ;i  ++ ){
        cin >> u[i] >> v[i] >> w[i];
        xr ^= w[i];
        lis.push_back({u[i], v[i], w[i]});
        E[u[i]].insert(v[i]);
        E[v[i]].insert(u[i]);
    }
    sort(lis.begin(), lis.end());
    for(int i = 1; i <= n; i ++ ){
        par[i] = i;
        sz[i] = 1;
        vis.insert(i);
    }
    int node;
    while(!vis.empty()){
        node = *vis.begin();
        vis.erase(vis.begin());
        dfs(node);
    }
    for(int i = 1; i <= m ; i ++ ){
        if(fin(u[i]) == fin(v[i])){
            edg[fin(u[i])] ++ ;
            xr = min(xr, w[i]);
        }
    }
    for(int i = 1; i <= n; i ++ ){
        if(fin(i) == i){
            if(edg[i] != sz[i] * 1ll * (sz[i] - 1) / 2ll - (sz[i] - 1)){
                xr = 0;
            }
            if(sz[i] > 1)
                big[i] = true;
        }

    }
    ll mst = 0;
    for(auto q : lis){
        if(unite(q.uu, q.vv)){
            mst += q.weight;
            T[q.uu].push_back(mp(q.vv, 0));
            T[q.vv].push_back(mp(q.uu, 0));
        }
    }
    dfs1(1,1);
    for(int i = 1; i <= m; i ++ ){
        if(dep[u[i]] + dep[v[i]] - 2 * dep[lca(u[i],v[i])] > 0){
            xr = min(xr, w[i]);
        }
    }
    cout << mst + xr << "\n";
    return 0;
}