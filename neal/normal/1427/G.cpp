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

const int INF = 1e9 + 5;

// Warning: when choosing flow_t, make sure it can handle the sum of flows, not just individual flows.
template<typename flow_t>
struct dfs_flow {
    struct edge {
        int node, rev;
        flow_t capacity;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity) : node(_node), rev(_rev), capacity(_capacity) {}
    };

    int V = -1;
    vector<vector<edge>> adj;
    vector<int> visited;
    int dfs_index = 0;
    bool flow_called;

    dfs_flow(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }

    void init(int vertices) {
        V = vertices;
        adj.assign(V, {});
        visited.assign(V, -1);
        dfs_index = 0;
        flow_called = false;
    }

    void _add_edge(int u, int v, flow_t capacity1, flow_t capacity2) {
        assert(0 <= u && u < V && 0 <= v && v < V);
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

    flow_t dfs(int node, flow_t path_cap, int sink) {
        if (node == sink)
            return path_cap;

        if (visited[node] == dfs_index)
            return 0;

        visited[node] = dfs_index;
        flow_t total_flow = 0;

        for (edge &e : adj[node])
            if (e.capacity > 0) {
                flow_t path = dfs(e.node, min(path_cap, e.capacity), sink);
                path_cap -= path;
                e.capacity -= path;
                reverse_edge(e).capacity += path;
                total_flow += path;

                if (path_cap == 0)
                    break;
            }

        return total_flow;
    }

    flow_t flow(int source, int sink) {
        assert(V >= 0);
        flow_t total_flow = 0, path;

        do {
            dfs_index++;
            path = dfs(source, numeric_limits<flow_t>::max(), sink);
            total_flow += path;
        } while (path > 0);

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

    edge& get_edge(int a, int b) {
        for (edge &e : adj[a])
            if (e.node == b)
                return e;

        assert(false);
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    int BIG = 4 * N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<int> border;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];

            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
                border.push_back(A[i][j]);
        }

    sort(border.begin(), border.end());
    border.erase(unique(border.begin(), border.end()), border.end());
    int B = int(border.size());

    auto get_index = [&](int r, int c) {
        return r * N + c;
    };

    int V = N * N + 2;
    int source = V - 2, sink = V - 1;
    dfs_flow<int> graph(V);

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (A[r][c] >= 0) {
                if (A[r][c] > 0) graph.add_directional_edge(get_index(r, c), sink, BIG);
                if (r < N - 1 && A[r + 1][c] >= 0) graph.add_bidirectional_edge(get_index(r, c), get_index(r + 1, c), 1);
                if (c < N - 1 && A[r][c + 1] >= 0) graph.add_bidirectional_edge(get_index(r, c), get_index(r, c + 1), 1);
            }

    int64_t total = 0;
    int flow = 0;

    for (int b = 0; b < B - 1; b++) {
        int low = border[b], high = border[b + 1];

        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                if (A[r][c] == low) {
                    int index = get_index(r, c);

                    // Remove edge index -> sink and add edge source -> index.
                    auto &e = graph.get_edge(index, sink);
                    int used = BIG - e.capacity;
                    flow -= used;
                    e.capacity = 0;
                    graph.add_directional_edge(source, index, BIG);
                }

        flow += graph.flow(source, sink);
        total += int64_t(high - low) * flow;
    }

    cout << total << '\n';
}