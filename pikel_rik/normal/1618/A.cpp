#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        array<int, 7> b;
        for (auto &x : b) cin >> x;

        sort(b.begin(), b.end());

        cout << b[0] << ' ' << b[1] << ' ';

        if (b[0] + b[1] > b[2]) {
            cout << b[2] << '\n';
        } else {
            cout << b[3] << '\n';
        }
    }
    return 0;
}