#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;

        if ((sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m)) {
            cout << "-1\n";
        } else if ((sx - d <= 1 && sy - d <= 1) || (sx + d >= n && sy + d >= m)) {
            cout << "-1\n";
        } else {
            cout << n - 1 + m - 1 << '\n';
        }
    }
    return 0;
}