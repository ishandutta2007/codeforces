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
const int N = 2e5 + 5;

int n, f[N], T;
vector<int> g[N];
vector<pair<int, int>> edges;
bool ok, visited[N], active[N];

void dfs(int x) {
    visited[x] = true;
    active[x] = true;

    for (int &v: g[x]) {
        if (active[v])
            ok = false;
        else if (!visited[v])
            dfs(v);
    }
    active[x] = false;
    f[x] = T++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            g[i].clear(), visited[i] = false;
        edges.clear();

        for (int i = 0, u, v, w; i < m; i++) {
            cin >> w >> u >> v;
            if (w)
                g[u].emplace_back(v);
            edges.emplace_back(u, v);
        }

        T = 0;
        ok = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                dfs(i);
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (auto &[u, v]: edges) {
            if (f[u] < f[v])
                swap(u, v);
            cout << u << " " << v << "\n";
        }
    }
    return 0;
}