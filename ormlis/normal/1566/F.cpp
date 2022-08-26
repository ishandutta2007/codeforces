#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<pair<int, int>> segs(m);
    range(i, m) {
        cin >> segs[i].first >> segs[i].second;
    }
    sort(all(a));
    sort(all(segs), [&](const pair<int, int> &x, const pair<int, int> &y) {
        return make_pair(x.first, -x.second) < make_pair(y.first, -y.second);
    });
    segs.resize(unique(all(segs)) - segs.begin());
    {
        vector<pair<int, int>> segs2;
        for (auto &[l, r] : segs) {
            if (lower_bound(all(a), l) != upper_bound(all(a), r)) continue;
            while (!segs2.empty() && segs2.back().second >= r) {
                segs2.pop_back();
            }
            segs2.emplace_back(l, r);
        }
        segs = segs2;
        m = segs.size();
    }
    vector<ll> dp(m + 1, INF);
    dp[0] = 0;
    range(i, n) {
        pair<int, int> tmp = {-INFi, -INFi};
        if (i) tmp.first = a[i - 1];
        int l = lower_bound(all(segs), tmp) - segs.begin();
        if (i + 1 < n) {
            tmp.first = a[i + 1];
        } else {
            tmp.first = INFi;
        }
        int r = lower_bound(all(segs), tmp) - segs.begin();
        tmp.first = a[i];
        int mid = lower_bound(all(segs), tmp) - segs.begin();
        if (l == r) continue;
        ll mn1 = dp[mid] - a[i], mn2 = dp[mid] - a[i] * 2;
        for (int j = l; j < mid; ++j) {
            mn1 = min(mn1, 1ll * a[i] + dp[j] - segs[j].second * 2);
            mn2 = min(mn2, 1ll * (-a[i]) + dp[j] - segs[j].second);
        }
        for (int j = mid; j < r; ++j) {
            dp[j + 1] = min(dp[j + 1], 1ll * segs[j].first + mn1);
            dp[j + 1] = min(dp[j + 1], 1ll * segs[j].first * 2 + mn2);
        }
        for (int j = l; j < mid; ++j) {
            assert(a[i] > segs[j].second);
            dp[mid] = min(dp[mid], dp[j] + a[i] - segs[j].second);
        }
    }
    cout << dp[m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}