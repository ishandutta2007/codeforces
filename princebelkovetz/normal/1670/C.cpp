#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 5e1 + 2, L = 30;

vector <vector <int>> g;
vector <bool> used;
vector <int> val;

void dfs(int v, int &sum) {
    used[v] = true;
    sum += val[v];
    for (auto& u : g[v]) {
        if (!used[u]) {
            dfs(u, sum);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n), b(n), d(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        for (auto& x : d) cin >> x;
        g.assign(n + 1, {});
        used.assign(n + 1, 0);
        val.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
            if (d[i] > 0) {
                val[a[i]] = val[b[i]] = 1;
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                int sum = 0;
                dfs(i, sum);
                if (sum == 0 and g[i][0] != i) ans <<= 1;
                ans %= mod;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}