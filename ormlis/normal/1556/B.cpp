#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    ar<int, 2> cnt = {(n + 1) / 2, n / 2};
    int x = 0;
    vector<int> pos;
    range(i, n) {
        cin >> a[i];
        if (a[i] % 2) {
            x++;
            pos.push_back(i);
        }
    }
    if (x != cnt[0] && x != cnt[1]) {
        cout << "-1\n";
        return;
    }

    vector<int> l, r;
    range(i, n) {
        if (i & 1) r.push_back(i);
        else l.push_back(i);
    }
    ll ans = INF;
    if (x == cnt[0]) {
        assert(l.size() == x);
        ll res = 0;
        range(i, (int)pos.size()) {
            res += abs(pos[i] - l[i]);
        }
        ans = min(ans, res);
    }

    if (x == cnt[1]) {
        assert(r.size() == x);
        ll res = 0;
        range(i, (int)pos.size()) {
            res += abs(pos[i] - r[i]);
        }
        ans = min(ans, res);
    }

    cout << ans << '\n';
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