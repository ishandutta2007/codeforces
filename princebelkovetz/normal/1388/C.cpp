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
void dfs(int u, vector <int> &p, vector <bool> &used, vector <vector <int>> &a, vector <int> &res) {
    used[u] = true;
    for (auto v : a[u]) {
        if (used[v]) continue;
        dfs(v, p, used, a, res);
        res[u] += res[v];
    }
    res[u] += p[u];
}
int dfs2(int u, vector <bool> &used, vector <int> &res, vector <vector <int>> &a, vector <int> &h, bool &c) {
    used[u] = true;
    int happy = (res[u] - abs(h[u])) / 2;
    if ((res[u] + h[u]) % 2 or happy < 0) c = false;
    if (h[u] > 0) happy += h[u];
    int cnt = 0;
    for (auto v : a[u]) {
        if (used[v]) continue;
        cnt += dfs2(v, used, res, a, h, c);
    }
    if (cnt > happy) {
        c = false;
    }
    //debug(u) debug(happy)
    return happy;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt --> 0){
        int n, m; cin >> n >> m;
        vector <int> p(n), h(n), res(n);
        for (auto& x : p) cin >> x;
        for (auto& x : h) cin >> x;
        vector <vector <int>> a(n);
        vector <bool> used(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            --u; --v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(0, p, used, a, res);
        //for (auto x : res) cout << x << ' ';
        bool c = true;
        for (int i = 0; i < n; ++i)
            used[i] = false;
        if (dfs2(0, used, res, a, h, c) > m) c = false;
        if (c) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}