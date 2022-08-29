#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N), B(N), C(N);

    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i];

    vector<int> latest(N);

    for (int i = 0; i < N; i++)
        latest[i] = i;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        latest[v] = max(latest[v], u);
    }

    vector<vector<int>> reaches(N);

    for (int i = 0; i < N; i++)
        reaches[latest[i]].push_back(i);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        if (K < A[i]) {
            cout << -1 << '\n';
            return 0;
        }

        while ((int) pq.size() > K - A[i])
            pq.pop();

        K += B[i];

        for (int x : reaches[i])
            pq.push(C[x]);
    }

    long long total = 0;

    while (!pq.empty()) {
        total += pq.top();
        pq.pop();
    }

    cout << total << '\n';
}