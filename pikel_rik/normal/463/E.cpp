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
const int A = 2e6 + 1;

int n, q, a[N], ans[N], lvl[N];
vector<int> g[N], d[A], visited[A];

void dfs(int x, int p = 0, int h = 0) {
    lvl[x] = h;
    ans[x] = -1;

    for (int i : d[a[x]]) {
        if (!visited[i].empty()) {
            if (ans[x] == -1)
                ans[x] = visited[i].back();
            else if (lvl[ans[x]] < lvl[visited[i].back()])
                ans[x] = visited[i].back();
        }
        visited[i].push_back(x);
    }

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x, h + 1);
    }

    for (int i : d[a[x]]) {
        visited[i].pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < A; i++) {
        if (d[i].empty()) {
            for (int j = i; j < A; j += i) {
                d[j].push_back(i);
            }
        }
    }

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int v;
            cin >> v;

            cout << ans[v] << "\n";
        }
        else {
            int v, w;
            cin >> v >> w;

            a[v] = w;
            dfs(1);
        }
    }
    return 0;
}