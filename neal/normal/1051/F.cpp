#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int NM_MAX = 1e5 + 5;
const int LOG = 17;
const int K_MAX = 22;

struct edge {
    int node, weight;

    edge(int _node = -1, int _weight = -1) : node(_node), weight(_weight) {}
};

int N, M, K;
int depth[NM_MAX];
int parent[NM_MAX];
int ancestor[LOG][NM_MAX];
vector<edge> adj[NM_MAX];

int special[2 * K_MAX];
long long special_dist[K_MAX][NM_MAX];

struct state {
    int node;
    long long dist;

    state(int _node = -1, long long _dist = -1) : node(_node), dist(_dist) {}

    bool operator<(const state &other) const {
        return dist > other.dist;
    }
};

inline void dijkstra_check(auto &pq, long long *my_dist, int node, long long current_dist) {
    if (current_dist < my_dist[node]) {
        my_dist[node] = current_dist;
        pq.push(state(node, current_dist));
    }
}

void special_dijkstra(int index) {
    long long *my_dist = special_dist[index];
    memset(my_dist, 63, NM_MAX * sizeof(my_dist[0]));
    priority_queue<state> pq;
    dijkstra_check(pq, my_dist, special[index], 0);

    while (!pq.empty()) {
        state top = pq.top(); pq.pop();

        if (top.dist > my_dist[top.node])
            continue;

        for (edge &e : adj[top.node])
            dijkstra_check(pq, my_dist, e.node, top.dist + e.weight);
    }
}

long long dist[NM_MAX];

void dfs(int node, int par) {
    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;

    for (edge &e : adj[node])
        if (e.node != par) {
            if (depth[e.node] < INF) {
                special[K++] = min(node, e.node);
                continue;
            }

            dist[e.node] = dist[node] + e.weight;
            dfs(e.node, node);
        }
}

void prepare_ancestors() {
    memcpy(ancestor[0], parent, sizeof(parent));

    for (int k = 1; k < LOG; k++)
        for (int i = 0; i < N; i++)
            ancestor[k][i] = ancestor[k - 1][i] < 0 ? -1 : ancestor[k - 1][ancestor[k - 1][i]];
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);

    for (int k = 0; k < LOG; k++)
        if ((depth[a] - depth[b]) >> k & 1)
            a = ancestor[k][a];

    if (a == b)
        return a;

    for (int k = LOG - 1; k >= 0; k--)
        if (ancestor[k][a] != ancestor[k][b]) {
            a = ancestor[k][a];
            b = ancestor[k][b];
        }

    assert(a != b);
    return parent[a];
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        a--; b--;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    memset(depth, 63, sizeof(depth));
    dist[0] = 0;
    K = 0;
    dfs(0, -1);
    prepare_ancestors();
    sort(special, special + K);
    K = unique(special, special + K) - special;
    assert(K < K_MAX);

    for (int k = 0; k < K; k++)
        special_dijkstra(k);

    int Q;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int start, end;
        scanf("%d %d", &start, &end);
        start--; end--;
        long long answer = dist[start] + dist[end] - 2 * dist[lca(start, end)];

        for (int k = 0; k < K; k++)
            answer = min(answer, special_dist[k][start] + special_dist[k][end]);

        printf("%lld\n", answer);
    }
}