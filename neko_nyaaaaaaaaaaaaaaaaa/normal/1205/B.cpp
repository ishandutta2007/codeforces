#include <bits/stdc++.h>
using namespace std;

vector<int> adj[120];

int solve(vector<pair<int, int>> edges, int x, int y, int n) {
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }

    for (auto [i, j]: edges) {
        if (i == x && j == y) continue;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    vector<int> dist(n, 10000);
    dist[x] = 0;

    queue<int> q;
    q.push(x);

    while (q.size()) {
        int now = q.front(); q.pop();
        for (int u: adj[now]) {
            if (dist[u] > dist[now] + 1) {
                dist[u] = dist[now] + 1;
                q.push(u);
            }
        }
    }

    return dist[y] + 1;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<long long>());
    while (a.size() && (a.back() == 0)) a.pop_back();

    n = a.size();
    if (n == 0) {
        cout << -1;
        return 0;
    }

    if (n > 120) {
        cout << "3";
        return 0;
    }

    vector<int> cnt(61);
    for (int i = 0; i < n; i++) {
        for (long long b = 0; b < 60; b++) {
            if ((1LL << b) & a[i]) {
                cnt[b]++;
            }
            if (cnt[b] >= 3) {
                cout << "3"; return 0;
            }
        }
        if (__builtin_popcountll(a[i]) <= 1) a[i] = 0;
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if ((a[i] & a[j]) != 0) {
                edges.emplace_back(i, j);
            }
        }
    }

    int ans = 10000;
    for (auto [x, y]: edges) {
        int ss = solve(edges, x, y, n);
        //cout << x << ' ' << y << ' ' << ss << '\n';
        ans = min(ans, ss);
    }

    if (ans == 10000) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}