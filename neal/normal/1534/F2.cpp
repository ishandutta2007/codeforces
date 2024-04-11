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
        V = int(adj.size());
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
                // neighbor is a candidate for low_link.
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
                which_component[x] = int(components.size()) - 1;
                component.push_back(x);
            } while (x != node);
        }
    }

    void build() {
        tour_index.assign(V, -1);
        low_link.resize(V);
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


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    vector<int> A(M);

    for (auto &a : A)
        cin >> a;

    vector<vector<int>> sand_index(N, vector<int>(M, -1));
    int S = 0;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == '#')
                sand_index[r][c] = S++;

    vector<vector<int>> adj(S);

    auto add_edge = [&](int a, int b) -> void {
        if (a >= 0 && b >= 0)
            adj[a].push_back(b);
    };

    vector<int> top(M, -1);

    for (int r = N - 1; r >= 0; r--) {
        for (int c = 0; c < M; c++) {
            add_edge(sand_index[r][c], top[c]);

            if (r > 0)
                add_edge(sand_index[r][c], sand_index[r - 1][c]);
        }

        for (int c = 0; c < M; c++)
            if (sand_index[r][c] >= 0)
                top[c] = sand_index[r][c];

        for (int c = 0; c < M; c++) {
            if (c > 0)
                add_edge(sand_index[r][c], top[c - 1]);

            if (c < M - 1)
                add_edge(sand_index[r][c], top[c + 1]);
        }
    }

    SCC scc(adj);
    scc.build();
    int C = int(scc.components.size());
    vector<int> in_degree(C, 0);

    for (int i = 0; i < S; i++)
        for (int j : adj[i])
            if (scc.which_component[i] != scc.which_component[j])
                in_degree[scc.which_component[j]]++;

    vector<int> source_cols;

    for (int c = 0; c < M; c++)
        for (int r = 0; r < N; r++)
            if (sand_index[r][c] >= 0 && in_degree[scc.which_component[sand_index[r][c]]] == 0) {
                source_cols.push_back(c);
                break;
            }

    vector<int> component_min(C, INF), component_max(C, -INF);

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (sand_index[r][c] >= 0) {
                int comp = scc.which_component[sand_index[r][c]];
                component_min[comp] = min(component_min[comp], c);
                component_max[comp] = max(component_max[comp], c);
            }

    for (int c = C - 1; c >= 0; c--)
        for (int x : scc.components[c])
            for (int y : adj[x]) {
                int cc = scc.which_component[y];
                component_max[cc] = max(component_max[cc], component_max[c]);
                component_min[cc] = min(component_min[cc], component_min[c]);
            }

    vector<array<int, 2>> intervals;

    for (int c = 0; c < M; c++) {
        int need = A[c];

        if (need == 0)
            continue;

        for (int r = N - 1; r >= 0; r--) {
            need -= sand_index[r][c] >= 0;

            if (need == 0) {
                int left = component_min[scc.which_component[sand_index[r][c]]];
                int right = component_max[scc.which_component[sand_index[r][c]]];
                intervals.push_back({left, right});
                break;
            }
        }
    }

    dbg(intervals);
    vector<int> max_start(M + 1, -INF);

    for (auto &inter : intervals)
        max_start[inter[1]] = max(max_start[inter[1]], inter[0]);

    for (int i = 0; i < M; i++)
        max_start[i + 1] = max(max_start[i + 1], max_start[i]);

    int current = M, ans = 0;

    while (current >= 0 && max_start[current] >= 0) {
        int col = *lower_bound(source_cols.begin(), source_cols.end(), max_start[current]);
        current = col - 1;
        ans++;
    }

    cout << ans << '\n';
}