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
const int inf = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    int n, m, k; cin >> n >> m >> k;
    vector <int> wow(k), dist(n + 1, 0), dist2(n + 1, 0); vector <vector <int>> a(n + 1);
    for (auto& x : wow) cin >> x;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    queue <int> q; q.push(1);
    vector <bool> used(n + 1); used[1] = true;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto u : a[v]) {
            if (used[u]) continue;
            used[u] = true;
            q.push(u);
            dist[u] = dist[v] + 1;
        }
    }
    vector <bool> used2(n + 1); used2[n] = true;
    q.push(n);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto u : a[v]) {
            if (used2[u]) continue;
            used2[u] = true;
            q.push(u);
            dist2[u] = dist2[v] + 1;
        }
    }
    //for (auto x : dist) cout << x << " ";
    //cout << endl;
    //for (auto x : dist2) cout << x << " ";
    //cout << endl;
    vector <pair <int, int>> ok;
    for (int i = 0; i < k; ++i) ok.push_back({ dist[wow[i]] - dist2[wow[i]], wow[i] });
    sort(ok.begin(), ok.end());
    int ans = 0, curmax = -1e9;
    for (auto x: ok){
        ans = max(ans, curmax + dist2[x.second]);
        curmax = max(curmax, dist[x.second]);
    }
    cout << min(ans + 1, dist[n]) << endl;
}