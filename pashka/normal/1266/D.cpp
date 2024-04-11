#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<long> d(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        d[x] += w;
        d[y] -= w;
    }
    int j = 0;
    vector<pair<pair<int, int>, long>> res;
    for (int i = 0; i < n; i++) {
        while (d[i] > 0) {
            while (d[j] >= 0) j++;
            long x = min(d[i], -d[j]);
            d[i] -= x;
            d[j] += x;
            res.push_back({{i, j}, x});
        }
    }
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.first.first + 1 << " " << p.first.second + 1 << " " <<
        p.second << "\n";
    }


    return 0;
}