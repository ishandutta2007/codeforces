#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define int long long
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
typedef __int128 i128;

const int INFi = 2e9 + 5;
const int maxN = 1e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k = 1;
    cin >> n >> k;
    vector<int> cur;
    while (n) {
        cur.push_back(n % 10);
        n /= 10;
    }
    reverse(all(cur));
    int ans = INFi;
    for (int len = 0; len <= cur.size(); ++len) {
        vector<bool> us(10, false);
        int cnt = 0;
        int x = 0;
        range(j, len) {
            x *= 10;
            x += cur[j];
            if (us[cur[j]]) continue;
            cnt++;
            us[cur[j]] = true;
        }
        if (cnt > k) break;
        if (len == (int) cur.size()) {
            ans = x;
            break;
        }
        int mx = -1, mn = 11;
        range(j, 10) if (us[j]) {
                mx = max(mx, j);
                mn = min(mn, j);
            }
        if (cur[len] == 9) continue;
        if (cnt + 2 <= k) {
            x *= 10;
            x += cur[len] + 1;
            range(_, (int) cur.size() - len - 1) x *= 10;
            ans = min(ans, x);
            continue;
        }
        if (us[cur[len] + 1]) {
            x *= 10;
            x += cur[len] + 1;
            int t = mn;
            if (cnt < k) {
                t = 0;
            }
            range(_, (int)cur.size() - len - 1) {
                x *= 10;
                x += t;
            }
            ans = min(ans, x);
            continue;
        }
        if (cnt + 1 <= k) {
            x *= 10;
            x += cur[len] + 1;
            mn = min(mn, cur[len] + 1);
            range(_, (int) cur.size() - len - 1) {
                x *= 10;
                x += mn;
            }
            ans = min(ans, x);
            continue;
        }
        if (mx <= cur[len]) continue;
        int t1 = cur[len] + 1;
        while(!us[t1]) t1++;
        x *= 10;
        x += t1;
        range(_, (int)cur.size() - len - 1) {
            x *= 10;
            x += mn;
        }
        ans = min(ans, x);
    }
    assert(ans >= n && ans != INFi);
    cout << ans << '\n';
}

signed main() {
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