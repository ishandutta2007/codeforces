#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    // max() - min()
    // b = 2*a, a = 2*b, b = 3*a, a = 3*b, a = b
    int ans = n + 2 * (n / 2) + 2 * (n / 3);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}