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


void run_case() {
    int N;
    cin >> N;
    assert(N % 2 == 0);
    vector<int> A(N), B(N);
    vector<int> freq(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        freq[A[i]]++;
        freq[B[i]]++;
    }

    if (*max_element(freq.begin(), freq.end()) > 2) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
        if (A[i] == B[i]) {
            cout << "NO" << '\n';
            return;
        }

    check_bipartite solver(N);
    vector<int> other(N, -1);

    for (int i = 0; i < N; i++) {
        if (other[A[i]] >= 0)
            solver.add_edge(i, other[A[i]]);

        if (other[B[i]] >= 0)
            solver.add_edge(i, other[B[i]]);

        other[A[i]] = other[B[i]] = i;
    }

    cout << (solver.solve() ? "YES" : "NO") << '\n';
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