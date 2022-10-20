#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector<int> adj[N];
vector<pair<int, int>> ans;

void dfs(int u, int p, int val) {
    ans.push_back({u, val});
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == p) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }

    if (adj[u].empty()) {
        ans.push_back({u, val - 1});
        return;
    }

    if (val == 0) {
        for (int v : adj[u]) {
            dfs(v, u, val + 1);
            val++;
            ans.push_back({u, val});
        }
    } else {
        int oldVal = val;
        while (adj[u].size() >= oldVal) {
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v, u, val + 1);
            val++;
            ans.push_back({u, val});
        }

        // adj[u].size() < oldVal
        val = oldVal - adj[u].size() - 1;
        ans.push_back({u, val});
        for (int v : adj[u]) {
            dfs(v, u, val + 1);
            val++;
            ans.push_back({u, val});
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;   
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << ' ' << 0 << endl;
        return 0;
    }

    ans.reserve(1000000);
    dfs(1, 0, 0);
    assert(ans.size() <= 1000000);
    cout << ans.size() << '\n';
    for (auto u : ans) {
        cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}