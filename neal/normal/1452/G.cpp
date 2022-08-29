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

const int INF = int(1e9) + 5;

struct BFS {
    int n;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<int> parent;

    BFS(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }

    void add_directional_edge(int a, int b) {
        adj[a].push_back(b);
    }

    void add_bidirectional_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void bfs_check(queue<int> &q, int node, int from, int new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            q.push(node);
        }
    }

    void bfs(const vector<int> &source) {
        if (n == 0) return;

        queue<int> q;
        dist.assign(n, INF);
        parent.assign(n, -1);

        for (int src : source)
            bfs_check(q, src, -1, 0);

        while (!q.empty()) {
            int top = q.front(); q.pop();

            for (int neigh : adj[top])
                bfs_check(q, neigh, top, dist[top] + 1);
        }
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
    BFS bfs(N);

    for (int e = 0; e < N - 1; e++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        bfs.add_bidirectional_edge(u, v);
    }

    int K;
    cin >> K;
    vector<int> bob(K);

    for (auto &b : bob) {
        cin >> b;
        b--;
    }

    bfs.bfs(bob);
    vector<int> dist_order(N);
    iota(dist_order.begin(), dist_order.end(), 0);
    sort(dist_order.begin(), dist_order.end(), [&](int a, int b) {
        return bfs.dist[a] > bfs.dist[b];
    });

    vector<int> answers(N, 0);
    vector<int> max_remain(N, 0);
    int64_t iterations = 0;

    for (int x : dist_order)
        y_combinator([&](auto dfs, int node, int dist, int remaining) {
            iterations++;

            if (remaining <= max_remain[node])
                return;

            answers[node] = max(answers[node], dist);
            max_remain[node] = max(max_remain[node], remaining);

            for (int neigh : bfs.adj[node])
                dfs(neigh, dist, remaining - 1);
        })(x, bfs.dist[x], bfs.dist[x]);

    cerr << iterations << " DFS iterations" << endl;
    output_vector(answers);
}