#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

char buf[101];

struct test {


    vector<vector<int>> g;
    vector<vector<int>> d;
    int s;

    void dfs(int x, int p, int dd) {
        d[s][x] = dd;
        for (int y : g[x]) {
            if (y != p) dfs(y, x, dd + 1);
        }
    }

    void solve() {
        int n;
        scanf("%d", &n);
        vector<vector<string>> a(n, vector<string>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                scanf("%s", buf);
                a[i][j] = buf;
                a[j][i] = a[i][j];
            }
        }
        vector<vector<vector<int>>> b(n);
        for (int v = 0; v < n; v++) {
            for (int i = 0; i < n; i++) {
                bool ok = false;
                for (auto &l : b[v]) {
                    if (a[l.back()][i][v] == '1') {
                        l.push_back(i);
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    b[v].push_back({i});
                }
            }
            sort(b[v].begin(), b[v].end());
        }
        vector<bool> removed(n);
        int nn = n;
        g.resize(n);
        while (nn > 2) {
            bool found = false;
            for (int v = 0; v < n; v++) {
                for (auto &l : b[v]) {
                    if (removed[v]) break;
                    if (l.size() == 1) {
                        int u = l[0];
                        bool ok = true;
                        for (auto &p : b[u]) {
                            for (auto x : p) {
                                if (x == v) {
                                    if (p.size() == 1) ok = false;
                                }
                            }
                        }
                        if (!ok) continue;
                        vector<vector<int>> bbu;
                        for (auto &p : b[u]) {
                            vector<int> e;
                            for (auto x : p) {
                                if (x != v) {
                                    e.push_back(x);
                                }
                            }
                            if (!e.empty())
                                bbu.push_back(e);
                        }
                        bbu.push_back({v});
                        sort(bbu.begin(), bbu.end());
                        if (bbu == b[v]) {
                            g[v].push_back(u);
                            g[u].push_back(v);
                            removed[v] = true;
                            for (int x = 0; x < n; x++) {
                                if (removed[x]) continue;
                                vector<vector<int>> bbx;
                                for (auto &p : b[x]) {
                                    vector<int> e;
                                    for (auto y : p) {
                                        if (y != v) {
                                            e.push_back(y);
                                        }
                                    }
                                    if (!e.empty())
                                        bbx.push_back(e);
                                }
                                sort(bbx.begin(), bbx.end());
                                b[x] = bbx;
                            }
                            found = true;
                            nn--;
                            break;
                        }
                    }
                }
            }
            if (!found) {
                cout << "No\n";
                return;
            }
        }
        if (nn == 2) {
            int x = 0;
            while (removed[x]) x++;
            int y = x + 1;
            while (removed[y]) y++;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        d.assign(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            s = i;
            dfs(i, -1, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if ((a[i][j][k] == '1') != (d[i][k] == d[j][k])) {
                        cout << "No\n";
                        return;
                    }
                }
            }
        }
        cout << "Yes\n";
        for (int i = 0; i< n; i++) {
            for (int j : g[i]) {
                if (j > i) {
                    cout << i + 1 << " " << j + 1 << "\n";
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
//    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}