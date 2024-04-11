#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, lvl[N];
vector<int> g[N];

double dfs(int x, int p, int d) {
    double ans = 1.0 / d;
    for (auto& i : g[x]) {
        if (i == p) continue;
        ans += dfs(i, x, d + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << fixed << setprecision(9);
    cout << dfs(1, 0, 1) << '\n';
    return 0;
}