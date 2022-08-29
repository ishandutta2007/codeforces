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

    int N;
    cin >> N;
    vector<array<int, 2>> edges(N);

    for (auto &e : edges)
        cin >> e[0] >> e[1];

    union_find UF(2 * N);

    for (auto &e : edges)
        UF.unite(e[0], e[1]);

    vector<int> edge_count(2 * N + 1, 0);

    for (auto &e : edges)
        edge_count[UF.find(e[0])]++;

    for (int i = 1; i <= 2 * N; i++)
        if (edge_count[i] == 1) {
            cout << -1 << '\n';
            return 0;
        }

    vector<vector<pair<int, int>>> adj(2 * N + 1);

    for (int i = 0; i < N; i++) {
        auto e = edges[i];
        adj[e[0]].emplace_back(e[1], i);
        adj[e[1]].emplace_back(e[0], i);
    }

    vector<bool> edge_done(N, false);
    vector<bool> visited(2 * N + 1, false);
    vector<int> dfs_cycle;

    auto dfs = y_combinator([&](auto self, int node) -> void {
        dfs_cycle.push_back(node);

        if (visited[node])
            return;

        visited[node] = true;

        for (auto &e : adj[node])
            if (!edge_done[e.second]) {
                edge_done[e.second] = true;
                self(e.first);
                dfs_cycle.push_back(node);
            }
    });

    vector<vector<int>> cycles;

    for (int i = 1; i <= 2 * N; i++) {
        dfs_cycle.clear();
        dfs(i);
        assert(dfs_cycle.size() % 2 != 0);
        assert(dfs_cycle.front() == dfs_cycle.back());
        dfs_cycle.pop_back();

        if (dfs_cycle.empty())
            continue;

        assert(dfs_cycle.size() >= 4);
        cycles.push_back(dfs_cycle);
    }

    vector<vector<int>> grid(2, vector<int>(N, -1));
    array<vector<string>, 2> carps;
    carps.fill(vector<string>(2, string(N, '?')));
    int column = 0;

    for (auto &cycle : cycles) {
        int C = int(cycle.size());
        assert(C % 2 == 0);
        int C2 = C / 2;

        for (int i = 0; i < C2; i++)
            grid[0][column + i] = cycle[i];

        for (int i = C2; i < C; i++)
            grid[1][column + C - 1 - i] = cycle[i];

        for (int c = 0; c < 2; c++)
            for (int i = column + c % 2; i < column + C2 - 1; i += 2) {
                carps[c][0][i] = carps[c][1][i] = 'L';
                carps[c][0][i + 1] = carps[c][1][i + 1] = 'R';
            }

        if ((C2) % 2 == 0) {
            carps[1][0][column] = carps[1][0][column + C2 - 1] = 'U';
            carps[1][1][column] = carps[1][1][column + C2 - 1] = 'D';
        } else {
            carps[1][0][column] = carps[0][0][column + C2 - 1] = 'U';
            carps[1][1][column] = carps[0][1][column + C2 - 1] = 'D';
        }

        column += C2;
    }

    cout << 2 << ' ' << N << '\n';
    cout << '\n';
    output_vector(grid[0]);
    output_vector(grid[1]);

    for (int c = 0; c < 2; c++) {
        cout << '\n';

        for (auto &row : carps[c])
            cout << row << '\n';
    }
}