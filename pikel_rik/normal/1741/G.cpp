#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int inf = (int) 1e8;

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n);
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v, --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int f;
        cin >> f;

        vector<int> h(f);
        for (auto &x : h) cin >> x, --x;

        int k;
        cin >> k;

        vector<int> p(k);
        for (auto &x : p) cin >> x, --x;

        auto bfs = [&](int s) -> vector<int> {
            vector<int> lvl(n, -1);

            queue<int> q;
            lvl[s] = 0;
            q.push(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (lvl[v] == -1) {
                        lvl[v] = 1 + lvl[u];
                        q.push(v);
                    }
                }
            }

            return lvl;
        };

        vector<vector<int>> dist(k);
        for (int i = 0; i < k; i++) {
            dist[i] = bfs(h[p[i]]);
        }

        vector<int> dist_s = bfs(0);

        vector<vector<int>> distance(1 << k, vector<int>(k, inf));
        for (int mask = 1; mask < (1 << k); mask++) {
            if (__builtin_popcount(mask) == 1) {
                for (int i = 0; i < k; i++) {
                    if (mask >> i & 1) {
                        distance[mask][i] = dist_s[h[p[i]]];
                    }
                }
            } else {
                for (int i = 0; i < k; i++) {
                    if (mask >> i & 1) {
                        for (int j = 0; j < k; j++) {
                            if (j != i && (mask >> j & 1)) {
                                distance[mask][i] = min(distance[mask][i], dist[j][h[p[i]]] + distance[mask ^ (1 << i)][j]);
                            }
                        }
                    }
                }
            }
        }

        vector<int> dp(1 << k);
        dp[0] = 1;

        for (int i = 0; i < f; i++) {
            if (find(p.begin(), p.end(), i) != p.end()) {
                continue;
            }

            vector<int> new_dp = dp;
            for (int mask = 1; mask < (1 << k); mask++) {
                bool possible = false;
                for (int j = 0; j < k; j++) {
                    if ((mask >> j & 1) && distance[mask][j] + dist[j][h[i]] == dist_s[h[i]]) {
                        possible = true;
                        break;
                    }
                }

                if (possible) {
                    for (int from_mask = 0; from_mask < (1 << k); from_mask++) {
                        new_dp[from_mask | mask] |= dp[from_mask];
                    }
                }
            }

            for (int mask = 0; mask < (1 << k); mask++) {
                dp[mask] |= new_dp[mask];
            }
        }

        int answer = k;
        for (int mask = 0; mask < (1 << k); mask++) {
            if (dp[mask]) {
                answer = min(answer, k - __builtin_popcount(mask));
            }
        }

        cout << answer << '\n';
    }
    return 0;
}