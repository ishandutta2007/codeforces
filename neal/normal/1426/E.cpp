#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int INF = int(1e9) + 5;

// Warning: when choosing flow_t, make sure it can handle the sum of flows, not just individual flows.
template<typename flow_t>
struct dinic {
    struct edge {
        int node, rev;
        flow_t capacity;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity) : node(_node), rev(_rev), capacity(_capacity) {}
    };

    int V = -1;
    vector<vector<edge>> adj;
    vector<int> dist;
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
        edge_index.resize(V);
        flow_called = false;
    }

    void _add_edge(int u, int v, flow_t capacity1, flow_t capacity2) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        assert(capacity1 >= 0 && capacity2 >= 0);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity1);
        edge vu_edge(u, int(adj[u].size()), capacity2);
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

    void bfs_check(queue<int> &q, int node, int new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            q.push(node);
        }
    }

    bool bfs(int source, int sink) {
        dist.assign(V, INF);
        queue<int> q;
        bfs_check(q, source, 0);

        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (edge &e : adj[top])
                if (e.capacity > 0)
                    bfs_check(q, e.node, dist[top] + 1);
        }

        return dist[sink] < INF;
    }

    flow_t dfs(int node, flow_t path_cap, int sink) {
        if (node == sink)
            return path_cap;

        if (dist[node] >= dist[sink])
            return 0;

        flow_t total_flow = 0;

        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[node] < int(adj[node].size())) {
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
            edge_index.assign(V, 0);
            total_flow += dfs(source, numeric_limits<flow_t>::max(), sink);
        }

        flow_called = true;
        return total_flow;
    }

    vector<bool> reachable;

    void reachable_dfs(int node) {
        reachable[node] = true;

        for (edge &e : adj[node])
            if (e.capacity > 0 && !reachable[e.node])
                reachable_dfs(e.node);
    }

    // Returns a list of {capacity, {from_node, to_node}} representing edges in the min cut.
    // TODO: for bidirectional edges, divide the resulting capacities by two.
    vector<pair<flow_t, pair<int, int>>> min_cut(int source) {
        assert(flow_called);
        reachable.assign(V, false);
        reachable_dfs(source);
        vector<pair<flow_t, pair<int, int>>> cut;

        for (int node = 0; node < V; node++)
            if (reachable[node])
                for (edge &e : adj[node])
                    if (!reachable[e.node])
                        cut.emplace_back(reverse_edge(e).capacity, make_pair(node, e.node));

        return cut;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int64_t N;
    array<int64_t, 3> A, B;
    cin >> N;

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    dinic<int64_t> graph(8);
    int source = 6, sink = 7;

/*
  0-3
 / / \
6-1-4-7
 \ / /
  2-5
*/

    graph.add_directional_edge(source, 0, A[0]);
    graph.add_directional_edge(source, 1, A[1]);
    graph.add_directional_edge(source, 2, A[2]);

    graph.add_directional_edge(3, sink, B[0]);
    graph.add_directional_edge(4, sink, B[1]);
    graph.add_directional_edge(5, sink, B[2]);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if ((i + 1) % 3 != j)
                graph.add_directional_edge(i, 3 + j, INF);

    int64_t minimum = N - graph.flow(source, sink);
    int64_t maximum = min(A[0], B[1]) + min(A[1], B[2]) + min(A[2], B[0]);
    cout << minimum << ' ' << maximum << '\n';
}