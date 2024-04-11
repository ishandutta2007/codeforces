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

const int mod = 1e9 + 7;

struct dsu {
    int n;
    vector <int> p;
    dsu(int n) : n(n) {
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
        p[a] = b;
        return true;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int n, m1, m2; cin >> n >> m1 >> m2;

    dsu d1(n), d2(n);

    for (int i = 0, u, v; i < m1; ++i) {
        cin >> u >> v;
        --u, --v;
        d1.unite(u, v);
    }

    for (int i = 0, u, v; i < m2; ++i) {
        cin >> u >> v;
        --u, --v;
        d2.unite(u, v);
    }

    vector <pair <int, int>> ans;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int i1 = d1.get(i), j1 = d1.get(j);
            int i2 = d2.get(i), j2 = d2.get(j);
            if (i1 != j1 and i2 != j2)
                d1.unite(i, j), d2.unite(i, j), ans.push_back({ i, j });
        }
    }

    cout << ans.size() << '\n';
    for (auto& x : ans) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    return 0;
}