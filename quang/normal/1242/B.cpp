#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector<int> adj[N];
int used[N];
set<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        s.insert(i);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        res++;
        queue<int> q;
        used[i] = 1;
        q.push(i);
        s.erase(i);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            vector<int> add;
            for (int u : s) {
                if (!binary_search(adj[now].begin(), adj[now].end(), u)) {
                    add.push_back(u);
                }
            }
            for (int u : add) {
                s.erase(u);
                used[u] = 1;
                q.push(u);
            }
        }
    }
    cout << res - 1 << endl;
    return 0;
}