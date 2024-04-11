#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int INF = 1e9;

int n, m;
vector<int> adj[N], revAdj[N];
int d[N];
int k, p[N];
int used[N];

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    queue<int> q;
    d[p[k]] = 0;
    q.push(p[k]);
    used[p[k]] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : revAdj[u]) {
            if (!used[v]) {
                used[v] = 1;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }
    dijkstra();
    int minRes = 0, maxRes = 0;
    for (int i = 1; i < k; i++) {
        int goV = 0, goElse = 0;
        for (int v : adj[p[i]]) {
            if (d[p[i]] == d[v] + 1) {
                if (v == p[i + 1]) goV = 1;
                else goElse = 1;
            }
        }
        if (!goV) {
            minRes++;
        }
        if (goElse) maxRes++;
    }
    cout << minRes << ' ' << maxRes << endl;
    return 0;
}