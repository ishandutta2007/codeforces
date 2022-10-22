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

struct SegTree {
    int n;
    vector <int> a, t;
    SegTree(int n, vector <int> a) : n(n), a(a) {
        t.resize(2 * n);
        for (int i = 2 * n - 1; i >= n; --i)
            t[i] = i - n;
        for (int i = n - 1; i >= 1; --i) {
            if (a[t[2 * i]] > a[t[2 * i + 1]]) t[i] = t[2 * i];
            else t[i] = t[2 * i + 1];
        }
    }
    int get(int l, int r) {
        int mx = -mod * mod, id = -1;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                if (a[t[l]] > mx)
                    mx = a[t[l]], id = t[l];
                l++;
            } 
            if (r & 1) {
                r--;
                if (a[t[r]] > mx)
                    mx = a[t[r]], id = t[r];
            }
        }
        return id;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        SegTree MaxTree(n, a);
        bool ans = true;
        auto rec = [&](int l, int r, auto rec) -> vector <int> {
            if (l == r) { return { 0, 0, 0 }; };
            if (l + 1 == r) {
                return { max(0ll, a[l]), max(0ll, a[l]), a[l] };
            }
            int maxId = MaxTree.get(l, r);
            auto lx = rec(l, maxId, rec), rx = rec(maxId + 1, r, rec);
            if (lx[1] + a[maxId] + rx[0] > a[maxId]) ans = false;
            return { max(lx[0], lx[2] + a[maxId] + rx[0]), max(rx[1], rx[2] + a[maxId] + lx[1]), lx[2] + rx[2] + a[maxId] };
            // pref, suf, sum
        };
        rec(0, n, rec);
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}