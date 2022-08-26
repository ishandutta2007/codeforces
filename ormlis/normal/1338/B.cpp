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

vector<int> g[maxN];
bool ch = false, nch = false;
int mx=0;
bool dfs(int v, int p, int h) {
    if (g[v].size() == 1) {
        if (h & 1) nch = true;
        else ch = true;
        return true;
    }
    int k = 0;
    for (auto &u: g[v]) {
        if (u == p) continue;
        if (dfs(u, v, h + 1)) {
            k++;
        }
    }
    mx -= max(0, k - 1);
    return false;
}

void solve() {
    int n;
    cin >> n;
    range(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() >= 2) root = i;
    }
    mx = n - 1;
    dfs(root, -1, 0);
    int min = 1;
    if (ch && nch) {
        min = 3;
    }
    cout << min << " " << mx;
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