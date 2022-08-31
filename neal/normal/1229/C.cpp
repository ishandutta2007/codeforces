#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<int> in_degree(N, 0), out_degree(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (a > b)
            swap(a, b);

        adj[a].push_back(b);
        in_degree[a]++;
        out_degree[b]++;
    }

    long long triples = 0;

    for (int i = 0; i < N; i++)
        triples += (long long) in_degree[i] * out_degree[i];

    cout << triples << '\n';
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int v;
        cin >> v;
        v--;

        triples -= (long long) in_degree[v] * out_degree[v];
        out_degree[v] += in_degree[v];
        in_degree[v] = 0;

        for (int neighbor : adj[v]) {
            out_degree[neighbor]--;
            triples -= in_degree[neighbor];

            in_degree[neighbor]++;
            triples += out_degree[neighbor];

            adj[neighbor].push_back(v);
        }

        adj[v].clear();
        cout << triples << '\n';
    }
}