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

vector <vector <int>> g;
vector <int> tin, tout, h;
int T = 0;

void dfs(int v, int p = -1) {
    tin[v] = T++;
    for (auto& u : g[v]) if (u != p) {
        h[u] = h[v] + 1;
        dfs(u, v);
    }
    tout[v] = T++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    g.resize(n + 1);
    h.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

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
        h[root] = 0;
        dfs(root);
        sort(curQ.begin(), curQ.end(), [&](int v, int u) {
            return h[v] < h[u];
            });
        bool OK = true;
        int lx = -1, rx = 2 * n + 1;
        for (auto& x : curQ) {
            if (tin[x] < lx or rx < tout[x]) OK = false;
            else lx = tin[x], rx = tout[x];
        }
        cout << (OK ? "YES" : "NO") << '\n';
    }


    return 0;
}