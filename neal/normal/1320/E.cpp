#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        levels = largest_bit(n) + 1;
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
        int level = largest_bit(b - a);
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
    vector<int> tour_start, tour_end, tour_list, postorder;
    vector<int> heavy_root;
    RMQ<int> rmq;

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
        tour_list.resize(n);
        postorder.resize(n);
        heavy_root.resize(n);
    }

    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj) {
        init(_adj.size());
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        // Erase the edge to parent.
        if (par >= 0)
            adj[node].erase(find(adj[node].begin(), adj[node].end(), par));

        for (int &child : adj[node]) {
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
        first_occurrence[node] = euler.size();
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

    void build() {
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0)
                dfs(i, -1);

        tour = post_tour = 0;

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }

        assert((int) euler.size() == 2 * n);
        vector<int> euler_depths;

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        rmq.build(euler_depths);
    }

    pair<int, int> find_farthest(int node, int par, int path) const {
        pair<int, int> current = {path, node};

        for (int neighbor : adj[node])
            if (neighbor != par)
                current = max(current, find_farthest(neighbor, node, path + 1));

        return current;
    }

    // Warning: this must be called before build(), since build() erases half of the edges.
    pair<int, pair<int, int>> get_diameter() const {
        int u = find_farthest(0, -1, 0).second;
        pair<int, int> farthest = find_farthest(u, -1, 0);
        int v = farthest.second;
        return {farthest.first, {u, v}};
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

    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree. Runs in O(k log k).
    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = nodes.size();

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin(), nodes.end(), compare_tour);
        nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < (int) nodes.size(); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};


const int INF = 1e9 + 5;

struct state {
    int node;
    pair<int, int> dist;

    state() {}

    state(int _node, pair<int, int> _dist) : node(_node), dist(_dist) {}

    bool operator<(const state &other) const {
        return dist > other.dist;
    }
};

int main() {
    IO::init();

    int N, Q;
    IO::read_int(N);
    LCA lca(N);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        IO::read_int(x, y);
        x--; y--;
        lca.add_edge(x, y);
    }

    lca.build();
    IO::read_int(Q);
    vector<vector<int>> compressed_adj(N);
    vector<int> which_virus(N, -1);
    vector<pair<int, int>> dist(N, {INF, INF});

    for (int q = 0; q < Q; q++) {
        int k, m;
        IO::read_int(k, m);
        vector<pair<int, int>> viruses(k);
        vector<int> queries(m);
        vector<int> nodes;

        for (auto &virus : viruses) {
            IO::read_int(virus.first, virus.second);
            virus.first--;
            nodes.push_back(virus.first);
        }

        for (int &query : queries) {
            IO::read_int(query);
            query--;
            nodes.push_back(query);
        }

        vector<pair<int, int>> compressed = lca.compress_tree(nodes);
        int n = compressed.size();

        for (int i = 0; i < n; i++) {
            int node = compressed[i].first;
            int parent = compressed[i].second;

            if (parent >= 0) {
                compressed_adj[node].push_back(parent);
                compressed_adj[parent].push_back(node);
            }
        }

        priority_queue<state> pq;

        auto &&dijkstra_check = [&](int node, pair<int, int> new_dist) {
            if (new_dist < dist[node]) {
                dist[node] = new_dist;
                which_virus[node] = new_dist.second;
                pq.emplace(node, new_dist);
            }
        };

        for (int i = 0; i < k; i++) {
            int node = viruses[i].first;
            dijkstra_check(node, {0, i});
        }

        while (!pq.empty()) {
            state top = pq.top(); pq.pop();

            if (top.dist > dist[top.node])
                continue;

            int v_index = which_virus[top.node];
            int speed = viruses[v_index].second;

            for (int neighbor : compressed_adj[top.node]) {
                int virus_dist = lca.get_dist(viruses[v_index].first, neighbor);
                int time = (virus_dist + speed - 1) / speed;
                dijkstra_check(neighbor, {time, v_index});
            }
        }

        for (int i = 0; i < m; i++)
            IO::write_int(which_virus[queries[i]] + 1, i < m - 1 ? ' ' : '\n');

        for (int i = 0; i < n; i++) {
            int node = compressed[i].first;
            compressed_adj[node].clear();
            which_virus[node] = -1;
            dist[node] = {INF, INF};
        }
    }
}