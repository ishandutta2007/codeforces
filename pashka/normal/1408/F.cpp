#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<pair<int, int>> res;
void go(int l, int r) {
    if (r == l + 1) return;
    int m = (l + r) / 2;
    go(l, m);
    go(m, r);
    for (int i = 0; i < m - l; i++) {
        res.push_back({l + i, m + i});
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int s = 1;
    while (2 * s < n) {
        s *= 2;
    }
    go(0, s);
    go(n - s, n);
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}