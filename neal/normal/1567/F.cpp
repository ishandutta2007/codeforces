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

const int DIRS = 4;
const int DR[DIRS] = {-1,  0, +1,  0};
const int DC[DIRS] = { 0, +1,  0, -1};

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


const char MARKED = 'X';
const char UNMARKED = '.';

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

    check_bipartite graph(N * M);
    vector<vector<int>> UM(N, vector<int>(M, 0));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == MARKED) {
                vector<array<int, 2>> unmarked;

                for (int dir = 0; dir < DIRS; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];

                    if (grid[nr][nc] == UNMARKED)
                        unmarked.push_back({nr, nc});
                }

                UM[r][c] = int(unmarked.size());

                if (UM[r][c] % 2 != 0) {
                    cout << "NO" << '\n';
                    return 0;
                }

                for (int i = 0; i < UM[r][c]; i++) {
                    int j = (i + 1) % UM[r][c];
                    graph.add_edge(unmarked[i][0] * M + unmarked[i][1], unmarked[j][0] * M + unmarked[j][1]);
                }
            }

    assert(graph.solve());
    cout << "YES" << '\n';
    vector<vector<int>> solution(N, vector<int>(M, -1));

    for (auto &component : graph.components)
        for (int index = 0; index < 2; index++)
            for (int node : component[index]) {
                int r = node / M;
                int c = node % M;
                solution[r][c] = array<int, 2>{1, 4}[index];
            }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == MARKED)
                solution[r][c] = 5 * UM[r][c] / 2;

    for (auto &row : solution)
        output_vector(row);
}