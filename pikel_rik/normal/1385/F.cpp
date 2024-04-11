#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> g(n + 1);

        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (k == 1) {
            cout << n - 1 << "\n";
            continue;
        }

        queue<int> q;
        vector<int> leaf(n + 1), visited(n + 1);

        for (int i = 1; i <= n; i++) {
            if (g[i].size() <= 1)
                q.push(i), visited[i] = true;
        }

        int ans = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int &i : g[x]) {
                leaf[i]++;
                if (!visited[i] and leaf[i] >= g[i].size() - 1 and leaf[i] % k == 0) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++)
            ans += leaf[i] / k;
        cout << ans << "\n";
    }
    return 0;
}