#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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
struct dinic {
    struct edge {
        int node, rev;
        flow_t capacity;
        int id = -1;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity, int _id = -1)
            : node(_node), rev(_rev), capacity(_capacity), id(_id) {}
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

    void _add_edge(int u, int v, flow_t capacity1, flow_t capacity2, int id1, int id2) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity1, id1);
        edge vu_edge(u, int(adj[u].size()), capacity2, id2);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
    }

    void add_directional_edge(int u, int v, flow_t capacity, int id = -1) {
        _add_edge(u, v, capacity, 0, id, -1);
    }

    void add_bidirectional_edge(int u, int v, flow_t capacity, int id = -1) {
        _add_edge(u, v, capacity, capacity, id, id);
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    void bfs_check(int node, int potential_dist) {
        if (potential_dist < dist[node]) {
            dist[node] = potential_dist;
            q[q_end++] = node;
        }
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
            for (int i = 0; i < V; i++)
                edge_index[i] = 0;

            total_flow += dfs(source, numeric_limits<flow_t>::max(), sink);
        }

        flow_called = true;
        return total_flow;
    }
};

// constrained_bipartite_matching solves the following problem:
// You are given a bipartite graph with edges going from the left side to the right side (there can be multi-edges).
// For each node, you are given constraints in the form of low[node] and high[node], meaning that the number of matches
// at this node must end up between low[node] and high[node].
// Find a subset of the edges to match that satisfies all the low/high constraints, or determine that it's impossible.
// When a solution exists, this can also find the minimum number of matched edges needed in order to solve the
// constraints. Note that this adds an additional log factor to the time complexity due to binary search.
// See also https://cp-algorithms.com/graph/flow_with_demands.html and https://codeforces.com/contest/1240/submission/62062679
struct constrained_bipartite_matching {
    int N, M;
    int source, sink, dummy_source, dummy_sink;
    vector<pair<int, int>> edges;
    dinic<int> graph;

    constrained_bipartite_matching(int n = 0, int m = 0) {
        init(n, m);
    }

    void init(int n, int m) {
        N = n;
        M = m;
        edges = {};
        source = N + M;
        sink = N + M + 1;
        dummy_source = N + M + 2;
        dummy_sink = N + M + 3;
    }

    void add_edge(int a, int b) {
        assert(0 <= a && a < N);
        assert(0 <= b && b < M);
        edges.emplace_back(a, N + b);
    }

    pair<int, int> build_graph(const vector<int> &low, const vector<int> &high, int dummy_cap = INF) {
        assert(int(low.size()) == N + M && int(high.size()) == N + M);
        graph.init(N + M + 4);
        int left_sum = 0, right_sum = 0;

        for (int i = 0; i < int(edges.size()); i++)
            graph.add_directional_edge(edges[i].first, edges[i].second, 1, i);

        for (int i = 0; i < N + M; i++)
            if (i < N) {
                graph.add_directional_edge(source, i, low[i]);
                graph.add_directional_edge(dummy_source, i, high[i] - low[i]);
                left_sum += low[i];
            } else {
                graph.add_directional_edge(i, sink, low[i]);
                graph.add_directional_edge(i, dummy_sink, high[i] - low[i]);
                right_sum += low[i];
            }

        graph.add_directional_edge(source, dummy_sink, right_sum);
        graph.add_directional_edge(dummy_sink, dummy_source, dummy_cap);
        graph.add_directional_edge(dummy_source, sink, left_sum);

        // Flow paths can move as follows:
        // 1) source -> left -> right -> sink. This helps directly satisfy two low constraints.
        // 2) source -> left -> right -> dummy_sink -> dummy_source -> sink. This satisfies a low constraint on the left
        //      with the help of a high constraint on the right. dummy_source -> sink is limited by left_sum in order to
        //      prevent using more of this than necessary to satisfy left low constraints.
        // 3) source -> dummy_sink -> dummy_source -> left -> right -> sink. This satisfies a low constraint on the
        //      right with the help of a high constraint on the left. dummy_source -> sink is limited by right_sum in
        //      order to prevent using more of this than necessary to satisfy right low constraints.
        // 4) source -> dummy_sink -> dummy_source -> sink. This is a direct path that helps ensure that the total flow
        //      reaches exactly left_sum + right_sum when completed.
        return {left_sum, right_sum};
    }

    int& get_capacity(int from, int to) {
        for (auto &e : graph.adj[from])
            if (e.node == to)
                return e.capacity;

        assert(false);
    }

    void add_to_dummy_edge(int change) {
        get_capacity(dummy_sink, dummy_source) += change;
    }

