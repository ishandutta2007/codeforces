#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g;
vector<int> all;

void dfs(int x) {
    vector<int> nall;
    vector<int> t;
    int j = 0;
    for (int y : all) {
        while (j < g[x].size() && g[x][j] < y) {
            j++;
        }
        if (j < g[x].size() && g[x][j] == y) {
            nall.push_back(y);
        } else {
            t.push_back(y);
        }
    }
    all = nall;
    for (int y : t) {
        dfs(y);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        all.push_back(i);
        sort(g[i].begin(), g[i].end());
    }

    int res = 0;
    while (all.size() > 0) {
        dfs(all.back());
        res++;
    }
    cout << res - 1;
    return 0;
}