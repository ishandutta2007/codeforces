#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    if (n < 6) {
        cout << -1 << '\n';
    } else {
        for (int i = 1; i < n; i++) {
            if (i < 4) cout << 1 << ' ' << i+1 << '\n';
            else cout << 2 << ' ' << i+1 << '\n';
        }
    }
    for (int i = 1; i < n; i++) cout << 1 << ' ' << i+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}