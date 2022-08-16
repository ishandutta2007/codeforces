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

int n, p[N], up[N][20], lvl[N], tin[N], tout[N], T;
vector<int> roots, g[N], dep[N];

void dfs(int x, int d = 0) {
    up[x][0] = p[x];
    for (int i = 1; i < 20; i++)
        up[x][i] = up[up[x][i - 1]][i - 1];

    tin[x] = T++;
    lvl[x] = d;
    dep[d].push_back(x);

    for (int &i : g[x]) {
        if (i == p[x]) continue;
        dfs(i, d + 1);
    }

    tout[x] = T++;
}

int par(int x, int k) {
    for (int i = 20; i >= 0; i--) {
        if (k & (1 << i))
            x = up[x][i];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i]) {
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }
        else {
            roots.push_back(i);
        }
    }

    for (int i : roots) {
        dfs(i);
    }

    int m;
    cin >> m;

    while (m--) {
        int v, x;
        cin >> v >> x;

        int a = par(v, x);
        if (!a) {
            cout << "0 ";
            continue;
        }

        int d = lvl[v];

        int lo = 0, hi = dep[d].size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (tin[dep[d][mid]] > tin[a])
                hi = mid;
            else lo = mid + 1;
        }

        int ans1 = lo;
        lo = 0; hi = dep[d].size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (tout[dep[d][mid]] < tout[a])
                lo = mid;
            else hi = mid - 1;
        }

        int ans2 = lo;
        cout << ans2 - ans1 << " ";
    }
    return 0;
}