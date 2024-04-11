#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <unordered_map>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define map unordered_map
vector <vector <int>> g;
vector <int> a, res;
vector <map <int, int>> cnt1, cnt2;
struct query {
    int k, id;
};
vector <vector <query>> qs;
// cnt1[i] = x -->
// x colors which appear exactly i times
// cnt2[i] = x -->
// color i appears exactly x times

void dfs(int v, int p = -1) {
    cnt1[v][1] = 1;
    cnt2[v][a[v]] = 1;
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (cnt2[u].size() > cnt2[v].size()) {
            cnt2[u].swap(cnt2[v]);
            cnt1[u].swap(cnt1[v]);
        }
        for (auto x : cnt2[u]) {
            if (cnt2[v].find(x.first) != cnt2[v].end())
                cnt1[v][cnt2[v][x.first]]--;
            cnt2[v][x.first] += x.second;
            cnt1[v][cnt2[v][x.first]]++;
        }
    }
    for (auto &x : qs[v]) {
        int get = 0;
        for (auto it = cnt1[v].begin(); it != cnt1[v].end(); it++) {
            if (it->first < x.k) continue;
            get += it->second;
        }
        res[x.id] = get;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n, q; cin >> n >> q;
    g.resize(n + 1);
    a.resize(n + 1);
    res.resize(q);
    qs.resize(n + 1);
    cnt1.resize(n + 1);
    cnt2.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < q; ++i) {
        int v, k; cin >> v >> k;
        qs[v].push_back({ k, i });
    }
    dfs(1);
    for (auto x : res) cout << x << '\n';
    cout << '\n';
    return 0;
}