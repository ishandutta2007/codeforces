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

struct eulerian_solver {
    struct edge {
        int node, rev, index;
        bool done = false;

        edge() {}

        edge(int _node, int _rev, int _index) : node(_node), rev(_rev), index(_index) {}
    };

    int n, edges;
    vector<vector<edge>> adj;

    eulerian_solver(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        edges = 0;
        adj.assign(n, {});
    }

    void add_edge(int u, int v) {
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), edges);
        edge vu_edge(u, int(adj[u].size()), edges);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
        edges++;
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    vector<size_t> edge_index;

    void eulerian_dfs(int node, edge *from_edge, vector<pair<int, edge*>> &tour) {
        while (edge_index[node] < adj[node].size()) {
            edge &e = adj[node][edge_index[node]];

            if (!e.done) {
                e.done = true;
                reverse_edge(e).done = true;
                eulerian_dfs(e.node, &e, tour);
            }

            edge_index[node]++;
        }

        // Generate the actual tour in reverse.
        tour.emplace_back(node, from_edge);
    }

    // Returns an Eulerian path/cycle with a list of vertices and edges. Includes the final vertex with a nullptr edge.
    // The i-th edge goes from the i-th vertex to the (i + 1)-th vertex.
    // Note: set `path_ok = false` when an Eulerian cycle is needed.
    vector<pair<int, edge*>> solve(bool path_ok) {
        if (edges == 0)
            return {};

        int odd_count = 0;

        for (int i = 0; i < n; i++)
            if (adj[i].size() % 2 != 0)
                odd_count++;

        if (odd_count > 2)
            return {};

        if (!path_ok && odd_count > 0)
            return {};

        int start = -1;

        for (int i = 0; i < n; i++)
            if (adj[i].size() % 2 != 0 || (odd_count == 0 && !adj[i].empty())) {
                start = i;
                break;
            }

        assert(start >= 0);
        edge_index.assign(n, 0);
        vector<pair<int, edge*>> tour;
        eulerian_dfs(start, nullptr, tour);
        reverse(tour.begin(), tour.end());
        int T = int(tour.size());

        if (T - 1 != edges)
            return {};

        // Shift the edges down one index.
        for (int i = 0; i < T - 1; i++)
            tour[i].second = tour[i + 1].second;

        tour.back().second = nullptr;
        return tour;
    }
};

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    eulerian_solver solver(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        solver.add_edge(x, y);
    }

    auto answer = solver.solve(true);

    if (!answer.empty()) {
        vector<int> path;

        for (auto &pr : answer)
            path.push_back(pr.first);

        cout << path.size() << '\n';
        output_vector(path, true);
        return 0;
    }

    int odd_degree_cnt = 0;

    for (int i = 0; i < N; i++)
        odd_degree_cnt += int(adj[i].size()) % 2;

    vector<vector<bool>> skip(N, vector<bool>(N, false));

    for (int center = 0; center < N; center++) {
        for (int neigh : adj[center])
            if (adj[neigh].size() % 2 != 0)
                skip[center][neigh] = skip[neigh][center] = true;

        solver.init(N);

        for (int x = 0; x < N; x++)
            for (int y : adj[x])
                if (x < y && !skip[x][y])
                    solver.add_edge(x, y);

        answer = solver.solve(true);

        auto output_solution = [&]() -> bool {
            if (answer.empty())
                return false;

            vector<int> path;

            for (auto &pr : answer)
                path.push_back(pr.first);

            if (path.front() != center && path.back() != center)
                return false;

            if (path.back() != center) {
                reverse(path.begin(), path.end());
                assert(path.back() == center);
            }

            path.push_back(-2);

            for (int i = 0; i < N; i++)
                if (skip[center][i]) {
                    path.push_back(i);
                    path.push_back(center);
                }

            cout << path.size() << '\n';
            output_vector(path, true);
            return true;
        };

        if (output_solution())
            return 0;

        for (int neigh : adj[center])
            if (adj[neigh].size() % 2 != 0) {
                skip[center][neigh] = skip[neigh][center] = false;
                solver.init(N);

                for (int x = 0; x < N; x++)
                    for (int y : adj[x])
                        if (x < y && !skip[x][y])
                            solver.add_edge(x, y);

                answer = solver.solve(true);

                if (output_solution())
                    return 0;

                skip[center][neigh] = skip[neigh][center] = true;
            }

        for (int x = 0; x < N; x++)
            skip[center][x] = skip[x][center] = false;
    }

    cout << 0 << '\n';
}