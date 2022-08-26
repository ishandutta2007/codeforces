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
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<vector<int>> to(n);
    range(i, n * 2) {
        int x; cin >> x;
        to[x - 1].push_back(i);
    }
    int ans = 0;
    range(a, n) {
        range(b, a) {
            int la = to[a][0], ra = to[a][1];
            int lb = to[b][0], rb = to[b][1];
            if (la > ra) swap(la, ra);
            if (lb > rb) swap(lb, rb);
            if (ra < lb || rb < la) continue;
            if (la < lb && rb < ra) {
                ans += 2;
            } else if (lb < la && ra < rb) {
                ans += 2;
            } else {
                ans += 1;
            }
        }
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