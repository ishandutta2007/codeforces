#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#include <climits>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double

const int mod = 1e9 + 7, N = 2e5 + 7;

vector <vector <pair <int, int>>> g, base;
vector <int> ans;
int get(int x) {
    int res = 0;
    while (x) 
        res ^= x & 1, x >>= 1;
    return res;
}

bool dfs(int v, int val) {
    if (ans[v] != -1) return ans[v] == val;
    ans[v] = val;
    for (auto u : g[v]) {
        if (!dfs(u.first, val ^ u.second))
            return false;
    }
    return true;
}

void recovery(int v, int p) {
    for (auto u : base[v]) {
        if (u.first == p) continue;
        cout << u.first + 1 << ' ' << v + 1 << ' ';
        cout << (u.second != -1 ? u.second : (ans[u.first] != ans[v])) << '\n';
        recovery(u.first, v);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        g.assign(n, {});
        ans.assign(n, -1);
        base.assign(n, {});
        for (int i = 0, u, v, w; i < n - 1; ++i) {
            cin >> u >> v >> w;
            --u, --v;
            base[u].push_back({ v, w });
            base[v].push_back({ u, w });
            if (w == -1) continue;
            g[u].push_back({ v, get(w) });
            g[v].push_back({ u, get(w) });
        }
        for (int i = 0, a, b, p; i < m; ++i) {
            cin >> a >> b >> p;
            --a, --b;
            if (p == 0) {
                g[a].push_back({ b, 0 });
                g[b].push_back({ a, 0 });
            }
            else {
                g[a].push_back({ b, 1 });
                g[b].push_back({ a, 1 });
            }
        }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (ans[i] != -1) continue;
            ok = ok && dfs(i, 0);
        }
        if (!ok) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            recovery(0, 0);
        }
    }
    
}