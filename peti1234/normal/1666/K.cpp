#include <bits/stdc++.h>

using namespace std;
long long sok=1e15;
vector<int> vis;
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            vis.push_back(v);
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            vis.clear();
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
} mf(2005, 0, 1);

int n, m, a, b, kezd=0, veg=1, ert[2005];

int main()
{
    cin >> n >> m >> a >> b;
    mf.add_edge(kezd, 2*a, sok);
    mf.add_edge(kezd, 2*b+1, sok);
    mf.add_edge(2*a+1, veg, sok);
    mf.add_edge(2*b, veg, sok);

    for (int i=1; i<=m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        mf.add_edge(2*x, 2*y+1, z);
        mf.add_edge(2*x+1, 2*y, z);
        mf.add_edge(2*y, 2*x+1, z);
        mf.add_edge(2*y+1, 2*x, z);
    }

    cout << mf.flow() << "\n";


    for (auto x:vis) {
        ert[x/2]+=(1+x%2);
    }
    for (int i=1; i<=n; i++) {
        if (ert[i]==1) cout << 'A';
        if (ert[i]==2) cout << 'B';
        if (ert[i]==0 || ert[i]==3) cout << 'C';
    }
    cout << "\n";
    return 0;
}