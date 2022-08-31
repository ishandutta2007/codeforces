#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int color[maxN];
vector<int> g[maxN];
int cntr = 0, cntb = 0;
int ans = 0;

pair<int, int> dfs(int v, int p) {
    pair<int, int> res = {0, 0};
    if (color[v] == 1) res.first++;
    if (color[v] == 2) res.second++;
    for (auto &u: g[v]) {
        if (u == p) continue;
        auto w = dfs(u, v);
        res.first += w.first;
        res.second += w.second;
    }
    if ((res.first == cntr && !res.second) || (!res.first && res.second == cntb)) {
        ans++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    range(i, n) {
        cin >> color[i + 1];
        if (color[i + 1] == 1) cntr++;
        if (color[i + 1] == 2) cntb++;
    }
    range(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
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