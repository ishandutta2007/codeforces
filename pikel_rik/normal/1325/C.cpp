#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n;
vector<int> g[N];
vector<pair<int, int>> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    vector<int> ans(n - 1, -1);

    int cur = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = edges[i].first, v = edges[i].second;
        if (g[u].size() == 1 or g[v].size() == 1)
            ans[i] = cur++;
    }

    for (int i = 0; i < n - 1; i++) {
        if (ans[i] != -1) cout << ans[i] << "\n";
        else cout << cur++ << "\n";
    }
    return 0;
}