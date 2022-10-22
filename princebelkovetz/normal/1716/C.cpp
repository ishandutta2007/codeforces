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

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 2e5 + 12;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <vector <int>> a(2, vector <int>(n));
        for (auto& x : a)
            for (auto& y : x) cin >> y;
        vector <vector <int>> suf(2, vector <int>(n + 1, -mod * mod));
        for (int i = 0; i < 2; i++) {
            for (int j = n - 1; j >= 0; --j) {
                suf[i][j] = max(suf[i][j + 1], a[i][j] - j);
            }
        }
        vector <vector <int>> suf2(2, vector <int>(n + 1, -mod * mod));
        for (int i = 0; i < 2; i++) {
            for (int j = n - 1; j >= 0; --j) {
                suf2[i][j] = max(suf2[i][j + 1], a[i][j] - (n - 1 - j));
            }
        }
        int c = 0, t = 0, ans = mod * mod;
        for (int i = 0; i < n; i++) {
            int curT = t;
            int curD = max(0ll, suf[c][i + 1] + i + 1 - t);
            curT += n - i - 1;
            curD = max(curD, suf2[c ^ 1][i] - curT);
            curT += n - i;
            ans = min(ans, curT + curD);
            c ^= 1;
            t = max(t, a[c][i]) + 1;
            curT = t;
            curD = max(0ll, suf[c][i + 1] + i + 1 - t);
            curT += n - i - 1;
            curD = max(curD, suf2[c ^ 1][i + 1] - curT);
            curT += n - i - 1;
            ans = min(ans, curT + curD);
            if (i < n - 1) t = max(t, a[c][i + 1]) + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}