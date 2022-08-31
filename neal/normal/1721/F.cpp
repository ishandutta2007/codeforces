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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

struct safe_hash {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T>
    uint64_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return sizeof(x) <= 4 ? hash32(unsigned(x ^ FIXED_RANDOM)) : splitmix64(x ^ FIXED_RANDOM);
    }
};

struct safe_array_hash {
    template<typename T_array>
    uint64_t operator()(const T_array &arr) const {
        static const uint64_t RANDOM_MULT = safe_hash::splitmix64(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1)) | 1;
        static safe_hash hash_obj;
        uint64_t hash_key = 0;

        for (const auto &x : arr)
            hash_key = RANDOM_MULT * hash_key + x;

        return hash_obj(hash_key);
    }
};

const int INF = int(1e9) + 5;

struct dinic_matching {
    int n, m;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<int> right_match, left_match;
    vector<int> edge_index;
    bool match_called = false;
    int matches = 0;

    dinic_matching() {
        init(0, 0);
    }

    dinic_matching(int _n, int _m) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        adj.assign(n, {});
        match_called = false;
        matches = 0;
    }

    void add_edge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < m);
        adj[a].push_back(b);
    }

    bool bfs() {
        vector<int> q(n);
        int q_start = 0, q_end = 0;
        dist.assign(n, INF);

        auto bfs_check = [&](int node, int new_dist) -> void {
            if (new_dist < dist[node]) {
                dist[node] = new_dist;
                q[q_end++] = node;
            }
        };

        for (int i = 0; i < n; i++)
            if (right_match[i] < 0)
                bfs_check(i, 0);

        bool has_path = false;

        while (q_start < q_end) {
            int left = q[q_start++];

            for (int right : adj[left])
                if (left_match[right] < 0)
                    has_path = true;
                else
                    bfs_check(left_match[right], dist[left] + 1);
        }

        return has_path;
    }

    bool dfs(int left) {
        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[left] < int(adj[left].size())) {
            int right = adj[left][edge_index[left]++];
            bool solved = false;

            if (left_match[right] < 0 || (dist[left] + 1 == dist[left_match[right]] && dfs(left_match[right]))) {
                left_match[right] = left;
                right_match[left] = right;
                solved = true;
            }

            if (solved)
                return true;
        }

        dist[left] = INF;
        return false;
    }

    int match() {
        match_called = true;
        right_match.assign(n, -1);
        left_match.assign(m, -1);
        matches = 0;

        while (bfs()) {
            edge_index.assign(n, 0);

            for (int i = 0; i < n; i++)
                if (right_match[i] < 0 && dfs(i))
                    matches++;
        }

        return matches;
    }

    vector<bool> reachable_left, reachable_right;

    void _reachable_dfs(int left) {
        reachable_left[left] = true;

        for (int right : adj[left])
            if (right != right_match[left] && !reachable_right[right]) {
                reachable_right[right] = true;
                int next_left = left_match[right];

                if (next_left >= 0 && !reachable_left[next_left])
                    _reachable_dfs(next_left);
            }
    }

    void solve_reachable() {
        reachable_left.assign(n, false);
        reachable_right.assign(m, false);

        for (int i = 0; i < n; i++)
            if (right_match[i] < 0 && !reachable_left[i])
                _reachable_dfs(i);
    }

    // The min vertex cover in a bipartite graph corresponds to the min cut in its flow graph.
    vector<int> min_vertex_cover() {
        assert(match_called);
        solve_reachable();
        vector<int> cover;

        for (int i = 0; i < n; i++)
            if (!reachable_left[i])
                cover.push_back(i);

        for (int i = 0; i < m; i++)
            if (reachable_right[i])
                cover.push_back(n + i);

        assert(int(cover.size()) == matches);
        return cover;
    }

    // The max independent set is the complement of the min vertex cover.
    vector<int> max_independent_set() {
        assert(match_called);
        solve_reachable();
        vector<int> independent_set;

        for (int i = 0; i < n; i++)
            if (reachable_left[i])
                independent_set.push_back(i);

        for (int i = 0; i < m; i++)
            if (!reachable_right[i])
                independent_set.push_back(n + i);

        assert(int(independent_set.size()) + matches == n + m);
        return independent_set;
    }
};


int main() {
    ios::sync_with_stdio(false);

    int N, M, E, Q;
    cin >> N >> M >> E >> Q;
    vector<array<int, 2>> edges(E);
    gp_hash_table<array<int, 2>, int, safe_array_hash> edge_to_index;
    dinic_matching graph(N, M);

    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges[i] = {x, y};
        edge_to_index[{x, y}] = i;
        graph.add_edge(x, y);
    }

    int match = graph.match();
    vector<int> vertex_cover = graph.min_vertex_cover();
    assert(int(vertex_cover.size()) == match);
    int64_t edge_sum = 0;

    for (int i = 0; i < N; i++)
        if (graph.right_match[i] >= 0)
            edge_sum += edge_to_index[{i, graph.right_match[i]}] + 1;

    vector<bool> deleted(N + M, false);
    int vc = 0;

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int u = vertex_cover[vc++];
            deleted[u] = true;
            match--;
            cout << 1 << '\n';

            if (u < N)
                cout << u + 1 << '\n';
            else
                cout << -(u - N + 1) << '\n';

            int v;

            if (u < N) {
                v = graph.right_match[u];
            } else {
                v = u - N;
                u = graph.left_match[v];
            }

            edge_sum -= edge_to_index[{u, v}] + 1;
            cout << edge_sum << endl;
        } else if (type == 2) {
            cout << match << '\n';
            bool space = false;

            for (int i = 0; i < N; i++)
                if (!deleted[i] && graph.right_match[i] >= 0 && !deleted[N + graph.right_match[i]]) {
                    if (space) cout << ' ';
                    cout << edge_to_index[{i, graph.right_match[i]}] + 1;
                    space = true;
                }

            cout << endl;
        } else {
            assert(false);
        }
    }
}