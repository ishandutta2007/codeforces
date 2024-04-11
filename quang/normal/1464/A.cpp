#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector<int> adj[N];
bool used[N];

pair<int, int> dfs(int u) {
    used[u] = 1;
    pair<int, int> res(1, 0);
    res.second += adj[u].size();
    for (int v : adj[u]) {
        if (!used[v]) {
            pair<int, int> foo = dfs(v);
            res.first += foo.first;
            res.second += foo.second;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                pair<int, int> now = dfs(i);
                // cout << i << ' ' << now.first << ' ' << now.second << endl;
                if (now.first == 1) {
                    // do nothing
                } else if (now.first * 2 == now.second) {
                    res += now.first + 1;
                } else {
                    res += now.first - 1;
                }
            }
        }
        cout << res << '\n';

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            used[i] = 0;
        }
    }
    return 0;
}