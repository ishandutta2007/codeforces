#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    vector<vector<int>> g;
    vector<int> l, r;

    pair<long, long> dfs(int x, int p) {
        pair<long, long> res = {0, 0};
        for (int y : g[x]) {
            if (y == p) continue;
            auto q = dfs(y, x);
            res.first += max(abs(l[x] - l[y]) + q.first,
                             abs(l[x] - r[y]) + q.second);
            res.second += max(abs(r[x] - l[y]) + q.first,
                             abs(r[x] - r[y]) + q.second);
        }
        return res;
    }

    void solve_test() {
        int n;
        cin >> n;
        l.resize(n);
        r.resize(n);
        for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
        g.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        auto q = dfs(0, -1);
        cout << max(q.first, q.second) << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve_test();
    }

    return 0;
}