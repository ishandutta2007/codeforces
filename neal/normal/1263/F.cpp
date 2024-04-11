#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct power_grid {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> tour_start, tour_end, tour_list;

    power_grid(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
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
    }

    int tour;

    void tour_dfs(int node) {
        tour_list[tour] = node;
        tour_start[node] = tour++;

        for (int child : adj[node])
            tour_dfs(child);

        tour_end[node] = tour;
    }

    void build() {
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0)
                dfs(i, -1);

        tour = 0;

        for (int i = 0; i < n; i++)
            if (parent[i] < 0)
                tour_dfs(i);
    }

    int L;
    vector<int> leaf, leaf_start, leaf_end;

    void build_leaf_ranges() {
        L = leaf.size();
        leaf_start.assign(n, INF);
        leaf_end.assign(n, -INF);

        for (int i = 0; i < L; i++) {
            leaf_start[leaf[i]] = i;
            leaf_end[leaf[i]] = i + 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            int node = tour_list[i];

            for (int child : adj[node]) {
                leaf_start[node] = min(leaf_start[node], leaf_start[child]);
                leaf_end[node] = max(leaf_end[node], leaf_end[child]);
            }
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T[2];
    power_grid tree[2];
    cin >> N;

    for (int t = 0; t < 2; t++) {
        cin >> T[t];
        tree[t].init(T[t]);

        for (int i = 1; i < T[t]; i++) {
            int p;
            cin >> p;
            p--;
            tree[t].add_edge(p, i);
        }

        tree[t].build();
        tree[t].leaf.resize(N);

        for (int &x : tree[t].leaf) {
            cin >> x;
            x--;
        }

        tree[t].build_leaf_ranges();
    }

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < N; i++)
        for (int t = 0; t < 2; t++) {
            int x = tree[t].leaf[i];

            while (x > 0 && tree[t].leaf_start[x] == i) {
                int end = tree[t].leaf_end[x];
                dp[end] = max(dp[end], dp[i] + tree[t].subtree_size[x]);
                x = tree[t].parent[x];
            }
        }

    cout << dp[N] << '\n';
}