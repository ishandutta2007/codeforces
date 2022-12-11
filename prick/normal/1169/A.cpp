#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    --a; --x; --b; --y;
    while (true) {
        a = (a + 1) % n;
        b = (b + n - 1) % n;
        if (a == b) {
            cout << "YES\n";
            return 0;
        }
        if (a == x || b == y) break;
    }
    cout << "NO\n";
}