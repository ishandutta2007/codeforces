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

int n, a[N], p[N], up[N][20];
ll dist[N], dp[N];
vector<pair<int, int>> g[N];

void idfs(int x, ll d) {
    up[x][0] = p[x];
    for (int i = 1; i < 20; i++) up[x][i] = up[up[x][i - 1]][i - 1];

    dist[x] = d;
    for (auto &[v, w]: g[x]) {
        if (v == p[x]) continue;
        idfs(v, d + w);
    }
}

void dfs(int x) {
    for (auto &[v, w] : g[x]) {
        if (v == p[x]) continue;
        dfs(v);
        dp[x] += dp[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2, w; i <= n; i++) {
        cin >> p[i] >> w;
        g[i].emplace_back(p[i], w);
        g[p[i]].emplace_back(i, w);
    }

    idfs(1, 0);
    for (int i = 1; i <= n; i++) {
        int x = i, cur = a[x];
        for (int j = 19; j >= 0; j--) {
            if (up[x][j] and dist[x] - dist[up[x][j]] <= cur) {
                cur -= dist[x] - dist[up[x][j]];
                x = up[x][j];
            }
        }
        dp[p[x]]--;
        dp[p[i]]++;
    }

    dfs(1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " "; cout << "\n";
    return 0;
}