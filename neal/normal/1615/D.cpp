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

struct bipartite_union_find {
    vector<int> parent;
    vector<int> size;
    vector<bool> bipartite;
    vector<bool> edge_parity;
    int components = 0;

    bipartite_union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        bipartite.assign(n + 1, true);
        edge_parity.assign(n + 1, false);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        int root = find(parent[x]);
        edge_parity[x] = edge_parity[x] ^ edge_parity[parent[x]];
        return parent[x] = root;
    }

    // Returns true if x and y are in the same component.
    bool query_component(int x, int y) {
        return find(x) == find(y);
    }

    // Returns the parity status between x and y (0 = same, 1 = different). Requires them to be in the same component.
    bool query_parity(int x, int y) {
        assert(query_component(x, y));
        return edge_parity[x] ^ edge_parity[y];
    }

    // Returns {union succeeded, edge consistent with bipartite conditions}.
    pair<bool, bool> unite(int x, int y, bool different = true) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            bool consistent = !(edge_parity[x] ^ edge_parity[y] ^ different);

            if (!consistent)
                bipartite[x_root] = false;

            return {false, consistent};
        }

        bool needed_parity = edge_parity[x] ^ edge_parity[y] ^ different;
        x = x_root;
        y = y_root;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        bipartite[x] = bipartite[x] && bipartite[y];
        edge_parity[y] = needed_parity;
        components--;
        return {true, true};
    }

    // Add an assertion that x and y are different; i.e., a normal edge.
    pair<bool, bool> add_different_edge(int x, int y) {
        return unite(x, y, true);
    }

    // Add an assertion that x and y are the same.
    pair<bool, bool> add_same_edge(int x, int y) {
        return unite(x, y, false);
    }
};


struct edge {
    int x, y, v;
};

void run_case() {
    int N, M;
    cin >> N >> M;
    bipartite_union_find UF(N);
    vector<edge> edges(N - 1);

    for (edge &e : edges) {
        cin >> e.x >> e.y >> e.v;
        e.x--; e.y--;

        if (e.v >= 0) {
            int parity = __builtin_popcount(e.v) % 2;
            pair<bool, bool> result = UF.unite(e.x, e.y, parity);
            assert(result.first && result.second);
        }
    }

    bool success = true;

    for (int q = 0; q < M; q++) {
        int a, b, p;
        cin >> a >> b >> p;
        a--; b--;
        pair<bool, bool> result = UF.unite(a, b, p);

        if (!result.second)
            success = false;
    }

    if (!success) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    for (int i = 1; i < N; i++)
        if (!UF.query_component(0, i))
            UF.unite(0, i, false);

    for (edge &e : edges) {
        int v = e.v >= 0 ? e.v : int(UF.query_parity(e.x, e.y));
        cout << e.x + 1 << ' ' << e.y + 1 << ' ' << v << '\n';
    }
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