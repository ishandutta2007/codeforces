#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3000 + 5;

class Graph {
public:
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int>> adj;

    Graph(): n(), m(), adj(), edges() {}
    Graph(int n): n(n), m(), adj(n), edges() {}

    const vector<int>& operator[](const int& x) const { return adj[x]; }
    vector<int>& operator[](const int &x) { return adj[x]; }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
        m++;
    }
};

vector<int> bfs(int s, const Graph& g) {
    vector<bool> visited(g.n);
    vector<int> lvl(g.n);

    queue<int> q;
    q.push(s);

    visited[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto& i : g[x]) {
            if (!visited[i]) {
                visited[i] = true;
                lvl[i] = lvl[x] + 1;
                q.push(i);
            }
        }
    }
    return lvl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        g.addEdge(--u, --v);
    }

    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    --s1; --t1; --s2; --t2;

    vector<vector<int>> lvl(n);
    for (int i = 0; i < g.n; i++) {
        lvl[i] = bfs(i, g);
    }

    if (lvl[s1][t1] > l1 or lvl[s2][t2] > l2) {
        cout << "-1\n";
        return 0;
    }

    int ans = lvl[s1][t1] + lvl[s2][t2];
    for (int i = 0; i < g.n; i++) {
        for (int j = i + 1; j < g.n; j++) {
            if (lvl[s1][i] + lvl[i][j] + lvl[j][t1] <= l1 and lvl[s2][i] + lvl[i][j] + lvl[j][t2] <= l2)
                ans = min(ans, lvl[i][j] + lvl[s1][i] + lvl[s2][i] + lvl[j][t1] + lvl[j][t2]);
            if (lvl[s1][i] + lvl[i][j] + lvl[j][t1] <= l1 and lvl[t2][i] + lvl[i][j] + lvl[j][s2] <= l2)
                ans = min(ans, lvl[i][j] + lvl[s1][i] + lvl[t2][i] + lvl[j][t1] + lvl[j][s2]);
            if (lvl[t1][i] + lvl[i][j] + lvl[j][s1] <= l1 and lvl[t2][i] + lvl[i][j] + lvl[j][s2] <= l2)
                ans = min(ans, lvl[i][j] + lvl[t1][i] + lvl[t2][i] + lvl[j][s1] + lvl[j][s2]);
            if (lvl[t1][i] + lvl[i][j] + lvl[j][s1] <= l1 and lvl[s2][i] + lvl[i][j] + lvl[j][t2] <= l2)
                ans = min(ans, lvl[i][j] + lvl[t1][i] + lvl[s2][i] + lvl[j][s1] + lvl[j][t2]);
        }
    }
    cout << g.m - ans << '\n';
    return 0;
}