#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, M, K;
vector<int> degree;
vector<set<int>> adj;
vector<pair<int, int>> edges;
vector<int> answers;
vector<bool> peeled;
int trip;

void peel(int node) {
    if (peeled[node])
        return;

    peeled[node] = true;
    trip--;

    for (int neighbor : adj[node]) {
        degree[node]--;
        degree[neighbor]--;
        adj[neighbor].erase(node);

        if (degree[neighbor] < K)
            peel(neighbor);
    }

    adj[node].clear();
}

void breakup(int a, int b) {
    if (adj[a].count(b) == 0)
        return;

    assert(adj[b].count(a));
    degree[a]--;
    degree[b]--;
    adj[a].erase(b);
    adj[b].erase(a);

    if (degree[a] < K)
        peel(a);

    if (degree[b] < K)
        peel(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    degree.resize(N);
    adj.resize(N);

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        degree[x]++;
        degree[y]++;
        edges.emplace_back(x, y);
        adj[x].insert(y);
        adj[y].insert(x);
    }

    peeled.assign(N, false);
    trip = N;

    for (int i = 0; i < N; i++)
        if (degree[i] < K)
            peel(i);

    answers.resize(M);

    for (int i = M - 1; i >= 0; i--) {
        answers[i] = trip;
        breakup(edges[i].first, edges[i].second);
    }

    for (int i = 0; i < M; i++)
        cout << answers[i] << '\n';
}