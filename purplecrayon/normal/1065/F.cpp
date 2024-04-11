#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e6+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

struct scc {
    vector<int> g[MAXN], gr[MAXN], order, comp[MAXN];
    unordered_set<int> ng[MAXN];
    int who[MAXN], cc=0;
    bool used[MAXN];
    void dfs1 (int v) {
        used[v] = true;
        for (auto nxt : g[v]) if (!used[nxt]) dfs1(nxt);
        order.push_back(v);
    }
    void dfs2(int v) {
        used[v] = true; comp[cc].push_back(v); who[v] = cc;
        for (auto nxt : gr[v]) if (!used[nxt]) dfs2(nxt);
    }
    vector<pair<int, int>> ed;
    void add(int a, int b){
        g[a].push_back(b), gr[b].push_back(a);
        ed.push_back({a, b});
    }
    void init(int n){
        memset(who, -1, sizeof(who)); memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++){
            int v = order[n-1-i];
            if (!used[v]) dfs2(v), cc++;
        }
        for (auto it : ed) if (who[it.first] != who[it.second]) ng[who[it.first]].insert(who[it.second]);
    }
} g;

int n, k, a[MAXN], cost[MAXN], mx[MAXN];
vector<int> adj[MAXN], ord;

void dfs(int c=0, int p=-1){
    ord.push_back(c); a[c] = 0;
    // cout << "VIS: " << c << "\n";
    if (c&&!sz(adj[c])){
        // cout << c << "\n";
        int nxt = ord[max(sz(ord)-k-1, 0)];
        g.add(c, nxt); a[c] = 1;
    }
    for (auto nxt : adj[c]) {
        dfs(nxt, c); g.add(c, nxt);
    }
    ord.pop_back();
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    dfs(); g.init(n); memset(cost, 0, sizeof(cost)); //comps generated in top order
    for (int i = 0; i < n; i++) cost[g.who[i]] += a[i];//, cout << g.who[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < g.cc; i++) cout << cost[i] << " ";
    // cout << "\n";
    memset(mx, 0, sizeof(mx));
    int st = g.who[0], ans = 0;
    for (int i = st; i < g.cc; i++){
        mx[i] += cost[i]; ans = max(ans, mx[i]);
        for (auto nxt : g.ng[i]) mx[nxt] = max(mx[nxt], mx[i]);
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}