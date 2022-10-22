#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e5 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    int n, m; cin >> n >> m;
    vector <int> color(n + 1);
    vector <set <int>> colors(inf);
    for (int i = 1; i <= n; ++i) cin >> color[i];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (color[u] != color[v]) {
            colors[color[u]].insert(color[v]);
            colors[color[v]].insert(color[u]);
        }
    }
    int ans = inf, mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (colors[color[i]].size() > mx) {
            mx = colors[color[i]].size();
            ans = color[i];
        }
        else if (colors[color[i]].size() == mx) ans = min(ans, color[i]);
    }
    cout << ans << endl;


}