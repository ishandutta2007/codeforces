#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

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

    vector<int>& operator[](const int &x) {
        return adj[x];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
        m++;
    }
};

class Matching {
public:
    Graph g;
    vector<int> d, match;
    vector<bool> visited;

    Matching(Graph& g): g(g), d(g.n, -1), match(g.n, -1), visited(g.n) {}

    void dfs(int x, int h) {
        d[x] = h;
        for (int &i : g[x]) {
            if (d[i] == -1)
                dfs(i, h ^ 1);
        }
    }
    bool dfs(int x) {
        for (int &i : g[x]) {
            if (!visited[i]) {
                visited[i] = true;
                if (match[i] < 0 or dfs(match[i])) {
                    match[i] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int size() {
        for (int i = 0; i < g.n; i++) {
            if (d[i] == -1)
                dfs(i, 0);
        }
        int matching = 0;

        for (int x = 0; x < g.n; x++) {
            if (!d[x]) {
                fill(visited.begin(), visited.end(), false);
                matching += dfs(x);
            }
        }
        return matching;
    }
};

const int N = 100 + 5;

int n, m, pref[N];
vector<int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                while (x % j == 0) {
                    a[i].push_back(j);
                    x /= j;
                }
            }
        }
        if (x > 1)
            a[i].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i].size();

    Graph g(pref[n]);

    for (int k = 0, i, j; k < m; k++) {
        cin >> i >> j;

        for (int i1 = 0; i1 < a[i].size(); i1++) {
            for (int i2 = 0; i2 < a[j].size(); i2++) {
                if (a[i][i1] == a[j][i2]) {
                    g.addEdge(pref[i - 1] + i1, pref[j - 1] + i2);
                }
            }
        }
    }

    cout << Matching(g).size() << "\n";
    return 0;
}