    // Returns {success, edge assignment (true for matched edges)}.
    pair<bool, vector<bool>> solve(const vector<int> &low, const vector<int> &high, bool require_minimum = false) {
        assert(int(low.size()) == N + M && int(high.size()) == N + M);

        for (int i = 0; i < N + M; i++)
            if (low[i] > high[i])
                return {false, {}};

        pair<int, int> sums = build_graph(low, high);
        int left_sum = sums.first, right_sum = sums.second;
        int total_flow = graph.flow(source, sink);

        if (total_flow != left_sum + right_sum)
            return {false, {}};

        if (require_minimum) {
            // Find the amount of flow sent through the edge dummy_sink -> dummy_source to use as an upper bound.
            int upper = get_capacity(dummy_source, dummy_sink);

            // We can use max(left_sum, right_sum) as a lower bound, since min(left_sum, right_sum) is an upper bound
            // for the amount of flow that went through without the dummy vertices.
            int lower = max(left_sum, right_sum);
            assert(lower <= upper);

            // Due to the way the graph is constructed, if we find the lowest capacity of the dummy_sink -> dummy_source
            // edge that still results in a total flow of left_sum + right_sum, we then guarantee that we've used the
            // minimum possible number of edges.
            if (lower < upper) {
                cerr << "Searching between " << lower << " and " << upper << endl;

                build_graph(low, high, lower);
                total_flow = graph.flow(source, sink);

                if (total_flow != left_sum + right_sum) {
                    // Binary search to find the highest dummy edge capacity that doesn't get enough flow.
                    while (lower < upper) {
                        int mid = (lower + upper + 1) / 2;

                        dinic<int> graph_copy = graph;
                        int total_flow_copy = total_flow;

                        add_to_dummy_edge(mid - lower);
                        total_flow += graph.flow(source, sink);

                        if (total_flow == left_sum + right_sum) {
                            upper = mid - 1;
                            graph = graph_copy;
                            total_flow = total_flow_copy;
                        } else {
                            lower = mid;
                        }
                    }

                    assert(total_flow != left_sum + right_sum);
                    lower++;
                    add_to_dummy_edge(1);
                    total_flow += graph.flow(source, sink);
                }

                cerr << "Result: " << lower << endl;
                assert(total_flow == left_sum + right_sum);
            }
        }

        vector<bool> matched(edges.size(), false);

        for (auto &e_list : graph.adj)
            for (auto &e : e_list)
                if (e.id >= 0)
                    matched[e.id] = e.capacity == 0;

        return {true, matched};
    }
};


const int DIRS = 4;
const int DR[DIRS] = {-1,  0, +1,  0};
const int DC[DIRS] = { 0, +1,  0, -1};

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));

    for (auto &row : A)
        for (auto &x : row)
            cin >> x;

    auto valid = [&](int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M;
    };

    vector<vector<bool>> is_local_minimum(N, vector<bool>(M, true));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            for (int dir = 0; dir < DIRS; dir++) {
                int nr = r + DR[dir];
                int nc = c + DC[dir];

                if (valid(nr, nc) && A[nr][nc] < A[r][c])
                    is_local_minimum[r][c] = false;
            }

    int even = (N * M + 1) / 2, odd = N * M / 2;
    constrained_bipartite_matching graph(even, odd);

    auto get_graph_index = [&](int r, int c) {
        return (r * M + c) / 2;
    };

    vector<array<int, 4>> edges;

    for (int r = 0; r < N; r++)
        for (int c = r % 2; c < M; c += 2)
            for (int dir = 0; dir < DIRS; dir++) {
                int nr = r + DR[dir];
                int nc = c + DC[dir];
                assert((r + c) % 2 == 0 && (nr + nc) % 2 != 0);

                if (valid(nr, nc) && A[nr][nc] == A[r][c]) {
                    graph.add_edge(get_graph_index(r, c), get_graph_index(nr, nc));
                    edges.push_back({r, c, nr, nc});
                }
            }

    dbg(edges);
    vector<int> match_low(even + odd, 0), match_high(even + odd, 1);

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (is_local_minimum[r][c]) {
                if ((r + c) % 2 == 0)
                    match_low[get_graph_index(r, c)] = 1;
                else
                    match_low[even + get_graph_index(r, c)] = 1;
            }

    auto result = graph.solve(match_low, match_high);

    if (!result.first) {
        cout << "NO" << '\n';
        return;
    }

    vector<bool> matches = result.second;
    vector<vector<int>> cost_ans(N, vector<int>(M, -1));
    vector<vector<char>> dir_ans(N, vector<char>(M, '?'));

    auto get_dir = [](int dr, int dc) {
        assert((dr != 0) ^ (dc != 0));

        if (dr != 0)
            return dr < 0 ? 'U' : 'D';
        else
            return dc < 0 ? 'L' : 'R';
    };

    for (int i = 0; i < int(matches.size()); i++)
        if (matches[i]) {
            array<int, 4> coords = edges[i];
            int r = coords[0], c = coords[1];
            int nr = coords[2], nc = coords[3];
            assert(A[r][c] == A[nr][nc]);

            cost_ans[r][c] = A[r][c] / 2;
            cost_ans[nr][nc] = (A[r][c] + 1) / 2;

            dir_ans[r][c] = get_dir(nr - r, nc - c);
            dir_ans[nr][nc] = get_dir(r - nr, c - nc);
        }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (dir_ans[r][c] == '?') {
                assert(!is_local_minimum[r][c]);

                for (int dir = 0; dir < DIRS; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];

                    if (valid(nr, nc) && A[nr][nc] < A[r][c]) {
                        cost_ans[r][c] = A[r][c] - A[nr][nc];
                        dir_ans[r][c] = get_dir(nr - r, nc - c);
                        break;
                    }
                }
            }

    cout << "YES" << '\n';

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cout << cost_ans[r][c] << (c < M - 1 ? ' ' : '\n');

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cout << dir_ans[r][c] << (c < M - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}