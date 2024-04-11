#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> G(N);
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        vector<vector<int>> DP(N, vector<int>(2, 0));
        // DP[n][0] = n as root, DP[n][1] = n and its parent is already picked
        function<void(int, int)> dfs = [&](int n, int p) {
            vector<int> opt;
            for (auto i : G[n]) if (i != p) {
                dfs(i, n);
                DP[n][0] = max(DP[n][0], DP[i][0]);
                DP[n][1] = max(DP[n][1], DP[i][1]);
                opt.emplace_back(DP[i][1]);
            }
            DP[n][1] += (int)G[n].size() - 1; // n and its parent is accounted for (-2), new DP[to][1] (+1)

            sort(begin(opt), end(opt));
            reverse(begin(opt), end(opt));

            int x = 0;
            for (int i = 0; i < min(2, (int)opt.size()); i++) {
                x += opt[i];
            }
            x += G[n].size() + 1; // count itself
            DP[n][0] = max(DP[n][0], x);
        };

        int root = 0;
        for (int i = 0; i < N; i++) {
            if (G[i].size() > 1) {
                root = i;
                break;
            }
        }
        dfs(root, -1);
        cout << DP[root][0] << "\n";
    }

    return 0;
}