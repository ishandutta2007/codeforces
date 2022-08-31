#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct edge {
    int node = -1, weight = -1;

    edge() {}

    edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

int N;
vector<vector<edge>> adj;
vector<int> dist;
vector<int> previous;

void bfs_check(queue<int> &q, queue<int> &next_q, int node, int from, int new_dist, int add) {
    assert(0 <= add && add <= 1);

    if (new_dist < dist[node]) {
        dist[node] = new_dist;
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


int M, K;
vector<int> special;
vector<int> dist_1, dist_n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    special.resize(K);
    adj.assign(N, {});

    for (int &a : special) {
        cin >> a;
        a--;
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].emplace_back(y, 1);
        adj[y].emplace_back(x, 1);
    }

    bfs({0});
    dist_1 = dist;
    bfs({N - 1});
    dist_n = dist;

    sort(special.begin(), special.end(), [&](int a, int b) {
        return dist_1[a] - dist_n[a] < dist_1[b] - dist_n[b];
    });

    int maximum = -INF;
    int best = -INF;

    for (int s : special) {
        best = max(best, maximum + 1 + dist_n[s]);
        maximum = max(maximum, dist_1[s]);
    }

    cout << min(best, dist_1[N - 1]) << '\n';
}