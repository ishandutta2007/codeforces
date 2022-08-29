#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 1e18 + 5;

struct edge {
    int node, weight, index;
};

int N, M, K;
vector<vector<edge>> adj;
vector<long long> dist;
vector<int> prev_edge;

void dijkstra_check(auto &pq, int node, int index, long long current_dist) {
    if (current_dist < dist[node]) {
        dist[node] = current_dist;
        prev_edge[node] = index;
        pq.push(make_pair(current_dist, node));
    }
}

void dijkstra(int source) {
    dist.assign(N, LL_INF);
    prev_edge.assign(N, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dijkstra_check(pq, source, -1, 0);

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();

        int node = top.second;
        long long current_dist = top.first;

        if (current_dist > dist[node])
            continue;

        for (edge &e : adj[node]) {
            int neighbor = e.node;
            long long neighbor_dist = current_dist + e.weight;
            dijkstra_check(pq, neighbor, e.index, neighbor_dist);
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    adj.assign(N, {});

    for (int i = 0; i < M; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        x--; y--;
        adj[x].push_back({y, w, i});
        adj[y].push_back({x, w, i});
    }

    dijkstra(0);
    vector<int> indices(N);

    for (int i = 0; i < N; i++)
        indices[i] = i;

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return dist[a] < dist[b];
    });

    assert(indices[0] == 0);
    vector<int> keep;

    for (int i = 1; i < N && (int) keep.size() < K; i++)
        keep.push_back(prev_edge[indices[i]]);

    printf("%d\n", (int) keep.size());

    for (int i = 0; i < (int) keep.size(); i++)
        printf("%d%c", keep[i] + 1, i < (int) keep.size() - 1 ? ' ' : '\n');
}