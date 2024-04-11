#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7;
struct DSU {
    vector <int> p, sz;
    DSU(int n) {
        p.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int get(int a) {
        return p[a] = p[a] == a ? a : get(p[a]);
    }
    bool unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
vector <int> tin, tout;
vector <vector <int>> g;
int timer = 1;
void dfs(int v) {
    tin[v] = timer++;
    for (auto u : g[v]) {
        dfs(u);
    }
    tout[v] = timer++;
}
bool isAnc(int u, int v) {
    return tin[u] <= tin[v] and tout[v] <= tout[u];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    g.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    vector <vector <int>> qs;
    vector <vector <pair <int, int>>> qq(q + 2);
    set <int> need;
    for (int i = 1; i <= n; ++i)
        need.insert(i);
    for (int i = 0; i < q; ++i) {
        int t, x, y; cin >> t;
        if (t == 1) {
            cin >> x >> y;
            g[y].push_back(x);
            need.erase(x);
            qs.push_back({ t, x, y });
        }
        else if (t == 2) {
            cin >> x;
            qs.push_back({ t, x });
        }
        else {
            cin >> x >> y;
            qq[y].push_back({ x, i });
        }
    }
    for (auto x : need)
        dfs(x);
    vector <vector <int>> ans;
    int last = 1;
    DSU forest(n + 1);
    for (auto x : qs) {
        if (x[0] == 1) {
            forest.unite(x[1], x[2]);
        }
        else {
            for (auto y : qq[last]) {
                if (forest.get(y.first) == forest.get(x[1])
                    and tin[y.first] <= tin[x[1]]
                    and tout[x[1]] <= tout[y.first])
                    ans.push_back({ y.second, 1 });
                else
                    ans.push_back({ y.second, 0 });
            }
            last++;
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << (x[1] ? "YES" : "NO") << '\n';
    return 0;
}