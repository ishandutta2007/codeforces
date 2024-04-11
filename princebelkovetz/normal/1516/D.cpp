#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7;
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
set <int> d(int x) {
    set <int> ok = {};
    for (int j = 2; j * j <= x; ++j) {
        while (x % j == 0) {
            ok.insert(j);
            x /= j;
        }
    }
    if (x != 1)
        ok.insert(x);
    return ok;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q, lg = 1; cin >> n >> q;
    while ((1 << lg) < n) lg++;
    lg++;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    vector <int> lx(n, n);
    int ind = 0;
    set <int> cur = {};
    for (int i = 0; i < n; ++i) {
        while (ind < n) {
            set <int> ok = d(a[ind]);
            bool c = true;
            for (auto x : ok) {
                if (cur.find(x) != cur.end()) {
                    c = false;
                    break;
                }
            }
            if (!c) break;
            for (auto x : ok)
                cur.insert(x);
            ind++;
        }
        lx[i] = ind;
        set <int> ok = d(a[i]);
        for (auto x : ok)
            cur.erase(x);
    }
    vector <vector <int>> binup(lg, vector <int>(n, n));
    for (int i = 0; i < n; ++i)
        binup[0][i] = lx[i];
    for (int i = 1; i < lg; ++i) {
        for (int j = 0; j < n; ++j) {
            if (binup[i - 1][j] == n) continue;
            binup[i][j] = binup[i - 1][binup[i - 1][j]];
        }
    }
    while (q --> 0) {
        int l, r; cin >> l >> r;
        l--;
        int ans = 0;
        for (int i = lg - 1; i >= 0; --i) {
            if (binup[i][l] < r) {
                ans += (1 << i);
                l = binup[i][l];
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}