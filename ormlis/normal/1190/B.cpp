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
typedef __int128 i128;

const int INFi = 1e9 + 5;
const int maxN = 1e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    int cnt = 0;
    for(int i = 1; i < n; ++i) if (a[i] == a[i - 1]) cnt++;
    if (cnt >= 2 || accumulate(all(a), 0ll) == 0) {
        cout << "cslnb\n";
        return;
    }
    int w = 0;
    if (cnt == 1) {
        for(int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                if (a[i] == 0 || (i >= 2 && a[i - 2] + 1 == a[i])) {
                    cout << "cslnb\n";
                    return;
                }
                a[i - 1]--;
                break;
            }
        }
        w = 1;
    }
    ll can = w;
    range(i, n) {
        can += a[i] - i;
    }
    if (can % 2) {
        cout << "sjfnb\n";
    } else {
        cout << "cslnb\n";
    }
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