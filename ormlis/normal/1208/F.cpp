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
const int maxN = 1 << 21;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int was[maxN];
int t[maxN];
int T;

void rec_was(int mask) {
    if (t[mask] == T) return;
    if (was[mask] == 2) return;
    was[mask]++;
    t[mask] = T;
    range(i, 21) {
        if (mask & (1 << i)) {
            rec_was(mask ^ (1 << i));
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i + 2 < n) {
            int mask = 0;
            for (int j = 20; j >= 0; --j) {
                if ((1 << j) & a[i]) continue;
                if (was[mask ^ (1 << j)] == 2) mask ^= (1 << j);
            }
            ans = max(ans, mask ^ a[i]);
        }
        T = i + 5;
        rec_was(a[i]);
    }
    cout << ans << '\n';
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