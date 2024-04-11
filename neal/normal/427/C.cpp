// Solution to https://codeforces.com/contest/427/problem/C
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


const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> cost(N);

    for (int i = 0; i < N; i++)
        cin >> cost[i];

    int M;
    cin >> M;
    SCC scc(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        scc.add_edge(u, v);
    }

    scc.build();
    int64_t min_money = 0, num_ways = 1;

    for (vector<int> &comp : scc.components) {
        int min_cost = INF;
        int count = 1;

        for (int v : comp)
            if (cost[v] < min_cost) {
                min_cost = cost[v];
                count = 1;
            } else if (cost[v] == min_cost) {
                count++;
            }

        min_money += min_cost;
        num_ways = num_ways * count % MOD;
    }

    cout << min_money << ' ' << num_ways << '\n';
}