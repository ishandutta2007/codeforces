#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, rev_tour_list;
    vector<int> heavy_root;
    RMQ<int> rmq;
    bool built;

    LCA(int _n = 0) {
        init(_n);
    }

    // Warning: this does not call build().
    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        postorder.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }

    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        // Erase the edge to parent.
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }

    int tour, post_tour;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }

        tour_end[node] = tour;
        postorder[node] = post_tour++;
    }

    void build(int root = -1, bool build_rmq = true) {
        parent.assign(n, -1);

        if (0 <= root && root < n)
            dfs(root, -1);

        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
                dfs(i, -1);

        tour = post_tour = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }

        rev_tour_list = tour_list;
        reverse(rev_tour_list.begin(), rev_tour_list.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        if (build_rmq)
            rmq.build(euler_depths);

        built = true;
    }

    pair<int, array<int, 2>> get_diameter() const {
        assert(built);

        // We find the maximum of depth[u] - 2 * depth[x] + depth[v] where u, x, v occur in order in the Euler tour.
        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};

        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            uxv_max = max(uxv_max, {ux_max.first + depth[node], {ux_max.second, node}});
        }

        return uxv_max;
    }

    // Returns the center(s) of the tree (the midpoint(s) of the diameter).
    array<int, 2> get_center() const {
        pair<int, array<int, 2>> diam = get_diameter();
        int length = diam.first, a = diam.second[0], b = diam.second[1];
        return {get_kth_node_on_path(a, b, length / 2), get_kth_node_on_path(a, b, (length + 1) / 2)};
    }

    // Note: returns -1 if `a` and `b` aren't connected.
    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];

        if (a > b)
            swap(a, b);

        return euler[rmq.query_index(a, b + 1)];
    }

    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }

    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    // Returns the child of `a` that is an ancestor of `b`. Assumes `a` is a strict ancestor of `b`.
    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));

        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(parent[child] == a);
        assert(is_ancestor(child, b));
        return child;
    }

    int get_kth_ancestor(int a, int k) const {
        while (a >= 0) {
            int root = heavy_root[a];

            if (depth[root] <= depth[a] - k)
                return tour_list[tour_start[a] - k];

            k -= depth[a] - depth[root] + 1;
            a = parent[root];
        }

        return a;
    }

    int get_kth_node_on_path(int a, int b, int k) const {
        int anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];
        assert(0 <= k && k <= first_half + second_half);

        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }

    // Note: this is the LCA of any two nodes out of three when the third node is the root.
    // It is also the node with the minimum sum of distances to all three nodes (the centroid of the three nodes).
    int get_common_node(int a, int b, int c) const {
        // Return the deepest node among lca(a, b), lca(b, c), and lca(c, a).
        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
        x = depth[y] > depth[x] ? y : x;
        x = depth[z] > depth[x] ? z : x;
        return x;
    }

    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree. Runs in O(k log k).
    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = int(nodes.size());

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};

const int INF = int(1e9) + 5;

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
        assert(capacity1 >= 0 && capacity2 >= 0);
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


void run_case() {
    int N;
    cin >> N;
    vector<array<int, 2>> edges(N - 1);
    LCA lca(N);
    vector<int> degree(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[i] = {a, b};
        lca.add_edge(a, b);
        degree[a]++;
        degree[b]++;
    }

    lca.build();
    int E = 0;

    for (int i = 0; i < N; i++)
        E += lca.depth[i] % 2 == 0;

    vector<int> match_index(N, -1);
    array<int, 2> indices = {0, 0};
    array<vector<int>, 2> ordering;

    for (int i = 0; i < N; i++) {
        int side = lca.depth[i] % 2;
        match_index[i] = E * side + indices[side]++;
        ordering[side].push_back(i);
    }

    constrained_bipartite_matching graph(E, N - E);

    for (auto &e : edges) {
        if (match_index[e[0]] >= E)
            swap(e[0], e[1]);

        graph.add_edge(match_index[e[0]], match_index[e[1]] - E);
    }

    vector<int> low(N), high(N);

    for (int i = 0; i < N; i++) {
        low[match_index[i]] = max(degree[i] - 2, 0);
        high[match_index[i]] = degree[i];
    }

    pair<bool, vector<bool>> result = graph.solve(low, high, true);
    assert(result.first);
    vector<bool> solution = result.second;
    dbg(edges);
    dbg(solution);
    vector<vector<int>> adj(N);

    for (int e = 0; e < N - 1; e++)
        if (!solution[e]) {
            adj[edges[e][0]].push_back(edges[e][1]);
            adj[edges[e][1]].push_back(edges[e][0]);
        }

    auto find_end = y_combinator([&](auto self, int node, int parent) -> int {
        for (int neigh : adj[node])
            if (neigh != parent)
                return self(neigh, node);

        return node;
    });

    vector<array<int, 2>> paths;
    vector<bool> done(N, false);

    for (int i = 0; i < N; i++)
        if (adj[i].size() <= 1 && !done[i]) {
            int end = find_end(i, -1);
            done[i] = done[end] = true;
            paths.push_back({i, end});
        }

    dbg(paths);
    vector<array<int, 2>> edges_add;

    for (int i = 1; i < int(paths.size()); i++)
        edges_add.push_back({paths[i - 1][1], paths[i][0]});

    vector<array<int, 2>> edges_remove;

    for (int e = 0; e < N - 1; e++)
        if (solution[e])
            edges_remove.push_back(edges[e]);

    assert(int(edges_remove.size()) == int(edges_add.size()));
    cout << edges_remove.size() << '\n';

    for (int i = 0; i < int(edges_remove.size()); i++)
        cout << edges_remove[i][0] + 1 << ' ' << edges_remove[i][1] + 1 << ' ' << edges_add[i][0] + 1 << ' ' << edges_add[i][1] + 1 << '\n';
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