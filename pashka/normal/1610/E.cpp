#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (a.empty() || a.back().first != x) a.push_back({x, 0});
            a.back().second++;
        }
        int n0 = n;
        n = a.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i].first;
            int s = a[i].second;
            int y = x + 1;
            while (true) {
                int k = lower_bound(a.begin(), a.end(), pair<int, int>(y, 0)) - a.begin();
                if (k == n) break;
                s++;
                y = 2 * a[k].first - x;
            }
            res = max(res, s);
        }
        cout << n0 - res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}