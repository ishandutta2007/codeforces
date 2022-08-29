// Solution to https://codeforces.com/contest/342/problem/E
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = int(1e9) + 5;

struct edge {
    int node;

    edge(int _node = -INF) : node(_node) {}
};

struct centroid_decomposition {
    int N;
    vector<vector<edge>> adj;
    vector<int> depth;
    vector<int> subtree_size;
    vector<int> centroid_parent;
    vector<int> nodes;
    vector<vector<pair<int, int>>> centroid_dists;

    centroid_decomposition(int _N = 0) {
        init(_N);
    }

    void init(int _N) {
        N = _N;
        adj.assign(N, {});
        depth.resize(N);
        subtree_size.resize(N);
        centroid_parent.assign(N, -1);
        centroid_dists.assign(N, {});
    }

    void add_edge(int u, int v) {
        assert(u != v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    void erase_edge(int from, int to) {
        for (edge &e : adj[from])
            if (e.node == to) {
                swap(e, adj[from].back());
                adj[from].pop_back();
                return;
            }

        assert(false);
    }

    int dfs(int node, int parent = -1, int subroot = -1) {
        if (parent < 0) {
            subroot = node;
            nodes.clear();
        }

        depth[node] = parent < 0 ? 0 : depth[parent] + 1;
        subtree_size[node] = 1;
        nodes.push_back(node);

        for (edge &e : adj[node])
            if (e.node != parent)
                subtree_size[node] += dfs(e.node, node, parent < 0 ? e.node : subroot);

        return subtree_size[node];
    }

    int centroid(int root) {
        int n = dfs(root);
        bool found;

        // Repeatedly move to the subtree that is at least half of the tree, if such a subtree exists.
        do {
            found = false;

            for (edge &e : adj[root])
                if (subtree_size[e.node] < subtree_size[root] && 2 * subtree_size[e.node] >= n) {
                    root = e.node;
                    found = true;
                    break;
                }
        } while (found);

        return root;
    }

    void solve(int root) {
        root = centroid(root);

        for (int node : nodes)
            if (node != root)
                centroid_parent[node] = root;

        dfs(root);

        for (int node : nodes)
            centroid_dists[root].emplace_back(node, depth[node]);

        sort(centroid_dists[root].begin(), centroid_dists[root].end());

        for (edge &e : adj[root])
            erase_edge(e.node, root);

        // Recurse after solving root, so that edge erasures don't cause incorrect results.
        for (edge &e : adj[root])
            solve(e.node);
    }

    int get_centroid_dist(int root, int node) const {
        auto it = lower_bound(centroid_dists[root].begin(), centroid_dists[root].end(), make_pair(node, -INF));

        if (it == centroid_dists[root].end() || it->first != node)
            return -1;

        return it->second;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    centroid_decomposition CD(N);

    for (int e = 0; e < N - 1; e++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        CD.add_edge(a, b);
    }

    CD.solve(0);
    vector<int> centroid_closest(N, INF);

    auto turn_on = [&](int node) {
        for (int x = node; x >= 0; x = CD.centroid_parent[x])
            centroid_closest[x] = min(centroid_closest[x], CD.get_centroid_dist(x, node));
    };

    auto find_closest = [&](int node) {
        int best = INF;

        for (int x = node; x >= 0; x = CD.centroid_parent[x])
            best = min(best, CD.get_centroid_dist(x, node) + centroid_closest[x]);

        return best;
    };

    turn_on(0);

    for (int q = 0; q < M; q++) {
        int type, node;
        cin >> type >> node;
        node--;

        if (type == 1)
            turn_on(node);
        else if (type == 2)
            cout << find_closest(node) << '\n';
        else
            assert(false);
    }
}