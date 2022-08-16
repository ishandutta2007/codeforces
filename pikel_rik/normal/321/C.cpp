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

int n, sz[N], ans[N];
vector<int> g[N];

bool visited[N];

void dfss(int x, int p = 0) {
    sz[x] = 1;

    for (int &i : g[x]) {
        if (i == p or visited[i]) continue;
        dfss(i, x);
        sz[x] += sz[i];
    }
}

int find_center(int x, int p, int n) {
    for (int &i : g[x]) {
        if (visited[i] or i == p or sz[i] <= n / 2) continue;
        return find_center(i, x, n);
    }
    return x;
}

void dfs(int x, int d = 0) {
    dfss(x);
    int c = find_center(x, 0, sz[x]);

    ans[c] = d;
    visited[c] = true;

    for (int &i : g[c]) {
        if (visited[i]) continue;
        dfs(i, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) cout << (char)('A' + ans[i]) << " ";
    return 0;
}