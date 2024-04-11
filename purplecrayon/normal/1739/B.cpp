#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> d(n); for (auto& x : d) cin >> x;
    vector<int> a(n); a[0] = d[0];
    for (int i = 1; i < n; i++) {
        if (a[i-1] - d[i] >= 0 && d[i] != 0) {
            cout << -1 << '\n';
            return;
        }
        a[i] = a[i-1] + d[i];
    }
    for (int x : a) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}