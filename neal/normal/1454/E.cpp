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
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

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


void run_case() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<array<int, 2>> edges(N);

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    vector<int> stack;
    vector<int> cycle;
    vector<bool> visited(N, false);

    y_combinator([&](auto dfs, int node, int parent) -> bool {
        if (visited[node]) {
            cycle = {node};

            while (stack.back() != node) {
                cycle.push_back(stack.back());
                stack.pop_back();
            }

            return true;
        }

        stack.push_back(node);
        visited[node] = true;

        for (int neigh : adj[node])
            if (neigh != parent && dfs(neigh, node))
                return true;

        stack.pop_back();
        return false;
    })(0, -1);

    set<array<int, 2>> cycle_edges;
    int C = int(cycle.size());

    for (int i = 0; i < C; i++) {
        int a = cycle[i], b = cycle[(i + 1) % C];
        cycle_edges.insert({a, b});
        cycle_edges.insert({b, a});
    }

    union_find UF(N);

    for (int i = 0; i < N; i++)
        if (cycle_edges.find(edges[i]) == cycle_edges.end())
            UF.unite(edges[i][0], edges[i][1]);

    int64_t answer = N * (N - 1LL);

    for (int i = 0; i < N; i++)
        if (UF.find(i) == i) {
            int size = UF.get_size(i);
            answer -= size * (size - 1LL) / 2;
        }

    cout << answer << '\n';
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