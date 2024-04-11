#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector<int> adj[N];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) v += n;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end(), greater<int>());
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            int u = (i + j) % n;
            int cnt = 0;
            for (int v : adj[u]) {
                res = max(res, cnt * n + j + v - u);
                cnt++;
            }
        }
        cout << res << ' ';
    }
    cout << endl;
    return 0;
}