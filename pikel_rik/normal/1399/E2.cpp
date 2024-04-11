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

struct item {
    int a, b, c;
    item(int a, int b, int c): a(a), b(b), c(c) {}
};

int n, sz[N];
ll s, cur;
vector<item> g[N];
vector<ll> v[2];

void dfs(int x, int p) {
    sz[x] = (p and g[x].size() <= 1);

    for (auto &[i, w, c] : g[x]) {
        if (i == p) continue;
        dfs(i, x);
        cur += w * (ll)sz[i];

        while (w) {
            v[c].push_back((w - w / 2) * (ll)sz[i]);
            w /= 2;
        }

        sz[x] += sz[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) g[i].clear();

        for (int i = 1, u, v, w, c; i < n; i++) {
            cin >> u >> v >> w >> c; --c;
            g[u].emplace_back(v, w, c);
            g[v].emplace_back(u, w, c);
        }

        v[0] = v[1] = {0};
        cur = 0;
        dfs(1, 0);
        int ans = INT_MAX;

        sort(1 + all(v[0]), greater<>());
        for (int i = 1; i < v[0].size(); i++) {
            v[0][i] += v[0][i - 1];
        }

        sort(1 + all(v[1]), greater<>());
        for (int i = 1; i < v[1].size(); i++) {
            v[1][i] += v[1][i - 1];
        }

        for (int i = 0; i < v[0].size(); i++) {
            if (cur - s - v[0][i] > v[1].back())
                continue;
            ans = min(ans, i + 2 * (lower_bound(all(v[1]), cur - s - v[0][i]) - v[1].begin()));
        }

        cout << ans << "\n";
    }
    return 0;
}