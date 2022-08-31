#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(n); for (auto& c : v) cin >> c.first >> c.second;
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        bool bad = 0;
        for (auto c : v) {
            if (c.first <= i && c.second >= i) bad = 1;
        }
        if (!bad) ans.push_back(i);
    }
    cout << size(ans) << '\n';
    for (auto c : ans) cout << c << ' ';
    cout << '\n';
}