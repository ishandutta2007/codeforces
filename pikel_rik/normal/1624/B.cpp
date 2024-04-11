#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (b - (c - b) > 0 && (b - (c - b)) % a == 0) {
            cout << "YES\n";
        } else if (b + b - a > 0 && (b + b - a) % c == 0) {
            cout << "YES\n";
        } else if ((c - a) % 2 == 0) {
            int diff = (c - a) / 2;
            if (a + diff > 0 && (a + diff) % b == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}