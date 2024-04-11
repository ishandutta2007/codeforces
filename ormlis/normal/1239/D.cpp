#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN][2];
int used[maxN][2];

void dfs(int v, int c) {
    used[v][c] = 1;
    for (auto &u: g[v][c]) {
        if (used[u][c]) continue;
        dfs(u, c);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        g[i][0].clear();
        g[i][1].clear();
        used[i][0] = used[i][1] = 0;
    }
    range(i, m) {
        int u, v;
        cin >> u >> v;
        g[u][0].push_back(v);
        g[v][1].push_back(u);
    }
    dfs(1, 0);
    dfs(1, 1);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++i) {
        cnt1 += used[i][0];
        cnt2 += used[i][1];
    }

    if (cnt1 != n) {
        cout << "Yes\n";
        cout << cnt1 << " " << n - cnt1 << "\n";
        for(int i = 1; i <= n; ++i) if (used[i][0]) cout << i << " ";
        cout << "\n";
        for(int i = 1; i <= n; ++i) if (!used[i][0]) cout << i << " ";
        cout << "\n";
        return;
    }
    if (cnt2 != n) {
        cout << "Yes\n";
        cout << n - cnt2 << " " << cnt2 << "\n";
        for(int i = 1; i <= n; ++i) if (!used[i][1]) cout << i << " ";
        cout << "\n";
        for(int i = 1; i <= n; ++i) if (used[i][1]) cout << i << " ";
        cout << "\n";
        return;
    }
    cout << "No\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}