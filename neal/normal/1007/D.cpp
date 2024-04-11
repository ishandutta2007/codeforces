// Solution to https://codeforces.com/contest/1007/problem/D
// This problem is crazy. Four advanced algorithms: SCC, 2-SAT, seg tree, and heavy-light decomposition.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct SCC {
    int V = 0;
    vector<vector<int>> adj;
    vector<int> tour_index, low_link;
    int tour;

    vector<int> stack;
    vector<bool> in_stack;

    vector<vector<int>> components;
    vector<int> which_component;

    SCC(int v = 0) {
        init(v);
    }

    SCC(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int v) {
        V = v;
        adj.assign(V, {});
    }

    void init(const vector<vector<int>> &_adj) {
        adj = _adj;
        V = adj.size();
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }

    // Tarjan's algorithm.
    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack.push_back(node);
        in_stack[node] = true;

        for (int neighbor : adj[node])
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is our tree ancestor, so it's a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }

        if (low_link[node] == tour_index[node]) {
            // node is the highest node in an SCC, which includes everything on the stack up to it.
            components.emplace_back();
            vector<int> &component = components.back();
            int x;

            do {
                assert(!stack.empty());
                x = stack.back();
                stack.pop_back();
                in_stack[x] = false;
                which_component[x] = (int) components.size() - 1;
                component.push_back(x);
            } while (x != node);
        }
    }

    void build() {
        tour_index.assign(V, -1);
        low_link.assign(V, -1);
        which_component.assign(V, -1);

        stack.clear();
        stack.reserve(V);
        in_stack.assign(V, false);
        tour = 0;

        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components = {};

        for (int i = 0; i < V; i++)
            if (tour_index[i] < 0)
                dfs(i);
    }
};


struct two_sat {
    int n = 0;
    vector<vector<int>> adj;
    vector<bool> assignment;
    SCC scc;

    int inv(int var) {
        return var ^ 1;
    }

    int new_var() {
        adj.emplace_back();
        adj.emplace_back();
        return 2 * n++;
    }

    void implies(int a, int b) {
        adj[a].push_back(b);
        adj[inv(b)].push_back(inv(a));
    }

    void either(int a, int b) {
        adj[inv(a)].push_back(b);
        adj[inv(b)].push_back(a);
    }

    void set_value(int a) {
        adj[inv(a)].push_back(a);
    }

    void equal(int a, int b) {
        implies(a, b);
        implies(inv(a), inv(b));
    }

    void unequal(int a, int b) {
        implies(a, inv(b));
        implies(inv(a), b);
    }

    // Warning: this only creates an implication in the negative direction. It is still possible for
    // a = b = true with and_var = false. In particular, it does not work to call set_value on inv(and_var).
    int create_and(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(result, a);
        implies(result, b);
        return result;
    }

    // Warning: this only creates an implication in the positive direction. It is still possible for
    // a = b = false with or_var = true. In particular, it does not work to call set_value on or_var.
    int create_or(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(a, result);
        implies(b, result);
        return result;
    }

    int create_at_most_one(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        either(inv(a), inv(b));
        return create_or(a, b);
    }

    template<typename T_iterable>
    int create_at_most_one(const T_iterable &vars) {
        int aux = -1;

        for (int var : vars)
            aux = create_at_most_one(aux, var);

        return aux;
    }

    bool solve() {
        scc.init(adj);
        scc.build();

        for (int i = 0; i < n; i++)
            if (scc.which_component[2 * i] == scc.which_component[2 * i + 1])
                return false;

        assignment.resize(2 * n);
        vector<bool> done(n, false);

        // Tarjan's algorithm provides the SCCs in reverse topological order.
        for (auto &component : scc.components)
            for (int x : component) {
                assignment[x] = !done[x / 2];
                done[x / 2] = true;
            }

        for (int i = 0; i < n; i++)
            assert(assignment[2 * i] ^ assignment[2 * i + 1]);

        return true;
    }
};

two_sat TS;


struct seg_tree {
    int tree_n;
    vector<vector<int>> tree;

