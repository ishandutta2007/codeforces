#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2000 + 5;

int n, a[2*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        char c;
        cin >> c;
        while (c != '.') {
            cin >> c;
        }
        for (int j = 0; j < 3; j++) {
            cin >> c;
            a[i] = a[i] * 10 + (c - '0');
        }
    }

    sort(a, a + 2*n);

    int zeros = upper_bound(a, a + 2*n, 0) - a, best = INT_MAX;

    for (int c1 = 0; c1 <= n; c1++) {
        if (c1 + zeros < n) continue;
        int floor = 0;
        for (int i = zeros; i < zeros + c1; i++) {
            floor += a[i];
        }

        int ceil = 0;
        for (int i = zeros + c1; i < 2*n; i++) {
            ceil += 1000 - a[i];
        }
        best = min(best, abs(ceil - floor));
    }

    cout << best / 1000 << '.';
    best = best % 1000;

    cout << best / 100;
    best = best % 100;

    cout << best / 10;
    best = best % 10;

    cout << best << '\n';
    return 0;
}