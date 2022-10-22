#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

struct SegTree {
    int n;
    vector <int> t;
    SegTree(int n) : n(n) {
        t.resize(2 * n);
    }
    void upd(int i, int x) {
        i += n;
        t[i] = max(t[i], x);
        for (i >>= 1; i > 0; i >>= 1)
            t[i] = max(t[i * 2], t[i * 2 + 1]);
    }
    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    int n, m; cin >> n >> m;
    vector <int> cnt(m);
    for (int i = 0, l, r; i < n; ++i) {
        cin >> l >> r;
        cnt[l - 1]++;
        if (r < m) cnt[r]--;
    }
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
    vector <int> dpUp(m), dpDn(m);
    SegTree stUp(n), stDn(n);
    for (int i = 0; i < m; ++i) {
        dpUp[i] = stUp.get(0, cnt[i] + 1) + 1;
        stUp.upd(cnt[i], dpUp[i]);
    }
    for (int i = m - 1; i >= 0; --i) {
        dpDn[i] = stDn.get(0, cnt[i] + 1) + 1;
        stDn.upd(cnt[i], dpDn[i]);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i)
        ans = max(ans, dpUp[i] + dpDn[i] - 1);
    cout << ans << '\n';
    return 0;
}