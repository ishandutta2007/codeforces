#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

void dfs(int i, vector <int> &ts, vector <bool> &used, vector <vector <int>> &adj) {
    used[i] = true;
    for (auto u : adj[i]) {
        if (used[u]) continue;
        dfs(u, ts, used, adj);
    }
    ts.push_back(i);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector <int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector <vector <int>> adj(n);
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0)
            adj[i].push_back(b[i] - 1);
    }
    vector <int> ts;
    vector <bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        dfs(i, ts, used, adj);
    }
    reverse(ts.begin(), ts.end());
    int ans = 0;
    vector <int> hah;
    for (int i = 0; i < n; ++i) {
        if (a[ts[i]] < 0) continue;
        ans += a[ts[i]];
        hah.push_back(ts[i]);
        if (b[ts[i]] - 1 >= 0) a[b[ts[i]] - 1] += a[ts[i]];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[ts[i]] >= 0) continue;
        ans += a[ts[i]];
        hah.push_back(ts[i]);
    }
    cout << ans << "\n";
    for (auto x : hah) cout << x + 1 << ' ';
    return 0;
}