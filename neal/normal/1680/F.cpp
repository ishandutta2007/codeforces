#include <algorithm>
#include <array>
#include <bitset>
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

    // Returns the parity status between x and y (0 = same, 1 = different). Requires them to be in the same component.
    bool query_parity(int x, int y) {
        assert(query_component(x, y));
        return edge_parity[x] ^ edge_parity[y];
    }

    // Returns {union succeeded, edge consistent with bipartite conditions}.
    pair<bool, bool> unite(int x, int y, bool different = true) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            bool consistent = !(edge_parity[x] ^ edge_parity[y] ^ different);
            bipartite[x_root] = bipartite[x_root] && consistent;
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


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<array<int, 2>> edge_list(M);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        if (u > v)
            swap(u, v);

        edge_list[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> preorder;
    vector<int> parent(N, -1);
    vector<int> depth(N, -1);
    vector<bool> visited(N, false);

    auto dfs = y_combinator([&](auto self, int node) -> void {
        visited[node] = true;
        depth[node] = parent[node] < 0 ? 0 : depth[parent[node]] + 1;
        preorder.push_back(node);

        for (int neigh : adj[node])
            if (!visited[neigh] && neigh != parent[node]) {
                parent[neigh] = node;
                self(neigh);
            }
    });

    dfs(0);
    vector<int> rev_preorder = preorder;
    reverse(rev_preorder.begin(), rev_preorder.end());

    auto remove_and_output = [&](int u, int v) -> void {
        dbg("remove", u + 1, v + 1);

        if (u > v)
            swap(u, v);

        bipartite_union_find UF(N);

        for (int e = 0; e < M; e++) {
            int a = edge_list[e][0], b = edge_list[e][1];

            if (a != u || b != v)
                UF.add_different_edge(a, b);
        }

        for (int i = 0; i < N; i++)
            assert(UF.bipartite[UF.find(i)]);

        vector<bool> solution(N);

        for (int i = 0; i < N; i++)
            solution[i] = UF.query_parity(0, i);

        if (u >= 0 && !solution[u]) {
            for (int i = 0; i < N; i++)
                solution[i] = !solution[i];
        }

        cout << "YES" << '\n';

        for (int i = 0; i < N; i++)
            cout << solution[i];

        cout << '\n';
    };

    vector<int> cover_bad(N, 0), cover_good(N, 0);
    int bad_edges = 0;
    array<int, 2> bad_edge = {-1, -1};

    for (auto &e : edge_list) {
        int u = e[0], v = e[1];

        if (depth[u] > depth[v])
            swap(u, v);

        if (depth[u] % 2 == depth[v] % 2) {
            cover_bad[v]++;
            cover_bad[u]--;
            bad_edges++;
            bad_edge = {u, v};
        } else if (u != parent[v]) {
            cover_good[v]++;
            cover_good[u]--;
        }
    }

    if (bad_edges <= 1) {
        remove_and_output(bad_edge[0], bad_edge[1]);
        return;
    }

    for (int x : rev_preorder)
        if (parent[x] >= 0) {
            cover_bad[parent[x]] += cover_bad[x];
            cover_good[parent[x]] += cover_good[x];
        }

    for (int x = 1; x < N; x++)
        if (cover_bad[x] == bad_edges && cover_good[x] == 0) {
            remove_and_output(x, parent[x]);
            return;
        }

    cout << "NO" << '\n';
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