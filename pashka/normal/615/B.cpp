#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> d(n);
    long long res = 1;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (auto j : g[i]) {
            if (j < i) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        long long dd = (long long) d[i] * g[i].size();
        if (dd > res)
            res = dd;
    }
    cout << res << endl;
    return 0;
}