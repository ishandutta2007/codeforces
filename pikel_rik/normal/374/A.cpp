#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int n, m, x, y, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x >> y >> a >> b;

    int ans = INT_MAX;

    vector<pair<int, int>> points = {{1, 1}, {n, 1}, {1, m}, {n, m}};

    for (auto &[i, j] : points) {
        if (x == i and y == j) {
            ans = 0;
            break;
        }
        if ((x - i) % a or (y - j) % b) continue;
        int m1 = abs((x - i) / a), m2 = abs((y - j) / b);

        if ((m1 - m2) % 2 or (x + a > n and x - a < 1) or (y + b > m and y - b < 1)) continue;
        ans = min(ans, max(m1, m2));
    }

    if (ans != INT_MAX)
        cout << ans << "\n";
    else cout << "Poor Inna and pony!\n";
    return 0;
}