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
#define ld long double
#define int long long
#define debug(x) cout << #x << " is " << x << " lol\n";
constexpr int mod = 998244353;
struct DSU {
    vector <int> p;
    DSU(int n) {
        p.resize(n);
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int get(int a) {
        return p[a] = p[a] == a ? a : get(p[a]);
    }
    bool unite(int a, int b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        p[b] = a;
        return true;
    }
};
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);
    int n, m; cin >> n >> m;
    if (n & 1 ^ 1) {
        cout << "-1\n";
        return 0;
    }
    vector <vector <int>> e1, e2;
    for (int i = 0, u, v; i < m; ++i) {
        char c;
        cin >> u >> v >> c;
        if (c == 'S')
            e1.push_back({ u, v, i });
        else
            e2.push_back({ u, v, i });
    }
    DSU dsu(n + 1), f(n + 1), s(n + 1);
    vector <vector <int>> ans;
    for (auto& x : e2)
        dsu.unite(x[0], x[1]);
    for (auto& x : e1) {
        if (dsu.unite(x[0], x[1])) {
            f.unite(x[0], x[1]);
            ans.push_back(x);
        }
    }
    if (ans.size() > n / 2) {
        cout << "-1\n";
        return 0;
    }
    for (auto& x : e1) {
        if (ans.size() == n / 2) break;
        if (f.unite(x[0], x[1])) {
            ans.push_back(x);
        }
    }
    if (ans.size() < n / 2) {
        cout << "-1\n";
        return 0;
    }
    for (auto& x : ans)
        assert(s.unite(x[0], x[1]));
    for (auto& x : e2) {
        if (s.unite(x[0], x[1])) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x[2] + 1 << ' ';
    cout << '\n';
    return 0;
}