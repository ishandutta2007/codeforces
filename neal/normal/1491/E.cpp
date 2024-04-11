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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> F = {1, 1};

    while (F.back() < N)
        F.push_back(F[F.size() - 2] + F.back());

    vector<vector<int>> adj(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subtree_size(N);

    cout << (y_combinator([&](auto solve, int root, int n) -> bool {
        if (n <= 3)
            return true;

        if (!binary_search(F.begin(), F.end(), n))
            return false;

        int f = int(lower_bound(F.begin(), F.end(), n) - F.begin());
        int split = -1, par = -1;

        y_combinator([&](auto dfs, int node, int parent) -> void {
            subtree_size[node] = 1;

            for (int neigh : adj[node])
                if (neigh != parent) {
                    dfs(neigh, node);
                    subtree_size[node] += subtree_size[neigh];
                }

            if (subtree_size[node] == F[f - 2] || subtree_size[node] == F[f - 1]) {
                split = node;
                par = parent;
            }
        })(root, -1);

        if (split < 0)
            return false;

        int split_size = subtree_size[split];
        int par_size = n - split_size;
        adj[split].erase(remove(adj[split].begin(), adj[split].end(), par), adj[split].end());
        adj[par].erase(remove(adj[par].begin(), adj[par].end(), split), adj[par].end());
        return solve(split, split_size) && solve(par, par_size);
    })(0, N) ? "YES" : "NO") << '\n';
}