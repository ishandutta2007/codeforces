#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int N = 300 + 2, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, k; cin >> n >> k;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        int ans = -mod;
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= max(0ll, i - 500); --j)
                ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
        }
        cout << ans << '\n';

    }
    cout << '\n';
    return 0;
}