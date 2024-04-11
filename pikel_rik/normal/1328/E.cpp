#include <bits/stdc++.h>
using namespace std;

vector<int> p, lvl, tin, tout;
vector<vector<int>> g;

int T = 0;

void dfs(int v, int P = 0, int d = 0) {
    tin[v] = T++;
    p[v] = P;
    lvl[v] = d;

    for (auto &x: g[v]) {
        if (x == p[v])
            continue;
        dfs(x, v, d+1);
    }
    tout[v] = T++;
}

int main() {
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    g.resize(n+1);

    int y1, y2;
    for (int i = 0; i < n-1; i++) {
        cin >> y1 >> y2;
        g[y1].push_back(y2);
        g[y2].push_back(y1);
    }

    p.resize(n+1);
    lvl.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);

    dfs(1);

    while (t--) {
        int m;
        cin >> m;

        vector<int> a(m);
        int x = 1;

        for (int i = 0; i < m; i++) {
            cin >> a[i];
            if (p[a[i]] != 0)
                a[i] = p[a[i]];
            if (lvl[a[i]] > lvl[x])
                x = a[i];
        }

        int flag = 0;

        for (auto &i : a) {
            if (tin[x] < tin[i] or tout[x] > tout[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}