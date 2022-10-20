#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int b;
        int x, y;
        int xx, yy;
        cin >> b >> x >> y;
        cin >> xx >> yy;
        if (xx < yy) {
            swap(xx, yy);
            swap(x, y);
        }
        int num = min(b / 2, x);
        int res = 0;
        res += num * xx;
        b -= num * 2;
        num = min(b / 2, y);
        res += num * yy;
        cout << res << endl;
    }
    return 0;
}