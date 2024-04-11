#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
vector<int> adj[N];
vector<int> adj2[N];
int cnt;

void join(int &u, int &v) {
    if (u == -1) {
        swap(u, v);
        return;
    }
    if (adj2[u].size() < adj2[v].size()) swap(u, v);
    for (int val : adj2[v]) adj2[u].push_back(val);
    adj2[v].clear();
}

pair<int, int> dfs(int u, int p) {
    pair<int, int> res(-1, -1);
    if (a[u] == 1) res.first = ++cnt;
    if (a[u] == 2) res.second = ++cnt;
    for (int v : adj[u]) {
        if (v == p) continue;
        pair<int, int> now = dfs(v, u);
        if (a[u] == 1) {
            if (now.first != -1) join(res.first, now.first);
            if (now.second != -1) adj2[res.first].push_back(now.second);
        } else if (a[u] == 2) {
            if (now.second != -1) join(res.second, now.second);
            if (now.first != -1) adj2[res.second].push_back(now.first);
        } else {
            if (now.first != -1) join(res.first, now.first);
            if (now.second != -1) join(res.second, now.second);
        }
    }
    return res;
}

int solve(int u, int p, int &res) {
    pair<int, int> now(0, -1e9);
    auto update = [&](int val) {
        if (val > now.first) swap(val, now.first);
        if (val > now.second) swap(val, now.second);
    };
    for (int v : adj2[u]) {
        if (v == p) continue;
        int foo = solve(v, u, res);
        update(foo + 1);
    }
    res = max(res, now.first + now.second + 1);
    return now.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            adj2[i].clear();
        }
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pair<int, int> now = dfs(1, 0);
        if (now.first == -1 && now.second == -1) {
            cout << 1 << '\n';
            continue;
        }
        if (now.first != -1 && now.second != -1) {
            adj2[now.first].push_back(now.second);
            now.second = -1;
        }
        int id = now.first != -1 ? now.first : now.second;
        int res = 0;
        solve(id, 0, res);
        cout << res / 2 + 1 << '\n';
    }
    return 0;
}