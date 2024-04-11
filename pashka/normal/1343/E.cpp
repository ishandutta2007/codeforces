#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka


void solve_test() {

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--;
    b--;
    c--;

    vector<long> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];
    sort(p.begin(), p.end());
    vector<long> ps(m + 1);
    for (int i = 0; i < m; i++) {
        ps[i + 1] = ps[i] + p[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    auto bfs = [&](int s) {
        vector<int> q = {s};
        vector<int> d(g.size(), -1);
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
    };

    auto da = bfs(a);
    auto db = bfs(b);
    auto dc = bfs(c);

    long res = numeric_limits<long>::max();
    for (int i = 0; i < n; i++) {
        int xx = da[i] + dc[i];
        int yy = db[i];
        if (xx + yy <= m) {
            long s = ps[yy] + ps[xx + yy];
            res = min(res, s);
        }
    }
    cout << res << "\n";
}


int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }
    return 0;
}