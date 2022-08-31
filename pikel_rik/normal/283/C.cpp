#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 300 + 5;
const int S = 100000 + 5;

int n, q, a[N], to[N], dp[S], vals[N];
bool active[N], cycle, visited[N];

vector<int> order;

void dfs(int x) {
    visited[x] = true;
    active[x] = true;

    if (active[to[x]]) {
        cycle = true;
    } else if (to[x]) {
        dfs(to[x]);
    }
    order.push_back(x);
    active[x] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll t;
    cin >> n >> q >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--) {
        int u, v;
        cin >> u >> v;
        to[u] = v;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    if (cycle) {
        cout << 0 << '\n';
        return 0;
    }

    reverse(order.begin(), order.end());
    memset(visited, false, sizeof(visited));

    for (int i : order) {
        if (!visited[i]) {
            vector<int> chain;
            while (i) {
                visited[i] = true;
                chain.push_back(i);
                i = to[i];
            }

            int d = chain.size(), pref = 0;
            for (int j : chain) {
                pref += a[j];
                vals[j] = pref;
                t -= (d - 1) * a[j];
                d--;
            }
        }
    }
    
    if (t < 0) {
        cout << 0 << '\n';
        return 0;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < t; j++) {
            if (dp[j] and j + vals[i] <= t) {
                dp[j + vals[i]] = (dp[j + vals[i]] + dp[j]) % mod;
            }
        }
    }
    cout << dp[t] << '\n';
    return 0;
}