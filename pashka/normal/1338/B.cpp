#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int n;
vector<vector<int>> g;
vector<int> c;

void dfs(int x, int p) {
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y != p) {
            c[y] = 1 - c[x];
            dfs(y, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    c.resize(n);
    dfs(0, -1);

    int cc = 0;
    vector<bool> z(n);
    int res = n - 1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            cc |= (1 << c[i]);
            int y = g[i][0];
            if (!z[y]) {
                z[y] = true;
            } else {
                res--;
            }
        }
    }
    cout << (cc == 3 ? 3 : 1) << " " << res << "\n";

    return 0;
}