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
    struct edge {
        int node = -1, weight = -1;

        edge() {}

        edge(int _node, int _weight) : node(_node), weight(_weight) {}
    };

    int n;
    vector<vector<edge>> adj;
    vector<int> dist;
    vector<int> parent;

    BFS(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }

    void add_directional_edge(int a, int b, int weight) {
        assert(0 <= weight && weight <= 1);
        adj[a].emplace_back(b, weight);
    }

    void add_bidirectional_edge(int a, int b, int weight) {
        assert(0 <= weight && weight <= 1);
        adj[a].emplace_back(b, weight);
        adj[b].emplace_back(a, weight);
    }

    void bfs_check(queue<int> &q, queue<int> &next_q, int node, int from, int new_dist, int add) {
        assert(add == 0 || add == 1);

        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            (add == 0 ? q : next_q).push(node);
        }
    }

    void bfs(const vector<int> &source) {
        if (n == 0) return;

        // Two queues are needed for 0-1 BFS.
        queue<int> q, next_q;
        dist.assign(n, INF);
        parent.assign(n, -1);

        for (int src : source)
            bfs_check(q, next_q, src, -1, 0, 0);

        int level = 0;

        while (!q.empty() || !next_q.empty()) {
            while (!q.empty()) {
                int top = q.front(); q.pop();

                if (level > dist[top])
                    continue;

                for (edge &e : adj[top])
                    bfs_check(q, next_q, e.node, top, dist[top] + e.weight, e.weight);
            }

            swap(q, next_q);
            level++;
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


void run_case() {
    int N, M;
    cin >> N >> M;
    BFS bfs(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        bfs.add_directional_edge(u, v, 1);
    }

    bfs.bfs({0});
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return bfs.dist[a] > bfs.dist[b];
    });

    vector<int> closest(N, INF);

    for (int x : order) {
        closest[x] = bfs.dist[x];

        for (auto &e : bfs.adj[x])
            if (bfs.dist[e.node] <= bfs.dist[x])
                closest[x] = min(closest[x], bfs.dist[e.node]);
            else
                closest[x] = min(closest[x], closest[e.node]);
    }

    output_vector(closest);
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