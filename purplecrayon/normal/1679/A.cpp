#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;
const ll INF = 2e18;

void solve() {
    ll n; cin >> n;
    if (n % 2 || n < 4) {
        cout << -1 << '\n';
        return;
    }
    n /= 2;
    cout << (n + 2) / 3 << ' ' << n / 2 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}