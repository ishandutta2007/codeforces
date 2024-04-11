#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 100000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        pair<int, int> X(-INF, INF);
        pair<int, int> Y = X;
        for (int i = 1; i <= n; i++) {
            int x, y;
            int a[4];
            cin >> x >> y >> a[0] >> a[1] >> a[2] >> a[3];
            if (!a[0]) {
                X.first = max(X.first, x);
            }
            if (!a[1]) {
                Y.second = min(Y.second, y);
            }
            if (!a[2]) {
                X.second = min(X.second, x);
            }
            if (!a[3]) {
                Y.first = max(Y.first, y);
            }
        }
        if (X.first > X.second || Y.first > Y.second) {
            cout << 0 << '\n';
        } else {
            cout << 1 << ' ' << X.first << ' ' << Y.first << '\n';
        }
    }
    return 0;
}