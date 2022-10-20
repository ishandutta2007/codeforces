#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
set<int> adj[N];
int used[N];
int num;

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;   
    num = n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    while (num > 1) {
        int u, v;
        u = v = -1;
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            if (adj[i].size() > 1) continue;
            if (u == -1) {
                u = i;
            } else if (v == -1) {
                v = i;
            } else break;
        }
        used[u] = used[v] = 1;
        for (int w : adj[u]) {
            adj[w].erase(u);
        }
        for (int w : adj[v]) {
            adj[w].erase(v);
        }
        num -= 2;
        cout << "? " << u << ' ' << v << endl;
        int lca;
        cin >> lca;
        if (lca == u) {
            cout << "! " << u << endl;
            return 0;
        } else if (lca == v) {
            cout << "! " << v << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
         cout << "! " << i << endl;
            return 0;   
        }
    }
    return 0;
}