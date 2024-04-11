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

        // a = n*d, b = m*d
        // lcm = n*m*d
        // gcd = d
        // lcm / gcd = n*m = 3 => n = 1 and m <= 3

        cout << n + 2 * (n / 2) + 2 * (n / 3) << '\n';
    }
    return 0;
}