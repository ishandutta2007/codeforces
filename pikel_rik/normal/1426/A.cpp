#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        if (n <= 2) {
            cout << 1 << '\n';
        } else {
            n -= 2;
            cout << 1 + (n + x - 1) / x << '\n';
        }
    }
    return 0;
}