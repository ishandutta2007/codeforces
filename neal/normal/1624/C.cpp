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

const int INF = int(1e9) + 5;

struct dinic_matching {
    int n, m;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<bool> matched;
    vector<int> edge_index;
    vector<int> prv;

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
        dist.resize(n);
        matched.resize(n);
        edge_index.resize(n);
        prv.resize(m);
    }

    void add_edge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < m);
        adj[a].push_back(b);
    }

    void bfs_check(queue<int> &q, int left, int new_dist) {
        if (new_dist < dist[left]) {
            dist[left] = new_dist;
            q.push(left);
        }
    }

    bool bfs() {
        dist.assign(n, INF);
        queue<int> q;

        for (int i = 0; i < n; i++)
            if (!matched[i])
                bfs_check(q, i, 0);

        bool has_path = false;

        while (!q.empty()) {
            int left = q.front(); q.pop();

            for (int right : adj[left])
                if (prv[right] < 0)
                    has_path = true;
                else
                    bfs_check(q, prv[right], dist[left] + 1);
        }

        return has_path;
    }

    bool dfs(int left) {
        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[left] < int(adj[left].size())) {
            int right = adj[left][edge_index[left]++];
            bool solved = false;

            if (prv[right] < 0 || (dist[left] + 1 == dist[prv[right]] && dfs(prv[right]))) {
                prv[right] = left;
                matched[left] = true;
                solved = true;
            }

            if (solved)
                return true;
        }

        dist[left] = INF;
        return false;
    }

    int match() {
        matched.assign(n, false);
        prv.assign(m, -1);
        int matches = 0;

        while (bfs()) {
            edge_index.assign(n, 0);

            for (int i = 0; i < n; i++)
                if (!matched[i] && dfs(i))
                    matches++;
        }

        return matches;
    }

    vector<bool> reachable_left, reachable_right;

    void reachable_dfs(int left) {
        reachable_left[left] = true;

        for (int right : adj[left])
            if (prv[right] != left && !reachable_right[right]) {
                reachable_right[right] = true;
                int next_left = prv[right];

                if (next_left >= 0 && !reachable_left[next_left])
                    reachable_dfs(next_left);
            }
    }

    // The min vertex cover in a bipartite graph corresponds to the min cut in its flow graph.
    vector<int> min_vertex_cover() {
        int match_size = match();
        reachable_left.assign(n, false);
        reachable_right.assign(m, false);

        for (int i = 0; i < n; i++)
            if (!matched[i] && !reachable_left[i])
                reachable_dfs(i);

        vector<int> cover;

        for (int i = 0; i < n; i++)
            if (!reachable_left[i])
                cover.push_back(i);

        for (int i = 0; i < m; i++)
            if (reachable_right[i])
                cover.push_back(n + i);

        assert(int(cover.size()) == match_size);
        return cover;
    }

    // The max independent set is the complement of the min vertex cover.
    vector<int> max_independent_set() {
        int cover_size = int(min_vertex_cover().size());
        vector<int> independent_set;

        for (int i = 0; i < n; i++)
            if (reachable_left[i])
                independent_set.push_back(i);

        for (int i = 0; i < m; i++)
            if (!reachable_right[i])
                independent_set.push_back(n + i);

        assert(int(independent_set.size()) + cover_size == n + m);
        return independent_set;
    }
};


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    dinic_matching graph(N, N);

    for (int i = 0; i < N; i++) {
        int a = A[i];

        while (a > 0) {
            if (a <= N)
                graph.add_edge(i, a - 1);

            a /= 2;
        }
    }

    cout << (graph.match() == N ? "YES" : "NO") << '\n';
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