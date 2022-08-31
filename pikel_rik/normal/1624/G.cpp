#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct edge {
        int u, v, w;
    };

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<edge> e(m);
        vector<vector<int>> g(n);

        for (int i = 0; i < m; i++) {
            auto &[u, v, w] = e[i];
            cin >> u >> v >> w, --u, --v;
            g[u].push_back(i);
            g[v].push_back(i);
        }

        int min_or = 0;
        vector<bool> visited(n), deleted(m);

        for (int bit = 29; bit >= 0; bit--) {
            auto dfs = [&](int u, auto &&self) -> void {
                visited[u] = true;
                for (int i : g[u]) {
                    if (deleted[i]) {
                        continue;
                    }
                    int v = e[i].u ^ e[i].v ^ u;
                    if (!visited[v] && !(e[i].w & (1 << bit))) {
                        self(v, self);
                    }
                }
            };

            fill(visited.begin(), visited.end(), false);

            dfs(0, dfs);

            if (count(visited.begin(), visited.end(), false) == 0) {
                for (int i = 0; i < m; i++) {
                    if (e[i].w >> bit & 1) {
                        deleted[i] = true;
                    }
                }
            } else {
                min_or |= 1 << bit;
            }
        }

        cout << min_or << '\n';
    }
    return 0;
}