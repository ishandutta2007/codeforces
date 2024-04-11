#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, m;
vector<int> adj[N];
int id[N];
int used[N];
int t[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) id[i] = i;
    sort(id + 1, id + n + 1, [&](int u, int v) {
        return t[u] < t[v];
    });
    bool found = 0;

    for (int i = 1; i <= n && !found; i++) {
        int u = id[i];
        
        set<int> s;
        for (int v : adj[u]) {
            if (used[v]) {
                s.insert(t[v]);
            }
        }

        for (int j = 1; j < t[u]; j++) {
            if (!s.count(j)) {
                found = 1;
                break;
            }
        }

        if (!s.empty() && *s.rbegin() >= t[u]) {
            found = 1;
            break;
        }

        used[u] = 1;
    }       
    if (found) cout << -1 << endl;
    else {
        for (int i = 1; i <= n; i++) cout << id[i] << ' ';
            cout << endl;
    }
    return 0;
}