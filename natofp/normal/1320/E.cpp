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
vector<int> adj[nax];
int pre[nax], post[nax];
int n, timer = 0, q;
const int LOG = 19;
int up[nax][LOG];
int dep[nax];

void dfs(int v, int p, int lv){
    dep[v] = lv;
    up[v][0] = p;
    for(int i=1;i<LOG;i++){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    pre[v] = ++timer;
    for(int x : adj[v]){
        if(x != p) dfs(x, v, lv + 1);
    }
    post[v] = ++timer;
}

bool anc(int u, int v){
    return (pre[u] <= pre[v] && post[u] >= post[v]);
}

int lca(int u, int v){
    if(anc(u, v)) return u;
    if(anc(v, u)) return v;
    for(int i=LOG-1;i>=0;i--){
        if(!anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int distance(int u, int v){
    return (dep[u] + dep[v] - 2 * dep[lca(u, v)]);
}

bool cmp(int x, int y){
    return pre[x] < pre[y];
}

vector<int> all;
vector<int> uni;

int getID(int v){
    return (int)(lower_bound(uni.begin(), uni.end(), v) - uni.begin());
}

vector<pii> G[nax];
vector<pii> v;
vector<int> c;
set<int> importantVerices;
pii dist[nax];
bool vis[nax];
int color[nax];

void dijkstraCalc(){
    for(int i=0;i<all.size();i++){
        G[i].clear();
        vis[i] = false;
        dist[i] = mp(1e9, 1e9);
    }
    stack<int> guys;
    for(int i=0;i<all.size();i++){
        int v = all[i];
        while(guys.size() && !anc(guys.top(), v)) guys.pop();
        if(guys.size()){
            int one = v;
            int two = guys.top();
            int w1 = getID(one);
            int w2 = getID(two);
            G[w1].pb(mp(w2, abs(dep[one] - dep[two])));
            G[w2].pb(mp(w1, abs(dep[one] - dep[two])));
        }
        guys.push(v);
    }

    for(int i=0;i<v.size();i++){
        dist[getID(v[i].st)] = mp(0, i);
    }
    priority_queue<tuple<int, int, int, int> , vector<tuple<int, int, int, int> >, greater<tuple<int, int, int, int> >> Q;
    int nodes = all.size();
    for(int i=0;i<nodes;i++){
        Q.push(make_tuple(dist[i].st, dist[i].nd, i, 0));
    }

    while(Q.size()){
        auto cur = Q.top();
        Q.pop();
        if(vis[get<2>(cur)]) continue;
        int fullIterations = get<0>(cur);
        int virusID = get<1>(cur);
        int nodeID = get<2>(cur);
        vis[nodeID] = true;
        color[nodeID] = virusID;
        int spread = v[virusID].nd;
        for(pii to : G[nodeID]){
            int need = to.nd;
            int offset = fullIterations * spread - get<3>(cur);
            need -= offset;
            int extraIterations = 0;
            if(need > 0) extraIterations = (need + spread - 1) / spread;
            Q.push(make_tuple(fullIterations + extraIterations, virusID, to.st, get<3>(cur) + to.nd));
        }
    }
}

void go(){
    uni.clear();
    v.clear(); all.clear(); c.clear();
    int viruses, cities;
    cin >> viruses >> cities;
    for(int i=1;i<=viruses;i++){
        int x, y; cin >> x >> y;
        v.pb(mp(x, y));
        all.pb(x);
    }
    for(int i=1;i<=cities;i++){
        int w; cin >> w;
        c.pb(w);
        all.pb(w);
    }
    importantVerices.clear();
    for(int x : all) importantVerices.insert(x);
    sort(all.begin(), all.end(), cmp);
    for(int i=0;i<(int)all.size()-1;i++){
        importantVerices.insert(lca(all[i], all[i + 1]));
    }
    all.clear();
    for(int x : importantVerices) all.pb(x);
    sort(all.begin(), all.end(), cmp);
    uni = all;
    sort(uni.begin(), uni.end());
    dijkstraCalc();
    for(int i=1;i<=cities;i++){
        int cityID = c[i - 1];
        cityID = getID(cityID);
        cout << color[cityID] + 1 << " ";
    }
    cout << "\n";
}

void solve(){
    cin >> n;
    for(int i=1;i<n;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 1, 0);
    cin >> q;
    while(q--) go();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}