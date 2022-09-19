#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int l, r;
    cin >> l >> r;
    vector<pair<pair<int, int>, int>> res;
    int n = 20;
    for (int i = n + 1; i > 1; i--) {
        res.push_back({{i, n + 2}, 1});
        int k = 1;
        for (int j = n + 1; j > i; j--) {
            res.push_back({{i, j}, k});
            k *= 2;
        }
    }
    res.push_back({{1, n + 2}, l});
    l++;
    int k = 1 << (n - 1);
    for (int i = 2; i <= n + 1; i++) {
//        cout << k << "\n";
        if (k <= (r - l + 1)) {
            res.push_back({{1, i}, l - 1});
            l += k;
        }
        k /= 2;
    }
    cout << "YES\n";
    cout << n + 2 << " " << res.size() << "\n";
    for (auto p : res) {
        cout << p.first.first << " " << p.first.second << " " << min(p.second, 1000000) << "\n";
    }

    return 0;
}