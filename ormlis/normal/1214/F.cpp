#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 1e6 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<ll> solve1(vector<pair<int, int>> &a, vector<pair<int, int>> &b, int n, int m, int c) {
    vector<ll> to(n + 1);
    int d = (m - c) / 2;
    auto upd = [&](int i, int l, int r, int x) {
        l -= i;
        r -= i;
        if (l < 0) l += n;
        if (r < 0) r += n;
        to[l] += x;
        to[r] -= x;
        if (l >= r) {
            to[0] += x;
        }
    };
    range(i, n) {
        int x = a[i].first;
        int y = x + d;
        if (y < m) {
            int l = lower_bound(all(b), pair<int, int>{x + c, -1}) - b.begin();
            int r = lower_bound(all(b), pair<int, int>{y + 1, -1}) - b.begin();
            if (l < r) {
                // [l, r)
                upd(i, l, r, -x);
            }
            if (r < n) {
                // [r, n)
                upd(i, r, n, x + m * c);
            }
            if (l != 0) {
                // [0, l)
                upd(i, 0, l, x);
            }
        } else {
            int l = lower_bound(all(b), pair<int, int>{x + c, -1}) - b.begin();
            int r = lower_bound(all(b), pair<int, int>{(y + 1) % m, -1}) - b.begin();
            if (l != n) {
                // [l, n)
                upd(i, l, n, -x);
            }
            if (r != 0) {
                // [0, r)
                upd(i, 0, r, -x + m * c);
            }
            if (r < l) {
                // [r, l)
                upd(i, r, l, x);
            }
        }
    }
    for(int i = 1; i <= n; ++i) to[i] += to[i - 1];
    to.pop_back();
    return to;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> a(n), b(n);
    range(i, n) {
        cin >> a[i].first;
        a[i].first--;
        a[i].second = i;
    }
    range(i, n) {
        cin >> b[i].first;
        b[i].first--;
        b[i].second = i;
    }
    sort(all(a));
    sort(all(b));
    auto to1 = solve1(a, b, n, m, 1);
    auto to2 = solve1(b, a, n, m, 0);
    pair<ll, int> res = {INF, -1};
    range(i, n) {
        ll cur = to1[i];
        int j = (n-i)%n;
        cur += to2[j];
        res = min(res, {cur, i});
    }
    vector<int> to(n);
    range(i, n) {
        int j = (i + res.second) % n;
        to[a[i].second] = b[j].second;
    }
    cout << res.first << '\n';
    range(i, n) cout << to[i] + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}