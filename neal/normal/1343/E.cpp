#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
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
        adj[a].emplace_back(b, weight);
    }

    void add_bidirectional_edge(int a, int b, int weight) {
        add_directional_edge(a, b, weight);
        add_directional_edge(b, a, weight);
    }

    void bfs_check(queue<int> &q, queue<int> &next_q, int node, int from, int new_dist, int add) {
        assert(0 <= add && add <= 1);

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


const int64_t INF64 = (int64_t) 2e18 + 5;

void run_case() {
    int N, M, A, B, C;
    cin >> N >> M >> A >> B >> C;
    A--; B--; C--;
    vector<int> P(M);

    for (auto &p : P)
        cin >> p;

    sort(P.begin(), P.end());
    vector<int64_t> P_sum(M + 1, 0);

    for (int i = 0; i < M; i++)
        P_sum[i + 1] = P_sum[i] + P[i];

    BFS bfs(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        bfs.add_bidirectional_edge(u, v, 1);
    }

    bfs.bfs({A});
    vector<int> distA = bfs.dist;
    bfs.bfs({B});
    vector<int> distB = bfs.dist;
    bfs.bfs({C});
    vector<int> distC = bfs.dist;

    int64_t answer = INF64;

    for (int middle = 0; middle < N; middle++) {
        int common = distB[middle];
        int a_dist = distA[middle];
        int c_dist = distC[middle];

        if (common + a_dist + c_dist > M)
            continue;

        answer = min(answer, P_sum[common] + P_sum[common + a_dist + c_dist]);
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