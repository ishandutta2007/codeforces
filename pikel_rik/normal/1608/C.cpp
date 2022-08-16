#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int i, int j) {
            return a[i] < a[j];
        });

        int a_winner = ind.back();

        vector<vector<int>> g(2 * n);
        for (int i = 1; i < n; i++) {
            g[ind[i - 1]].push_back(ind[i]);
        }

        sort(ind.begin(), ind.end(), [&](int i, int j) {
            return b[i] < b[j];
        });

        int b_winner = ind.back();

        for (int i = 1; i < n; i++) {
            g[n + ind[i - 1]].push_back(n + ind[i]);
        }

        for (int i = 0; i < n; i++) {
            g[i].push_back(n + i);
            g[n + i].push_back(i);
        }

        vector<bool> visited(2 * n);
        auto dfs = [&](int u, auto &&self) -> void {
            if (visited[u]) {
                return;
            }
            visited[u] = true;
            for (int v : g[u]) {
                if (!visited[v]) {
                    self(v, self);
                }
            }
        };

        dfs(a_winner, dfs);
        dfs(b_winner, dfs);

        for (int i = 0; i < n; i++) {
            cout << visited[i];
        }
        cout << '\n';
    }
    return 0;
}