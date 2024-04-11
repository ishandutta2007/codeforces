#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <unordered_map>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 200;

struct Fenwick {
    vector <int> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void inc(int i) {
        for (; i < t.size(); i |= i + 1)
            t[i]++;
    }
    int get(int i) {
        int res = 0;
        for (; i >= 0; i &= i + 1, --i)
            res += t[i];
        return res;
    }
    void clear() {
        for (auto& x : t) x = 0;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n, ans = 0; cin >> n;

    vector <pair <int, int>> a(n);
    vector <int> vs;
    for (auto& x : a) cin >> x.first;
    for (auto& x : a) cin >> x.second, vs.push_back(x.second);
    sort(a.begin(), a.end());
    sort(vs.begin(), vs.end());

    for (auto& x : a)
        x.second = lower_bound(vs.begin(), vs.end(), x.second) - vs.begin();

    Fenwick tree(n);

    for (int i = 0; i < n; ++i) {
        ans += a[i].first * tree.get(a[i].second);
        tree.inc(a[i].second);
    }
    tree.clear();

    for (int i = n - 1; i >= 0; --i) {
        ans -= a[i].first * (tree.get(n - 1) - tree.get(a[i].second - 1));
        tree.inc(a[i].second);
    }


    cout << ans << '\n';
    return 0;
}