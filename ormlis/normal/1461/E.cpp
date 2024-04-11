#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

ll max_time(ll k, ll r, ll x, ll y) {
    if (r - y < 0) {
        return k / x;
    }
    if (x >= y) {
        ll need_days = max(0ll, (k - (r - y) + x - 1)) / x;
        ll there = k - need_days * x;
        if (there < 0) {
            return need_days - 1;
        }
        ll od = x - y;
        if (x == y) {
            return INF;
        }
        return need_days + there / od;
    }
    ll mxt = 0;
    if (r - y >= k) {
        ll add = y - x;
        ll need_first = (r - y + 1 - k) / add;
        mxt += need_first;
        k += need_first * add;
    }
    if (r - y + 1 - x >= 0) return INF;
    ll bad = r - y;
    vector<bool> was(bad + 1);
    ll cur = k % x;
    mxt += k / x;
    while (cur <= bad && !was[cur]) {
        was[cur] = true;
        mxt++;
        cur += y - x;
        mxt += cur / x;
        cur %= x;
    }
    if (cur > bad) {
        return mxt;
    }
    return INF;
}

void solve() {
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    r -= l;
    k -= l;
    l = 0;
    if (max_time(k, r, x, y) >= t) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}