#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

vector<ar<int, 3>> ans;

struct comp {
    int n, m;
    vector<vector<int>> adj, sub, ch;
    vector<pair<int, int>> ed;
    map<int, int> mp;
    vector<bool> vis;
    vector<int> par, rmp;
    
    comp(vector<pair<int, int>> cur) : ed(cur) { m = sz(cur); };
    
    
    void dfs1(int c, int p=-1){
        par[c] = p; vis[c] = 1;
        for (auto nxt : adj[c]) if (nxt != p){
            if (!vis[nxt]){
                dfs1(nxt, c);
                ch[c].push_back(nxt);
            } else {
                if (c < nxt) sub[c].push_back(nxt);
            }
        }
    }
    void dfs2(int c){
        for (auto nxt : ch[c]) dfs2(nxt);
        if (c){
            if (sz(sub[c])&1) sub[c].push_back(par[c]);
            else sub[par[c]].push_back(c);
        }
    }
    void solve(){
        if (!m) return;
        for (auto& it : ed) mp[it.first]++, mp[it.second]++;
        int cc=0; for (auto& it : mp) it.second=cc++;
        n=cc; adj.resize(n); ch.resize(n); sub.resize(n);
        for (auto& it : ed) adj[mp[it.first]].push_back(mp[it.second]), adj[mp[it.second]].push_back(mp[it.first]);
        rmp.assign(n, -1);
        for (auto& it : mp) rmp[it.second]=it.first;
        //if (m&1) -> ignore some edge
        //lets say i'm given a tree -> remove a leaf
        //either remove a back-edge, or an edge to a leaf
        // 1-2-3-4
        vis.assign(n, 0); par.assign(n, -1);
        dfs1(0); //initialize dfs_tree
        //assign back-edges in any way
        //fix everything else using dfs tree
        dfs2(0);
        for (int i = 0; i < n; i++){
            if (sz(sub[i])&1) sub[i].pop_back();
            while (sz(sub[i])){
                int a=sub[i].back(); sub[i].pop_back();
                int b=sub[i].back(); sub[i].pop_back();
                ans.push_back(ar<int, 3>{rmp[a], rmp[i], rmp[b]});
            }
        }
    }
};

int n, m;
vector<int> adj[MAXN];
vector<pair<int, int>> cur;
bool vis[MAXN];

void dfs(int c){
    vis[c]=1;
    for (auto nxt : adj[c]) {
        if (nxt < c) cur.emplace_back(c, nxt);
        if (!vis[nxt]) dfs(nxt);
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) if (!vis[i]) {
        cur.clear(); dfs(i);
        comp c(cur); c.solve();
    }
    cout << sz(ans) << '\n';
    for (auto& it : ans){
        cout << (it[0]+1) << ' ' << (it[1]+1) << ' ' << (it[2]+1) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}