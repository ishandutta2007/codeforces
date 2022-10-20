#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3010;
const int LOG = 15;

int n;
vector<int> adj[N];
int dp[N][N];
pair<int, int> b[N][N];

int dist[N][N];
int lv[N];
int numChild[N];
int used[N][N];

void dfs(int u, int p, int s, int d) {
    dist[u][s] = d;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, s, d + 1);
    }
}


void dfsInit(int u, int p)  {
    lv[u] = lv[p] + 1;
    numChild[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfsInit(v, u);
        numChild[u] += numChild[v];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<int, int>> ls;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ls.push_back({u, v});
    }   
    int res = 0;
    for (int i = 1; i <= n; i++) {
        dfs(i, 0, i, 0);
    }
    dfsInit(1, 0);

    queue<pair<int, int>> q;
    for (auto u : ls) {
        int x, y;
        tie(x, y) = u;
        if (x > y) swap(x, y);
        pair<int, int> now;
        now.first = lv[x] < lv[y] ? n - numChild[y] : numChild[x];
        now.second = lv[y] < lv[x] ? n - numChild[x] : numChild[y];
        b[x][y] = now;
        dp[x][y] = now.first * now.second; 
        res = max(res, dp[x][y]);
        used[x][y] = 1;
        q.push({x, y});
    }
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int u : adj[x]) {
            if (dist[u][x] + dist[u][y] == dist[x][y]) continue;
            pair<int, int> now;
            now.second = b[x][y].second;
            now.first = lv[u] < lv[x] ? n - numChild[x] : numChild[u];
            int v = y;
            if (u > v) {
                swap(u, v);
                swap(now.first, now.second);
            }
            dp[u][v] = max(dp[u][v], dp[x][y] + now.first * now.second);
            b[u][v] = now;
            res = max(res, dp[u][v]);
            if (!used[u][v]) {
                used[u][v] = 1;
                q.push({u, v});
            }
        }

        for (int u : adj[y]) {
            if (dist[u][x] + dist[u][y] == dist[x][y]) continue;
            pair<int, int> now;
            now.second = b[x][y].first;
            now.first = lv[u] < lv[y] ? n - numChild[y] : numChild[u];
            int v = x;
            if (u > v) {
                swap(u, v);
                swap(now.first, now.second);
            }
            dp[u][v] = max(dp[u][v], dp[x][y] + now.first * now.second);
            b[u][v] = now;
            res = max(res, dp[u][v]);
            if (!used[u][v]) {
                used[u][v] = 1;
                q.push({u, v});
            }
        }
    }
    cout << res << endl;
    return 0;   
}