#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (auto& c : v) cin >> c.first >> c.second;
        // bool bad = 0;
        bool done = 0;
        for (auto x : v) {
            bool bad = 0;
            for (auto y : v) {
                
                if (abs(x.first - y.first) + abs(x.second - y.second) > k)
                    bad = 1;
            }
                            if (!bad) {
                    done = 1;
                    cout << 1 << '\n';
                    break;
                }

        }
        if (!done)
            cout << -1 << '\n';
    }
}