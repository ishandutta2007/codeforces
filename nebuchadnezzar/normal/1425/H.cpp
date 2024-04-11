#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}

void solve() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if ((a + b) % 2 == 1) {
            if (a > 0 || d > 0) cout << "Ya ";
            else cout << "Tidak ";

            if (b > 0 || c > 0) cout << "Ya ";
            else cout << "Tidak ";
            cout << "Tidak Tidak ";

        } else {
            cout << "Tidak Tidak ";

            if (b > 0 || c > 0) cout << "Ya ";
            else cout << "Tidak ";
            if (a > 0 || d > 0) cout << "Ya ";
            else cout << "Tidak ";

        }
        cout << "\n";
    }
}