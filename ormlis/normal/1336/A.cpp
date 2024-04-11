#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> w;
vector<int> g[maxN];
int dfs(int v, int p, int h) {
    int res = 1;
    for (auto &u: g[v]) {
        if (u == p) continue;
        res += dfs(u, v, h + 1);
    }
    w.emplace_back(h - (res - 1));
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    range(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
    sort(rall(w));
    ll ans = 0;
    range(i, k) {
        ans += w[i];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}