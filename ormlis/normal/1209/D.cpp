#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

vector<int> g[maxN];
bool was[maxN];
int edg = 0;
int vert = 0;
void dfs(int v) {
    vert++;
    edg += g[v].size();
    was[v] = true;
    for(auto &u : g[v]) {
        if (was[u]) continue;
        dfs(u);
    }
}

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    range(_, k) {
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if (was[i]) continue;
        vert = 0;
        edg = 0;
        dfs(i);
        edg /= 2;
        ans += edg - (vert - 1);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}