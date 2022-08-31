#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, D, K;
vector<int> dist;
queue<int> q;
vector<vector<int>> adj;

void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool bfs() {
    if (D > N - 1)
        return false;

    if (K == 1 && D > 1)
        return false;

    adj.resize(N);

    for (int i = 0; i <= D; i++) {
        dist.push_back(D / 2 - min(i, D - i));
        q.push(i);

        if (i < D)
            add_edge(i, i + 1);
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (dist[current] >= D / 2)
            continue;

        while ((int) adj[current].size() < K && (int) dist.size() < N) {
            int neighbor = dist.size();
            dist.push_back(dist[current] + 1);
            add_edge(current, neighbor);
            q.push(neighbor);
        }
    }

    return (int) dist.size() == N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> D >> K;

    if (!bfs()) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';

    for (int i = 0; i < N; i++)
        for (int neighbor : adj[i])
            if (i < neighbor)
                cout << i + 1 << ' ' << neighbor + 1 << '\n';

    return 0;
}