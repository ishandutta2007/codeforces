#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
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

    inline void read_str(string &str) {
        while (isspace(next_char(false)))
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
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

    inline void write_str(const string &str, char after = '\0') {
        for (char c : str)
            write_char(c);

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

template<typename T, bool maximum_mode = false>
struct block_RMQ {
    static const int BLOCK = 16;

    int n = 0;
    vector<T> values;
    vector<uint8_t> block_index, block_prefix, block_suffix;
    RMQ<T, maximum_mode> rmq;

    block_RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    // Note: when `values[a] == values[b]` and `maximum_mode` is false, returns `b`.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    int get_block_start(int index) const {
        return index - index % BLOCK;
    }

    bool is_block_start(int index) const {
        return index % BLOCK == 0;
    }

    bool is_block_end(int index) const {
        return index == n - 1 || index % BLOCK == BLOCK - 1;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        block_prefix.assign(n + 1, 0);
        block_suffix.assign(n + 1, BLOCK - 1);

        // Manually fix the last block.
        for (int i = n - n % BLOCK; i <= n; i++)
            block_suffix[i] = (n - 1) % BLOCK;

        for (int i = 1; i <= n; i++) {
            int block_start = get_block_start(i);
            block_prefix[i] = (is_block_start(i) ? i : better_index(block_start + block_prefix[i - 1], i - 1)) - block_start;
        }

        for (int i = n - 1; i >= 0; i--) {
            int block_start = get_block_start(i);
            block_suffix[i] = (is_block_end(i) ? i : better_index(i, block_start + block_suffix[i + 1])) - block_start;
        }

        block_index.resize(n / BLOCK);
        vector<T> block_values(n / BLOCK);

        for (int i = 0; i < n / BLOCK; i++) {
            int block_start = BLOCK * i, best = block_start;

            for (int j = block_start + 1; j < block_start + BLOCK; j++)
                best = better_index(best, j);

            block_values[i] = values[best];
            block_index[i] = best - block_start;
        }

        rmq.build(block_values);
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int answer = a;

        // Check if we are strictly inside a block. Note we can't use (a - 1) / BLOCK because -1 / BLOCK rounds to 0.
        if ((a + BLOCK - 1) / BLOCK == b / BLOCK + 1) {
            for (int i = a + 1; i < b; i++)
                answer = better_index(answer, i);

            return answer;
        }

        int a_block_start = get_block_start(a);

        if (!is_block_start(a))
            answer = a_block_start + block_suffix[a];

        int a_block = (a + BLOCK - 1) / BLOCK, b_block = b / BLOCK;

        if (a_block < b_block) {
            int rmq_index = rmq.query_index(a_block, b_block);
            answer = better_index(answer, BLOCK * rmq_index + block_index[rmq_index]);
        }

        int b_block_start = get_block_start(b);

        if (!is_block_start(b))
            answer = better_index(answer, b_block_start + block_prefix[b]);

        return answer;
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
    block_RMQ<int> rmq;

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

    int get_dist(int a, int b, int anc = -1) const {
        if (anc < 0) anc = get_lca(a, b);
        return depth[a] + depth[b] - 2 * depth[anc];
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

    int get_kth_node_on_path(int a, int b, int k, int anc = -1) const {
        if (anc < 0) anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];
        assert(0 <= k && k <= first_half + second_half);

        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }
};


const int INF = 1e9 + 5;

struct edge {
    int node = -1, weight = -1;

    edge() {}

    edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

int N;
vector<vector<edge>> adj;
vector<int> dist;
vector<int> previous;

void bfs_check(queue<int> &q, queue<int> &next_q, int node, int from, int new_dist, int add) {
    assert(0 <= add && add <= 1);

    if (new_dist < dist[node]) {
        dist[node] = new_dist;
        previous[node] = from;
        (add == 0 ? q : next_q).push(node);
    }
}

void bfs(const vector<int> &source) {
    if (N == 0) return;
    // Two queues are needed for 0-1 BFS.
    queue<int> q, next_q;
    dist.assign(N, INF);
    previous.assign(N, -1);

    for (int src : source)
        bfs_check(q, next_q, src, -1, 0, 0);

    int level = 0;

    while (!q.empty() || !next_q.empty()) {
        while (!q.empty()) {
            int top = q.front(); q.pop();

            if (level > dist[top])
                continue;

            for (edge &e : adj[top])
                bfs_check(q, next_q, e.node, top, dist[top] + e.weight, e.weight);
        }

        swap(q, next_q);
        level++;
    }
}


struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


int K, R, V;
vector<pair<int, int>> edges;
vector<int> rests;
LCA lca;
union_find UF;

bool query(int a, int b) {
    int anc = lca.get_lca(a, b);

    if (lca.get_dist(a, b, anc) <= K)
        return true;

    int jump_a = lca.get_kth_node_on_path(a, b, (K + 1) / 2, anc);
    int jump_b = lca.get_kth_node_on_path(b, a, (K + 1) / 2, anc);

    if (dist[jump_a] > K / 2 || dist[jump_b] > K / 2)
        return false;

    return UF.find(jump_a) == UF.find(jump_b);
}

int main() {
    IO::init();
    IO::read_int(N, K, R);
    lca.init(N);
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        IO::read_int(x, y);
        x--; y--;
        lca.add_edge(x, y);
        adj[x].emplace_back(y, 1);
        adj[y].emplace_back(x, 1);
        edges.emplace_back(x, y);
    }

    lca.build();
    rests.resize(R);

    for (int &rest : rests) {
        IO::read_int(rest);
        rest--;
    }

    bfs(rests);
    UF.init(N);

    for (pair<int, int> &e : edges)
        if (dist[e.first] + 1 + dist[e.second] <= K)
            UF.unite(e.first, e.second);

    IO::read_int(V);

    for (int v = 0; v < V; v++) {
        int a, b;
        IO::read_int(a, b);
        a--; b--;
        IO::write_str(query(a, b) ? "YES" : "NO", '\n');
    }
}