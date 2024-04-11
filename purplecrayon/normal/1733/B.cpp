#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    if (min(x, y) >= 1) {
        cout << -1 << '\n';
        return;
    }
    int m = max(x, y);
    if (m == 0 || (n - 1) % m) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++) cout << (i / m) * m + 2 << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}