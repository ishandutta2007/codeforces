#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        x = abs(x - xx);
        y = abs(y - yy);
        int res = x + y;
        if (x > 0 && y > 0) res += 2;
        cout << res << '\n';
    }
    return 0;
}