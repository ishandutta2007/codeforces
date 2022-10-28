#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

struct DSU {
    int p[MAXN], sz[MAXN];
    void init(int n){ fill(sz, sz+n, 1); iota(p, p+n, 0); }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    bool union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a, sz[a] += sz[b], sz[b] = 0;
        return true;
    }
} d;

vector<array<int, 4>> ed, mst;
vector<pair<int, int>> adj[MAXN];
ll ans[MAXM], mx[MAXN][MAXL], tot=0;
int anc[MAXN][MAXL], depth[MAXN];

void dfs(int c=0, int p=-1, int d=0, int w=-1){
    anc[c][0] = p, depth[c] = d, mx[c][0] = w;
    for (int i = 1; i < MAXL; i++){ 
        anc[c][i] = (anc[c][i-1]==-1?-1:anc[anc[c][i-1]][i-1]);
        mx[c][i] = max(mx[c][i-1], (anc[c][i-1]==-1?0:mx[anc[c][i-1]][i-1]));
    }
    for (auto nxt : adj[c]) if (nxt.first != p) dfs(nxt.first, c, d+1, nxt.second);
}
ll mxp(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);  
    ll ans = -1; for (int i = MAXL-1; i >= 0; i--) if ((depth[a] - (1 << i)) >= depth[b]) ans = max(ans, mx[a][i]), a = anc[a][i];
    if (a == b) return ans;  
    for (int i = MAXL-1; i >= 0; i--) if (anc[a][i] != anc[b][i]) ans = max(ans, max(mx[a][i], mx[b][i])), a = anc[a][i], b = anc[b][i];  
    return ans = max(ans, max(mx[a][0], mx[b][0]));
}
void solve(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w, --a, --b;
        ed.push_back({w, a, b, i});
    }
    sort(ed.begin(), ed.end()); d.init(n);
    for (auto it : ed)
        if (d.union_sets(it[1], it[2])) mst.push_back(it), tot += it[0];
    memset(ans, -1, sizeof(ans));
    for (auto it : mst) ans[it[3]]=tot, adj[it[1]].push_back({it[2], it[0]}), adj[it[2]].push_back({it[1], it[0]});
    dfs();
    // for (int i = 0; i < n; i++) cout << mx[i][0] << " " << mx[i][1] << " " << mx[i][2] << "\n";
    for (auto it : ed) if (ans[it[3]] == -1) {
        // cout << it[1] << " " << it[2] << " " << mxp(it[1], it[2]) << "\n";
        ans[it[3]] = tot+it[0]-mxp(it[1], it[2]);
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}