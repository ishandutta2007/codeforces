#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka


struct edge {
    int src, dst, cap, flw;
};

vector<edge> edges;
vector<vector<int>> graph;
vector<int> first;
vector<int> dist;

void bfs(int s) {
    dist.assign(graph.size(), -1);
    dist[s] = 0;
    int h = 0;
    vector<int> q;
    q.push_back(s);
    while (h < q.size()) {
        int x = q[h++];
        for (int i = 0; i < graph[x].size(); i++) {
            edge &e = edges[graph[x][i]];
            if (e.flw == e.cap) continue;
            int y = e.dst;
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push_back(y);
            }
        }
    }
}

int dfs(int x, int t, int f) {
    if (f == 0) return 0;
    if (x == t) return f;
    for (int i = first[x]; i < graph[x].size(); i++) {
        first[x] = i;
        edge &e = edges[graph[x][i]];
        edge &er = edges[graph[x][i] ^ 1];
        if (e.flw == e.cap || dist[e.dst] != dist[e.src] + 1)
            continue;
        int y = e.dst;
        int res = dfs(y, t, std::min(f, e.cap - e.flw));
        if (res > 0) {
            e.flw += res;
            er.flw -= res;
            return res;
        }
    }
    return 0;
}

long maxFlow(int s, int t) {
    long flow = 0;
    for (int e : graph[s]) {
        flow += edges[e].flw;
    }
    while (true) {
        bfs(s);
        first.assign(graph.size(), 0);
        if (dist[t] == -1) break;
        while (true) {
            int pushed = dfs(s, t, INT_MAX);
            if (pushed > 0) {
                flow += pushed;
            } else {
                break;
            }
        }
    }
    return flow;
}

void addEdge(int u, int v, int cap) {
//    cout << u << " " << v << "\n";
    edges.push_back({u, v, cap, 0});
    edges.push_back({v, u, 0, 0});
    graph[u].push_back(edges.size() - 2);
    graph[v].push_back(edges.size() - 1);
}

int n, m, k;
vector<long> pc;

void bt(int i, int x, long fl) {
//    cout << i << " " << x << " " << fl << "\n";
    if (i == k) {
        pc[x] = fl;
        return;
    }
    bt(i + 1, x, fl);
    edges[2 * i].cap = INT_MAX;
    vector<int> ff(edges.size());
    for (int j = 0; j < edges.size(); j++) {
        ff[j] = edges[j].flw;
    }
    bt(i + 1, x + (1 << i), maxFlow(0, n - 1));
    edges[2 * i].cap = 0;
    for (int j = 0; j < edges.size(); j++) {
        edges[j].flw = ff[j];
    }
}

int main() {
    ios::sync_with_stdio(false);

    int q;
    cin >> n >> m >> k >> q;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        addEdge(u, v, w);
    }

    pc.resize(1 << k);
    bt(0, 0, maxFlow(0, n - 1));

    vector<int> w(k);
    vector<int> ww(1 << k);
    vector<int> d(1 << k);
    for (int x = 1; x < (1 << k); x++) {
        while (((x >> (d[x])) & 1) == 0) d[x]++;
    }
//    for (int x = 0; x < (1 << k); x++) {
//        cout << x << " " << pc[x] << "\n";
//    }
    int z = (1 << k) - 1;
    while (q--) {
        for (int i = 0; i < k; i++) {
            cin >> w[i];
        }
        for (int x = 1; x < (1 << k); x++) {
            ww[x] = w[d[x]] + ww[x - (1 << d[x])];
        }
        long res = LONG_MAX;
        for (int x = 0; x < (1 << k); x++) {
            res = min(res, ww[x] + pc[z - x]);
        }
        cout << res << "\n";
    }

    return 0;
}