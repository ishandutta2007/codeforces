#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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
        depth.assign(V, -1);
        visited.assign(V, false);
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


const int N_MAX = 5005;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;
    check_bipartite solver(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        solver.add_edge(u, v);
    }

    bool bipartite = solver.solve();

    if (!bipartite) {
        cout << "NO" << '\n';
        return 0;
    }

    auto &components = solver.components;
    int C = int(components.size());
    vector<bitset<N_MAX>> knapsack(C + 1);
    knapsack[0][0] = 1;

    for (int i = 0; i < C; i++)
        knapsack[i + 1] = (knapsack[i] << components[i][0].size()) | (knapsack[i] << components[i][1].size());

    if (!knapsack[C][N2]) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    string color(N, '0');
    int count = C, size = N2;

    while (count > 0) {
        int index = count - 1;
        assert(knapsack[count][size]);
        int size0 = int(components[index][0].size());
        int which = -1;

        if (size >= size0 && knapsack[count - 1][size - size0])
            which = 0;
        else
            which = 1;

        for (int x : components[index][which])
            color[x] = '2';

        for (int x : components[index][!which])
            if (N1 > 0) {
                color[x] = '1';
                N1--;
            } else {
                color[x] = '3';
                N3--;
            }

        count--;
        size -= int(components[index][which].size());
    }

    cout << color << '\n';
}