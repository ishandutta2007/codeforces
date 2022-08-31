#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// Warning: when choosing flow_t, make sure it can handle the sum of flows, not just individual flows.
template<typename flow_t>
struct dinic {
    static const int INF = 1e9 + 5;
    static const flow_t CAP_INF = numeric_limits<flow_t>::max() / 2;

    struct edge {
        int node, rev;
        flow_t capacity;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity)  : node(_node), rev(_rev), capacity(_capacity) {}
    };

    int V = -1;
    vector<vector<edge>> adj;
    vector<int> dist;
    vector<int> q;
    int q_start, q_end;
    vector<int> edge_index;
    bool flow_called;

    dinic(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }

    void init(int vertices) {
        V = vertices;
        adj.assign(V, {});
        dist.resize(V);
        q.resize(V);
        edge_index.resize(V);
        flow_called = false;
    }

    void _add_edge(int u, int v, flow_t capacity1, flow_t capacity2) {
        edge uv_edge(v, adj[v].size() + (u == v ? 1 : 0), capacity1);
        edge vu_edge(u, adj[u].size(), capacity2);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }

    void add_directional_edge(int u, int v, flow_t capacity) {
        _add_edge(u, v, capacity, 0);
    }

    void add_bidirectional_edge(int u, int v, flow_t capacity) {
        _add_edge(u, v, capacity, capacity);
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    bool bfs(int source, int sink) {
        fill(dist.begin(), dist.end(), INF);
        q_start = q_end = 0;
        bfs_check(source, 0);

        while (q_start < q_end) {
            int node = q[q_start++];

            for (edge &e : adj[node])
                if (e.capacity > 0)
                    bfs_check(e.node, dist[node] + 1);
        }

        return dist[sink] < INF;
    }

    void bfs_check(int node, int potential_dist) {
        if (potential_dist < dist[node]) {
            dist[node] = potential_dist;
            q[q_end++] = node;
        }
    }

    flow_t dfs(int node, flow_t path_cap, int sink) {
        if (node == sink)
            return path_cap;

        if (dist[node] >= dist[sink])
            return 0;

        flow_t total_flow = 0;

        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[node] < (int) adj[node].size()) {
            edge &e = adj[node][edge_index[node]];

            if (e.capacity > 0 && dist[node] + 1 == dist[e.node]) {
                flow_t path = dfs(e.node, min(path_cap, e.capacity), sink);
                path_cap -= path;
                e.capacity -= path;
                reverse_edge(e).capacity += path;
                total_flow += path;
            }

            // If path_cap is 0, we don't want to increment edge_index[node] as this edge may not be fully searched yet.
            if (path_cap == 0)
                break;

            edge_index[node]++;
        }

        return total_flow;
    }

    flow_t flow(int source, int sink) {
        assert(V >= 0);
        flow_t total_flow = 0;

        while (bfs(source, sink)) {
            for (int i = 0; i < V; i++)
                edge_index[i] = 0;

            total_flow += dfs(source, CAP_INF, sink);
        }

        flow_called = true;
        return total_flow;
    }
};


const int INF = 1e9 + 5;

struct rect {
    int x1, y1, x2, y2;
};

int N, M, A, B;
vector<rect> rects;
vector<int> X, Y;

int convert(vector<int> &Z, int z) {
    return lower_bound(Z.begin(), Z.end(), z) - Z.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    rects.resize(M);
    X = Y = {};

    for (rect &r : rects) {
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        r.x1--; r.y1--;
        X.push_back(r.x1);
        X.push_back(r.x2);
        Y.push_back(r.y1);
        Y.push_back(r.y2);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
    A = X.size();
    B = Y.size();
    vector<vector<bool>> black(A, vector<bool>(B, false));

    for (rect &r : rects)
        for (int x = convert(X, r.x1); x < convert(X, r.x2); x++)
            for (int y = convert(Y, r.y1); y < convert(Y, r.y2); y++)
                black[x][y] = true;

    int V = A + B + 2;
    dinic<long long> graph(V);
    int source = V - 2, sink = V - 1;

    for (int a = 0; a < A - 1; a++)
        graph.add_directional_edge(source, a, X[a + 1] - X[a]);

    for (int b = 0; b < B - 1; b++)
        graph.add_directional_edge(A + b, sink, Y[b + 1] - Y[b]);

    for (int a = 0; a < A; a++)
        for (int b = 0; b < B; b++)
            if (black[a][b])
                graph.add_directional_edge(a, A + b, INF);

    cout << graph.flow(source, sink) << '\n';
}