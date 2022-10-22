#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, B = 60, N = 1e3 + 15;

vector <vector <int>> g, binup;
vector <int> tin, tout, h;
int T = 0, L = 0;

void dfs(int v, int p) {
    tin[v] = T++;
    binup[0][v] = p;
    for (int i = 1; i < L; ++i)
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    for (auto& u : g[v]) if (u != p) {
        h[u] = h[v] + 1;
        dfs(u, v);
    }
    tout[v] = T++;
}

bool isAnc(int u, int v) {
    return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int lca(int u, int v) {
    if (isAnc(u, v)) return u;
    if (isAnc(v, u)) return v;
    for (int i = L - 1; i >= 0; --i) {
        if (!isAnc(binup[i][u], v))
            u = binup[i][u];
    }
    return binup[0][u];
}

int lca(int u, int v, int root) {
    return lca(u, v) ^ lca(u, root) ^ lca(v, root);
}

int dist(int u, int v) {
    int w = lca(u, v);
    return h[u] + h[v] - 2 * h[w];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    while ((1ll << L) <= n) L++;
    binup.resize(L, vector <int>(n + 1));
    g.resize(n + 1);
    h.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);

    int q; cin >> q;
    while (q-- > 0) {
        T = 0;
        int k; cin >> k;
        vector <int> curQ(k);
        for (auto& x : curQ) cin >> x;
        sort(curQ.begin(), curQ.end(), [&](int v, int u) {
            return h[v] > h[u];
            });
        int root = curQ[0];
        sort(curQ.begin(), curQ.end(), [&](int v, int u) {
            return dist(v, root) < dist(u, root);
            });
        bool OK = true;
        int lst = root;
        for (auto& x : curQ) {
            if (lca(x, lst, root) != lst) OK = false;
            lst = x;
        }
        cout << (OK ? "YES" : "NO") << '\n';
    }


    return 0;
}