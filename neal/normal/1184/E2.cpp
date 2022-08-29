#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

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

template<typename T>
struct kruskal {
    struct edge {
        int a, b;
        T weight;
        int index = -1;
        bool in_tree = false;

        edge() {}

        edge(int _a, int _b, T _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    union_find UF;
    vector<edge> edges;
    vector<bool> original_in_tree;

    kruskal(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        UF.init(n);
        edges = {};
    }

    void add_edge(int a, int b, T weight) {
        edges.emplace_back(a, b, weight, edges.size());
        original_in_tree.push_back(false);
    }

    T solve() {
        sort(edges.begin(), edges.end());
        T total = 0;

        for (edge &e : edges)
            if (UF.unite(e.a, e.b)) {
                total += e.weight;
                e.in_tree = true;
                original_in_tree[e.index] = true;
            }

        return total;
    }
};

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        if (n > 0)
            range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

// https://codeforces.com/blog/entry/71568?#comment-559304
// Performs O(n log n) preprocessing to enable querying the maximum edge weight on any path in a tree in O(1) time.
template<typename T_weight>
struct line_tree {
    struct line_tree_union_find {
        vector<int> parent;
        vector<int> size;
        vector<int> left, right;

        line_tree_union_find(int n = -1) {
            if (n >= 0)
                init(n);
        }

        void init(int n) {
            parent.resize(n);
            size.assign(n, 1);
            left.resize(n);
            right.resize(n);

            for (int i = 0; i < n; i++)
                parent[i] = left[i] = right[i] = i;
        }

        int find(int x) {
            return x == parent[x] ? x : parent[x] = find(parent[x]);
        }

        // Returns the two nodes that get joined in the line tree by joining these two nodes.
        pair<int, int> unite(int x, int y) {
            x = find(x);
            y = find(y);
            assert(x != y);

            if (size[x] < size[y])
                swap(x, y);

            parent[y] = x;
            size[x] += size[y];
            pair<int, int> result = {right[x], left[y]};
            right[x] = right[y];
            return result;
        }
    };

    struct edge {
        int a, b;
        T_weight weight;

        edge() {}

        edge(int _a, int _b, T_weight _weight) : a(_a), b(_b), weight(_weight) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    int n = 0;
    vector<edge> edges;
    vector<int> line_index;
    RMQ<T_weight, true> rmq;

    line_tree(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        edges.clear();
    }

    void add_edge(int a, int b, T_weight weight) {
        edges.emplace_back(a, b, weight);
    }

    void build() {
        assert((int) edges.size() == max(n - 1, 0));
        sort(edges.begin(), edges.end());
        line_tree_union_find UF(n);
        vector<int> next_node(n, -1);
        vector<bool> has_prev(n, false);
        vector<T_weight> next_weight(n, numeric_limits<T_weight>::min());

        for (edge &e : edges) {
            pair<int, int> to_unite = UF.unite(e.a, e.b);
            next_node[to_unite.first] = to_unite.second;
            has_prev[to_unite.second] = true;
            next_weight[to_unite.first] = e.weight;
        }

        int start = -1;

        for (int i = 0; i < n; i++)
            if (!has_prev[i]) {
                start = i;
                break;
            }

        vector<int> line;
        vector<T_weight> line_weights;

        while (start >= 0) {
            line.push_back(start);

            if (next_node[start] >= 0)
                line_weights.push_back(next_weight[start]);

            start = next_node[start];
        }

        line_index.resize(n);

        for (int i = 0; i < n; i++)
            line_index[line[i]] = i;

        rmq.build(line_weights);
    }

    T_weight query_path_max(int a, int b) const {
        if (a == b)
            return numeric_limits<T_weight>::min();

        a = line_index[a];
        b = line_index[b];

        if (a > b)
            swap(a, b);

        return rmq.query_value(a, b);
    }
};


struct edge {
    int a, b, weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<edge> edges(M);
    kruskal<int> mst(N);

    for (edge &e : edges) {
        cin >> e.a >> e.b >> e.weight;
        e.a--; e.b--;
        mst.add_edge(e.a, e.b, e.weight);
    }

    mst.solve();
    line_tree<int> line(N);

    for (int i = 0; i < M; i++)
        if (mst.original_in_tree[i])
            line.add_edge(edges[i].a, edges[i].b, edges[i].weight);

    line.build();

    for (int i = 0; i < M; i++)
        if (!mst.original_in_tree[i])
            cout << line.query_path_max(edges[i].a, edges[i].b) << '\n';
}