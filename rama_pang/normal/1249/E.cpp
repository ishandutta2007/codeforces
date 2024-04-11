#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, c;
    cin >> n >> c;

    vector<vector<pair<int, int>>> g(n + n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        g[i - 1].emplace_back(i, a);
        g[i].emplace_back(i - 1, a);
    }

    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        g[n + i - 1].emplace_back(n + i, a);
        g[n + i].emplace_back(n + i - 1, a);
    }

    for (int i = 0; i < n; i++) {
        g[i].emplace_back(i + n, c);
        g[i + n].emplace_back(i, 0);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + n, -1);
    pq.emplace(0, 0);
    dist[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if (dist[u] != w) {
            continue;
        }
        for (auto i : g[u]) {
            if (dist[i.first] == -1 || dist[i.first] > dist[u] + i.second) {
                dist[i.first] = dist[u] + i.second;
                pq.emplace(dist[i.first], i.first);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i == n - 1];
    }
    return 0;
}