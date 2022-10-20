#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const long long INF = 1e18;

int n, m;
vector<int> adj[N];
long long a[N];
vector<pair<int, long long>> dp[N];

vector<pair<int, long long>> join(vector<pair<int, long long>> &u, vector<pair<int, long long>> &v) {
    vector<pair<int, long long>> res(u.size() + v.size() - 1, {0, -INF});
    for (int i = 1; i < u.size(); i++) {
        for (int j = 1; j < v.size(); j++) {
            // not join
            pair<int, long long> foo;
            foo.first = u[i].first + v[j].first + (v[j].second > 0);
            foo.second = u[i].second;
            res[i + j] = max(res[i + j], foo);
            // join
            foo.first = u[i].first + v[j].first;
            foo.second = u[i].second + v[j].second;
            res[i + j - 1] = max(res[i + j - 1], foo);
        }
    }
    return res;
}

void dfs(int u, int p) {
    dp[u].clear();
    dp[u].push_back({0, -INF});
    dp[u].push_back({0, a[u]});
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = join(dp[u], dp[v]);
    }
    // cout << "val " << u << endl;
    // for (auto v : dp[u]) {
    //     cout << v.first << ' ' << v.second << endl;
    // }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            a[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            a[i] -= u;
        }
        for (int i = 1; i <= n; i++) {
            int u; cin >> u;
            a[i] += u;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        pair<int, long long> foo = dp[1][m];
        if (foo.second > 0) foo.first++;
        cout << foo.first << '\n';
    }
    return 0;
}