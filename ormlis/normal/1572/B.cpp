#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


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
const int maxN = 2e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int cnt = accumulate(all(a), 0);
    if (cnt % 2) {
        cout << "NO\n";
        return;
    }
    if (cnt == n) {
        cout << "NO\n";
        return;
    }
    if (cnt == 0) {
        cout << "YES\n0\n";
        return;
    }
    int t = 0;
    while (a[t] == 0) t++;
    vector<int> ans;
    auto Op = [&](int i) {
        assert(i + 2 < n && 0 <= i);
        ans.push_back(i + 1);
        int x = a[i] ^a[i + 1] ^a[i + 2];
        a[i] = a[i + 1] = a[i + 2] = x;
    };
    while (t > 2) {
        Op(t - 2);
        t -= 2;
    }
    range(i, n - 2) {
        if (a[i] == 0 && a[i + 1] == 0 && a[i + 2] == 0) {
            Op(i - 1);
        }
    }
    int x = 0;
    int mid = -1;
    range(i, n) {
        if (a[i] == 1) {
            x++;
            continue;
        }
        if (x % 2 == 0) {
            mid = i;
            break;
        }
        if (a[i - 1] == 1 && a[i + 1] == 1) {
            mid = i;
            break;
        }
    }
    if (mid == -1) {
        cout << "NO\n";
        return;
    }
    if (x % 2) {
        Op(mid - 1);
    }
    for(int i = mid - 1; i >= 0; --i) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            assert(i > 0);
            if (a[i - 1] == 1) {
                Op(i - 1);
                continue;
            }
            assert(i > 1);
            // 0 0 1
            if (a[i - 2] == 0) {
                Op(i - 2);
                Op(i - 1);
            } else {
                Op( i - 2);
                continue;
            }
        }
    }
    for(int i = mid + 1; i < n; ++i) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            assert(i < n);
            if (a[i + 1] == 1) {
                Op(i - 1);
                continue;
            }
            // 1 0
            assert(i + 2 < n);
            if (a[i + 2] == 0) {
                Op(i);
                Op(i - 1);
            } else {
                Op(i);
            }
        }
    }
    range(i, n) assert(a[i] == 0);
    cout << "YES\n";
    cout << ans.size() << '\n';
    for(auto &w : ans) cout << w << ' ';
    cout << '\n';
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