#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int g = 0;
    for (int x : a) g = gcd(g, x);
    if (g == 1) {
        cout << 0 << '\n';
        return;
    }
    if (gcd(g, n) == 1) {
        cout << 1 << '\n';
    } else if (gcd(g, n - 1) == 1) {
        cout << 2 << '\n';
    } else {
        cout << 3 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}