#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x, y, x1, x2, y1, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        if (a > 0 and a == b and x == x1 and x == x2)
            cout << "No\n";
        else if (c > 0 and c == d and y == y1 and y == y2)
            cout << "No\n";
        else if (x - a + b < x1 or x - a + b > x2 or y - c + d < y1 or y - c + d > y2)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}