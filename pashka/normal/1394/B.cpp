#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({w, v});
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    vector<vector<pair<int, int>>> c(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            c[g[i][j].second].push_back({g[i].size() - 1, j});
        }
    }
    vector<vector<int>> nm(k, vector<int>(k));
    int cc = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) nm[i][j] = cc++;
    }

    vector<bool> ban(cc);
    vector<long> bad(cc);
    for (int i = 0; i < n; i++) {
        vector<bool> z(cc);
        for (int j = 0; j < (int) c[i].size(); j++) {
            auto p1 = c[i][j];
            int x = nm[p1.first][p1.second];
            if (z[x]) ban[x] = true;
            z[x] = true;
        }
        for (int x = 0; x < cc; x++) {
            for (int y = 0; y < cc; y++) {
                if (z[x] && z[y]) bad[x] |= (1LL << y);
            }
        }
    }
    vector<int> a(k);
    int res = 0;
    while (true) {
        long z = 0;
        bool ok = true;
        for (int i = 0; i < k; i++) {
            int x = nm[i][a[i]];
            if (ban[x]) {
                ok = false;
                break;
            }
            for (int y = 0; y < 100; y++) {
                if (bad[x] & z) {
                    ok = false;
                    break;
                }
            }
            z |= (1LL << x);
        }
        if (ok) {
//            for (int x : a) cout << x + 1 << " ";
//            cout << "\n";
            res++;
        }
        {
            int i = 0;
            while (i < k && a[i] == i) {
                a[i] = 0;
                i++;
            }
            if (i == k) break;
            a[i]++;
        }
    }
    cout << res << "\n";
    return 0;
}