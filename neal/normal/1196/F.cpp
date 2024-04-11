#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct edge {
    int node, weight;
};

int N, M, K;
vector<vector<edge>> adj;
map<pair<int, int>, long long> dist;
set<pair<long long, pair<int, int>>> closest, distances;

void attempt_push(int x, int y, long long current_dist) {
    if (x == y)
        return;

    pair<int, int> path = {min(x, y), max(x, y)};

    if ((int) distances.size() < K || current_dist < distances.rbegin()->first) {
        if (dist.find(path) == dist.end() || current_dist < dist[path]) {
            pair<long long, pair<int, int>> dist_pair = {dist[path], path};
            closest.erase(dist_pair);
            distances.erase(dist_pair);

            dist_pair.first = dist[path] = current_dist;;
            closest.insert(dist_pair);
            distances.insert(dist_pair);

            if ((int) distances.size() > K)
                distances.erase(--distances.end());
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    adj.assign(N, {});

    for (int i = 0; i < M; i++) {
        int x, y, weight;
        cin >> x >> y >> weight;
        x--; y--;

        if (x > y)
            swap(x, y);

        adj[x].push_back({y, weight});
        adj[y].push_back({x, weight});
        attempt_push(x, y, weight);
    }

    long long answer = 0;
    int paths = 0;

    while (paths < K) {
        pair<long long, pair<int, int>> top = *closest.begin();
        closest.erase(closest.begin());
        assert(top.first == dist[top.second]);

        paths++;
        answer = top.first;
        int x = top.second.first, y = top.second.second;

        for (edge &e : adj[x])
            attempt_push(e.node, y, top.first + e.weight);

        for (edge &e : adj[y])
            attempt_push(x, e.node, top.first + e.weight);
    }

    cout << answer << '\n';
}