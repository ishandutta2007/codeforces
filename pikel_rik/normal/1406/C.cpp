#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, sz[N], dp[N];
vector<int> g[N];

void dfs(int x, int p) {
    sz[x] = 1;
    dp[x] = 0;
    for (auto& i : g[x]) {
        if (i == p) continue;
        dfs(i, x);
        sz[x] += sz[i];
        dp[x] = max(dp[x], sz[i]);
    }
    dp[x] = max(dp[x], n - sz[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) g[i].clear();

        pair<int, int> dummy;
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            dummy = {u, v};
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 0);

        int cur_max = INT_MAX;
        vector<int> centroids;

        for (int i = 1; i <= n; i++) {
            if (dp[i] < cur_max) {
                cur_max = dp[i];
                centroids.clear();
                centroids.push_back(i);
            } else if (dp[i] == cur_max) {
                centroids.push_back(i);
            }
        }

        if (centroids.size() == 1) {
            cout << dummy.first << ' ' << dummy.second << '\n';
            cout << dummy.first << ' ' << dummy.second << '\n';
        } else {
            dfs(centroids.back(), centroids.front());
            int cur = 0;
            for (auto& i : g[centroids.back()]) {
                if (i == centroids.front()) continue;
                if (sz[i] > sz[cur]) {
                    cur = i;
                }
            }
            cout << centroids.back() << ' ' << cur << '\n';
            cout << centroids.front() << ' ' << cur << '\n';
        }
    }
    return 0;
}