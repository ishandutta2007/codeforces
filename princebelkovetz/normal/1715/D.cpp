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
const int root = 212, mod = 998244353, N = 2e5 + 12;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, q; cin >> n >> q;
    vector <vector <int>> a(q, vector <int>(3));
    for (auto& x : a) {
        for (auto& y : x) cin >> y;
        x[0]--, x[1]--;
        if (x[0] > x[1]) swap(x[0], x[1]);
    }
    sort(a.begin(), a.end());
    vector <int> ans(n);

    for (int i = 0; i < 30; i++) {
        vector <bool> z(n), o(n);
        vector <vector <int>> e(n);
        for (auto& x : a) {
            if ((x[2] >> i) & 1 ^ 1)
                z[x[0]] = z[x[1]] = true;
            else
                e[x[0]].push_back(x[1]);
        }
        for (int j = 0; j < n; j++) {
            if (o[j]) continue;
            bool ok = false, same = false;
            for (auto& x : e[j]) {
                if (z[x]) ok = true;
                if (x == j) same = true;
            }
            if (ok or same) o[j] = true;
            else
                for (auto& x : e[j])
                    o[x] = true;
        }
        for (int j = 0; j < n; j++)
            ans[j] += o[j] * (1ll << i);
    }

    for (auto& x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}