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
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int W, H; cin >> W >> H;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int w, h; cin >> w >> h;
    ll ans = INF;
    if (x2 - x1 + w <= W) {
        ans = min(ans, 1ll * max(0, min(x2 - (W - w), w - x1)));
    }
    if (y2 - y1 + h <= H) {
        ans = min(ans, 1ll * max(0, min(y2 - (H - h), h - y1)));
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}