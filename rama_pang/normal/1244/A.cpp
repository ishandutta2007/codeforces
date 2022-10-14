#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int p1 = ceil(1.00 * a / c);
        int p2 = ceil(1.00 * b / d);
        if (p1 + p2 > k) {
            cout << -1 << "\n";
        } else {
            cout << p1 << " " << p2 << "\n";
        }
    }
    return 0;
}