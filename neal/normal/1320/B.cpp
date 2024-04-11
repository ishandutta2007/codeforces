#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
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
    vector<int> previous;
    vector<set<int>> previous_set;

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
            previous[node] = from;
            previous_set[node] = {from};
            (add == 0 ? q : next_q).push(node);
        } else if (new_dist == dist[node]) {
            previous_set[node].insert(from);
        }
    }

    void bfs(const vector<int> &source) {
        if (n == 0) return;

        // Two queues are needed for 0-1 BFS.
        queue<int> q, next_q;
        dist.assign(n, INF);
        previous.assign(n, -1);
        previous_set.assign(n, {});

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


int N, M, K;
BFS graph;
vector<int> path;

int solve_min() {
    int rebuilds = 0;

    for (int i = 0; i < K - 1; i++)
        if (graph.dist[path[i]] != graph.dist[path[i + 1]] + 1)
            rebuilds++;

    return rebuilds;
}

int solve_max() {
    int rebuilds = 0;

    for (int i = 0; i < K - 1; i++) {
        bool could = graph.dist[path[i]] != graph.dist[path[i + 1]] + 1;

        if (graph.previous_set[path[i]].size() > 1)
            could = true;

        if (could)
            rebuilds++;
    }

    return rebuilds;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.init(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph.add_directional_edge(v, u, 1);
    }

    cin >> K;
    path.resize(K);

    for (int &p : path) {
        cin >> p;
        p--;
    }

    graph.bfs({path.back()});
    cout << solve_min() << ' ' << solve_max() << '\n';
}