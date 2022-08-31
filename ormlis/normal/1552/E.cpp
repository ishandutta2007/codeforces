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

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 31607;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(n * k);
    vector<int> c(n * k);
    range(i, n * k) cin >> c[i];
    int l = 0;
    vector<int> last(n + 1, -1);
    vector<bool> was(n + 1);
    int mx = (n + k - 2) / (k - 1);
    vector<pair<int, int>> ans(n + 1);
    range(i, n * k) {
        if (was[c[i]]) continue;
        if (last[c[i]] < l) {
            last[c[i]] = i;
            continue;
        }
        was[c[i]] = true;
        for(int j = last[c[i]]; j <= i; ++j) {
            cnt[j]++;
            if (cnt[j] == mx) {
                l = j + 1;
            }
        }
        ans[c[i]] = {last[c[i]], i};
    }
    range(i, n) {
        assert(was[i + 1]);
    }
    range(i, n) {
        cout << ans[i + 1].first + 1 << ' ' << ans[i + 1].second + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}