#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 998244353, N = 2e5 + 3;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt;
    cin >> tt;
    while (tt-- > 0) {
        int n; cin >> n;
        vector <int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        for (int i = 0; i < n; ++i)
            if (a[i] > b[i]) swap(a[i], b[i]);
        vector <int> d(n);
        int s1 = 0, s2 = 0, s3 = 0;
        for (int i = 0; i < n; ++i) {
            s1 += a[i], s2 += b[i];
            d[i] = b[i] - a[i];
            s3 += d[i];
        }
        vector <vector <int>> rs(n + 1, vector <int>(s3 + 1));
        rs[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            rs[i + 1] = rs[i];
            for (int j = s3 - d[i]; j >= 0; --j) {
                if (rs[i][j]) rs[i + 1][j + d[i]] = 1;
            }
        }
        int sa = s1, sb = s2, best = 0;
        for (int i = 0; i <= s3; ++i) {
            if (!rs[n][i]) continue;
            int na = s1 + i, nb = s2 - i;
            if (abs(na - nb) < abs(sa - sb))
                sa = na, sb = nb, best = i;
        }
        int curn = n;
        while (curn) {
            if (best >= d[curn - 1] and rs[curn - 1][best - d[curn - 1]]) {
                swap(a[curn - 1], b[curn - 1]);
                best -= d[curn - 1];
            }
            curn--;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += (a[i] + a[j]) * (a[i] + a[j]);
                ans += (b[i] + b[j]) * (b[i] + b[j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}