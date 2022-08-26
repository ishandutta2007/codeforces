#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <numeric>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n, INF);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] = min(fenw[i], x);
    }

    ll get(int i) {
        ll res = INF;
        for (; i >= 0; i = (i & (i + 1)) - 1) res = min(res, fenw[i]);
        return res;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<bool> b(n);
    range(i, k) {
        int x;
        cin >> x;
        b[x - 1] = true;
    }
    range(i, n) {
        a[i] = a[i] - i;
    }
    auto solve = [&](int l, int r) {
        if (l == r) return 0ll;
        vector<int> values;
        for (int i = l - 1; i <= r; ++i) {
            if (i < 0 || i >= n) continue;
            values.push_back(a[i]);
        }
        values.push_back(INFi);
        values.push_back(-INFi);
        sort(all(values));
        values.resize(unique(all(values)) - values.begin());
        int vn = values.size();
        auto get_ind = [&](int v) {
            return lower_bound(all(values), v) - values.begin();
        };
        fenwick f;
        f.build(vn);
        if (l) {
            f.upd(get_ind(a[l - 1]), -l + 1);
        } else {
            f.upd(get_ind(-INFi), -l + 1);
        }
        for (int i = l; i < r; ++i) {
            int j = get_ind(a[i]);
            ll pdp = f.get(j);
            if (pdp != INF) {
                ll dp = i + pdp - 1;
                f.upd(j, dp - i);
            }
        }
        if (r != n) {
            int j = get_ind(a[r]);
            ll pdp = f.get(j);
            if (pdp != INF) {
                ll dp = r + pdp - 1;
                return dp;
            }
        } else {
            int j = get_ind(INFi);
            ll pdp = f.get(j);
            if (pdp != INF) {
                ll dp = r + pdp - 1;
                return dp;
            }
        }
        cout << "-1\n";
        exit(0);
    };
    int previous = 0;
    int ans = 0;
    range(i, n) {
        if (b[i]) {
            if (previous != 0 && a[i] < a[previous-1]) {
                cout << "-1\n";
                return;
            }
            ans += solve(previous, i);
            previous = i + 1;
        }
    }
    ans += solve(previous, n);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}