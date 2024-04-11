#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e5+10, MOD = 1e9+7;

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
} scc;

ar<int, 2> comb(ar<int, 2> a, ar<int, 2> b) {
    return {min(a[0], b[0]), max(a[1], b[1])};
}
void add(ar<int, 2>& a, ar<int, 2> b) {
    a = comb(a, b);
}
int get(vector<ar<int, 2>> rng, vector<bool> dead) {
    int n = sz(rng);

    map<int, int> comp;
    for (int i = 0; i < sz(dead); i++) if (!dead[i]) {
        int c = sz(comp);
        comp[i] = c;
    }
    for (auto& c : rng) {
        assert(comp.count(c[0]) && comp.count(c[1]));
        c[0] = comp[c[0]], c[1] = comp[c[1]];
    }

    int m = sz(comp);

    vector<int> mx(m, -1);
    for (auto c : rng) mx[c[0]] = max(mx[c[0]], c[1]);
    for (int i = 1; i < m; i++) mx[i] = max(mx[i], mx[i-1]);

    int c = 0, ans = 0;
    while (c < m) {
        int nxt = mx[c];
        assert(nxt != -1);

        ans++, c = nxt+1;
    }
    return ans;
}
void solve(){
    int n, m; cin >> n >> m;
    vector<string> g(n); for (auto& r : g) cin >> r;
    vector<vector<int>> nxt(n, vector<int>(m, -1));
    vector<vector<int>> a(n, vector<int>(m, -1));
    vector<int> v(m); for (auto& c : v) cin >> c;

    int c = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (g[i][j] == '#') a[i][j] = c++;
    }

    vector<bool> dead(m);
    vector<ar<int, 2>> spec;
    for (int j = 0; j < m; j++) {
        if (!v[j]) { dead[j] = 1; continue; }

        int cnt = 0;
        for (int i = n-1; i >= 0; i--) if (g[i][j] == '#') {
            cnt++;

            if (cnt == v[j]) spec.push_back({i, j});
        }
        if (cnt < v[j]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (i < n-1) nxt[i][j] = nxt[i+1][j];
            if (g[i][j] == '#') nxt[i][j] = a[i][j];
        }
    }
    scc.init(c);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] != -1) {
        if (i && a[i-1][j] != -1) scc.add(a[i][j], a[i-1][j]);
        if (j < m-1 && nxt[i][j+1] != -1) scc.add(a[i][j], nxt[i][j+1]);
        if (j && nxt[i][j-1] != -1) scc.add(a[i][j], nxt[i][j-1]);
        if (i < n-1 && nxt[i+1][j] != -1) scc.add(a[i][j], nxt[i+1][j]);
    }
    scc.bld();

    vector<ll> reach(scc.cc);
    for (auto c : spec) reach[scc.who[a[c[0]][c[1]]]] = 1;

    for (int i = 0; i < scc.cc; i++) {
        for (auto prv : scc.ngr[i]) {
            reach[i] += reach[prv];
            reach[i] = min(reach[i], 2ll);
        }
    }

    vector<ar<int, 2>> dp(scc.cc, ar<int, 2>{m, -1});
    for (auto c : spec) {
        int who = scc.who[a[c[0]][c[1]]];
        if (reach[who] > 1) {
            dead[c[1]] = 1;
            continue;
        }

        add(dp[who], ar<int, 2>{c[1], c[1]});
    }

    vector<ar<int, 2>> rng;
    for (int i = scc.cc-1; i >= 0; i--) {
        for (auto nxt : scc.ng[i]) {
            add(dp[i], dp[nxt]);
        }
        if (dp[i][0] != m && dp[i][1] != -1) {
            rng.push_back(dp[i]);
        }
    }
    cout << get(rng, dead) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}