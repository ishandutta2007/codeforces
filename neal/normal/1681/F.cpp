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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<array<int, 3>> edges(N - 1);
    vector<vector<array<int, 2>>> adj(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--; x--;
        edges[i] = {u, v, x};
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    vector<int> up(N, -1);
    vector<int> subtree_size(N, 0);
    vector<int> component_size(2 * N, 0);
    vector<vector<int>> color_stack(N);

    for (int x = 0; x < N; x++) {
        color_stack[x].push_back(N + x);
        component_size[N + x] = N;
    }

    y_combinator([&](auto dfs, int node, int parent) -> void {
        subtree_size[node] = 1;

        for (auto &e : adj[node]) {
            int child = e[0];
            int color = e[1];

            if (child == parent)
                continue;

            color_stack[color].push_back(child);
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
            color_stack[color].pop_back();
            up[child] = color_stack[color].back();
            component_size[up[child]] -= subtree_size[child];
        }

        component_size[node] += subtree_size[node];
    })(0, -1);

    int64_t total = 0;

    for (auto &e : edges) {
        int node = subtree_size[e[0]] < subtree_size[e[1]] ? e[0] : e[1];
        total += int64_t(component_size[node]) * component_size[up[node]];
    }

    cout << total << '\n';
}