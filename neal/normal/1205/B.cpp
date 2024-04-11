#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
vector<vector<int>> adj;
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

            for (int neighbor : adj[top])
                bfs_check(q, next_q, neighbor, dist[top] + 1, 1, top);
        }

        swap(q, next_q);
        level++;
    }
}


const int BITS = 60;

vector<long long> A;
vector<int> how_many(BITS, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (long long &a : A) {
        cin >> a;

        for (int b = 0; b < BITS; b++)
            if (a >> b & 1)
                how_many[b]++;
    }

    for (int b = 0; b < BITS; b++)
        if (how_many[b] >= 3) {
            cout << 3 << '\n';
            return 0;
        }

    sort(A.rbegin(), A.rend());

    while (N > 0 && A.back() == 0) {
        A.pop_back();
        N--;
    }

    assert(N <= 2 * BITS);
    adj.assign(N, {});

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && (A[i] & A[j]) != 0)
                adj[i].push_back(j);

    int shortest = INF;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < (int) adj[i].size(); j++) {
            int neighbor = adj[i][j];
            adj[i].erase(adj[i].begin() + j);

            bfs({i});
            shortest = min(shortest, dist[neighbor] + 1);

            adj[i].insert(adj[i].begin() + j, neighbor);
        }

    cout << (shortest < INF ? shortest : -1) << '\n';
}