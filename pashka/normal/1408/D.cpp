#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;

    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i].first <= b[j].first && a[i].second <= b[j].second) {
                c.emplace_back(b[j].first - a[i].first, b[j].second - a[i].second);
            }
        }
    }
    sort(c.begin(), c.end());
    int mx = -1;
    int res = INT_MAX;
    for (int i = (int)c.size() - 1; i >= 0; i--) {
//        cout << c[i].first << " " << c[i].second << "\n";
        res = min(res, c[i].first + 1 + mx + 1);
        mx = max(mx, c[i].second);
    }
    res = min(res, mx + 1);
    cout << res << "\n";

    return 0;
}