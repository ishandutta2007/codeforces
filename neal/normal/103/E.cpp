#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename flow_t>
struct dinic {
    static const int INF = 1e9 + 5;
    static const flow_t CAP_INF = numeric_limits<flow_t>::max() / 2;

    struct edge {
        int node, rev;
        flow_t capacity;

        edge(int _node = -1, int _rev = -1, flow_t _capacity = 0) {
            node = _node;
            rev = _rev;
            capacity = _capacity;
        }
    };

    int V;
    vector<vector<edge>> adj;
    vector<int> dist;
    vector<int> q;
    int q_start, q_end;
    vector<int> edge_index;

    dinic(int vertices = -1) {
        initialize(vertices);
    }

    void initialize(int vertices) {
        V = vertices;
        adj.clear();
        adj.resize(V);
        dist.resize(V);
        q.resize(V);
        edge_index.resize(V);
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

    edge &get_reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    bool bfs(int source, int sink) {
        for (int i = 0; i < V; i++)
            dist[i] = INF;

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
                get_reverse_edge(e).capacity += path;
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

        return total_flow;
    }
};


const int N_MAX = 305;
const long long LL_INF = 1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    dinic<long long> graph(2 * N + 2);
    int source = graph.V - 2;
    int sink = graph.V - 1;

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;

        while (M--) {
            int x;
            cin >> x;
            x--;
            graph.add_directional_edge(i, N + x, LL_INF);
        }
    }

    int weight_sum = 0;

    for (int i = 0; i < N; i++) {
        int weight;
        cin >> weight;
        weight_sum += weight;
        graph.add_directional_edge(source, i, LL_INF - weight);
        graph.add_directional_edge(N + i, sink, LL_INF);
    }

    cout << weight_sum - (N * LL_INF - graph.flow(source, sink)) << '\n';
    return 0;
}