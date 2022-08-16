#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int one = 0, two = 0;
    while (n--) {
        char t; cin >> t;
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        if (t == '+') {
            one = max(one, x), two = max(two, y);
        } else {
            if (one <= x && two <= y) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}