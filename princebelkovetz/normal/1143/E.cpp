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

const int mod = 1e9 + 7, N = 4e2 + 2;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int n, m, q; cin >> n >> m >> q;
    vector <int> p(n), a(m), id(n);
    for (auto& x : p) cin >> x, --x;
    for (auto& x : a) cin >> x, --x;
    for (int i = 0; i < n; ++i) id[p[i]] = i;
    int LOG = 0;
    while ((1 << LOG) <= m) LOG++;
    vector <vector <int>> binup(m + 1, vector <int>(LOG));
    for (auto& x : binup.back())
        x = m;
    map <int, int> last;
    for (auto& x : p)
        last[x] = m;
    for (int i = m - 1; i >= 0; --i) {
        binup[i][0] = last[p[(id[a[i]] + 1) % n]];
        for (int j = 1; j < LOG; ++j)
            binup[i][j] = binup[binup[i][j - 1]][j - 1];
        last[a[i]] = i;
    }
    vector <int> rx(m);
    for (int i = 0; i < m; ++i) {
        int lft = n - 1, ind = i;
        for (int j = LOG - 1; j >= 0; --j) {
            if ((1ll << j) <= lft) {
                lft -= (1ll << j), ind = binup[ind][j];
            }
        }
        rx[i] = ind;
    }
    vector <vector <int>> t(m, vector <int>(LOG));
    vector <int> l2(m + 1);
    for (int i = 2; i <= m; ++i)
        l2[i] = l2[i / 2] + 1;
    for (int i = 0; i < m; ++i)
        t[i][0] = rx[i];
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i + (1ll << (j - 1)) < m; ++i) {
            t[i][j] = min(t[i][j - 1], t[i + (1ll << (j - 1))][j - 1]);
        }
    }
    auto rmq = [&](int l, int r) -> int {
        int lg = l2[r - l];
        return min(t[l][lg], t[r - (1ll << lg)][lg]);
    };
    string ans;
    while (q--) {
        int l, r; cin >> l >> r;
        --l;
        ans += rmq(l, r) < r ? '1' : '0';
    }
    cout << ans << '\n';
}