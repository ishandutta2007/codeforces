#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long 

const int mod = 1e9 + 7, N = 52;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int n, m; cin >> n >> m;
    vector <set <int>> g(n + 1, { 0 });
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (i > * (--g[i].end()));
    }
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            if (u > * (--g[u].end())) cnt--;
            if (v > * (--g[v].end())) cnt--;
            g[u].insert(v);
            g[v].insert(u);
            if (u > * (--g[u].end())) cnt++;
            if (v > * (--g[v].end())) cnt++;
        }
        else if (t == 2) {
            int u, v; cin >> u >> v;
            if (u > * (--g[u].end())) cnt--;
            if (v > * (--g[v].end())) cnt--;
            g[u].erase(v);
            g[v].erase(u);
            if (u > * (--g[u].end())) cnt++;
            if (v > * (--g[v].end())) cnt++;
        }
        else cout << cnt << '\n';
    }
    return 0;
}