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
const int N = 1e5 + 5;

int n, a[N], p[N];
vector<int> ans, g[N], like[N];

bool visited[N], ok = true;

void dfs(int x) {
    if (x != a[x] and a[x] != a[p[x]])
        ok = false;
    visited[x] = true;
    for (int &i : g[x])
        dfs(i);
}

void construct(int x) {
    visited[x] = true;
    for (int &i : g[x])
        construct(i);

    if (x == a[x]) {
        ans.push_back(x);
        for (int i : like[x]) {
            if (i != x)
                ans.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        p[v] = u;
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i], like[a[i]].push_back(i);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int j = i;
            while (p[j] != 0)
                j = p[j];
            dfs(j);
        }
    }

    if (!ok) {
        cout << "-1\n";
        return 0;
    }

    fill(visited, visited + n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int j = i;
            while (p[j] != 0)
                j = p[j];
            construct(j);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << "\n";
    return 0;
}