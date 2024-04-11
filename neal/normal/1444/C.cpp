#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
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

struct check_bipartite {
    int V;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<bool> visited;

    check_bipartite(int v = -1) {
        if (v >= 0)
            init(v);
    }

    void init(int v) {
        V = v;
        adj.assign(V, {});
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<array<vector<int>, 2>> components;

    bool dfs(int node, int parent) {
        assert(!visited[node]);
        visited[node] = true;
        depth[node] = parent < 0 ? 0 : depth[parent] + 1;
        components.back()[depth[node] % 2].push_back(node);

        for (int neigh : adj[node])
            if (neigh != parent) {
                if (!visited[neigh] && !dfs(neigh, node))
                    return false;

                if (depth[node] % 2 == depth[neigh] % 2)
                    return false;
            }

        return true;
    }

    // Returns true iff the graph is bipartite.
    // Also builds a vector of components, where each component is divided into its two parts.
    bool solve() {
        depth.assign(V, -1);
        visited.assign(V, false);
        components = {};

        for (int i = 0; i < V; i++)
            if (!visited[i]) {
                components.emplace_back();

                if (!dfs(i, -1))
                    return false;
            }

        return true;
    }
};

struct bipartite_union_find {
    vector<int> parent;
    vector<int> size;
    vector<bool> bipartite;
    vector<bool> edge_parity;
    int components = 0;

    bipartite_union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        bipartite.assign(n + 1, true);
        edge_parity.assign(n + 1, false);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        int root = find(parent[x]);
        edge_parity[x] = edge_parity[x] ^ edge_parity[parent[x]];
        return parent[x] = root;
    }

    // Returns true if x and y are in the same component.
    bool query_component(int x, int y) {
        return find(x) == find(y);
    }

    // Returns the parity status between x and y. Requires that they are in the same component.
    bool query_parity(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        assert(x_root == y_root);
        return edge_parity[x] ^ edge_parity[y];
    }

    // Returns {union succeeded, edge consistent with bipartite conditions}.
    pair<bool, bool> unite(int x, int y, bool different = true) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            bool consistent = !(edge_parity[x] ^ edge_parity[y] ^ different);

            if (!consistent)
                bipartite[x_root] = false;

            return {false, consistent};
        }

        bool needed_parity = edge_parity[x] ^ edge_parity[y] ^ different;
        x = x_root;
        y = y_root;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        bipartite[x] = bipartite[x] && bipartite[y];
        edge_parity[y] = needed_parity;
        components--;
        return {true, true};
    }

    // Add an assertion that x and y are different; i.e., a normal edge.
    pair<bool, bool> add_different_edge(int x, int y) {
        return unite(x, y, true);
    }

    // Add an assertion that x and y are the same.
    pair<bool, bool> add_same_edge(int x, int y) {
        return unite(x, y, false);
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> C(N);

    for (auto &c : C) {
        cin >> c;
        c--;
    }

    vector<vector<int>> group_list(K);

    for (int i = 0; i < N; i++)
        group_list[C[i]].push_back(i);

    vector<vector<int>> adj(N);
    map<array<int, 2>, vector<array<int, 2>>> edge_lists;

    for (int e = 0; e < M; e++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

        if (C[a] > C[b])
            swap(a, b);

        edge_lists[{C[a], C[b]}].push_back({a, b});
    }

    int64_t B = 0;
    vector<bool> bipartite(K);
    vector<int> parity(N, -1);

    for (int g = 0; g < K; g++) {
        int V = int(group_list[g].size());
        check_bipartite checker(V);

        auto get_index = [&](int v) {
            int index = int(lower_bound(group_list[g].begin(), group_list[g].end(), v) - group_list[g].begin());
            assert(group_list[g][index] == v);
            return index;
        };

        for (int node : group_list[g])
            for (int neigh : adj[node])
                if (C[neigh] == g)
                    checker.add_edge(get_index(node), get_index(neigh));

        bipartite[g] = checker.solve();
        B += bipartite[g];

        for (int i = 0; i < V; i++)
            parity[group_list[g][i]] = checker.depth[i] % 2;
    }

    union_find UF(N);

    for (int node = 0; node < N; node++)
        for (int neigh : adj[node])
            if (C[node] == C[neigh])
                UF.unite(node, neigh);

    int64_t answer = B * (B - 1) / 2;

    for (auto &pr : edge_lists) {
        int g0 = pr.first[0];
        int g1 = pr.first[1];

        if (!bipartite[g0] || !bipartite[g1])
            continue;

        vector<int> roots;

        for (auto &edge : pr.second) {
            roots.push_back(UF.find(edge[0]));
            roots.push_back(UF.find(edge[1]));
        }

        sort(roots.begin(), roots.end());
        roots.erase(unique(roots.begin(), roots.end()), roots.end());

        auto get_index = [&](int root) {
            int index = int(lower_bound(roots.begin(), roots.end(), root) - roots.begin());
            assert(roots[index] == root);
            return index;
        };

        int R = int(roots.size());
        bipartite_union_find BUF(R);
        bool consistent = true;

        for (auto &edge : pr.second)
            consistent = consistent && BUF.unite(get_index(UF.find(edge[0])), get_index(UF.find(edge[1])), parity[edge[0]] == parity[edge[1]]).second;

        answer -= !consistent;
    }

    cout << answer << '\n';
}