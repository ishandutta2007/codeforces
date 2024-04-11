#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m, p[N], sz[N];
vector<int> g[N];
vector<ll> vals;

void dfs(int x, int par) {
    sz[x] = 1;

    for (int &i : g[x]) {
        if (i == par) continue;
        dfs(i, x);
        sz[x] += sz[i];
        vals.push_back(sz[i] * (ll)(n - sz[i]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) g[i].clear();

        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cin >> m;
        for (int i = 0; i < m; i++) cin >> p[i];

        if (m <= n - 1) {
            while (m < n - 1) {
                p[m] = 1;
                m++;
            }
            sort(p, p + m);
        }

        if (m > n - 1) {
            sort(p, p + m);
            while (m > n - 1) {
                p[m - 2] = p[m - 1] * (ll)p[m - 2] % mod;
                m--;
            }
        }

        vals.clear();
        dfs(1, 0);
        sort(vals.begin(), vals.end());

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = (ans + vals[i] % mod * p[i]) % mod;
        }

        cout << ans << "\n";
    }
    return 0;
}