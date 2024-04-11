#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            cout << 0 << endl;
        } else {
            int val = x * x + y * y;
            int k = sqrt(val);
            if (k * k == val) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
    return 0;
}