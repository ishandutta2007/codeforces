#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

// a, b, c, d, e 
// a, b - a, c - b, d - c, e - d
// a, c + a - b, c, d, e
// a, c - b, b - a, d - c, e - d

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    vector<ll> b(n); for (auto& x : b) cin >> x;
    if (a[0] != b[0]) {
        cout << "No\n";
        return;
    }
    for (int i = n-1; i >= 1; i--) a[i] -= a[i-1], b[i] -= b[i-1];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) cout << "Yes\n";
    else cout << "No\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}