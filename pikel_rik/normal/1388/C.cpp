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

int n, m;
ll p[N], h[N], sz[N], gd[N], bd[N];
vector<int> g[N];

bool ok;

void dfs(int x, int par) {
    sz[x] = p[x];
    ll sum1 = 0, sum2 = 0;

    for (int &i : g[x]) {
        if (i == par) continue;
        dfs(i, x);
        sz[x] += sz[i];
        sum1 += gd[i];
        sum2 += bd[i];
    }

    if (sz[x] < abs(h[x]) or ((sz[x] - abs(h[x])) & 1))
        ok = false;

    gd[x] = bd[x] = (sz[x] - abs(h[x])) / 2;
    if (h[x] < 0)
        bd[x] -= h[x];
    else gd[x] += h[x];

    ok &= (sum1 <= gd[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) g[i].clear();

        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];

        for (int i = 1, x, y; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        ok = true;
        dfs(1, 0);

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}