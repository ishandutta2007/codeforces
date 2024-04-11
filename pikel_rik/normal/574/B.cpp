#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 4e3 + 5;

int n, sum[N];
bool adj[N][N];

vector<pair<int, int>> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        sum[u] += 1;
        sum[v] += 1;
        adj[u][v] = adj[v][u] = true;
        edges.emplace_back(u, v);
    }

    int best = INT_MAX;
    for (auto p : edges) {
        int u = p.first, v = p.second;
        for (int i = 1; i <= n; i++) {
            if (adj[u][i] and adj[v][i])
                best = min(best, sum[u] + sum[v] + sum[i] - 6);
        }
    }

    if (best == INT_MAX) cout << "-1\n";
    else cout << best << "\n";

    return 0;
}