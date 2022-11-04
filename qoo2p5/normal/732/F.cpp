#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

const int N = 4e5 + 123;
const int M = 8e5 + 123;

struct Edge {
    int u, v;
    bool blocked;
    bool bridge;
};

int n, m;
vector<int> g[N];
Edge edge[M];
bool vis[N];
int tin[N], fup[N];

void dfs1(int v, int from = -1) {
    static int tmr = 0;
    vis[v] = true;
    tin[v] = tmr++;
    fup[v] = tin[v];
    
    for (int eid : g[v]) {
        int u = edge[eid].v;
        if (u == from) {
            continue;
        }
        
        if (!vis[u]) {
            dfs1(u, v);
            fup[v] = min(fup[v], fup[u]);
        } else {
            fup[v] = min(fup[v], tin[u]);
        }
                
        if (fup[u] > tin[v]) {
            edge[eid].bridge = true;
            edge[eid ^ 1].bridge = true;
        }
    }
}

int dfs2(int v) {
    int res = 1;
    vis[v] = true;
    
    for (int eid : g[v]) {
        int u = edge[eid].v;
        if (vis[u] || edge[eid].bridge) {
            continue;
        }
        
        res += dfs2(u);
    }
    
    return res;
}

void dfs3(int v, int from = -1) {
    vis[v] = true;
    
    for (int eid : g[v]) {
        int u = edge[eid].v;
        if (u == from) {
            continue;
        }
        
        if (!edge[eid ^ 1].blocked) {
            edge[eid].blocked = true;
        }
        
        if (!vis[u]) {
            dfs3(u, v);
        }
    }
}

int run() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(2 * i);
        g[v].push_back(2 * i + 1);
        edge[2 * i] = {u, v, false, false};
        edge[2 * i + 1] = {v, u, false, false};
    }
    
    dfs1(0);
    
    int best_v = -1;
    int best_cnt = -1;
    fill(vis, vis + n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int cur = dfs2(i);
            if (cur > best_cnt) {
                best_cnt = cur;
                best_v = i;
            }
        }
    }
    
    fill(vis, vis + n, false);
    dfs3(best_v);
    
    cout << best_cnt << "\n";
    
    for (int i = 0; i < 2 * m; i++) {
        if (!edge[i].blocked) {
            cout << edge[i].u + 1 << " " << edge[i].v + 1 << "\n";
        }
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}