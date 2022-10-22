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
#include <bitset>
#include <functional>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int mod = 1e9 + 7, p = 239;

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
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    vector <int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {return a[i] != a[j] ? (a[i] > a[j]) : (i < j); });
    int q; cin >> q;
    vector <vector <int>> qs(q, vector <int>(2));
    for (auto& x : qs) cin >> x[0] >> x[1], x[0]--;
    vector <int> Q(q);
    iota(Q.begin(), Q.end(), 0);
    sort(Q.begin(), Q.end(), [&](int i, int j) {return qs[i][0] < qs[j][0]; });
    vector <int> ans(q);
    int lst = 0;
    Fenwick tree(n);
    for (auto& id : Q) {
        while (lst <= qs[id][0])
            tree.inc(ids[lst++]);
        int l = -1, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (tree.get(m) >= qs[id][1]) r = m;
            else l = m;
        }
        ans[id] = a[r];
    }
    for (auto& x : ans) cout << x << '\n';
    return 0;
}