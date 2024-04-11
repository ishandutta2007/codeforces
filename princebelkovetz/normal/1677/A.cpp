#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, B = 60, N = 1e3 + 15;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, ans = 0; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x, --x;
        for (int i = 0; i < n; ++i) {
            vector <int> cnt(n);
            for (int j = i + 1; j < n; ++j) cnt[a[j]]++;
            for (int j = 1; j < n; j++) cnt[j] += cnt[j - 1];
            int cur = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (a[j] < a[i]) ans += cur;
                cur += cnt[a[j]];
            }
        }

        cout << ans << '\n';
    }
    return 0;
}