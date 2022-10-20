#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector<int> adj[N];
int maxRes;
int found = 0;
int id[N];

void dfs(int u, int p) {
    if (adj[u].size() == 1) {
        id[u] = 0;
        return;
    }
    int nonLeaf = 0;
    int hasLeft = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (adj[v].size() == 1) hasLeft = 1;
        else nonLeaf++;
        dfs(v, u);
    }
    maxRes += nonLeaf + hasLeft;
    int curId = -1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (curId == -1) curId = id[v];
        if (curId != id[v]) {
            found = 1;
        }
    }
    id[u] = curId ^ 1;
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
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 1) {
            root = i;
        }
    }
    maxRes = 0;
    dfs(root, 0);
    if (found) cout << 3 << ' ';
    else cout << 1 << ' ';
    cout << maxRes << endl;
    return 0;
}