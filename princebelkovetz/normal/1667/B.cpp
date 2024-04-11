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
const int root = 212, mod = 1e9 + 7, N = 5e5 + 2, L = 30;

struct SegTree {
    int n;
    vector <int> tree;
    SegTree(int n) : n(n) {
        tree.resize(2 * n, -mod * mod);
    }
    void upd(int i, int x) {
        i += n;
        tree[i] = max(tree[i], x);
        for (i /= 2; i > 0; i /= 2)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    int get(int l, int r) {
        int res = -mod * mod;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n), pref(n + 1);
        for (auto& x : a) cin >> x;
        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + a[i];
        sort(pref.begin(), pref.end());
        pref.erase(unique(pref.begin(), pref.end()), pref.end());
        SegTree s1(pref.size()), s2(pref.size()), s3(pref.size());
        
        auto getInd = [&](int i) {
            return lower_bound(pref.begin(), pref.end(), i) - pref.begin();
        };
        s1.upd(getInd(0), 0);
        s2.upd(getInd(0), 0);
        s3.upd(getInd(0), 0);
        int sum = 0, ans = -mod * mod;
        for (int i = 1; i <= n; ++i) {
            sum += a[i - 1];
            int id1 = getInd(sum);
            int id2 = getInd(sum + 1);
            int res = max({ s1.get(0, id1) + i, s2.get(id2, pref.size()) - i, s3.get(id1, id2) });
            if (i == n) ans = res;
            s1.upd(id1, res - i);
            s2.upd(id1, res + i);
            s3.upd(id1, res);
        }
        cout << ans << '\n';
    }



    return 0;
}