    seg_tree(int n = -1) {
        tree_n = 0;

        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, vector<int>());
    }

    bool empty() const {
        return tree_n == 0;
    }

    void add_path(int a, int b, int var) {
        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                tree[a++].push_back(var);

            if (b & 1)
                tree[--b].push_back(var);
        }
    }

    void build_implications(int position = 1, int parent_var = -1) {
        // For every segment, at most one var between both it and its parent can be chosen.
        int my_var = TS.create_at_most_one(tree[position]);
        my_var = TS.create_at_most_one(parent_var, my_var);

        if (position >= tree_n)
            return;

        build_implications(2 * position, my_var);
        build_implications(2 * position + 1, my_var);
    }
};


struct heavy_light {
    int n;
    bool vertex_mode;

    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> depth;
    vector<int> subtree_size;

    vector<int> chain_root;
    vector<int> chain_size;
    vector<seg_tree> chain_tree;

    heavy_light(int _n = -1, bool _vertex_mode = false) {
        if (_n >= 0)
            init(_n, _vertex_mode);
    }

    void init(int _n, bool _vertex_mode) {
        n = _n;
        vertex_mode = _vertex_mode;

        adj.clear();
        adj.resize(n);
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);

        chain_root.resize(n);
        chain_size.assign(n, 0);
        chain_tree.clear();
        chain_tree.resize(n);
    }

    void add_edge(int a, int b) {
         adj[a].push_back(b);
         adj[b].push_back(a);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par == -1 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        for (int neighbor : adj[node])
            if (neighbor != par) {
                dfs(neighbor, node);
                subtree_size[node] += subtree_size[neighbor];
            }
    }

    void chain_dfs(int node, bool heavy) {
        chain_root[node] = heavy ? chain_root[parent[node]] : node;
        chain_size[chain_root[node]]++;
        int biggest_subtree = 0;
        int heavy_child = -1;

        for (int neighbor : adj[node])
            if (neighbor != parent[node] && subtree_size[neighbor] > biggest_subtree) {
                biggest_subtree = subtree_size[neighbor];
                heavy_child = neighbor;
            }

        for (int neighbor : adj[node])
            if (neighbor != parent[node])
                chain_dfs(neighbor, neighbor == heavy_child);
    }

    void build() {
        dfs(0, -1);
        chain_dfs(0, false);

        for (int i = 0; i < n; i++)
            if (chain_root[i] == i)
                chain_tree[i].init(chain_size[i]);
    }

    template<typename T_tree_op>
    void process_path(int u, int v, T_tree_op &&op) {
        while (chain_root[u] != chain_root[v]) {
            // Always pull up the chain with the deeper root.
            if (depth[chain_root[u]] > depth[chain_root[v]])
                swap(u, v);

            int root = chain_root[v];
            op(chain_tree[root], 0, depth[v] - depth[root] + 1);
            v = parent[root];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        // u is now an ancestor of v.
        int root = chain_root[v];
        op(chain_tree[root], depth[u] - depth[root] + (vertex_mode ? 0 : 1), depth[v] - depth[root] + 1);
    }

    void add_path(int u, int v, int var) {
        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            tree.add_path(a, b, var);
        });
    }

    void build_all_implications() {
        for (seg_tree &tree : chain_tree)
            if (!tree.empty())
                tree.build_implications();
    }
};


int main() {
    int N;
    scanf("%d", &N);
    heavy_light HLD(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        HLD.add_edge(u, v);
    }

    HLD.build();

    int M;
    scanf("%d", &M);
    vector<int> vars(M);

    for (int i = 0; i < M; i++)
        vars[i] = TS.new_var();

    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a--; b--; c--; d--;
        HLD.add_path(a, b, vars[i]);
        HLD.add_path(c, d, TS.inv(vars[i]));
    }

    HLD.build_all_implications();
    cerr << TS.n << " nodes" << endl;

    if (!TS.solve()) {
        puts("NO");
        return 0;
    }

    puts("YES");

    for (int i = 0; i < M; i++)
        puts(TS.assignment[vars[i]] ? "1" : "2");
}