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
        int n, sum = 0; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x, sum += x;
        if (n == 1) {
            cout << "YES\n" << a[0] << '\n';
            continue;
        }
        if (sum % (n * (n + 1) / 2)) {
            cout << "NO\n";
            continue;
        }
        sum /= n * (n + 1) / 2;
        vector <int> ans(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int cur = sum + a[i] - a[(i + 1) % n];
            if (cur % n or cur <= 0) ok = false;
            else ans[(i + 1) % n] = cur / n;
        }
        if (ok) {
            cout << "YES\n";
            for (auto& x : ans) cout << x << ' ';
        }
        else cout << "NO";
        cout << '\n';

    }
}