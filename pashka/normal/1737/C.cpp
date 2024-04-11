#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        vector<pair<int, int>> p(4);
        cin >> n;
        for (int i = 0; i < 4; i++) cin >> p[i].first >> p[i].second;

        bool ok = false;
        for (int i = 0; i < 3; i++) {
            if (p[i] == p[3]) ok = true;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                long dx1 = p[j].first - p[i].first;
                long dx2 = p[3].first - p[i].first;
                long dy1 = p[j].second - p[i].second;
                long dy2 = p[3].second - p[i].second;
                if (dx1 * dy2 == dx2 * dy1) ok = true;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        } else {
            ok = false;
            for (int i = 0; i < 3; i++) {
                if ((p[i].first != 1 && p[i].first != n) &&
                    (p[i].second != 1 && p[i].second != n))
                    ok = true;
            }
            if (!ok) {
                cout << "NO\n";
                return;
            }
            int xx = p[0].first ^ p[1].first ^ p[2].first;
            int yy = p[0].second ^ p[1].second ^ p[2].second;
            int dx = abs(p[3].first - xx);
            int dy = abs(p[3].second - yy);
            if (dx % 2 == 0 && dy % 2 == 0) {
                cout << "NO\n";
            } else {
//                if ((p[3].first == 1 || p[3].first == n) &&
//                    (p[3].second == 1 || p[3].second == n) &&
//                        (dx % 2 == 1 && dy % 2 == 1)) {
//                    cout << "NO\n";
//                } else {
                    cout << "YES\n";
//                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}