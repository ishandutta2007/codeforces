#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        int x = (l + i - 1) / i * i;
        if (l <= x && x <= r) {
            ans[i-1] = x;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}