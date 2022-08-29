#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct edge {
    int node, weight;

    edge() {}

    edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

int N;
vector<vector<edge>> adj;
vector<int> dist;
vector<int> previous;

void bfs_check(queue<int> &q, queue<int> &next_q, int node, int current_dist, int add, int from) {
    assert(0 <= add && add <= 1);

    if (current_dist < dist[node]) {
        dist[node] = current_dist;
        previous[node] = from;
        (add == 0 ? q : next_q).push(node);
    }
}

void bfs(const vector<int> &source) {
    if (N == 0) return;
    // Two queues are needed for 0-1 BFS.
    queue<int> q, next_q;
    dist.assign(N, INF);
    previous.assign(N, -1);

    for (int src : source)
        bfs_check(q, next_q, src, 0, 0, -1);

    int level = 0;

    while (!q.empty() || !next_q.empty()) {
        while (!q.empty()) {
            int top = q.front(); q.pop();

            if (level > dist[top])
                continue;

            for (edge &e : adj[top])
                bfs_check(q, next_q, e.node, dist[top] + e.weight, e.weight, top);
        }

        swap(q, next_q);
        level++;
    }
}


vector<int> A;

void add_edge(int node, int neighbor) {
    if (0 <= neighbor && neighbor < N) {
        if (A[node] % 2 == A[neighbor] % 2)
            adj[neighbor].emplace_back(node, 1);
        else
            adj[N].emplace_back(node, 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    adj.assign(N + 1, {});

    for (int i = 0; i < N; i++) {
        add_edge(i, i - A[i]);
        add_edge(i, i + A[i]);
    }

    N++;
    bfs({N - 1});
    N--;

    for (int i = 0; i < N; i++)
        cout << (dist[i] < INF ? dist[i] : -1) << (i < N - 1 ? ' ' : '\n');
}