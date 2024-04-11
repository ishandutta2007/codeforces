#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {

    vector<vector<int>> g;
    vector<long> s;

    pair<long, long> dfs(int x, int k) {
        int m = g[x].size();
        vector<pair<long, long>> c;
        for (int y: g[x]) {
            auto pp = dfs(y, k / m);
            c.emplace_back(pp.second - pp.first, pp.first);
        }
        sort(c.rbegin(), c.rend());
        pair<long, long> res;
        for (int d = 0; d <= 1; d++) {
            long ss = (k + d) * s[x];
            for (auto p : c) {
                ss += p.second;
            }
            if (m > 0) {
                int t = k % m + d;
                for (int i = 0; i < t; i++) {
                    ss += c[i].first;
                }
            }
            if (d == 0) res.first = ss; else res.second = ss;
        }
        return res;
    }

    void solve() {
        int n, k;
        cin >> n >> k;
        g.resize(n);
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            g[p - 1].push_back(i);
        }
        s.resize(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        cout << dfs(0, k).first << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}