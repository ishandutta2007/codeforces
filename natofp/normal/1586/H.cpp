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
int n, q;
int enjoyValue[nax];
vector<pii> adj[nax];
vector<pair<pii, pii> > roads;
int timer = 0;
int preorder[nax];
int postorder[nax];
const int LOG = 19;
int up[nax][LOG];
int mxup[nax][LOG];
int dep[nax];
int kto[nax * 2];

void dfs(int v, int p, int cost, int lv){
    dep[v] = lv;
    preorder[v] = ++timer;
    kto[preorder[v]] = v;
    up[v][0] = p;
    mxup[v][0] = cost;
    for(int i=1;i<LOG;i++){
        up[v][i] = up[up[v][i - 1]][i - 1];
        mxup[v][i] = max(mxup[v][i - 1], mxup[up[v][i - 1]][i - 1]);
    }
    for(pii x : adj[v]){
        if(x.st != p) dfs(x.st, v, x.nd, lv + 1);
    }
    postorder[v] = ++timer;
}

bool anc(int u, int v){
    return (preorder[u] <= preorder[v] && postorder[u] >= postorder[v]);
}

int lca(int x, int y){
    if(anc(x, y)) return x;
    if(anc(y, x)) return y;
    for(int i=LOG-1;i>=0;i--){
        if(!anc(up[x][i], y)) x = up[x][i];
    }
    return up[x][0];
}

int maxOnPath(int x, int y){
    int d = lca(x, y);
    int mx = 0;
    for(int i=LOG-1;i>=0;i--){
        if(dep[x] - dep[d] >= (1 << i)){
            mx = max(mx, mxup[x][i]);
            x = up[x][i];
        }
        if(dep[y] - dep[d] >= (1 << i)){
            mx = max(mx, mxup[y][i]);
            y = up[y][i];
        }
    }
    return mx;
}

vector<pair<pii, int> > zap;


int par[nax];
int sz[nax];
set<int> order[nax];
int mxEnjoy[nax];
int mxEdgeWithin[nax];


void ini(){
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
        order[i].insert(preorder[i]);
        mxEnjoy[i] = enjoyValue[i];
    }
}

int f(int x){
    if(par[x] == x) return x;
    return par[x] = f(par[x]);
}

pii ask(int city){
    int comp = f(city);
    int enjoy = mxEnjoy[comp];
    int pre = preorder[city];
    int ans = mxEdgeWithin[comp];
    int to = (*order[comp].begin());
    ans = max(ans, maxOnPath(city, kto[to]));
    return mp(enjoy, ans);
}


void u(int x, int y){
    x = f(x);
    y = f(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    // x -> y
    if(mxEnjoy[x] != mxEnjoy[y]){
        if(mxEnjoy[x] > mxEnjoy[y]){
            // erase all in y
            order[y] = order[x];
            mxEdgeWithin[y] = mxEdgeWithin[x];
            mxEnjoy[y] = mxEnjoy[x];
        }
        else{
            ;
        }
        sz[y] += sz[x];
        par[x] = y;
        return;
    }

    int bonus = 0;
    for(int cur : order[x]){
        auto it = order[y].lower_bound(cur);
        if(it != order[y].begin()){
            it--;
            int to = (*it);
            bonus = max(bonus, maxOnPath(kto[to], kto[cur]));
        }
        it = order[y].lower_bound(cur);
        if(it != order[y].end()){
            int to = (*it);
            bonus = max(bonus, maxOnPath(kto[to], kto[cur]));
        }
    }
    mxEdgeWithin[y] = max(mxEdgeWithin[y], mxEdgeWithin[x]);
    mxEdgeWithin[y] = max(mxEdgeWithin[y], bonus);
    for(int cur : order[x]){
        order[y].insert(cur);
    }
    sz[y] += sz[x];
    par[x] = y;
    return;
}

pii result[nax];

void solve(){
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> enjoyValue[i];
    for(int i=1;i<n;i++){
        int a,b,c,t; cin >> a >> b >> c >> t;
        adj[a].pb(mp(b, t));
        adj[b].pb(mp(a, t));
        roads.pb(mp(mp(c, t), mp(a, b)));
    }
    dfs(1, 1, 0, 0);
    for(int i=0;i<q;i++){
        int v, x; cin >> v >> x;
        zap.pb(mp(mp(v, x), i));
    }
    sort(zap.begin(), zap.end());
    reverse(zap.begin(), zap.end());
    sort(roads.begin(), roads.end());
    reverse(roads.begin(), roads.end());
    ini();
    int doneRoads = 0;
    for(int i=0;i<zap.size();i++){
        int id = zap[i].nd;
        int city = zap[i].st.nd;
        int limit = zap[i].st.st;
        while(doneRoads < roads.size() && roads[doneRoads].st.st >= limit){
            auto cur = roads[doneRoads];
            int s1 = cur.nd.st;
            int s2 = cur.nd.nd;
            u(s1, s2);
            doneRoads += 1;
        }
        result[id] = ask(city);
    }
    for(int i=0;i<q;i++){
        cout << result[i].st << " " << result[i].nd << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}