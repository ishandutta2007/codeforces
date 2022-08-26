#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;

const ld INF = 1e20;
const ld EPS = 1e-9;
const int maxN = 4e5 + 5;
vector<pair<int, int>> g[maxN];
int w[maxN];
ll ans = -1;

ll dfs(int v, int p, ll x) {
    x += w[v];
    vector<ll> have = {x, x};
    for (auto &[u, c] : g[v]) {
        if (u == p) continue;
        have.push_back(dfs(u, v, x - c));
    }
    sort(rall(have));
    ans = max(ans, have[0] + have[1] - x * 2 + w[v]);
    return have[0];
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    range(_, n - 1) {
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dfs(1, -1, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(30) << fixed;
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}