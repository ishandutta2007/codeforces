#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

using namespace __gnu_pbds;
typedef tree<pair<int, int>,
        null_type,
        greater<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, w, k;
    cin >> n >> w >> k;
    vector<int> a(n + 1), t(n);
    range(i, n) cin >> a[i];
    a[n] = 0;
    range(i, n) cin >> t[i];
    int ans = 0;
    int cur_tsum = 0;
    int cur_tskip = 0;
    int cur_asum = 0;
    ordered_set skip;
    int j = 0;
    range(i, n) {
        while (cur_tsum - cur_tskip <= k && j < n) {
            cur_asum += a[j];
            cur_tsum += t[j];
            pair<int, int> kek = {t[j], j};
            skip.insert(kek);
            if (skip.size() <= w) {
                cur_tskip += t[j] / 2;
            } else if (skip.order_of_key(kek) < w) {
                cur_tskip += t[j] / 2;
                cur_tskip -= (*skip.find_by_order(w)).first / 2;
            }
            j++;
        }
        if (cur_tsum - cur_tskip <= k) {
            ans = max(ans, cur_asum);
        } else {
            ans = max(ans, cur_asum - a[j - 1]);
        }
        cur_tsum -= t[i];
        pair<int, int> kek = {t[i], i};
        if (skip.order_of_key(kek) < w) {
            cur_tskip -= t[i] / 2;
            if (skip.size() > w) {
                cur_tskip += (*skip.find_by_order(w)).first / 2;
            }
        }
        skip.erase(kek);
        cur_asum -= a[i];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}