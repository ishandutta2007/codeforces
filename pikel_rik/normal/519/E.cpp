#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, d[N], st[N], fi[N], sz[N], T = 0, up[N][18];
vector<int> g[N];

void dfs(int x, int p, int h) {
    d[x] = h;
    sz[x] = 1;
    st[x] = T++;

    up[x][0] = p;
    for (int i = 1; i < 18; i++) {
        up[x][i] = up[up[x][i-1]][i-1];
    }

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x, h + 1);
        sz[x] += sz[i];
    }

    fi[x] = T++;
}

int lca(int u, int v) {
    if (st[u] <= st[v] and fi[u] >= fi[v])
        return u;
    if (st[v] <= st[u] and fi[v] >= fi[u])
        return v;

    int i = 17;
    while (i >= 0) {
        int w = up[u][i];
        if (w == 0 or (st[w] <= st[v] and fi[w] >= fi[v]))
            i--;
        else u = w, i--;
    }
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    d[0] = inf;

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    int m;
    cin >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;

        int l = lca(x, y);
        if (d[x] - d[l] == d[y] - d[l]) {
            int ans = n;
            int dist = d[x] - d[l] - 1;
            if (dist < 0) {
                cout << n << "\n";
                continue;
            }
            int temp = x;
            for (int i = 0; i < 18; i++) {
                if (dist & (1 << i))
                    temp = up[temp][i];
            }
            ans -= sz[temp];
            temp = y;
            dist = d[y] - d[l] - 1;
            for (int i = 0; i < 18; i++) {
                if (dist & (1 << i))
                    temp = up[temp][i];
            }
            ans -= sz[temp];
            cout << ans << "\n";
            continue;
        }

        int dist = d[x] + d[y] - 2 * d[l];
        if (d[x] < d[y]) swap(x, y);

        if (dist % 2 != 0) {
            cout << "0\n";
            continue;
        }

        dist /= 2;
        int temp1 = x, temp2 = x;
        for (int i = 0; i < 18; i++) {
            if (dist & (1 << i))
                temp1 = up[temp1][i];
        }

        dist -= 1;
        for (int i = 0; i < 18; i++) {
            if (dist & (1 << i))
                temp2 = up[temp2][i];
        }

        cout << sz[temp1] - sz[temp2] << "\n";
    }
    return 0;
}