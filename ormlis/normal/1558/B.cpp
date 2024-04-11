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

const int INFi = 2e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 3e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    vector<int> cnt(n + 2);
    int cur = 1;
    cnt[2] = m - 1;
    for(int i = 1; i <= n; ++i) {
        cur = (cur + cnt[i]) % m;
        cnt[i + 1] = (cnt[i + 1] + cur) % m;
        for(int z = 2; z * i <= n; ++z) {
            int l = z * i;
            int r = min(n + 1, l + z);
            cnt[l] = (cnt[l] + cur) % m;
            cnt[r] = (cnt[r] - cur + m) % m;
        }
    }
    cout << cur << '\n';
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