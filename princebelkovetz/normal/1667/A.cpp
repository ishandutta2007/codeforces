#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    int ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        int lst = 0, cur = 0;
        for (int j = i - 1; j >= 0; --j) {
            lst++;
            cur += (lst + a[j] - 1) / a[j];
            lst = (lst + a[j] - 1) / a[j] * a[j];
        }
        lst = 0;
        for (int j = i + 1; j < n; ++j) {
            lst++;
            cur += (lst + a[j] - 1) / a[j];
            lst = (lst + a[j] - 1) / a[j] * a[j];
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';



    return 0;
}