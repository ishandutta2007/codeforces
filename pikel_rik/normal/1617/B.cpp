#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << n / 2 << ' ' << n / 2 - 1 << ' ' << 1 << '\n';
        } else {
            if (((n - 1) / 2) % 2 == 0) {
                cout << (n - 1) / 2 - 1 << ' ' << (n - 1) / 2 + 1 << ' ' << 1 << '\n';
            } else {
                cout << (n - 1) / 2 - 2 << ' ' << (n - 1) / 2 + 2 << ' ' << 1 << '\n';
            }
        }
    }
    return 0;
}