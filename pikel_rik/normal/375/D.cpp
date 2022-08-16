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

int n, m, c[N], ans[N], k[N];
vector<int> g[N], q[N];
map<int, int> cnt[N], f[N];

void dfs(int x, int p) {
    cnt[x][c[x]]++; f[x][1]++;

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x);

        if (cnt[i].size() > cnt[x].size()) {
            cnt[x].swap(cnt[i]);
            f[x].swap(f[i]);
        }

        for (auto &[col, c]: cnt[i]) {
            int y = cnt[x][col];
            cnt[x][col] += c;
            for (int j = y + 1; j <= y + c; j++) f[x][j]++;
        }
    }

    for (int i : q[x]) {
        ans[i] = f[x][k[i]];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0, v; i < m; i++) {
        cin >> v >> k[i];
        q[v].push_back(i);
    }

    dfs(1, 0);
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
    return 0;
}