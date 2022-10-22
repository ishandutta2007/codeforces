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
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) ans = max(a[i] * a[i + 1], ans);
        cout << ans << '\n';
    }
    cout << '\n';
    return 0;
}