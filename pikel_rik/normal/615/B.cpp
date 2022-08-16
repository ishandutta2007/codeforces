#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n, dp[N];
vector<int> g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int u : g[i]) {
            if (u < i)
                dp[i] = max(dp[i], 1 + dp[u]);
        }
        ans = max(ans, dp[i] * (ll)g[i].size());
    }

    cout << ans << "\n";
    return 0;
}