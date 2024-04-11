#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << '\n';
            continue;
        }
        int now = 0;
        vector<int> res;
        res.reserve(n);
        for (int i = 1; i < n; i++) {
            now = (now * 10 + 2) % 3;
            res.push_back(2);
        }
        if (now == 0) {
            res.back() = 3;
            now++;
        }
        now = (now * 10 + 3) % 3;
        res.push_back(3);
        for (int u : res) cout << u;
            cout << '\n';
    }

    return 0;
}