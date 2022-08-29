#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<T> values;
    vector<vector<uint8_t>> range_low8;
    vector<vector<uint16_t>> range_low16;
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

    int get_index(int level, int a) const {
        if (level == 0)
            return a;
        else if (level <= 8)
            return a + range_low8[level][a];
        else if (level <= 16)
            return a + range_low16[level][a];
        else
            return a + range_low[level][a];
    }

    void set_index(int level, int a, int index) {
        if (level == 0)
            return;
        else if (level <= 8)
            range_low8[level][a] = index - a;
        else if (level <= 16)
            range_low16[level][a] = index - a;
        else
            range_low[level][a] = index - a;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        levels = largest_bit(n) + 1;
        range_low8.resize(levels);
        range_low16.resize(levels);
        range_low.resize(levels);

        for (int k = 1; k < levels; k++)
            if (k <= 8)
                range_low8[k].resize(n - (1 << k) + 1);
            else if (k <= 16)
                range_low16[k].resize(n - (1 << k) + 1);
            else
                range_low[k].resize(n - (1 << k) + 1);

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                set_index(k, i, better_index(get_index(k - 1, i), get_index(k - 1, i + (1 << (k - 1)))));
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(get_index(level, a), get_index(level, b - (1 << level)));
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

    // Note: returns -1 if a and b aren't connected.
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
        int anc = get_lca(a, b);
        return is_ancestor(anc, x) && (is_ancestor(x, a) || is_ancestor(x, b));
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    // Returns the child of a that is an ancestor of b.
    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));

        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(is_ancestor(child, b));
        return child;
    }
};

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};


const int MOD = 1e9 + 7;

struct ordering {
    int n = 0, head = -1, tail = -1;
    vector<int> next, prev;
    union_find UF;

    ordering(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        head = tail = -1;
        next.assign(n, -1);
        prev.assign(n, -1);
        UF.init(n);
    }

    bool set_head(int h) {
        assert(0 <= h && h < n);

        if (head >= 0 || prev[h] >= 0)
            return false;

        head = h;
        return true;
    }

    bool set_tail(int t) {
        assert(0 <= t && t < n);

        if (tail >= 0 || next[t] >= 0)
            return false;

        tail = t;
        return true;
    }

    bool link(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);

        if (a == tail || b == head)
            return false;

        if (next[a] >= 0 || prev[b] >= 0)
            return false;

        if (UF.find(a) == UF.find(b))
            return false;

        next[a] = b;
        prev[b] = a;
        UF.unite(a, b);
        return true;
    }

    int degrees_of_freedom() const {
        // Check if there is a path from head to tail, but something is missing.
        if (head >= 0 && tail >= 0) {
            int current = head, touched = 1;

            while (current >= 0 && current != tail) {
                current = next[current];
                touched++;
            }

            if (current == tail && touched < n)
                return -1;
        }

        int count = n;

        for (int i = 0; i < n; i++)
            count -= next[i] >= 0;

        count -= head >= 0;
        count -= tail >= 0;
        return max(count, 0);
    }
};

int N;
LCA lca;
vector<int> A;
vector<vector<int>> neighbors;
vector<ordering> orders;

vector<int> get_path(int u, int v) {
    int anc = lca.get_lca(u, v);
    vector<int> u_path, v_path;

    while (u != anc) {
        u_path.push_back(u);
        u = lca.parent[u];
    }

    u_path.push_back(anc);

    while (v != anc) {
        v_path.push_back(v);
        v = lca.parent[v];
    }

    while (!v_path.empty()) {
        u_path.push_back(v_path.back());
        v_path.pop_back();
    }

    return u_path;
}

int get_neighbor_index(int v, int neighbor) {
    return lower_bound(neighbors[v].begin(), neighbors[v].end(), neighbor) - neighbors[v].begin();
}

void fail() {
    cout << 0 << '\n';
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    lca.init(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        lca.add_edge(u, v);
    }

    neighbors = lca.adj;
    lca.build();
    A.resize(N);

    for (int &a : A) {
        cin >> a;
        a--;
    }

    for (int i = 0; i < N; i++)
        if (A[i] == i)
            fail();

    for (int i = 0; i < N; i++)
        sort(neighbors[i].begin(), neighbors[i].end());

    orders.resize(N);

    for (int i = 0; i < N; i++)
        orders[i].init(neighbors[i].size());

    for (int i = 0; i < N; i++)
        if (A[i] >= 0) {
            vector<int> path = get_path(A[i], i);
            int P = path.size();
            assert(P >= 2);

            int first_index = get_neighbor_index(path[0], path[1]);

            if (!orders[path[0]].set_head(first_index))
                fail();

            int last_index = get_neighbor_index(path[P - 1], path[P - 2]);

            if (!orders[path[P - 1]].set_tail(last_index))
                fail();

            for (int p = 1; p < P - 1; p++) {
                int before_index = get_neighbor_index(path[p], path[p - 1]);
                int after_index = get_neighbor_index(path[p], path[p + 1]);

                if (!orders[path[p]].link(before_index, after_index))
                    fail();
            }
        }

    long long answer = 1;

    for (int i = 0; i < N; i++) {
        int degrees = orders[i].degrees_of_freedom();

        if (degrees < 0)
            fail();

        for (int d = 1; d <= degrees; d++)
            answer = answer * d % MOD;
    }

    cout << answer << '\n';
}