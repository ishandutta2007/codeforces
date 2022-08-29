#include <algorithm>
#include <array>
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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


struct edge {
    int node;
    int64_t weight;

    edge() {}

    edge(int _node, int64_t _weight) : node(_node), weight(_weight) {}
};

const int INF = int(1e9) + 5;
const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<edge>> adj(N);
    check_bipartite checker(N);

    for (int i = 0; i < M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, b ? -1 : 1);
        checker.add_edge(u, v);
    }

    if (!checker.solve()) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<int64_t> dist;

    auto bellman_ford = [&](int source) -> bool {
        dist.assign(N, INF64);
        dist[source] = 0;

        for (int iteration = 0; iteration < N; iteration++)
            for (int node = 0; node < N; node++)
                for (edge &e : adj[node])
                    dist[e.node] = min(dist[e.node], dist[node] + e.weight);

        for (int node = 0; node < N; node++)
            for (edge &e : adj[node])
                if (dist[node] + e.weight < dist[e.node])
                    return true;

        return false;
    };

    int64_t best = -1;
    int best_source = -1;

    for (int source = 0; source < N; source++) {
        if (bellman_ford(source)) {
            cout << "NO" << '\n';
            return 0;
        }

        int64_t maximum = 0;

        for (int i = 0; i < N; i++) {
            assert(dist[i] < INF64 / 2);
            maximum = max(maximum, dist[i]);
        }

        if (maximum >= INF / 2)
            continue;

        bool bad = false;

        for (int i = 0; i < N; i++)
            for (edge &e : adj[i]) {
                if (abs(dist[e.node] - dist[i]) != 1)
                    bad = true;

                if (e.weight == -1 && dist[e.node] != dist[i] - 1)
                    bad = true;
            }

        if (bad)
            continue;

        if (maximum > best) {
            best = maximum;
            best_source = source;
        }
    }

    if (best < 0) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    cout << best << '\n';
    bellman_ford(best_source);

    for (int i = 0; i < N; i++)
        dist[i] += N;

    output_vector(dist);
}