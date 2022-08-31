#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 501;
ll md = 1000000007;

void solve() {
        int n; ll m; cin >> n >> m;
        ll lc = m, rc = m, tc=0;
    int flag = 0;
    range(i, n) {
        ll t1, l, h; cin >> t1 >> l >> h;
        ll t = t1 - tc;
        tc = t1;
        if (lc - t > h || rc + t < l) {
            flag = 1;
        }
        lc = max(l, lc - t);
        rc = min(h, rc + t);
    }
    if (flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}