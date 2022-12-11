#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int maxw, n;
    cin >> maxw >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector<pair<int, int>> candidates;
    for (auto x: vector<int>{a[0].first, a[0].second}) {
        if (x > 1) {
            candidates.emplace_back(1, x);
        } else {
            candidates.emplace_back(1, 2);
        }
        for (int i = 0; i < n; ++i) {
            if (a[i].first == x || a[i].second == x) continue;
            candidates.emplace_back(min(x, a[i].first), max(x, a[i].first));
            candidates.emplace_back(min(x, a[i].second), max(x, a[i].second));
            break;
        }
    }
    
    for (auto [x, y]: candidates) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i].first != x && a[i].first != y && a[i].second != x && a[i].second != y) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    
}