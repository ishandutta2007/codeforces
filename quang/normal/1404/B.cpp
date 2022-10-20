#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a, b, da, db;
vector<int> adj[N];
int d[N];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        d[1] = 0;
        dfs(1, 0);
        int root = 1;
        for (int i = 2; i <= n; i++) {
            if (d[i] > d[root]) root = i;
        }
        d[root] = 0;
        dfs(root, 0);
        int maxDist = *max_element(d + 1, d + n + 1);


        d[a] = 0;
        dfs(a, 0);

        if (db >= 2 * da + 1 && maxDist >= 2 * da + 1 && d[b] > da) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }   
    return 0;
}