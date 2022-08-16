#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

struct scc {
    int n;
	vector<vector<int>> g, gr, comp;
	vector<int> order, who;
    vector<unordered_set<int>> ng, ngr;
    vector<bool> used;
    int cc=0;
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
        this->n=n;
        g.assign(n, vector<int>()); gr.assign(n, vector<int>()); comp.assign(n, vector<int>());
        ng.assign(n, unordered_set<int>()); ngr.assign(n, unordered_set<int>());
    }
    void bld(){
    	who.assign(n, -1); used.assign(n, false);
        for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
        fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; i++){
            int v = order[n-1-i];
            if (!used[v]) dfs2(v), cc++;
        }
        for (auto it : ed) if (who[it.first] != who[it.second]) ng[who[it.first]].insert(who[it.second]), ngr[who[it.second]].insert(who[it.first]);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    scc g;
    g.init(n);

    vector<bool> mark(n);
    while (m--) {
        int a, b; cin >> a >> b, --a, --b;
        if (a != b) {
            g.add(a, b);
        } else mark[a] = 1;
    }
    g.bld();
    vector<int> dp1(g.cc, -1), dp2(g.cc);
    dp1[g.who[0]] = sz(g.comp[g.who[0]]), dp2[g.who[0]] = 1;
    for (int i = 0; i < g.cc; i++) {
        dp1[i] = sz(g.comp[i]);
        for (auto c : g.comp[i]) if (mark[c]) dp1[i]++;

        for (auto nxt : g.ngr[i]) dp2[i] += dp2[nxt], dp2[i] = min(dp2[i], 2);
        for (auto nxt : g.ngr[i]) dp1[i] = max(dp1[i], dp1[nxt]);
        if (!dp2[i]) dp1[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int c = g.who[i];
        if (dp1[c] > 1) cout << -1 << ' ';
        else if (dp2[c] <= 1) cout << dp2[c] << ' ';
        else if (dp1[c] == 1) cout << 2 << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}