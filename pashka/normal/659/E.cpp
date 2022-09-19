#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>


// @author: pashka

using namespace std;

int vcnt = 0;
int ecnt = 0;
vector<vector<int>> g;
vector<bool> z;

void dfs(int x) {
    if (z[x]) return;
    vcnt++;
    z[x] = true;
    for (int y : g[x]) {
        ecnt++;
        dfs(y);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>(0));
    z.assign(n, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (!z[i]) {
            ecnt = 0;
            vcnt = 0;
            dfs(i);
            ecnt /= 2;
            if (ecnt == vcnt - 1) {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}