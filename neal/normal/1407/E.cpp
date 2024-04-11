#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int INF = 1e9 + 5;

struct BFS {
    struct edge {
        int node = -1, type = -1;

        edge() {}

        edge(int _node, int _type) : node(_node), type(_type) {}
    };

    int n;
    vector<vector<edge>> adj;
    vector<array<int, 2>> dist;

    BFS(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }

    void add_directional_edge(int a, int b, int type) {
        assert(0 <= type && type <= 1);
        adj[a].emplace_back(b, type);
    }

    void add_bidirectional_edge(int a, int b, int type) {
        assert(0 <= type && type <= 1);
        add_directional_edge(a, b, type);
        add_directional_edge(b, a, type);
    }

    int get_dist(int node) const {
        return max(dist[node][0], dist[node][1]);
    }

    void bfs_check(queue<int> &next_q, int node, int type, int new_dist) {
        if (new_dist < dist[node][type]) {
            dist[node][type] = new_dist;

            if (dist[node][type] >= dist[node][!type])
                next_q.push(node);
        }
    }

    void bfs() {
        queue<int> q, next_q;
        dist.assign(n, {INF, INF});
        dist[n - 1][0] = dist[n - 1][1] = 0;
        q.push(n - 1);
        int level = 0;

        while (!q.empty() || !next_q.empty()) {
            while (!q.empty()) {
                int top = q.front(); q.pop();

                if (level > get_dist(top))
                    continue;

                for (edge &e : adj[top])
                    bfs_check(next_q, e.node, e.type, get_dist(top) + 1);
            }

            swap(q, next_q);
            level++;
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    BFS bfs(N);

    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        bfs.add_directional_edge(v, u, t);
    }

    bfs.bfs();
    cout << (bfs.get_dist(0) < INF ? bfs.get_dist(0) : -1) << '\n';

    for (int i = 0; i < N; i++)
        cout << (bfs.dist[i][1] >= bfs.dist[i][0]);

    cout << '\n';
}