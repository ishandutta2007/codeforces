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
#define vi vector<int>

using namespace std;

const int nax = 2e5 + 5;
set<pii> big[nax];
vector<pii> adj[nax];
int n,m;

int par[nax];
int sz[nax];

int f(int x){
    if(par[x] == x) return x;
    return (par[x] = f(par[x]));
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

set<int> unvis;
vector<int> cur;

void dfs(int v){
    cur.pb(v);
    vi gone;
    for(pii to : big[v]){
        int go = to.st;
        if(unvis.count(go)){
            gone.pb(go);
            unvis.erase(go);
        }
    }
    vi fre;
    for(int x : unvis) fre.pb(x);
    for(int x : gone) unvis.insert(x);
    for(int x : fre){
        unvis.erase(x);
    }
    for(int x : fre){
        dfs(x);
    }
}

vector<pair<int, pii> > edges;

void mst(){
    for(int i=1;i<=n;i++){
        sz[i] = 1;
        par[i] = i;
        unvis.insert(i);
    }
    for(int i=1;i<=n;i++){
        if(unvis.count(i)){
            unvis.erase(i);
            cur.clear();
            dfs(i);
            for(int j=1;j<cur.size();j++){
                u(cur[0], cur[j]);
            }
        }
    }
    ll cost = 0;
    for(auto e : edges){
        int w = e.st;
        int x = e.nd.st;
        int y = e.nd.nd;
        if(f(x) != f(y)){
            u(x, y);
            cost += w;
        }
    }
    cout << cost << "\n";
    exit(0);
}

void rst(){
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

vector<int> zeros[1005];

void solve(){
    cin >> n >> m;
    int xo = 0;
    for(int i=1;i<=m;i++){
        int x, y, w; cin >> x >> y >> w;
        xo ^= w;
        big[x].insert(mp(y, w));
        big[y].insert(mp(x, w));
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
        edges.pb(mp(w, mp(x, y)));
    }
    sort(edges.begin(), edges.end());
    if(n >= 1000){
        mst();
    }
    rst();
    for(int i=1;i<=n;i++){
        set<int> go;
        for(int j=1;j<=n;j++){
            if(j!=i) go.insert(j);
        }
        for(pii cur : adj[i]){
            go.erase(cur.st);
        }
        for(int x : go) zeros[i].pb(x);
    }
    bool cyc = false;
    for(int i=1;i<=n;i++){
        for(int x : zeros[i]){
            if(x < i) continue;
            if(f(i) == f(x)){
                cyc = true;
            }
            else u(i, x);
        }
    }
    if(cyc){
        mst();
    }

    rst();
    vector<pair<int, pii> > useful;
    for(auto e : edges){
        int w = e.st;
        int x = e.nd.st;
        int y = e.nd.nd;
        if(f(x) != f(y)){
            useful.pb(e);
        }
        u(x, y);
    }

    vector<pii> zero;
    for(int i=1;i<=n;i++){
        for(int x : zeros[i]){
            if(x > i){
                zero.pb(mp(i, x));
            }
        }
    }

    ll ans = 2e18;

    for(int i=0;i<zero.size();i++){
        ll cost = 0;
        rst();
        for(int j=0;j<zero.size();j++){
            if(j != i){
                int x = zero[j].st;
                int y = zero[j].nd;
                u(x, y);
            }
        }
        //for(int j=1;j<=n;j++) cout<<f(j)<<" ";
        //cout<<endl;
        int x1 = zero[i].st;
        int x2 = zero[i].nd;
        bool done = false;
        for(auto e : edges){
            int w = e.st;
            int x = e.nd.st;
            int y = e.nd.nd;
            if(!done && w>xo){
                if(f(x1)!=f(x2)){
                    cost+=xo;
                    u(x1,x2);
                }
                done = true;

            }
            if(f(x) != f(y)){
                cost += w;
                u(x, y);
            }
        }
        if(!done){
            if(f(x1)!=f(x2)){
                cost+=xo;
                u(x1,x2);
            }
            done = true;
        }

        ans = min(ans, cost);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}