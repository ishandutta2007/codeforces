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
const int N = 1e5 + 5;

int n, a[N], cur[N];
vector<int> g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (cur[i] == a[i])
            q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ans.push_back(u);
        cur[u] += 1;

        for (int &i : g[u]) {
            cur[i] += 1;
            if (cur[i] == a[i])
                q.push(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    return 0;
}