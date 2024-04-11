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
        int n, k; cin >> n >> k;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        vector <int> able;
        for (int i = 0; i < n - 1; i++) {
            able.push_back(a[i] < 2 * a[i + 1]);
        }
        int cnt = 0, ans = 0;
        for (int i = 0; i < k - 1; i++) cnt += able[i];
        for (int i = k - 1; i < n - 1; i++) {
            cnt += able[i];
            if (cnt == k) ans++;
            cnt -= able[i - k + 1];
        }
        cout << ans << '\n';
    }

    return 0;
}