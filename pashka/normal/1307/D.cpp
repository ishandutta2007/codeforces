#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<int> bfs(vector<vector<int>> &g, int s) {
    int n = g.size();
    vector<int> q = {s};
    vector<int> d(n, -1);
    d[s] = 0;
    for (int i = 0; i < q.size(); i++) {
        int x = q[i];
        for (int y : g[x]) {
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                q.push_back(y);
            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i]; a[i]--;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> d1 = bfs(g, 0);
    vector<int> d2 = bfs(g, n - 1);

    vector<pair<int, int>> b(k);
    for (int i = 0; i < k; i++) {
        b[i] = {d1[a[i]], a[i]};
    }
    sort(b.begin(), b.end());
    int res = 0;
    int mx = 0;
    for (int i = k - 1; i >= 0; i--) {
        int x = b[i].second;
        if (i < k - 1)
            res = max(res, d1[x] + 1 + mx);
        mx = max(mx, d2[x]);
//        cout << x << " " << mx << " " << res << "\n";
    }
    res = min(res, d1[n - 1]);
    cout << res << "\n";

    return 0;
}