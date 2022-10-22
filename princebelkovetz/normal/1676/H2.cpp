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

struct Fenwick {
    vector <int> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void upd(int i) {
        for (; i < t.size(); i |= i + 1) t[i]++;
    }
    int get(int i) {
        int r = 0;
        for (; i >= 0; i &= i + 1, --i) r += t[i];
        return r;
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
        int ans = 0;
        Fenwick tree(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            ans += tree.get(a[i]);
            tree.upd(a[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}