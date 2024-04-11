
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
#include <random>

using namespace std;
mt19937 rnd(239);

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9 + 7, p = 239, N = 2e5 + 5;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector <int> a(n), b;
        for (auto& x : a) cin >> x;
        b = a;
        sort(b.begin(), b.end());
        for (auto& x : a)
            x = lower_bound(b.begin(), b.end(), x) - b.begin();
        int cnt = 0;
        for (int i = 0; i + 1 < n; ++i) {
            cnt += (a[i] != a[i + 1] - 1);
        }
        cout << (cnt < k ? "Yes" : "No") << '\n';
    }

    return 0;
}