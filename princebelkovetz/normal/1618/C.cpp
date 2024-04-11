#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 4e2 + 2;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        auto gcd = [](auto gcd, int a, int b) -> int {
            return b ? gcd(gcd, b, a % b) : a;
        };

        int g[2] = { 0, 0 }, ok[2] = { 1, 1 };
        for (int i = 0; i < n; i++)
            g[i & 1] = gcd(gcd, g[i & 1], a[i]);

        for (int i = 0; i < n; i++) {
            if (a[i] % g[i & 1 ^ 1] == 0) {
                ok[i & 1 ^ 1] = 0;
            }
        }
        if (ok[0]) ok[1] = 0;
        cout << ok[0] * g[0] + ok[1] * g[1] << '\n';

    }
}